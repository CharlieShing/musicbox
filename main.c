#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"



// Definition of PR values for different tones.
#define C3 0x9550
#define CS3 0x8CEE
#define D3 0x8505
#define DS3 0x7D8E
#define E3 0x7682
#define F3 0x6FDC
#define FS3 0x6993
#define G3 0x63A6
#define GS3 0x5E0F
#define A3 0x58C8
#define AS3 0x53CC
#define B3 0x4F18

#define C4 0x4AA7
#define CS4 0x4677
#define D4 0x4283
#define DS4 0x3EC7
#define E4 0x3B41
#define F4 0x37EE
#define FS4 0x34C9
#define G4 0x31D3
#define GS4 0x2F08
#define A4 0x2C64
#define AS4 0x29E6
#define B4 0x278C

#define C5 0x2554
#define CS5 0x233C
#define D5 0x2141
#define DS5 0x1F64
#define E5 0x1DA1
#define F5 0x1BF7
#define FS5 0x1A65
#define G5 0x18E9
#define GS5 0x1784
#define A5 0x1632
#define AS5 0x14F3
#define B5 0x13C6

#define C6 0x12AA

volatile unsigned int* _T4CON = (unsigned int*) 0xbf800c00;
unsigned int btnint_status, btnext_status, sw_status;
int counter = 0;
int button1tone = C5;
int button2tone = D5;
int button3tone = E5;
int button4tone = F5;
int button5tone = G5;
int button6tone = A5;
int button7tone = B5;


void change_tone(int* button){
    if(sw_status == 1) {
        *button = C5;
    } else if(sw_status == 2) {
        *button = D5;
    } else if(sw_status == 3) {
        *button = E5;
    } else if(sw_status == 4) {
        *button = F5;
    } else if(sw_status == 5) {
        *button = G5;
    } else if(sw_status == 6) {
        *button = A5;
    } else if(sw_status == 7) {
        *button = B5;
    } else if(sw_status == 8) {
        *button = C5;
    } else if(sw_status == 9) {
        *button = D5;
    } else if(sw_status == 10) {
        *button = E5;
    } else if(sw_status == 11) {
        *button = F5;
    } else if(sw_status == 12) {
        *button = G5;
    } else if(sw_status == 13) {
        *button = A5;
    } else if(sw_status == 14) {
        *button = B5;
    } else if(sw_status == 15) {
        *button = C6;
    }
}


int main(void){
    setup();
    while(1){
        update_status();
        
        //Button 1
        if (btnint_status & 1) {
            T2CONSET = 0x8000;
            if (sw_status != 0) {
                change_tone(&button1tone);
            }
            play_tone(button1tone);
            
            //Button 2
        } else if (btnint_status & 2) {
            T2CONSET = 0x8000;
            if (sw_status != 0) {
                change_tone(&button2tone);
            }
            play_tone(button2tone);
            
            //Button 3
        } else if (btnint_status & 4) {
            T2CONSET = 0x8000;
            if (sw_status != 0) {
                change_tone(&button3tone);
            }
            play_tone(button3tone);
            
            //Button 4
        } else if (btnint_status & 8) {
            T2CONSET = 0x8000;
            if (sw_status != 0) {
                change_tone(&button4tone);
            }
            play_tone(button4tone);
            
            //Button 5
        } else if (btnext_status & 1) {
            T2CONSET = 0x8000;
            if (sw_status != 0) {
                change_tone(&button5tone);
            }
            play_tone(button5tone);
            
            //Button 6
        } else if (btnext_status & 2) {
            T2CONSET = 0x8000;
            if (sw_status != 0) {
                change_tone(&button6tone);
            }
            play_tone(button6tone);
            
            //Button 7
        } else if (btnext_status & 4) {
            T2CONSET = 0x8000;
            if (sw_status != 0) {
                change_tone(&button7tone);
            }
            play_tone(button7tone);
            
            //Button 8
        } else {
            // Clear overflow flag
            IFSCLR(0) = 0x0100;
            T2CON &= ~0x8000;
            
            // Turn of sound
            TRISDCLR = 0x1;
            T2CON &= ~0x8000;
        }
    }
    
}

//Update status
int update_status(void) {
    btnint_status = getintbtns();
    btnext_status = getextbtns();
    sw_status = getsw();
    
}

int play_tone(int tone) {
    
    if (tone) {
        PR2 = tone;
        int counter = counter%2;
        unsigned int overflow = IFS(0);
        overflow &= 0x000100;
        overflow >>= 8;
        
        if (overflow == 1) {
            // Alternate between 1 and 0 each time overflow flag is reached
            if (counter%2 == 0) {
                PORTDSET = 0x1;
            } else
                PORTDCLR = 0x1;
            counter++;
            IFSCLR(0) = 0x100;
        }
    }
}

// Play a melody from given array.
int play_melody(int *melody_array) {
    *_T4CON |= 0x8000;
    int i, tone_length, overflow_count;
    int array_size = sizeof(melody_array)/sizeof(melody_array[0]);
    for (i = 0; i < array_size-1; i+2) {
        tone_length = melody_array[i+1];
        //While overflow isn't reached
        while (overflow_count < tone_length)
            if(IFS(0) & 0x10000) {
                overflow_count++;
                IFSCLR(0) = 0x10000;
            }
        play_tone(melody_array[i]);
    }
    *_T4CON &= ~0x8000;
}













