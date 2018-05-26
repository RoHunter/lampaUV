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

#define Plus  RB0
#define Minus RB1
#define Start RB2
#define Stop  RB3

void main(void) {

    initial_config();//configure ports
    
    Lcd_Init();//init display
    Lcd_Clear();
    
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Hello World");

    
while(1)
{

    if(Start==1)
    {
        Lcd_Clear();    
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("Start");
        __delay_ms(1000);
    }
    
    if(Stop==1)
    {
        Lcd_Clear();    
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("Stop");
        __delay_ms(1000);
    }
    
    if(Minus==1)
    {
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("Minus");
        __delay_ms(1000);
    }
    
    if(Plus==1)
    {
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("Plus");
        __delay_ms(1000);
    }
    
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Main");
    __delay_ms(1000);
}
}
