/* 
 * File:   mainbrain.c
 * Author: BME464
 *
 * Created on November 27, 2017, 5:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "mainbrain.h"
#include "ADAS1000.h"
#include "Communication.h"

extern unsigned char RadioCnt = 0;
extern unsigned char *FillingBuffPnt;   
extern unsigned long ADASdata;
extern char FillingBuff;               // currently filling buffer (0,1))
extern char radioBuff;                 // currently the radio buffer
extern unsigned char Buffer0[64], Buffer1[64];
extern unsigned char* radiodataptr;
/********************************************************************
* Function:         recCommand
* 
* PreCondition: 	serial data has to be available to receive
*
* Side Effects: 	None
*/
/**
* @ingroup  		Serial
*
* @brief    		This function receives a "radio tx data" from the photon.  it needs
 *                  to be able to parse the "data" for an integer that represents
 *                  the case to switch to in the while(1) loop of the main fxn
* 
* @param			none
*
* @result			{int}	this int determines what case we go to
*
* @note    			we need to be able to differentiate between integers 
 *                  suggesting commands, and other ints, like parameters 
*/
/*******************************************************************/
unsigned char recCommand(void){
    
}

/********************************************************************
* Function:         wakeADAS
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		ADAS
*
* @brief    		This function is called to wake up the ADAS
* 
* @param			none
*
* @result			none, other than the ADAS in now awake
*
* @note    			
*/
/*******************************************************************/
void wakeADAS(void){
    
}

/********************************************************************
* Function:         setPacingParam
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Serial/Pacing
*
* @brief    		This function receives a packet of data from the photon
 *                  that contains all of the pacing parameters, systematically
 *                  parses through that data to separate out the parameters 
 *                  correctly, and sets the right variables in the pacing 
 *                  subroutines with the data parsed here
* 
* @param			none currently
*
* @result			{unclear}	this depends on how the pacing subfunctions work:
 *                              this can return an array with the params organized
 *                              in that array, or it can just go ahead and set
 *                              the params themselves if they are global, a pointer
 *                              to the first param, or a whole lot of individual
 *                              variables that each correspond to a param.
*
* @note    			
*/
/*******************************************************************/
void setPacingParam(void){
    
}

/********************************************************************
* Function:         setADASregister
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Serial/ADAS
*
* @brief    		This function parses through something received from the photon
 *                  much like setPacingParam above, but immediately takes the 
 *                  resulting parameters and moves them into the appropriate
 *                  ADAS register
* 
* @param			none currently
*
* @result			{unclear}	if we pass things directly into the ADAS registers
 *                              there will be no output.  alternatively, any of 
 *                              the options from setPacingParam are in play
*
* @note    			
*/
/*******************************************************************/
void setADASregister(void){
    
}

/********************************************************************
* Function:         setDt
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Serial/ADAS
*
* @brief    		This function receives an amount of time in ms (or s, doesn't
 *                  matter just needs to be decided) from the user, and converts
 *                  that into an integer that corresponds to the ammount of packets
 *                  we can transmit in that time - each packet takes 32 microseconds
 *                  so in short - how many times does 32 us go into the integer 
 *                  time we receive from the photon?  output that number rounded down
* 
* @param			none currently
*
* @result			{int}	Int representing amount of packets, to be inputed in 
 *                          acquireData
*
* @note    			
*/
/*******************************************************************/
unsigned char setDt(void){
    
}

/********************************************************************
* Function:         startPacing
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Pacing
*
* @brief    		Assuming all parameters are set (maybe this checks? for a 
 *                  more advanced implementation) this should do whatever it takes
 *                  to start pacing
* 
* @param			none
*
* @result			{none}	could potentially be a bool that tells you whether
 *                          we successfully started pacing, but I think error checking 
 *                          should be ignored for now.
*
* @note    			
*/
/*******************************************************************/
void startPacing(void){
    
}

