#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"
#include "input_status.h"

struct Tone {
	int freq;
	int length;
};

int main(void){
    setup();
    while(1){
        update_status();        
        	//Button 1
        if (btn_int & 1) {
			play_tone(c6_whole);
			PORTESET = 0x80;
            //Button 2
        } else if (btn_int & 2) {
			PORTESET = 0x40;
			play_tone_simple(C6);
            //Button 3
        } else if (btn_int & 4) {
			//play_tone(tone_btn3);
            //Button 4
        } else if (btn_int & 8) {
			//play_tone(tone_btn4);
            //Button 5
        } else if (btn_ext & 1) {
			//play_tone(tone_btn5);
            //Button 6
        } else if (btn_ext & 2) {
			//play_tone(tone_btn6);
            //Button 7
        } else if (btn_ext & 4) {
			//play_tone(tone_btn7);         
        } else {
            // Clear tones etc.
			PORTECLR = 0xc0;
        }
    }    
}













