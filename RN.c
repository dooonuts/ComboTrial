#include "Lcd.h"
#include "General.h"
#include "Serial.h"
#include "RN.h"
#include <stdio.h>
#include <string.h>

unsigned char OKResponse;
unsigned char done;
unsigned char Uinputstr[24];   //a place to store all incoming chars from uart


void CheckResponse()
{
    //define needed constants
    unsigned char keepgoing;
    char Uinput;
    unsigned char count = 0; //to iterate through inputstr  pdw 11/21

    OKResponse = 0; //set this so that we can cause the program to wait until this is 1;
    keepgoing = 1;
    LCDGoto(0,0);
    LCDWriteStr("INPUT:"); //** changed from "Voltage:"
    LCDGoto(0,1); //Line 2
    //loop to accomplish goal
    while(keepgoing)
    {
        if(SERRxDatAvail())
        {
            Uinput=SERRxGet();
            Uinputstr[count] = Uinput; //save input to our array
            count++; //iterate count to move through the array
            if (Uinput == '\n')
            {
                Uinputstr[count]=NULL; 
                LCDDispStr(Uinputstr);
                if(Uinputstr[0]=='o' && Uinputstr[1]=='k')
                {
                    OKResponse = 1;  //allow init to continue
                }
                keepgoing=0;
                done=1;
            }
        }
    }
    LCDGoto(0,0);
}

void RNInit()
{
    int i;
    int checked = 0;
    done=0;
    for(i=0;i<9;i++)
    {
        if(i==0)
        {
            checked = SERSendStr("U\r\n");
            while(checked==1 && done==0)CheckResponse();
            checked = 0;
            done = 0;
        }
        else if(i==1)
        {
            checked = SERSendStr("mac pause\r\n");
            while(checked==1 && done==0)CheckResponse();
            checked = 0;
            done = 0;
        }
        else if(i==2)
        {
            checked = SERSendStr("radio set mod fsk\r\n");
            while(checked==1 && done==0)CheckResponse();
            checked = 0;
            done = 0;
        }
        else if(i==3)
        {
            checked = SERSendStr("radio set freq 434000000\r\n");
            while(checked==1 && done==0)CheckResponse();
            checked = 0;
            done = 0;
        }
        else if(i==4)
        {
            checked = SERSendStr("radio set bitrate 250000\r\n");
            while(checked==1 && done==0)CheckResponse();
            checked = 0;
            done = 0;
        }
        else if(i==5)
        {
            checked = SERSendStr("radio set prlen 48\r\n");
            while(checked==1 && done==0)CheckResponse();
            checked = 0;
            done = 0;
        }
        else if(i==6)
        {
            checked = SERSendStr("radio set afcbw 166.7\r\n");
            while(checked==1 && done==0)CheckResponse();
            checked = 0;
            done = 0;
        }
        else if(i==7)
        {
            checked = SERSendStr("radio set rxbw 100\r\n");
            while(checked==1 && done==0)CheckResponse();
            checked = 0;
            done = 0;
        }
        else
        {
            checked = SERSendStr("radio set fdev 100000\r\n");
            while(checked==1 && done==0)CheckResponse();
            checked = 0;
            done = 0;
        }
    }
}

UINT8_T RNTrans(/* need to determine whats going into a packet to input here */ char packet[32])
{
    //define needed vars
    int i;
    char point; //doesn't matter what its set to, just cannot be null
    OKResponse = 0;
    //now we can send things out
    LATBbits.LATB0 = ~LATBbits.LATB0; //~the general io pin of choice ~LATBbits.RB1; 
    SERSendStr("radio tx ");
    SERSendData(packet);
    SERSendStr("\r\n");  //need to append \r\n to our commands
    // now we need to wait for both of its responses before moving on
    while(done == 0)
    {
        CheckResponse();
    }
    //having gotten the ok for here, we need to receive radio tx ok
    //either going to get radio_err or radio_tx_ok.  have to differentiate between the two
    CheckResponse();  //this gets inputstr how we might want it
    //turn inputstr into a string
//    i=1;
//    point = Uinputstr[0];
//    while(point!=NULL)
//    {
//        strcat(string2,point);
//        point = Uinputstr[i];  //since we add a null character to this after \r\n, point should eventually be null, breaking the loop;
//        i++;
//    }
//    if (strcmp(string2,"radio_err")==0)//indicates an error in transmission (notice the space to incorporate the null)
//    {
//        return(0);  //there was an error      
//    }
//    else if (strcmp(string2,"radio_tx_ok"==0))
//    {
//        return(1);  //success
//    }
}

void InitBreak(void)
{
    //see rn command guide page 15 for rationale
    //make the UART_RX pin low for a decent period of time
    TRISCbits.RC6=0;
    LATCbits.LATC6=0;
    Delay10KTCYx(8000); //Wait 80*10k*instruction cycle time = 80*10k*1/8MHz = 100 ms
    //reset it to high so stuff is enabled again
    LATCbits.LATC6=1;
    TRISCbits.RC6=1;
}