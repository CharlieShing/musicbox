#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"
#include "status.h"

int tone_length;
int tone;

// Index for button tones will be stored in these variables.
int btn1 = 54;
int btn2 = 49;
int btn3 = 48;
int btn4 = 47;
int btn5 = 42;
int btn6 = 44;
int btn7 = 46;

int main(void){
    setup();	
	tone_length = 5;
    while(1){
    	update_status(); 
		if (sw == 0) {
	        if (btns & 0x1) {
				tone = tone_frq[btn1];
				play_tone(tone, tone_length);
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
			}
		} else if (sw == 0x1) {
			modify_pitch(1);
		} else if (sw == 0x3) {
			modify_pitch(-1);
		} else if (sw == 0xf) {
			if (btns & 0x1) {
				play_noize();
			} else if (btns & 0x2) {
				//play_melody();
			}
		}
        // Clear tones etc.
		PORTECLR = 0xff;
    }
	return 0;
}

int modify_pitch(int change_pitch) {
	if (btns & 0x1) {
		btn1 += change_pitch;
		tone = tone_frq[btn1];
		play_tone(tone, tone_length);		
	} if (btns & 0x2) {
		btn2 += change_pitch;		
		tone = tone_frq[btn2];
		play_tone(tone, tone_length);		
	} if (btns & 0x4) {
		btn3 += change_pitch;	
		tone = tone_frq[btn3];
		play_tone(tone, tone_length);			
	} if (btns & 0x8) {
		btn4 += change_pitch;	
		tone = tone_frq[btn4];
		play_tone(tone, tone_length);			
	} if (btns & 0x10) {
		btn5 += change_pitch;
		tone = tone_frq[btn5];
		play_tone(tone, tone_length);				
	} if (btns & 0x20) {
		btn6 += change_pitch;
		tone = tone_frq[btn6];
		play_tone(tone, tone_length);				
	} if (btns & 0x40) {
		btn7 += change_pitch;
		tone = tone_frq[btn7];
		play_tone(tone, tone_length);		
	}	
	return 0;
}













