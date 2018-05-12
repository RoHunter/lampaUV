/*
 * File:   main.c
 * Author: Silviu
 *
 * Created on May 12, 2018, 8:24 PM
 */

#define _XTAL_FREQ  32000000
#include <xc.h>
#include "config.h"
#include "hd44780.h"


void main(void) {
    config();
    init_hd44780();
    //write_char_hd44780('H');
    write_char_hd44780('E');
    
    write_string_hd44780("Hello World",2);
    while(1)
    {
     
    
    }
}
