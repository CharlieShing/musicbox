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
    TRISE &= ~0x2;
    PORTECLR = 0x2;
    
    // Initialize BTNs to input
    TRISF |= 0x2;
    TRISD |= 0xe0;
    
    // Initialize PIN3 as output for speaker PWM signal
    TRISD &= ~0x1;
    PORTDCLR = 0xffff;
    
    // Initialize TMR2 as timer for creating audio through speaker
    T2CON &= ~0xffff;
    T2CONSET = 0x0030;
    
}


int play_sound_pwm(int duty) {
    OC4RS = duty;
    T2CONSET = 0x8000;
    OC4CON |= 0x8006;
    int i;
    for (i = 0; i < 1000000; i++);
}