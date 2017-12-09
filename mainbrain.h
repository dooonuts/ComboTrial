/* 
 * File:   mainbrain.h
 * Author: BME464
 *
 * Created on November 27, 2017, 5:11 PM
 */

#ifndef MAINBRAIN_H
#define	MAINBRAIN_H

#include <p18cxxx.h>
#include <GenericTypeDefs.h>

#include "General.h"

UINT8_T recCommand(void);
void wakeADAS(void);
void setPacingParam(long T, long P);
void setADASregister(void);
unsigned int setDt(void);
void startPacing(void);
void acquireData(unsigned int nTotalBuffersOfData);
void stopPacing(void);
void resetParams(void);
void parseSerial(void);  //this acts on a global var now
void parseVars(void);  //acts on the filled global char array from parseSErial
void initRx(void);



#endif

