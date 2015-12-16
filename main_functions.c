#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"
#include "status.h"
#include "example_songs.h"

#define TONES_IN_SCALE 36

int led_up  = 0x01;
int led_down  = 0x80;
static int
x=666,
y=1024,
z=1337,
w=999,
v=4;

/*Method for generating random number. Found on 
http://mathoverflow.net/questions/29494/pseudo-random-number-generation-algorithms*/ 
/* replace defaults with five random seed values in calling program */ 
unsigned long xorshift(void) {
	int t; 
	t=(x^(x>>7)); 
	x=y; 
	y=z; 
	z=w; 
	w=v; 
	v=(v^(v<<6))^(t^(t<<13)); 
	return (y+y+1)*v;
} 

int play_tone(int freq, int length) {
	xorshift();
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
	PORTESET = led_up + led_down + ((xorshift() & 0xa4) * (xorshift() & 0x1));
	// Counters increment each microsecond.
	while (duration_counter < duration) {
		if (IFS(0) & 0x100 ) {
			duration_counter++;		// increment counters
			wave_counter++;
			IFS(0) |= ~0x100;	// reset overflow flag TODO: add freq > 0
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

int * get_scale(int scale) {
	if (scale == 0) {
		return scale_C_Major;
	} else if (scale == 1) {
		return scale_D_Major;
	} else if (scale == 2) {
		return scale_E_Major;
	} else if (scale == 3) {
		return scale_F_Major;
	} else if (scale == 4) {
		return scale_G_Major;
	} else if (scale == 5) {
		return scale_A_Major;
	} else if (scale == 6) {
		return scale_B_Major;
	} else if (scale == 7) {
		return scale_C_Minor;
	} else if (scale == 8) {
		return scale_D_Minor;
	} else if (scale == 9) {
		return scale_E_Minor;
	} else if (scale == 10) {
		return scale_F_Minor;
	} else if (scale == 11) {
		return scale_G_Minor;
	} else if (scale == 12) {
		return scale_A_Minor;
	} else if (scale == 13) {
		return scale_B_Minor;
	} else if (scale == 14) {
		return scale_C_Arabix;
	} else return scale_C_Major;
}


int short_noize() {
	int noize[8];
	noize[0] = xorshift() & 0x7f;
	noize[0] = 8;
	noize[2] = xorshift() & 0x7f;
	noize[0] = 8;
	noize[4] = xorshift() & 0x7f;
	noize[0] = 8;
	noize[6] = xorshift() & 0x7f;
	noize[0] = 8;
	play_tones(0, noize, 8, 0, 1);
}

int get_random_tone(int scale) {
	int tone = 0;
	int *tones = get_scale(scale);
	int tone_index = TONES_IN_SCALE;
	while (!(tone_index < TONES_IN_SCALE)) {
		tone_index = xorshift() & 0x3f;
		tone = tones[tone_index];
	}
	return tone;
}

void play_example(tone_info example[], int length) {
	int i;
	for(i = 0; i < length; i++) {
		play_tone(example[i].tone[0], example[i].tone[1]);
	}
}


int * generate_tones(int scale, int tone_count, int speed) {
	
	// Find 12 random tones in scale
	int tones[tone_count];
	int tone_length;
	int *tones_ptr = tones;
	int index;
	for (index = 0; index < tone_count; index++) {
		tone_length = ((xorshift() & 0x2) + speed + 1);
		tones[index] = get_random_tone(scale);
		tones[index+1] = tone_length;
		index++;
	}
	return tones_ptr;
}

int melody_happy() {

	// Choose scale
	int scale;	
	scale = xorshift() & 0x7;
	int tone_count = (xorshift() & 0x3f) << 2;
	
	int play_count;
	int *tones = generate_tones(scale, tone_count, 2);
	for (play_count = 0; play_count < 1; play_count++) {
		play_tones(scale, tones, tone_count, 8, 8);
	}
}


int melody_sad() {

	// Choose scale
	int scale;	
	scale = (xorshift() & 0x7) + 0x7;
	int tone_count = (xorshift() & 0x3f) << 2;
	
	int play_count;
	int *tones = generate_tones(scale, tone_count, 1);
	for (play_count = 0; play_count < 1; play_count++) {
		play_tones(scale, tones, tone_count, 3, 6);
	}
}

int melody_arabix() {
	int scale = 14;
	int tone_count = (xorshift() & 0x3f) << 2;
	int play_count;
	int *tones = generate_tones(scale, tone_count, 2);
	for (play_count = 0; play_count < 2; play_count++) {
		play_tones(scale, tones, tone_count, 2, 8);
	}
}

int melody_slow() {
	int scale = (xorshift() & 0x7) + 0x7;
	int tone_count = (xorshift() & 0x3f) << 1;
	int play_count;
	int *tones = generate_tones(scale, tone_count, 1);
	for (play_count = 0; play_count < 1; play_count++) {
		play_tones(scale, tones, tone_count, 10, 12);
	}
}

int melody_small() {
	int scale = (xorshift() & 0x7) + 0x7;
	int tone_count = 0x7;
	int play_count;
	int *tones;
	for (play_count = 0; play_count < 10; play_count++) {
		tones = generate_tones(scale, tone_count, 0);
		play_tones(scale, tones, tone_count, 1, 4);
	}
}

int play_song() {
	int segment_case;
	int segment_count;
	for (segment_count = 0; segment_count < 4; segment_count++) {
		segment_case = xorshift() & 0x3;
		if (segment_case == 0)
			melody_happy();
		else if (segment_case == 1)
			melody_sad();
		else if (segment_case == 2)
			melody_arabix();
		else if (segment_case == 3)
			melody_slow();
		else
			melody_happy();
	}
}

int play_tones(int scale, int *tones, int tone_count, int drills, int drill_length) {	
	// Play tones 4 times
	int index;
	int play_count;
	int drill_count;
	play_tone(0, 1);
	int *scale_tones = get_scale(scale);
	for (play_count = 0; play_count < 1; play_count++) {
		for (index = 0; index < tone_count; index++) {
			play_tone(tones[index], tones[index+1]);
			int drill_start = (xorshift() & 0xf) + 0x5;
			for (drill_count = 0; drill_count < drills; drill_count++) {
				play_tone(scale_tones[drill_start + (drill_count * 2)], drill_length);
			}
			index++;
		}
	}
}






