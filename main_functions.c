#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"
#include "status.h"

#define SCALES_AMOUNT 7
#define TONES_IN_SCALE 36

int verse_length_1;
int verse_length_2;
int verse_length_3;
int verse_length_4;
int verse_tone_1;
int verse_tone_2;
int verse_tone_3;
int verse_tone_4;
int verse_tone_5;
int verse_tone_6;
int verse_tone_7;
int verse_tone_8;
int verse_tone_9;
int verse_tone_10;
int verse_tone_11;
int verse_tone_12;
int verse_tone_13;
int verse_tone_14;
int verse_tone_15;
int verse_tone_16;
int verse_tone_17;
int verse_tone_18;
int verse_tone_19;
int verse_tone_20;
int verse_tone_21;
int verse_tone_22;
int verse_tone_23;
int verse_tone_24;

int bridge_length_1;
int bridge_length_2;
int bridge_length_3;
int bridge_length_4;
int bridge_tone_1;
int bridge_tone_2;
int bridge_tone_3;
int bridge_tone_4;
int bridge_tone_5;
int bridge_tone_6;
int bridge_tone_7;
int bridge_tone_8;
int bridge_tone_9;
int bridge_tone_10;
int bridge_tone_11;
int bridge_tone_12;
int bridge_tone_13;
int bridge_tone_14;
int bridge_tone_15;
int bridge_tone_16;
int bridge_tone_17;
int bridge_tone_18;
int bridge_tone_19;
int bridge_tone_20;
int bridge_tone_21;
int bridge_tone_22;
int bridge_tone_23;
int bridge_tone_24;

int chorus_length_1;
int chorus_length_2;
int chorus_length_3;
int chorus_length_4;
int chorus_tone_1;
int chorus_tone_2;
int chorus_tone_3;
int chorus_tone_4;
int chorus_tone_5;
int chorus_tone_6;
int chorus_tone_7;
int chorus_tone_8;	
int chorus_tone_9;
int chorus_tone_10;
int chorus_tone_11;
int chorus_tone_12;
int chorus_tone_13;
int chorus_tone_14;
int chorus_tone_15;
int chorus_tone_16;
int chorus_tone_17;
int chorus_tone_18;
int chorus_tone_19;
int chorus_tone_20;
int chorus_tone_21;
int chorus_tone_22;
int chorus_tone_23;
int chorus_tone_24;

int led_up  = 0x01;
int led_down  = 0x80;
static int
x=739677345,
y=908315784,
z=275428064,
w=279215799,
v=134787432;

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
	PORTESET = led_up + led_down + (xorshift() & 0xa5);
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

int get_verse() {
	verse_length_1 = (xorshift() & 0xf);
	verse_length_2 = (xorshift() & 0xf);
	verse_length_3 = (xorshift() & 0xf);
	verse_length_4 = (xorshift() & 0xf);
	verse_tone_1 = xorshift() & 0x7f;
	verse_tone_2 = verse_tone_1 + 4;
	verse_tone_3 = xorshift() & 0x7f;
	verse_tone_4 = xorshift() & 0x7f;
	verse_tone_5 = verse_tone_3 + 4;
	verse_tone_6 = xorshift() & 0x7f;
	verse_tone_7 = verse_tone_6 + 4;
	verse_tone_8 = xorshift() & 0x7f;	
	verse_tone_9 = xorshift() & 0x7f;
	verse_tone_10 = xorshift() & 0x7f;
	verse_tone_11 = xorshift() & 0x7f;
	verse_tone_12 = xorshift() & 0x7f;
	verse_tone_13 = xorshift() & 0x7f;
	verse_tone_14 = xorshift() & 0x7f;
	verse_tone_15 = xorshift() & 0x7f;
	verse_tone_16 = xorshift() & 0x7f;	
	verse_tone_17 = (xorshift() & 0xf) << 1;
	verse_tone_18 = (xorshift() & 0xf) << 1;
	verse_tone_19 = (xorshift() & 0xf) << 1;
	verse_tone_20 = (xorshift() & 0xf) << 1;
	verse_tone_21 = (xorshift() & 0xf) << 1;
	verse_tone_22 = (xorshift() & 0xf) << 1;
	verse_tone_23 = (xorshift() & 0xf) << 1;
	verse_tone_24 = (xorshift() & 0xf) << 1;	
}

