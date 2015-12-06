//
//  main_functions.c
//  
//
//  Created by Christoffer Alenskog Berg on 05/12/15.
//
//


#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"

volatile unsigned int* _T4CON2 = (unsigned int*) 0xbf800c00;
volatile unsigned int* _PR4 = (unsigned int*) 0xbf800c20;

int setup(void) {
    
    // Initialize internal buttons RF1, RD5-7:
    //BTN1
    TRISFSET = 0x2;
    //BTN2-4
    TRISDSET = 0xe0;
    
    // Initialize switches RD8-11:
    TRISDSET = 0xf00;
    
    // Initialize external buttons:
    //BTN1 at RD1, pin 5
    TRISDSET = 0x2;
    //BTN2 at RD2, pin 6
    TRISDSET = 0x4;
    //BTN3 at RD3, pin 9
    TRISDSET = 0x8;
    
    // Initialize speaker as output RD0:
    TRISD &= ~0x1;
    
    // Initialize TMR2 as timer for creating audio through speaker
    T2CON &= ~0xffff;
    T2CONSET = 0x0000;
    PR2 = 0x1F4;
    
}