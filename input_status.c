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
int getintbtns(void) {
    
    unsigned int btn1 = PORTF;
    btn1 >>= 1;
    btn1 &= 0x1;
    
    unsigned int btnrest = PORTD;
    btnrest >>= 4;
    btnrest &= 0xe;
    unsigned int btn_status = btn1 | btnrest;
    return btn_status;
}

int getextbtns(void) {
    unsigned int _portd = PORTD;
    unsigned int btn1, btn2, btn3;
    
    btn1 = _portd;
    btn1 >>= 1;
    btn1 &= 0x1;
    btn2 = _portd;
    btn2 >>= 1;
    btn2 &= 0x2;
    btn3 = _portd;
    btn3 >>= 1;
    btn3 &= 0x4;

    return btn3 + btn2 + btn1;
}

int getsw(void) {
    
    unsigned int sw = PORTD;
    sw >>= 8;
    sw = sw & 0xf;
    return sw;
}