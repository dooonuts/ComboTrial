/***************************************************************************//**
 *   @file   Communication.c
 *   @brief  Implementation of Communication Driver.
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

/******************************************************************************/
/* Include Files                                                              */
/******************************************************************************/
#include "Communication.h"
#include <p18f46k22.h>
#include <delays.h>  

/***************************************************************************//**
 * @brief Initializes the SPI communication peripheral.
 *
 * @param lsbFirst - Transfer format (0 or 1).
 *                   Example: 0x0 - MSB first.
 *                            0x1 - LSB first.
 * @param clockFreq - SPI clock frequency (Hz).
 *                    Example: 1000 - SPI clock frequency is 1 kHz.
 * @param clockPol - SPI clock polarity (0 or 1).
 *                   Example: 0x0 - idle state for SPI clock is low.
 *	                          0x1 - idle state for SPI clock is high.
 * @param clockPha - SPI clock phase/edge (0 or 1).
 *                   Example: 0x0 - data is latched on the leading edge of SPI
 *                                  clock and data changes on trailing edge.
 *                            0x1 - data is latched on the trailing edge of SPI
 *                                  clock and data changes on the leading edge.
 *
 * @return 0 - Initialization failed, 1 - Initialization succeeded.
*******************************************************************************/
unsigned char SPI_Init(unsigned char lsbFirst,
                       unsigned long clockFreq,
                       unsigned char clockPol,
                       unsigned char clockPha)
{
    /* Re-initialize the SSP1 control register 1 and the status register */
    SSP1CON1 = 0x00; // SSP control register 1
    SSP1STAT = 0x00; // SSP status register
    
    /* SSP1 Status Register bits */
    
    //SPI_SAMPLING = 0; // Master mode sampling occurs at the middle of data output time
    SPI_SAMPLING = 1; // Master mode sampling occurs at the end of data output time (What we originally thought it was)
    
    SPI_CLOCK_EDGE = 0; // Transmit occurs on transition from active to Idle clock state (what we originally thought it was))
    //SPI_CLOCK_EDGE = 1; // Transmit occurs on transition from idle to active clock state 
    
    /* SSP1 Control Register 1 bits */
    
    // SPI_CLOCK_POLARITY = 0; // Idle state for clock is high
    SPI_CLOCK_POLARITY = 1; // Idle state for clock is high
    
    //SPI_FOSCbit3 = 0;
    //SPI_FOSCbit2 = 0;
    //SPI_FOSCbit1 = 0;
    //SPI_FOSCbit0 = 0;
    SPI_FOSC = 0000;    // set frequency of the shift clock
    SPI_ENABLE = 1;     // enable the SPI
    
    /* Properly configure the pins */
    
    SPI_CLOCK_DIR = 0;      // SCLK (shift clock) is output
    
    SPI_DATA_IN = 1;        // SPI_IN (SPI input) is input    
    SPI_DATA_IN_ANL = 0;    // clear analog select bit for SPI_IN 
    
    SPI_DATA_OUT = 0;       // SPI_OUT (SPI output) is output
    
    SPI_DATA_READY = 1;     // DRDY (data ready) is input
    SPI_DATA_READY_ANL = 0; // clear analog select bit for DRDY
    
    SPI_RESET = 0;          // RESET is output
    
    SPI_SLAVE_SELECT = 0;   // CS (chip/slave select) is output
    
    /* Set the CS (chip select) to HIGH as default state */
    /* CS is used to frame the data and must be included in the code.
     * When CS falls LOW, it begins the frame. When CS is brought HIGH,
     * the frame ends.
     */
    SLAVE_SELECT = 1;   // Chip Select goes HIGH
    RESET = 1;          // RESET is at HIGH
    
    /* Configure the interrupt bits for the SSP interrupt flag */
    //PIE1bits.SSP1IE = 1;
    //IPR1bits.SSP1IP = 1;
    
    return 1;
}

/***************************************************************************//**
 * @brief Writes data to SPI.
 *
 * @param data - data represents the write buffer.
 * @param bytesNumber - Number of bytes to write.
 *
 * @return Number of written bytes.
*******************************************************************************/
unsigned char SPI_Write(unsigned char* data,
						unsigned char bytesNumber)
{
    unsigned char i;
    
    /* To begin the frame, bring CS to LOW */
    SLAVE_SELECT = 0;
    
    for(i = 0; i < bytesNumber; i++){
        SPI_DATA_BUFFER = *data++;
        while(!SPI_DATA_CHECK);
    }
    
    /* To end the frame, bring CS back HIGH */
    SLAVE_SELECT = 1;

	return bytesNumber;
}

/***************************************************************************//**
 * @brief Reads data from SPI.
 *
 * @param data - Data represents the read buffer.
 * @param bytesNumber - Number of bytes to read.
 *
 * @return Number of read bytes.
*******************************************************************************/
unsigned char SPI_Read(unsigned char* data,
					   unsigned char bytesNumber)
{
    unsigned char i;
    
    /* To begin the frame, bring CS to LOW */
    SLAVE_SELECT = 0;
    
    for(i = 0; i < bytesNumber; i++){ 
        SPI_DATA_BUFFER = 0x00; // Write the buffer to shift bits in
        while(!SPI_DATA_CHECK); // When transmission has yet to be completed, stalls
        //while(!SPI_INTERRUPT);  // Wait for the interrupt flag to indicate the buffer is full
        *data++ = SPI_DATA_BUFFER; 
    }
    
    /* To end the frame, bring CS to HIGH*/
    SLAVE_SELECT = 1;
    
    return bytesNumber;
}

/***************************************************************************//**
 * @brief Reads 32 bits of data from SPI.
 *
 * @param data - Data represents the read buffer.
 * @param bytesNumber - Number of bytes to read.
 *
 * @return Number of read bytes.
*******************************************************************************/
unsigned char SPI_Read_32bit(unsigned char* data)
{
    SLAVE_SELECT = 0;
    
    /* Reads Byte 1 */
    SPI_DATA_BUFFER = 0x00;
    while(!SPI_DATA_CHECK); 
    data[0] = SPI_DATA_BUFFER; 
    
    /* Reads Byte 2 */
    SPI_DATA_BUFFER = 0x00;
    while(!SPI_DATA_CHECK); 
    data[1] = SPI_DATA_BUFFER; 
    
    /* Reads Byte 3 */
    SPI_DATA_BUFFER = 0x00;
    while(!SPI_DATA_CHECK); 
    data[2] = SPI_DATA_BUFFER; 
    
    /* Reads Byte 4 */
    SPI_DATA_BUFFER = 0x00;
    while(!SPI_DATA_CHECK); 
    data[3] = SPI_DATA_BUFFER; 
    
    SLAVE_SELECT = 1;
}