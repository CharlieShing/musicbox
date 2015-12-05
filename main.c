#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"

#define whole_note 1;
#define half_note 0.5;
#define quarter_note 0.25;
#define eight_note 0.125;
#define sixteenth_note 0.0625;
#define thirty_second_note 0.03125;

// Define tone frequencies
#define C3 261.63;
#define CS3 280;

int main(void){
	
    setup();    
    while(1){
		// Variables for state of buttons and switches
		unsigned int btn_status;
		unsigned int sw_status;
        update_status();    
        if (btn_status & 1) {
            on(0x1);
            play_sound_simple();
        }
		else
			off(0x1);
		if (btn_status & 2)
			on(0x2);
		else
			off(0x2);
		if (btn_status & 4)
			on(0x4);
		else
			off(0x4);
		if (btn_status & 8)
			on(0x8);
		else
			off(0x8);
    }
}

int setup(void) {
    
    // Set bit 0-7 in TRISE to output for LEDs
    TRISE &= ~0xff;
    // Set bit 1 to input for BTN1
    TRISFSET = 0x2;
    // Set bit 5-11 in TRISD to input for buttons and switches
    TRISDSET = 0xfe8 << 4;
	// Set pin 9 for the speaker to 0 output
	TRISDINV = 0x8;
	
	// Clear controll register for Timer2
	T2CON = 0x0;
	// Clear controll register for Timer3
	T3CON = 0x0;
	// Setup timer for playing of tones
	T2CONSET = 0x78;
	// Reset Timer 2 & 3
	TMR2 = 0;
	// Set PR2 and PR3 registers with 32-bit value
	PR2 = 1194;
	
	// Set priority level for timer 3
	IPC3SET = 0x00000005;
	/* Clear interupt flag for timer 3
	IFS0CLR = 0x1000;
	// Set interupt flag for timer 3
	IFS0SET = 0x1000;*/
    
}

int update_status(void) {
	
	btn_status = getbtns();
	
	sw_status = getsw();
	
}

int on(unsigned int led) {
    PORTESET = led;
}

int off(unsigned int led) {
	PORTECLR = led;
}

/* Play a simple sound
 */
int play_sound_simple() {
    for(int i = 0; i < 1000000; i++) {
        PORTDCLR = 0x8;
        if (i%3 == 0) PORTDSET = 0x8;
    }
}

int play_sound_pwm(int duty) {
    OC4RS = duty;
    OC4CONSET = 0b110;
    T2CONSET = 0x8000;
    OC4CONSET = 0x8000;
    for (int i = 0; i < 1000000; i++)
}












