//
//  main_functions.c
//  
//
//  Created by Christoffer Alenskog Berg on 05/12/15.
//
//


#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
int setup(void) {
    
    // Initialize Switches, Buttons and Speaker as Input and Output
    TRISFSET = 0x2;
    TRISD = 0xfe0;
    TRISBSET = 0x514;
    
    // Initialize TMR2 as timer for creating audio through speaker
    T2CON &= ~0xffff;
    T2CONSET = 0x0040;
    
}