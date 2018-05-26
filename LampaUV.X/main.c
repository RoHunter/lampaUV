/*
 * File:   main.c
 * Author: georg
 *
 * Created on May 26, 2018, 9:19 AM
 */

#define _XTAL_FREQ 32000000 
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "bit_config.h"
#include "config.h"
#include "lcd.h"

void main(void) {

    initial_config();//configure ports
    
    Lcd_Init();//init display
    Lcd_Clear();
    
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Hello World");

    
while(1)
{
   // LATC=0X00;
   // LATA=0X00;
   // LATB=0X00;
   // __delay_ms(1);
   // LATC=0XFF;
   // LATB=0XFF;
   // LATA=0XFF;
    __delay_ms(1);


}
}
