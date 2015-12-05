//
//  input_status.c
//  
//
//  Created by Christoffer Alenskog Berg on 05/12/15.
//
//

#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"

// Help functions
int getbtns(void) {
    
    unsigned int btn1 = PORTF;
    btn1 >>= 1;
    btn1 &= 0x1;
    
    unsigned int btnrest = PORTD;
    btnrest >>= 4;
    btnrest &= 0xe;
    return btnrest + btn1;
}

int getsw(void) {
    
    unsigned int input = PORTD;
    input >>= 8;
    input = input & 0xf;
}