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
    
    // Initialize LED1 to output
    PORTECLR = 0x2;
    TRISE &= ~0x2;
    
    // Initialize BTNs to input external BTNs 1-4, internal 5-8
    PORTFCLR = 0x2;
    PORTDCLR = 0xef;
    TRISF |= 0x2;
    TRISD |= 0xef;
    
    // Initialize switches
    PORTDCLR = 0xf00;
    TRISDSET = 0xf00;
    
    // Initialize PIN3 as output for speaker PWM signal
    PORTDCLR = 0x1;
    TRISD &= ~0x1;
    
    // Initialize TMR2 as timer for creating audio through speaker
    T2CON &= ~0xffff;
    T2CONSET = 0x0040;
    
}