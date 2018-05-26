/*
 * File:   config.c
 * Author: georg
 *
 * Created on May 26, 2018, 9:40 AM
 */


#include <xc.h>
#include "config.h"


void init_int(void)
{


   //TMR0
    T0CON0=0b00000000;
    T0CON1=0b01001111;
    //T0CON1=0b01000000;
    T0CON0bits.T0EN=0;
    TMR0L=0X00;
    TMR0H=0Xf3;/////////rollover when TMR0L hits this value
    
    INTCONbits.GIE=1;//general interupts
    PIE0bits.TMR0IE=1;//tmr0 interupt
    
    T0CON0bits.T0EN=0;//tmr0 off
}

void initial_config()
{
    TRISA=0X00;
    TRISB=0X00;
    TRISC=0X00;
    
    PORTA=0X00;
    PORTB=0X00;
    PORTC=0X00;
     
    LATA=0X00;
    LATB=0X00;
    LATC=0X00;
    
    ANSELA=0X00;
    ANSELB=0X00;
    ANSELC=0X00;
    
    //LATA=0XFF;
    
    //LATAbits.LATA5=1;
    TRISBbits.TRISB0=1;
    TRISBbits.TRISB1=1;
    TRISBbits.TRISB2=1;
    TRISBbits.TRISB3=1;
}
