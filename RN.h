/* 
 * File:   RN.h
 * Author: Matt Levey
 * Initialization for RN specific subfunctions
 * Created on October 27, 2017, 3:47 PM
 */

#ifndef RN_H
#define	RN_H

#include "General.h"

void CheckResponse(void);   ///< check the response from the RN and display to LCD
void RNInit(void);
UINT8_T RNTrans(char packet[32]);
void InitBreak(void);
#endif	/* RN_H */