int get_bridge() {
	bridge_length_1 = (xorshift() & 0xf);
	bridge_length_2 = (xorshift() & 0xf);
	bridge_length_3 = (xorshift() & 0xf);
	bridge_length_4 = (xorshift() & 0xf);
	bridge_tone_1 = xorshift() & 0x7f;
	bridge_tone_2 = bridge_tone_1 + 4;
	bridge_tone_3 = xorshift() & 0x7f;
	bridge_tone_4 = xorshift() & 0x7f;
	bridge_tone_5 = bridge_tone_3 + 4;
	bridge_tone_6 = xorshift() & 0x7f;
	bridge_tone_7 = bridge_tone_6 + 4;
	bridge_tone_8 = xorshift() & 0x7f;	
	bridge_tone_9 = xorshift() & 0x7f;
	bridge_tone_10 = xorshift() & 0x7f;
	bridge_tone_11 = xorshift() & 0x7f;
	bridge_tone_12 = xorshift() & 0x7f;
	bridge_tone_13 = xorshift() & 0x7f;
	bridge_tone_14 = xorshift() & 0x7f;
	bridge_tone_15 = xorshift() & 0x7f;
	bridge_tone_16 = xorshift() & 0x7f;	
	bridge_tone_17 = (xorshift() & 0xf) << 1;
	bridge_tone_18 = (xorshift() & 0xf) << 1;
	bridge_tone_19 = (xorshift() & 0xf) << 1;
	bridge_tone_20 = (xorshift() & 0xf) << 1;
	bridge_tone_21 = (xorshift() & 0xf) << 1;
	bridge_tone_22 = (xorshift() & 0xf) << 1;
	bridge_tone_23 = (xorshift() & 0xf) << 1;
	bridge_tone_24 = (xorshift() & 0xf) << 1;
}

int get_chorus() {
	chorus_length_1 = (xorshift() & 0xf);
	chorus_length_2 = (xorshift() & 0xf);
	chorus_length_3 = (xorshift() & 0xf);
	chorus_length_4 = (xorshift() & 0xf);
	chorus_tone_1 = xorshift() & 0x7f;
	chorus_tone_2 = chorus_tone_1 + 4;
	chorus_tone_3 = xorshift() & 0x7f;
	chorus_tone_4 = xorshift() & 0x7f;
	chorus_tone_5 = chorus_tone_3 + 4;
	chorus_tone_6 = xorshift() & 0x7f;
	chorus_tone_7 = chorus_tone_6 + 4;
	chorus_tone_8 = xorshift() & 0x7f;	
	chorus_tone_9 = xorshift() & 0x7f;
	chorus_tone_10 = xorshift() & 0x7f;
	chorus_tone_11 = xorshift() & 0x7f;
	chorus_tone_12 = xorshift() & 0x7f;
	chorus_tone_13 = xorshift() & 0x7f;
	chorus_tone_14 = xorshift() & 0x7f;
	chorus_tone_15 = xorshift() & 0x7f;
	chorus_tone_16 = xorshift() & 0x7f;	
	chorus_tone_17 = (xorshift() & 0xf) << 1;
	chorus_tone_18 = (xorshift() & 0xf) << 1;
	chorus_tone_19 = (xorshift() & 0xf) << 1;
	chorus_tone_20 = (xorshift() & 0xf) << 1;
	chorus_tone_21 = (xorshift() & 0xf) << 1;
	chorus_tone_22 = (xorshift() & 0xf) << 1;
	chorus_tone_23 = (xorshift() & 0xf) << 1;
	chorus_tone_24 = (xorshift() & 0xf) << 1;
}

int play_verse() {
	play_tone(verse_tone_1, verse_length_1);
	play_tone(verse_tone_2, verse_length_2);
	play_tone(verse_tone_3, verse_length_3);
	play_tone(verse_tone_4, verse_length_4);
	play_tone(verse_tone_5, verse_length_1);
	play_tone(verse_tone_6, verse_length_3);
	play_tone(verse_tone_7, verse_length_2);
	play_tone(verse_tone_8, verse_length_4);
	play_tone(verse_tone_9, verse_length_3);
	play_tone(verse_tone_10, verse_length_2);
	play_tone(verse_tone_11, verse_length_1);
	play_tone(verse_tone_12, verse_length_4);
	play_tone(verse_tone_13, verse_length_3);
	play_tone(verse_tone_14, verse_length_2);
	play_tone(verse_tone_15, verse_length_1);
	play_tone(verse_tone_16, verse_length_3);
	play_tone(verse_tone_17, verse_length_2);
	play_tone(verse_tone_18, verse_length_4);
	play_tone(verse_tone_19, verse_length_1);
	play_tone(verse_tone_20, verse_length_2);
	play_tone(verse_tone_21, verse_length_3);
	play_tone(verse_tone_22, verse_length_1);
	play_tone(verse_tone_23, verse_length_2);
	play_tone(verse_tone_24, verse_length_3);
}

