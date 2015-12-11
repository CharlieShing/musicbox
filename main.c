#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"


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

#define C4 0x264
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

#define C6 0x99


#define fourth 0x4E200

volatile unsigned int* _T4CON = (unsigned int*) 0xbf800c00;
unsigned int btnint_status, btnext_status, sw_status;
int signal_counter = 0;
int overflow_tone_count = 0;
int overflow_duration_count = 0;
int button1tone = C5;
int button2tone = D5;
int button3tone = C6;
int button4tone = C4;
int button5tone = G5;
int button6tone = A5;
int button7tone = B5;



int main(void){
    setup();
    while(1){
        update_status();
        
        //Button 1
        if (btnint_status & 1) {
            T2CONSET = 0x8000;
            
            play_fourth();
            
            //Button 2
        } else if (btnint_status & 2) {
            
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













