//
//  
//  
//


#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "example_songs.h"


tone_info example_twinkle[69] = {{0x15D, 2}/*G4*/, {0, 10}, {0x15D, 2}/*G4*/, {0, 10}, {0x20B, 2}/*D5*/, {0, 10}, {0x20B, 2}/*D5*/, {0, 10}, {0x24B, 2}/*E5*/, {0, 10}, {0x24B, 2}/*E5*/, {0, 10}, {0x20B, 1}/*D5*/, {0, 10}, {0x1D2, 2}/*C5*/, {0, 10}, {0x1D2, 2}/*C5*/, {0, 10}, {0x1B8, 2}/*B4*/, {0, 10}, {0x1B8, 2}/*B4*/, {0, 10}, {0x188, 2}/*A4*/, {0, 10}, {0x188, 2}/*A4*/, {0, 10}, {0x15D, 1}/*G4*/, {0, 10}, {0x1D2, 2}/*C5*/, {0, 10}, {0x1D2, 2}/*C5*/, {0, 10}, {0x1B8, 2}/*B4*/, {0, 10}, {0x1B8, 2}/*B4*/, {0, 10}, {0x188, 2}/*A4*/, {0, 10}, {0x188, 2}/*A4*/, {0, 10}, {0x15D, 1}/*G4*/, {0, 10}, {0x15D, 2}/*G4*/, {0, 10}, {0x15D, 2}/*G4*/, {0, 10}, {0x20B, 2}/*D5*/, {0, 10}, {0x20B, 2}/*D5*/, {0, 10}, {0x24B, 2}/*E5*/, {0, 10}, {0x24B, 2}/*E5*/, {0, 10}, {0x20B, 1}/*D5*/, {0, 10}, {0x1D2, 2}/*C5*/, {0, 10}, {0x1D2, 2}/*C5*/, {0, 10}, {0x1B8, 2}/*B4*/, {0, 10},{0x1B8, 2}/*B4*/, {0, 10}, {0x188, 2}/*A4*/, {0, 10}, {0x188, 2}/*A4*/, {0, 10}, {0x15D, 1}/*G4*/};
int twinkle_length;
tone_info example_imperial[134] = {{0x62, 1}/*A2*/, {0, 10}, {0x62, 1}/*A2*/, {0, 10}, {0x62, 1}/*A2*/, {0, 10}, {0x4E, 2}/*F2*/, {0, 10}, {0x75, 4}/*C3*/, {0, 10}, {0x62, 1}/*A2*/, {0, 10}, {0x4E, 2}/*F2*/, {0, 10}, {0x75, 4}/*C3*/, {0, 10}, {0x62, 1}/*A2*/, {0x62, 1}/*A2*/, {0x93, 1}/*E3*/, {0, 10}, {0x93, 1}/*E3*/, {0, 10}, {0x93, 1}/*E3*/, {0, 10}, {0x4E, 2}/*F2*/, {0, 10}, {0x75, 4}/*C3*/, {0, 10}, {0x62, 1}/*A2*/, {0, 10}, {0x4E, 2}/*F2*/, {0, 10}, {0x75, 4}/*C3*/, {0, 10}, {0x62, 1}/*A2*/, {0x62, 1}/*A2*/, {0xC4, 1}/*A3*/, {0, 10}, {0x62, 2}/*A2*/, {0, 10}, {0x62, 4}/*A2*/, {0, 10}, {0xC4, 1}/*A3*/, {0, 10}, {0xB9, 2}/*GS3*/, {0, 10}, {0xAF, 4}/*G3*/, {0, 10}, {0xA5, 4}/*FS3*/, {0, 10}, {0x93, 4}/*E3*/, {0, 10}, {0x9C, 2}/*F3*/, {0, 10}, {0x68, 2}/*AS2*/, {0, 10}, {0x8B, 1}/*DS3*/, {0, 10}, {0x83, 2}/*D3*/, {0, 10}, {0x83, 2}/*CS3*/, {0, 10}, {0x75, 4}/*C3*/, {0, 10}, {0x6E, 4}/*B2*/, {0, 10}, {0x75, 2}/*C3*/, {0, 10}, {0x4E, 1,}/*F2*/, {0, 10}, {0x5D, 2}/*GS2*/, {0, 10}, {0x4E, 2}/*F2*/, {0, 10}, {0x62, 4}/*A2*/, {0, 10}, {0x75, 1}/*C3*/, {0, 10}, {0x62, 2}/*A2*/, {0, 10}, {0x75, 4}/*C3*/, {0, 10}, {0x93, 1}/*E3*/, {0x93, 1}/*E3*/, {0xC4, 1}/*A3*/, {0, 10}, {0x62, 2}/*A2*/, {0, 10}, {0x62, 4}/*A2*/, {0, 10}, {0xC4, 1}/*A3*/, {0, 10}, {0xB9, 2}/*GS3*/, {0, 10}, {0xAF, 4}/*G3*/, {0, 10}, {0xA5, 4}/*FS3*/, {0, 10}, {0x93, 4}/*E3*/, {0, 10}, {0x9C, 2}/*F3*/, {0, 10}, {0x68, 2}/*AS2*/, {0, 10}, {0x8B, 1}/*DS3*/, {0, 10}, {0x83, 2}/*D3*/, {0, 10}, {0x83, 2}/*CS3*/, {0, 10}, {0x75, 4}/*C3*/, {0, 10}, {0x6E, 4}/*B2*/, {0, 10}, {0x75, 2}/*C3*/, {0, 10}, {0x4E, 1,}/*F2*/, {0, 10}, {0x5D, 2}/*GS2*/, {0, 10}, {0x4E, 2}/*F2*/, {0, 10}, {0x62, 4}/*A2*/, {0, 10}, {0x62, 1}/*A2*/, {0, 10}, {0x4E, 2}/*F2*/, {0, 10}, {0x75, 4}/*C3*/, {0, 10}, {0x62, 1}/*A2*/, {0x62, 1}/*A2*/, {0x62, 1}/*A2*/, {0x62, 1}/*A2*/};
int imperial_length;


void setup_songs() {
	twinkle_length = sizeof(example_twinkle)/sizeof(example_twinkle[0]);
	imperial_length = sizeof(example_imperial)/sizeof(example_imperial[0]);
}