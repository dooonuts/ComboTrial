/***************************************************************************//**
 *   @file   Communication.h
 *   @brief  Header file of Communication Driver.
 *   @author DBogdan (dragos.bogdan@analog.com)
********************************************************************************
 * Copyright 2012(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
********************************************************************************
 *   SVN Revision: 570
*******************************************************************************/
#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

/******************************************************************************/
/* Include Files                                                              */
/******************************************************************************/
#include <p18f46k22.h>                                                   

/******************************************************************************/
/* Define variables                                                           */
/******************************************************************************/

/* Define the SPI bits in the SSP1 Status Register */
#define SPI_CLOCK_EDGE      SSP1STATbits.CKE // SPI Clock Edge Select bit
#define SPI_SAMPLING        SSP1STATbits.SMP // SPI Data Input Sample bit
#define SPI_DATA_CHECK      SSP1STATbits.BF 

/* Define the SPI bits in SSP1 Control Register 1 */
#define SPI_ENABLE          SSP1CON1bits.SSPEN
#define SPI_CLOCK_POLARITY  SSP1CON1bits.CKP
#define SPI_FOSC            SSP1CON1bits.SSPM // set SCLK to run FOSC/4 for SPI 
#define SPI_FOSCbit3        SSP1CON1bits.SSPM3
#define SPI_FOSCbit2        SSP1CON1bits.SSPM2
#define SPI_FOSCbit1        SSP1CON1bits.SSPM1
#define SPI_FOSCbit0        SSP1CON1bits.SSPM0 

/* Define the SPI bits for the data buffer */
#define SPI_DATA_BUFFER     SSP1BUF
//#define SPI_INTERRUPT       PIR1bits.SSP1IF

/* Define the pins of the SPI */
#define SPI_CLOCK_DIR       TRISCbits.RC3       // SCLK on RC3 direction

#define SPI_DATA_IN         TRISCbits.RC4       // ADAS SDO to RC4 direction
#define SPI_DATA_IN_ANL     ANSELCbits.ANSC4    // SPI_IN pin analog select bit

#define SPI_DATA_OUT        TRISCbits.RC5       // ADAS SDI to RC5 direction

#define SPI_DATA_READY      TRISAbits.RA3       // DRDY pin direction
#define SPI_DATA_READY_ANL  ANSELAbits.ANSA3    // DRDY pin analog select bit
#define ADAS_DATA_NOT_READY          PORTAbits.RA3       // DRDY pin (input)

#define SPI_RESET           TRISAbits.RA2       // RESET pin direction
#define RESET               LATAbits.LATA2      // RESET pin (output)

#define SPI_SLAVE_SELECT    TRISAbits.RA0       // ADAS CS to RA0 direction
#define SLAVE_SELECT        LATAbits.LATA0      // CS pin (output) 

/******************************************************************************/
/* Functions Prototypes                                                       */
/******************************************************************************/

/* Initializes the SPI communication peripheral. */
unsigned char SPI_Init(unsigned char lsbFirst,
                       unsigned long clockFreq,
                       unsigned char clockPol,
                       unsigned char clockPha);

/* Writes data to SPI. */
unsigned char SPI_Write(unsigned char* data,
                        unsigned char bytesNumber);

/* Reads data from SPI. */
unsigned char SPI_Read(unsigned char* data,
                       unsigned char bytesNumber);

/* Reads 32 bits of data from SPI */
unsigned char SPI_Read_32bit(unsigned char* data);

#endif	// _COMMUNICATION_H_
