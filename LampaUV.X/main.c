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

#define Plus   RB0
#define Minus  RB1
#define Start  RB2
#define Stop   RB3
#define Switch LATCbits.LATC1

char buffer[5];//variabila buffer blobal
int flag=0;

void interrupt timer();

void main(void) {

    
    int counter=0;
    
    initial_config();//configure ports
    init_int();
    
    Lcd_Init();//init display
    Lcd_Clear();
    
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Hello World");
//Switch=1; 
  
    LATCbits.LATC1=1;
    
while(1)
{

    sprintf(buffer, "%d", counter);
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("           ");
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(buffer);
    __delay_ms(1000);
    counter++;
    
    
    
    if(Stop==1)
    {
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("        ");
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("Stopped");
        __delay_ms(500);
        Switch=1;
    }
    
    if(Start==1)
    {
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("        ");
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("Exposing");
        Switch=0;
        __delay_ms(500);
    
    }

}
}


void interrupt timer()
{
    PIR0bits.TMR0IF=0;
    T0CON0bits.T0EN=0;//tmr0 on
    
    switch (flag)
    {
        case 0:
            LATAbits.LATA5=1;
            flag=1;
            break;
        case 1:    
            LATAbits.LATA5=0;
            flag=0;
            break;
    }
    
    TMR0L=0X00;
    T0CON0bits.T0EN=1;//tmr0 on
    
}