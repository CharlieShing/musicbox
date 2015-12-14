#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"
#include "status.h"

int tone_length;
int tone;

// Index for button tones will be stored in these variables.
int btn1 = 8;
int btn2 = 10;
int btn3 = 12;
int btn4 = 14;
int btn5 = 42;
int btn6 = 44;
int btn7 = 46;

int main(void){
    setup();	
	tone_length = 10;
    while(1){
        update_status(); 
		if (0) {
			if (btns & 1) {
				play_song();
			}		
		} else if (0) {
			if (btns & 1)
				if (btn1 < 61) btn1 = btn1 - 1;
			else if (btns & 0x2)
				if (btn2 < 61) btn2 = btn2 - 1;
			else if (btns & 0x4)
				if (btn3 < 61) btn3 = btn3 - 1;
			else if (btns & 0x8)
				if (btn4 < 61) btn4 = btn4 - 1;
			else if (btns & 0x10)
				if (btn5 < 61) btn5 = btn5 - 1;
			else if (btns & 0x20)
				if (btn6 < 61) btn6 = btn6 - 1;
			else if (btns & 0x40)
				if (btn7 < 61) btn7 = btn7 - 1;
		} else if (0) {
			if (btns & 1)
				if (btn1 > 0) btn1 = btn1 + 1;
			if (btns & 0x2)
				if (btn2 > 0) btn2 = btn2 + 1;
			if (btns & 0x4)
				if (btn3 > 0) btn3 = btn3 + 1;
			if (btns & 0x8)
				if (btn4 > 0) btn4 = btn4 + 1;
			if (btns & 0x10)
				if (btn5 > 0) btn5 = btn5 + 1;
			if (btns & 0x20)
				if (btn6 > 0) btn6 = btn6 + 1;
			if (btns & 0x40)
				if (btn7 > 0) btn7 = btn7 + 1;
		} if (1) {
	        if (btns & 0x1) {
				if (sw & 0x1) {
					play_tone(tone, tone_length);
				} else if (sw & 0x2) {
					play_tone(C6, tone_length);
				} else if (sw & 0x4) {
					play_tone(D6, tone_length);
				} else if (sw & 0x8) {
					play_tone(E6, tone_length);
				} else if (sw & 0x10) {
					play_tone(F6, tone_length);
				} else if (sw & 0x20) {
					play_tone(G6, tone_length);
				} else if (sw & 0x40) {
					play_tone(A6, tone_length);
				}
	        } if (btns & 0x2) {
				tone = tone_frq[btn2];
				play_tone(tone, tone_length);
	        } if (btns & 0x4) {
				tone = tone_frq[btn3];
				play_tone(tone, tone_length);
	        } if (btns & 0x8) {
				tone = tone_frq[btn4];
				play_tone(tone, tone_length);
	        } if (btns & 0x10) {
				tone = tone_frq[btn5];
				play_tone(tone, tone_length);
	        } if (btns & 0x20) {
				tone = tone_frq[btn6];
				play_tone(tone, tone_length);
	        } if (btns & 0x40) {
				tone = tone_frq[btn7];
				play_tone(tone, tone_length);      
			}else {
	            // Clear tones etc.
				PORTECLR = 0xff;
			}
		}
    }
}













