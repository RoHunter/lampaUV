/*
 * File:   config.c
 * Author: georg
 *
 * Created on May 26, 2018, 9:40 AM
 */


#include <xc.h>

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
    
    
    TRISBbits.TRISB0=1;
    TRISBbits.TRISB1=1;
    TRISBbits.TRISB2=1;
    TRISBbits.TRISB3=1;
}
