/*
 * File:   main.c
 * Author: georg
 *
 * Created on May 26, 2018, 9:19 AM
 */

#define _XTAL_FREQ 32000000 
#include <xc.h>
#include "bit_config.h"
#include "config.h"

void main(void) {

    initial_config();

    
while(1)
{
    LATC=0X00;
    LATA=0X00;
    LATB=0X00;
    __delay_ms(1);
    LATC=0XFF;
    LATB=0XFF;
    LATA=0XFF;
    __delay_ms(1);


}
}
