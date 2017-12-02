#include <p18f46k22.h>
#include "Pacing.h"

//unsigned char FullIntH, FullIntL, ShortIntH, ShortIntL, PulseH, PulseL;
//unsigned int IntCounter;
//
//void setPacingParam(long T, long P) {
//    unsigned long PWn, IIn;
//    
//    IIn = (T-P)/2;
//    PWn = P/2;
//    unsigned int IntN = (int) IIn/50000;
//    
//    // calculate values to set capture compare registers
//    FullIntH = (char) (IntN & 0xFF);
//    FullIntL = (char) ((IntN >> 8) & 0xFF);
//    
//    unsigned int Remainder = (int) (IIn-((IntN-1)*50000))/2;
//    ShortIntH = (char) (Remainder & 0xFF);
//    ShortIntL = (char) ((Remainder >> 8) & 0xFF);
//    
//    PulseH = (char) (PWn & 0xFF);
//    PulseL = (char) ((PWn >> 8) & 0xFF);
//    
//    CCP1CON = 0b00001011;
//    T1GCON = 0b00000000;
//    T1CON = 0b00110011;
//}
//
//void startPacing(int FullIntH, int FullIntL, int IIn) {
//    CCPR1H = FullIntH;
//    CCPR1L = FullIntL;
//    
//    IntCounter = IIn;
//    
//    TRISAbits.RA5 = 0;
//    PIE1bits.CCP1IE = 1;        
//}
//
//void endPacing() {
//    PIE1bits.CCP1IE = 0;
//}

