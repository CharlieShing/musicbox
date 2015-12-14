#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"
#include "status.h"

int led_up  = 0x01;
int led_down  = 0x80;

int play_tone(int freq, int length) {
	T2CONSET = 0x8000;
	int duration_counter = 0;
	int wave_counter = 0;
	int duration = 1000000/length;
	int half_wave = (500000/freq);

	if (led_up <= 0x80) led_up <<= 1;
	else led_up = 0x01;
	if (led_down >= 0x01) led_down >>= 1;
	else led_down = 0x80;
	
	// Turn on one of the LEDs
	PORTESET = led_up + led_down;
	// Counters increment each microsecond.
	while (duration_counter < duration) {
		if (IFS(0) & 0x100 ) {
			duration_counter++;		// increment counters
			wave_counter++;
			IFS(0) |= ~0x100;	// reset overflow flag
		} if (wave_counter >= half_wave) {
			PORTDINV = 0x1; // Invert signal to speaker
			wave_counter = 0; // Clear wave counter
		}
	}
	PORTECLR = led_up + led_down;
	// Stop timer and tone
	PORTDCLR = 0x1;
	T2CON |= ~0x8000;
}

int play_song() {
	
}

