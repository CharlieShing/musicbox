#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "status.h"




// Status for buttons is stored int these variables
unsigned int btns;
unsigned int sw;

//Update status
int update_status() {
	getbtns();
    getsw();    
}

// Help functions
int getbtns() {

	unsigned btn1_board = PORTF;
	btn1_board >>= 1;
	btn1_board &= 0x1;

	unsigned int btn_rest_board = PORTD;
	btn_rest_board >>= 4;
	btn_rest_board &= 0xe;

    unsigned int btn_ext_1 = PORTD;
    btn_ext_1 <<= 3;
    btn_ext_1 &= 0x10;
    unsigned int btn_ext_2 = PORTD;
    btn_ext_2 <<= 3;
    btn_ext_2 &= 0x20;
    unsigned int btn_ext_3 = PORTD;
    btn_ext_3 <<= 3;
    btn_ext_3 &= 0x40;

	btns = btn1_board + btn_rest_board + btn_ext_1 + btn_ext_2 + btn_ext_3;
}

int getsw() {
    
    sw = PORTD;
    sw >>= 8;
    sw = sw & 0xf;
    
}
