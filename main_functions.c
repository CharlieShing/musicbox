//
//  main_functions.c
//  
//
//  Created by Christoffer Alenskog Berg on 05/12/15.
//
//


#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"

struct Tone {
	int freq;
	int length;
};

int change_tone(struct Tone button){
/*
    if(sw_status == 1) {
        *button = c4_fourth;
    } else if(sw_status == 2) {
        *button = c4_whole;
    } else if(sw_status == 3) {
        *button = c3_fourth;
    } else if(sw_status == 4) {
        *button = c5_sixteenth;
    } else if(sw_status == 5) {
        *button = d5_sixteenth;
    } else if(sw_status == 6) {
        *button = e5_sixteenth;
    } else if(sw_status == 7) {
        *button = f5_sixteenth;
    } else if(sw_status == 8) {
        *button = c6_sixteenth;
    } else if(sw_status == 9) {
        *button = c5_fourth;
    } else if(sw_status == 10) {
        *button = d5_fourth;
    } else if(sw_status == 11) {
        *button = e5_fourth;
    } else if(sw_status == 12) {
        *button = f5_fourth;
    } else if(sw_status == 13) {
        *button = c6_fourth;
    } else if(sw_status == 14) {
        *button = c3_whole;
    } else if(sw_status == 15) {
        *button = c6_whole;
    }
*/
}
int play_tone(struct Tone t) {
	int start_wave, end_wave, reached_mid, mid_wave;
	int start_tone = TMR2;
	int duration = t.length * 312500;
	int end_tone = start_tone + duration;
	T2CONSET = 0x8000;

	// While tone time is less than start + duration
	while (TMR2 < end_tone) {

		start_wave = TMR2;
		reached_mid = 0;
		end_wave = start_wave + 312500 / t.freq;
		mid_wave = end_wave / 2;

		// First part of wave
		if (PORTD & 0x1)
			PORTDSET = 0x1;
		else PORTDCLR = 0x1;

		// While wave time is less than start + duration
		while (TMR2 < end_wave) {
			if (!reached_mid & TMR2 > mid_wave) {
				reached_mid = 1;
				
				// Second part of wave
				if (PORTD & 0x1)
					PORTDSET = 0x1;
				else PORTDCLR = 0x1;
			}
		}
	}
	PORTDCLR = 0x1;
	T2CON |= ~0x8000;
}
int play_tone_simple(int freq) {
	T2CONSET = 0x8000;
	int start_wave = TMR2;
	int reached_mid = 0;
	int end_wave = start_wave + (312500 / freq);
	int mid_wave = end_wave / 2;

	// First part of wave
	if (PORTD & 0x1)
		PORTDSET = 0x1;
	else PORTDCLR = 0x1;

	// While wave time is less than start + duration
	while (TMR2 < end_wave) {
		if (!reached_mid & TMR2 > mid_wave) {
			reached_mid = 1;
				
			// Second part of wave
			if (PORTD & 0x1)
					PORTDSET = 0x1;
			else PORTDCLR = 0x1;
		}
	}
	T2CON |= ~0x8000;
}


