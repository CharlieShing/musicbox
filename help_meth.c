#include <pic32mx.h>
#include "musicbox.h"

int getbtns(void) {
	
	unsigned int btn1 = PORTF;
	btn1 &= 0x2;
	btn1 >>= 1;
	
	unsigned int btns4to2 = PORTD;
	btns4to2 >>= 4;
	btns4to2 &= 0xe;
	
	unsigned int input = btns4to2 | btn1;
	
	return input;
}

int getsw(void) {
	unsigned int input = PORTD;
	input >>= 8;
	input = input & 0xf;
}