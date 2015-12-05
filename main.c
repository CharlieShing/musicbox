#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"

unsigned int btn_status, sw_status;

// Definition of PR values for different tones.
#define C0 =

int counter = 0;

int main(void){
	
    setup();
    while(1){
        update_status();
        if (btn_status & 1) {
            T2CONSET |= 0x8000;
//            PR2 = 0x9550;
            play_sounds(0x9550);
        } else if (btn_status & 2) {
            T2CONSET |= 0x8000;
//            PR2 = 0x4AA7;
            play_sounds(0x4AA7);
            
        } else if (btn_status & 4) {
            T2CONSET |= 0x8000;
//            PR2 = 0x2554;
            play_sounds(0x2554);
            
        } else {
            IFSCLR(0) = 0x0100;
            PORTDCLR = 0x1;
            T2CON &= ~0x8000;
        }
    }
    
}

//Update status
int update_status(void) {
    btn_status = getbtns();
}

int play_sounds(int tone) {

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
        IFSCLR(0) = 0x0100;
    }
}











