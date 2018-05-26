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
#define Clock  T0CON0bits.T0EN


char buffer_sec[3];//variabila buffer blobal
char buffer_min[3];//variabila buffer blobal
int flag=0;
int min,sec=0;

void interrupt timer();

void main(void) {

    sec=0;
    min=0;
    int counter=0;
    
    initial_config();//configure ports
    init_int();
    
    Lcd_Init();//init display
    Lcd_Clear();
    
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String("Idle");
//Switch=1; 
  
    LATCbits.LATC1=1;
    
while(1)
{
    if(min>=0)
    {
        sprintf(buffer_sec, "%2d", sec);//convert to ascii string
        sprintf(buffer_min, "%2d", min);

        Lcd_Set_Cursor(1,1);//goto to line 1 row 1
        Lcd_Write_String("  ");
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String(buffer_min);

        Lcd_Write_String(":");//separator

        Lcd_Set_Cursor(1,4);
        Lcd_Write_String("  ");
        Lcd_Set_Cursor(1,4);
        Lcd_Write_String(buffer_sec);
        }
    
 
    __delay_ms(100);
    
    
    
    if(Stop==1)
    {
        Clock=0;//tmr0 off
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("        ");
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("Stopped");
        __delay_ms(500);
        Switch=1;
    }
    
    if(Start==1)
    {
        Clock=1;//tmr0 on
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("        ");
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("Exposing");
        Switch=0;
        __delay_ms(500);
    
    }
    
    if(Plus==1)
    {
        min++;
        __delay_ms(100);
    }
    
    if(Minus==1)
    {
        min--;
        if(min<0)
        {
            min=0;
            sec=0;
        }    
        __delay_ms(100);
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
    sec--;
    
    if(sec<0)
    {
        sec=59;
        min--;
        if(min<0)
        {
        Clock=0;//tmr0 off
        sec=0;
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("        ");
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("Stopped");
        __delay_ms(500);
        Switch=1;
        }
    }  
    
    TMR0L=0X00;
    if(min>=0)
        T0CON0bits.T0EN=1;//tmr0 on
    
}