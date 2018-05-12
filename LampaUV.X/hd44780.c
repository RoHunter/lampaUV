/*
 * File:   h.c
 * Author: georg
 *
 * Created on April 30, 2018, 4:45 PM
 */



#define _XTAL_FREQ 64000000
#include <xc.h>
#include "hd44780.h"
#include <stdio.h>
#include <string.h>
#define data_port LATC
#define RS LATBbits.LATB0
#define RW LATBbits.LATB1
#define E LATBbits.LATB2

void init_hd44780()
{
    RS=0;
    RW=0;
    
    
    E=1;
    data_port=0b00000001;//clear display
    __delay_ms(10);
    E=0;
    
   
     
     E=1;
    data_port=0b00001110;//display on, cursor on
    __delay_ms(10);
     E=0;
   
    

}

void write_char_hd44780(char chr)
{
    RW=0;
    RS=1;
    E=1;
    data_port=chr;
    __delay_ms(10);
    RS=0;
    E=0;
    
   
}

void write_string_hd44780(char *string,unsigned rand)
{
    
    for(int i=0;i<strlen(string);i++)
    {
    RW=0;
    RS=1;
    E=1;
    data_port=string[i];
    __delay_ms(10);
    RS=0;
    E=0;
    
    }


}

void row_sel_hd44780(unsigned row)
{

    RS=0;
    RW=0;
    E=1;
    data_port=0xc0;//row 2
    __delay_ms(10);
    E=0;


}