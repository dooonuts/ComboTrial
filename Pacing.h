/* 
 * File:   Pacing.h
 * Author: BME464
 *
 * Created on November 29, 2017, 3:52 PM
 */

#ifndef PACING_H
#define	PACING_H

#define PACING_OUTPUT  LATAbits.LATA5
void setPacingParam();
void startPacing();
void endPacing();

#endif	/* PACING_H */

