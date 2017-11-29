/*An extra C file for all of the ADAS specific subfunctions that were written in the main.c file.
 Intended to clean up main.c so that it is easier to understand what is going on and modify it later.
 Code by Dan and Suzhou, compiled by Matt*/

#include "Lcd.h"
#include "ADASfxns.h"
#include <p18f46k22.h>
#include <stdio.h>
#include <stdlib.h>
#include "ADAS1000.h"
#include "Communication.h"
#include "General.h"

//unsigned char                 // for pacing
unsigned long ADAS1000_RegVal_ECGCTL;
unsigned long ADAS1000_RegVal_CMREFCTL;
unsigned long ADAS1000_RegVal_TESTTONE;
unsigned long ADAS1000_RegVal_FRMCTL;

// allocate a buffer for storing a frame. It is the max frame size for 2k
// data(12) and the word size is in bits (32). This buffer should be 48 bytes.
// THis means that you can NEVER read more than one frame at a time into this buffer
// unless you calculate how many of the new frame size packets can fit into a 48 byte buffer.
extern unsigned char data_buffer[48];

extern unsigned char FillingCnt = 0;    //counts in samples (not bytes))
extern unsigned char *FillingBuffPnt, lastRadioBuff;   
extern unsigned long *data;
extern unsigned char* radiodataptr;
extern char FillingBuff;               // currently filling buffer (0,1))
extern char radioBuff;                 // currently the radio buffer
extern unsigned char logicAnalyzerOutputEnable = 1;            //true if outputting
extern unsigned char Buffer0[64], Buffer1[64];
extern unsigned char RadioCnt, doneRadioBuff;
extern unsigned char RadioCnt, lastRadioBuff;

void InitLogicAnalyzerOut(){
    // logic analyzer output puts data on the output pins that can be read by the anlyzer
    // It outputs 1 byte and a clock as follows:
    // Data bits 0-3  output on Port E 0-2 and Port A 4
    // Data bits 4-7  output on Port B 4-7
    // Clock output on Port A 5
    // This routine initializes the ports
    TRISBbits.RB4 = 0;
    TRISBbits.RB5 = 0;
    TRISBbits.RB6 = 0;
    TRISBbits.RB7 = 0;
    TRISEbits.RE0 = 0;
    TRISEbits.RE1 = 0;
    TRISEbits.RE2 = 0;
    TRISAbits.RA4 = 0;
    TRISAbits.RA5 = 0; 
}

/***************************************************************************//**
 * @brief Prints a register value from the ADAS.
 *
 * @param regVal - value read from the register
 * 
 * @return None.
*******************************************************************************/
void LCDWriteADAS(unsigned long regVal) {
    int i;
    char str[8];
    sprintf(str, "%08lX", regVal);
    for (i = 0; i < 8; i++) {
        LCDPutChar(str[i]);
    }
}

/* Set the register values of the ADAS */
void ADAS_DATA_INIT(){
    unsigned char readCmd[4] = {0, 0, 0, 0};
    
    /* Set ECG Control Register */
    
    //0b111110000000010010101110
    //ADAS1000_RegVal_ECGCTL = \
        ADAS1000_ECGCTL_LAEN | ADAS1000_ECGCTL_LLEN |  ADAS1000_ECGCTL_RAEN | \
        ADAS1000_ECGCTL_CHCONFIG | ADAS1000_ECGCTL_VREFBUF | ADAS1000_ECGCTL_MASTER | \
        ADAS1000_ECGCTL_HP | ADAS1000_ECGCTL_CNVEN | ADAS1000_ECGCTL_PWREN | \
        ADAS1000_ECGCTL_GAIN_2_8 | ADAS1000_ECGCTL_GANG;
    
    //0b100000000000000010111110
    ADAS1000_RegVal_ECGCTL = \
        ADAS1000_ECGCTL_LAEN | ADAS1000_ECGCTL_VREFBUF | ADAS1000_ECGCTL_MASTER | \
        ADAS1000_ECGCTL_HP | ADAS1000_ECGCTL_CNVEN | \
        ADAS1000_ECGCTL_GAIN_2_8 | \
        ADAS1000_ECGCTL_PWREN;
    
    /* Set Common Mode Electrodes */
    
    //0b111000000000000000001011
    //ADAS1000_RegVal_CMREFCTL = \
        ADAS1000_CMREFCTL_LACM | ADAS1000_CMREFCTL_LLCM | ADAS1000_CMREFCTL_RACM | \
        ADAS1000_CMREFCTL_DRVCM | ADAS1000_CMREFCTL_RLD_EN | ADAS1000_CMREFCTL_SHLDEN;
    
    //0b100000000000000000000011
    //ADAS1000_RegVal_CMREFCTL = ADAS1000_CMREFCTL_DRVCM | ADAS1000_CMREFCTL_SHLDEN;
    
    //ADAS1000_RegVal_CMREFCTL = 0ul;
    
    ADAS1000_RegVal_CMREFCTL = \
        ADAS1000_CMREFCTL_CERLD | ADAS1000_CMREFCTL_CEREFEN | ADAS1000_CMREFCTL_DRVCM | \
        ADAS1000_CMREFCTL_RLD_EN | ADAS1000_CMREFCTL_SHLDEN;
            
    /* Set Frame Control Register */
    
    //0b000001111001011000000000
    //ADAS1000_RegVal_FRMCTL = \
        ADAS1000_FRMCTL_V1DIS | ADAS1000_FRMCTL_V2DIS | ADAS1000_FRMCTL_LOFFDIS | \
        ADAS1000_FRMCTL_PACEDIS | ADAS1000_FRMCTL_RESPMDIS | ADAS1000_FRMCTL_RESPPHDIS | \
        ADAS1000_FRMCTL_GPIODIS | ADAS1000_FRMCTL_CRCDIS | ADAS1000_FRMCTL_RDYRPT | \
        ADAS1000_FRMCTL_SKIP_4FRM;
    
    //0b011111111111111000010000
    ADAS1000_RegVal_FRMCTL = \
        ADAS1000_FRMCTL_LEAD_II_LLDIS | ADAS1000_FRMCTL_LEAD_III_RADIS | ADAS1000_FRMCTL_V1DIS | \
        ADAS1000_FRMCTL_V2DIS | ADAS1000_FRMCTL_PACEDIS | ADAS1000_FRMCTL_RESPMDIS | \
        ADAS1000_FRMCTL_RESPPHDIS | ADAS1000_FRMCTL_GPIODIS | ADAS1000_FRMCTL_LOFFDIS | \
        ADAS1000_FRMCTL_CRCDIS | ADAS1000_FRMCTL_DATAFMT | ADAS1000_FRMCTL_SKIP_4FRM;
    
    ADAS1000_SetInactiveFrameWords( \
        ADAS1000_FRMCTL_LEAD_II_LLDIS | ADAS1000_FRMCTL_LEAD_III_RADIS | ADAS1000_FRMCTL_V1DIS | \
        ADAS1000_FRMCTL_V2DIS | ADAS1000_FRMCTL_PACEDIS | ADAS1000_FRMCTL_RESPMDIS | \
        ADAS1000_FRMCTL_RESPPHDIS | ADAS1000_FRMCTL_GPIODIS | ADAS1000_FRMCTL_LOFFDIS | \
        ADAS1000_FRMCTL_CRCDIS);
    
    /* Use functions to set the registers */
    
    ADAS1000_SetRegisterValue(ADAS1000_CMREFCTL, ADAS1000_RegVal_CMREFCTL);
    
    ADAS1000_SetRegisterValue( ADAS1000_FILTCTL, (0b10ul<<2));
    
    ADAS1000_SetRegisterValue( ADAS1000_FRMCTL, ADAS1000_RegVal_FRMCTL);
    ADAS1000_SetInactiveFrameWords(ADAS1000_RegVal_FRMCTL & ADAS1000_FRMCTL_WORD_MASK);
    
    ADAS1000_SetRegisterValue(ADAS1000_ECGCTL, ADAS1000_RegVal_ECGCTL);
}

