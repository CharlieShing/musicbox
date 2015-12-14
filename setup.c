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
#include "input_status.h"

// Definitions of tone frequencies
int C3 = 0x83;
#define CS3 0
#define D3 0
#define DS3 0
#define E3 0
#define F3 0
#define FS3 0
#define G3 0
#define GS3 0
#define A3 0
#define AS3 0
#define B3 0
int C4 = 0x106;
#define CS4 0
#define D4 0
#define DS4 0
#define E4 0
#define F4 0
#define FS4 0
#define G4 0
#define GS4 0
#define A4 0
#define AS4 0
#define B4 0
int C5 = 0x20B;
#define CS5 0
int D5 = 0x24B;
#define DS5 0
int E5 = 0x293;
int F5 = 0x2BA;
/*int FS5 0
int G5 0
int GS5 0
int A5 0
int AS5 0
int B5 0*/
int C6 = 0x417;

#define SPEED 1
/*
struct Tone  pause_whole = {0, 0.5*SPEED};
struct Tone  pause_half = {0, 1*SPEED};
struct Tone  pause_fourth = {0, 2*SPEED};
struct Tone  pause_eighth = {0, 4*SPEED};
struct Tone  pause_sixteenth = {0, 8*SPEED};
*/

struct Tone {
	int freq;
	int length;
};

struct Tone c6_whole;

/*struct Tone  c6_half = {C6, 1*SPEED};
struct Tone  c6_fourth = {C6, 2*SPEED};
struct Tone  c6_eighth = {C6, 4*SPEED};
struct Tone  c6_sixteenth = {C6, 8*SPEED};

struct Tone  f5_whole = {F5, 0.5*SPEED};
struct Tone  f5_half = {F5, 1*SPEED};
struct Tone  f5_fourth = {F5, 2*SPEED};
struct Tone  f5_eighth = {F5, 4*SPEED};
struct Tone  f5_sixteenth = {F5, 8*SPEED};

struct Tone  e5_whole = {E5, 0.5*SPEED};
struct Tone  e5_half = {E5, 1*SPEED};
struct Tone  e5_fourth = {E5, 2*SPEED};
struct Tone  e5_eighth = {E5, 4*SPEED};
struct Tone  e5_sixteenth = {E5, 8*SPEED};

struct Tone  d5_whole = {D5, 0.5*SPEED};
struct Tone  d5_half = {D5, 1*SPEED};
struct Tone  d5_fourth = {D5, 2*SPEED};
struct Tone  d5_eighth = {D5, 4*SPEED};
struct Tone  d5_sixteenth = {D5, 8*SPEED};

struct Tone  c5_whole = {C5, 0.5*SPEED};
struct Tone  c5_half = {C5, 1*SPEED};
struct Tone  c5_fourth = {C5, 2*SPEED};
struct Tone  c5_eighth = {C5, 4*SPEED};
struct Tone  c5_sixteenth = {C5, 8*SPEED};

struct Tone c4_whole = {C4, 0.5*SPEED};
struct Tone  c4_half = {C4, 1*SPEED};
struct Tone  c4_fourth = {C4, 2*SPEED};
struct Tone  c4_eighth = {C4, 4*SPEED};
struct Tone  c4_sixteenth = {C4, 8*SPEED};

struct Tone  c3_whole = {C3, 0.5*SPEED};
struct Tone  c3_half = {C3, 1*SPEED};
struct Tone  c3_fourth = {C3, 2*SPEED};
struct Tone  c3_eighth = {C3, 4*SPEED};
struct Tone  c3_sixteenth = {C3, 8*SPEED};
*/

//TODO update examples
/*int example_twinkle[]; = {G4, 153, G4, 153, D5, 153, D5, 153, E5, 153, E5, 153, D5, 305, C5, 153, C5, 153, B5, 153, B5, 153, A5, 153, A5, 153, G4, 305, C5, 153, C5, 153, B5, 153, B5, 153, A5, 153, A5, 153, G4, 305, G4, 153, G4, 153, D5, 153, D5, 153, E5, 153, E5, 153, D5, 305, C5, 153, C5, 153, B5, 153, B5, 153, A5, 153, A5, 153, G4, 305};

int example_zelda[] = {D4, 153, D5, 153, B5, 305, A5, 153, B5, 153, A5, 305, D4, 153, D5, 153, B5, 305, A5, 153, B5, 153, A5, 305, E4, 153, A5, 153, G4, 305, A5, 153, G4, 153, A5, 305, G4, 153};
*/
int setup(void) {
	init_tones();
	// Initialize internal buttons RF1, RD5-7. Pin 4, 34, 36, 37:
    //BTN1
    TRISFSET = 0x2;
    //BTN2-4
    TRISDSET = 0xe0;

	// Init led1 & 2
	TRISECLR = 0xc0;
    
    // Initialize external buttons, Pin 5, 6, 9:
    //BTN1 at RD1, pin 5
    TRISDSET = 0x2;
    //BTN2 at RD2, pin 6
    TRISDSET = 0x4;
    //BTN3 at RD3, pin 9
    TRISDSET = 0x8;
    
    // Initialize switches RD8-11, Pin 2, 7, 8, 35:
    TRISDSET = 0xf00;
    
    // Initialize speaker as output RD0, Pin 3:
    TRISD &= ~0x1;
    
    // Initialize TMR2 as timer for creating audio through speaker
	// Prescaler is set to 1:256 and period register to max 32-bit value.
    T2CON &= ~0xffff;
    T2CONSET = 0x00f0;
    PR2 = 0xffffffff;
}

int init_tones(void) {
	c6_whole.freq = C6;
	c6_whole.length = (0.5*SPEED);
}