int play_bridge() {
	play_tone(bridge_tone_1, bridge_length_1);
	play_tone(bridge_tone_2, bridge_length_2);
	play_tone(bridge_tone_3, bridge_length_3);
	play_tone(bridge_tone_4, bridge_length_4);
	play_tone(bridge_tone_5, bridge_length_1);
	play_tone(bridge_tone_6, bridge_length_3);
	play_tone(bridge_tone_7, bridge_length_2);
	play_tone(bridge_tone_8, bridge_length_4);
	play_tone(bridge_tone_9, bridge_length_3);
	play_tone(bridge_tone_10, bridge_length_2);
	play_tone(bridge_tone_11, bridge_length_1);
	play_tone(bridge_tone_12, bridge_length_4);
	play_tone(bridge_tone_13, bridge_length_3);
	play_tone(bridge_tone_14, bridge_length_2);
	play_tone(bridge_tone_15, bridge_length_1);
	play_tone(bridge_tone_16, bridge_length_3);
	play_tone(bridge_tone_17, bridge_length_2);
	play_tone(bridge_tone_18, bridge_length_4);
	play_tone(bridge_tone_19, bridge_length_1);
	play_tone(bridge_tone_20, bridge_length_2);
	play_tone(bridge_tone_21, bridge_length_3);
	play_tone(bridge_tone_22, bridge_length_1);
	play_tone(bridge_tone_23, bridge_length_2);
	play_tone(bridge_tone_24, bridge_length_3);
}

int play_chorus() {
	play_tone(chorus_tone_1, chorus_length_1);
	play_tone(chorus_tone_2, chorus_length_2);
	play_tone(chorus_tone_3, chorus_length_3);
	play_tone(chorus_tone_4, chorus_length_4);
	play_tone(chorus_tone_5, chorus_length_1);
	play_tone(chorus_tone_6, chorus_length_3);
	play_tone(chorus_tone_7, chorus_length_2);
	play_tone(chorus_tone_8, chorus_length_4);
	play_tone(chorus_tone_9, chorus_length_3);
	play_tone(chorus_tone_10, chorus_length_2);
	play_tone(chorus_tone_11, chorus_length_1);
	play_tone(chorus_tone_12, chorus_length_4);
	play_tone(chorus_tone_13, chorus_length_3);
	play_tone(chorus_tone_14, chorus_length_2);
	play_tone(chorus_tone_15, chorus_length_1);
	play_tone(chorus_tone_16, chorus_length_3);
	play_tone(chorus_tone_17, chorus_length_2);
	play_tone(chorus_tone_18, chorus_length_4);
	play_tone(chorus_tone_19, chorus_length_1);
	play_tone(chorus_tone_20, chorus_length_2);
	play_tone(chorus_tone_21, chorus_length_3);
	play_tone(chorus_tone_22, chorus_length_1);
	play_tone(chorus_tone_23, chorus_length_2);
	play_tone(chorus_tone_24, chorus_length_3);
}

int play_noize() {
	get_verse();
	get_bridge();
	get_chorus();
	int i, j, k;
	for (i = 0; i < 1; i++) {
		for (j = 0; j < 1; j++)
		{
			play_verse();
		}
		play_bridge();
		for (k = 0; k < 1; k++)
		{
			play_chorus();
		}		
	}
}

int play_preset(int *array) {
	int size = sizeof(array)/sizeof(array[0]);
	int i;
	for (i = 0; i < size; (i+2)) {
		play_tone(array[i], array[i+1]);
	}
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
		play_tones(scale, tones, tone_count, 3, 4);
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
	for (play_count = 0; play_count < 2; play_count++) {
		play_tones(scale, tones, tone_count, 0, 8);
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
	melody_happy();
	melody_sad();
	melody_arabix();
	melody_happy();
	melody_sad();
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
				play_tone(scale_tones[drill_start + (drill_count *2)], drill_length);
			}
			index++;
		}
	}
}






