/* 
 * File:   ADASfxns.h
 * Author: BME464
 *
 * Created on November 16, 2017, 1:37 PM
 */

#ifndef ADASFXNS_H
#define	ADASFXNS_H
// #define _XTAL_FREQ 16000000

#ifdef	__cplusplus
extern "C" {
#endif
    void LCDWriteADAS();
    void ADAS_TEST_TONE();
    void ADAS_DATA_INIT();
    void ProcessSample();
    void SwapBuffers();
 //   void main();
    void InitLogicAnalyzerOut();
    void startRadioTransmission();
    void readFormatStoreSample();
    unsigned char moveRadioSample ();
    void AcquireECGData (unsigned int);


#ifdef	__cplusplus
}
#endif

#endif	/* ADASFXNS_H */