/********************************************************************
* Function:         acquireData
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Serial/ADAS
*
* @brief    		This function is I believe already written - we just need to 
 *                  adapt it given how we receive info from user if that becomes
 *                  an issue (hopefully it won't).  It takes an integer input that
 *                  tells you how many buffers it will send out - that number is 
 *                  decided using setDt().
* 
* @param			UINT8_T     The output of setDt().
*
* @result			{none}	could always be a confirmation boolean if we wanted
*
* @note    			
*/
/*******************************************************************/
void acquireData(unsigned int nTotalBuffersOfData){
    unsigned char acquireState = 0;
    int nBuffersOfData = 0;
    unsigned char radioCnt, FillingCounter;
    unsigned char readCmd[4] = {0, 0, 0, 0};
    
    while (acquireState <= 12){
        switch (acquireState){
            case 0:
                // Init buffer 0
                FillingBuffPnt = Buffer0;       // set the pointer
                FillingCounter = 0;                 // Init Counter
                acquireState = 1;
                readCmd[0] = ADAS1000_FRAMES;	// Register address.
                SPI_Write(readCmd, 4);
                break;
            case 1:                              // Fill buf 0, no radio xmit
                while (ADAS_DATA_NOT_READY);                                // wait for data from ADAS
                readFormatStoreSample();
                if (++FillingCounter >= 16) {
                    acquireState = 2; 
                    if (++nBuffersOfData >= nTotalBuffersOfData) {
                        ADAS1000_GetRegisterValue(ADAS1000_FRMCTL, readCmd);    // stop ADAS
                        acquireState = 8;         // case of only one buffer    
                    }
                }
                FillingBuffPnt++;
                break;
            case 2:                                                     // Init Fill buf 1, empty buf 0;
                FillingBuffPnt = Buffer1;       // set the pointer
                FillingCounter = 0;                 // Init Counter
                radiodataptr = Buffer0;
                radioCnt = 0;
                acquireState = 3;
                SERSendStr("radio tx ");
                break;
            case 3:                                                     // fill buf 1, empty 0                       
                if (ADAS_DATA_NOT_READY){           // When no ADAS data available 
                    if (moveRadioSample()) {                //  4 spots available? store, else not
                        if (++radioCnt >= 16) {             //radio buff sample counter
                            SERSendStr("\r\n"); //append char return line feed
                            acquireState = 4;       
                            break;
                        }
                    }
                    else break;                             // not enough room yet, go around again
                }
                else {                                            // if there is ADAS data ready
                    readFormatStoreSample();                    
                    ++FillingCounter;
                    // don't check filling counter here because filling buffer should not be full before radio is done
                }
                break;

            case 4:                                              //finish Fill buf 1, no radio xmit
                while (ADAS_DATA_NOT_READY);                                // wait for data from ADAS
                readFormatStoreSample();
                if (++FillingCounter >= 16) {                           // filling buffer full?
                    acquireState = 5;                                   // swap
                    if (++nBuffersOfData >= nTotalBuffersOfData) {
                        ADAS1000_GetRegisterValue(ADAS1000_FRMCTL, readCmd);    // stop ADAS
                        acquireState = 10;         // go to ending state
                    }   
                    break;
                }
                break;
            case 5:
                FillingBuffPnt = Buffer0;       // set the pointer
                FillingCounter = 0;                 // Init Counter
                radiodataptr = Buffer1;
                radioCnt = 0;
                acquireState = 6;
                SERSendStr("radio tx ");
                break;
            case 6:                                                     // fill buf 0, empty 1                       
                if (ADAS_DATA_NOT_READY){           // When no ADAS data available 
                    if (moveRadioSample()) {                //  4 spots available? store, else not
                        if (++radioCnt >= 16) {             //radio buff sample counter 
                            SERSendStr("\r\n"); //append char return line feed
                            acquireState = 7;       
                            break;
                        }
                    }
                    else break;                             // not enough room yet, go around again
                }
                else {                                            // if there is ADAS data ready
                    readFormatStoreSample();                    
                    ++FillingCounter;
                    // don't check filling counter here because filling buffer should not be full before radio is done
                }
                break;

            case 7:                                              //finish Fill buf 0, no radio xmit
                while (ADAS_DATA_NOT_READY);                                // wait for data from ADAS
                readFormatStoreSample();
                if (++FillingCounter >= 16) {                           // filling buffer full?
                    acquireState = 2;                                   // swap
                    if (++nBuffersOfData >= nTotalBuffersOfData) {
                        ADAS1000_GetRegisterValue(ADAS1000_FRMCTL, readCmd);    // stop ADAS
                        acquireState = 8;         // go to ending state
                    }   
                    break;
                }
                break;
            case 8:                                         // transmit only from 0, no data colloect
                radiodataptr = Buffer0;
                radioCnt = 0;
                SERSendStr("radio tx ");
                acquireState = 9;
            case 9:
                if (moveRadioSample()) {                //  4 spots available? store else not
                    if (++radioCnt >= 16) {             //radio buff sample counter 
                        acquireState = 12;       
                        break;
                    }
                }
                break;
            case 10:                                         // transmit only from 1, no data colloect
                radiodataptr = Buffer1;
                radioCnt = 0;
                SERSendStr("radio tx ");
                acquireState = 11;
            case 11:
                if (moveRadioSample()) {                //  4 spots available? store else not
                    if (++radioCnt >= 16) {             //radio buff sample counter 
                        acquireState = 12;
                        break;
                    }
                }
                break;
            case 12:
                SERSendStr("\r\n");                     //append char return line feed
                return;
        }
    }
}

/********************************************************************
* Function:         stopPacing
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Pacing
*
* @brief    		Upon receiving this command, the pacing of the heart should
 *                  be stopped.  Nothing fancy here.
* 
* @param			none
*
* @result			{none}	confirmation boolean if desired, as always likely
 *                          more headache than its worth right now
*
* @note    			
*/
/*******************************************************************/
void stopPacing(void){
    
}

/********************************************************************
* Function:         resetParams
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		all
*
* @brief    		This function can reset all of the parameters that the user
 *                  can set.  it has no explicit use, as parameters can always 
 *                  just be overwritten without ever being reset, but it could 
 *                  prove sneaky useful if we want to write it
* 
* @param			none - though this could be modified to take in an argument
 *                         and just reset that argument.
*
* @result			{none}	
*
* @note    			
*/
/*******************************************************************/
void resetParams(void){
    
}

/********************************************************************
* Function:         parseSerial
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Serial
*
* @brief    		This function will parse the received chars from uart and 
 *                  put them in a usable form, like a char array, that can be 
 *                  attacked later by all these other subroutines.  this will be
 *                  useful in any implementation - either each subroutine will 
 *                  start with it, or it will be the first thing we do (if command
 *                  and then data for that command end up being included in the 
 *                  same serial transmission as opposed to two separate ones)
* 
* @param			none 
*
* @result			{char array[32]}  can increase size if need be, but it shouldnt
 *                                    be needed.  
*
* @note    			
*/
/*******************************************************************/
char* parseSerial(void){
    
}
