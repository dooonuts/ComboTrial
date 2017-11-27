/* 
 * File:   funcdec.h
 * Author: daniel
 *
 * Created on October 16, 2017, 4:23 PM
 */

#ifndef FUNCDEC_H
#define	FUNCDEC_H
#define _XTAL_FREQ 8000000

#ifdef	__cplusplus
extern "C" {
#endif
    //int main(int, char**);
    void ProcessSample();
    void main();
    void outputToLogicAnalyzer();

#ifdef	__cplusplus
}
#endif

#endif	/* FUNCDEC_H */