void ADAS_TEST_TONE(){
 //   unsigned char readCmd[4] = {0, 0, 0, 0};
    
    ADAS1000_RegVal_ECGCTL = \
        ADAS1000_ECGCTL_LAEN | ADAS1000_ECGCTL_LLEN | ADAS1000_ECGCTL_RAEN | \
        ADAS1000_ECGCTL_V1EN | ADAS1000_ECGCTL_V2EN | ADAS1000_ECGCTL_VREFBUF | \
        ADAS1000_ECGCTL_MASTER | ADAS1000_ECGCTL_HP | ADAS1000_ECGCTL_CNVEN | \
        ADAS1000_ECGCTL_PWREN;
    
    ADAS1000_RegVal_CMREFCTL = \
        ADAS1000_CMREFCTL_DRVCM | ADAS1000_CMREFCTL_RLD_EN | ADAS1000_CMREFCTL_SHLDEN;
    
    ADAS1000_RegVal_TESTTONE = \
        ADAS1000_TESTTONE_TONLA | ADAS1000_TESTTONE_TONLL | ADAS1000_TESTTONE_TONRA |  \
        ADAS1000_TESTTONE_TONV1 | ADAS1000_TESTTONE_TONV2 | \
        ADAS1000_TESTTONE_TONINT | ADAS1000_TESTTONE_TONEN;
    
    ADAS1000_RegVal_FRMCTL = \
        ADAS1000_FRMCTL_LEAD_II_LLDIS | ADAS1000_FRMCTL_LEAD_III_RADIS | ADAS1000_FRMCTL_V1DIS | \
        ADAS1000_FRMCTL_V2DIS | ADAS1000_FRMCTL_PACEDIS | ADAS1000_FRMCTL_RESPMDIS | ADAS1000_FRMCTL_RESPPHDIS | \
        ADAS1000_FRMCTL_GPIODIS | ADAS1000_FRMCTL_LOFFDIS | ADAS1000_FRMCTL_CRCDIS | \
        ADAS1000_FRMCTL_DATAFMT | ADAS1000_FRMCTL_SKIP_4FRM;
            
    ADAS1000_SetRegisterValue(ADAS1000_CMREFCTL, ADAS1000_RegVal_CMREFCTL);
    
    ADAS1000_SetRegisterValue(ADAS1000_TESTTONE, ADAS1000_RegVal_TESTTONE);
    
    ADAS1000_SetRegisterValue( ADAS1000_FILTCTL, (0b10ul<<2));
    
    ADAS1000_SetRegisterValue( ADAS1000_FRMCTL, ADAS1000_RegVal_FRMCTL);
    ADAS1000_SetInactiveFrameWords(ADAS1000_RegVal_FRMCTL & ADAS1000_FRMCTL_WORD_MASK);
    
    ADAS1000_SetRegisterValue(ADAS1000_ECGCTL, ADAS1000_RegVal_ECGCTL);
}

