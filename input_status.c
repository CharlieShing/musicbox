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
    btnrest >>= 5;
    btnrest &= 0x7;
    unsigned int btn_status = btn1 | btnrest;
    return btn_status;
}

int getextbtns(void) {
    unsigned int btns = PORTB;
    unsigned int btn1, btn2, btn3, btn4;
    
    btn1 = btns;
    btn1 >>= 2;
    btn1 &= 0x1;
    btn2 = btns;
    btn2 >>= 4;
    btn2 &= 0x1;
    btn3 = btns;
    btn3 >>= 8;
    btn3 &= 0x1;
    btn4 = btns;
    btn4 >>= 10;
    btn4 &= 0x1;

    return btn1 + btn2 + btn3 + btn4;
}

int getsw(void) {
    
    unsigned int sw = PORTD;
    sw >>= 8;
    sw = sw & 0xf;
    return sw;
}