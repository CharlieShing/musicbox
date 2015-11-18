#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"


int main(void){
	
    setup();    
    while(1){
		// Variables for state of buttons and switches
		unsigned int btn_status;
		unsigned int sw_status;
        update_status();    
        if (btn_status & 1)
            on(0x1);
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
		
		if (sw_status & 1)
			play_sound();
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
	// Clear interupt flag for timer 3
	IFS0CLR = 0x1000;
	// Set interupt flag for timer 3
	IFS0SET = 0x1000;
    
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

int play_sound(void) {
	double freq = 261.63; //C4
	double duty_cycle = 0.50;
	int current_pos = 0;
	PORTDSET = 0x8;
	for (int i = 0; i < 1000; i++){
		current_pos++;;
	}
	PORTDCLR = 0x8;
	/* cpu operates at 80 MHz, if frequency is to be 261.63 Hz
	   the amount of ticks per wave length must be approx 305775.33 */
}

int wave(void) {
	T4CONSET = 0x8000;
	double duration = 0;
	
	for (int i; i < 1000; i++) {
		if (IFS0 & 8) {
			
		} 
	}
}













/* Simple program lights up LD1 when BTN4 is pressed.
int main(void) {
	TRISE &= ~0xf;
	
	TRISF |= 0x2;
	while(1){
		PORTE = (PORTF >> 1) & 0x1;			
	}
}*/

/* constants won't change. They're used here to
// set pin numbers:
const int button_1 = 4;
const int button_2 = 34;
const int button_3 = 36;
const int button_4 = 37;
const int switch_1 = 2;
const int switch_2 = 7;
const int switch_3 = 8;
const int switch_4 = 35;
const int led_1 = 33;
const int led_2 = 32;
const int led_3 = 31;
const int led_4 = 30;
const int led_5 = 33;
const int led_6 = 28;
const int led_7 = 27;
const int led_8 = 26;
const int speaker = 9;

// variables will change:
int button_1_state = 0;
int button_2_state = 0;
int button_3_state = 0;
int button_4_state = 0;
int switch_1_state = 0;
int switch_2_state = 0;
int switch_3_state = 0;
int switch_4_state = 0;

const int rate = 800;
const int note_length = 8;
int repeat;

int played_1, played_2, played_3, played_4;

int test[] = {
    NOTE_C1,3, NOTE_C2,3, NOTE_C3,3, NOTE_C4,3, NOTE_C5,3, NOTE_C6,3, NOTE_C7,3, NOTE_C8,3
};

int test_size = sizeof(test)/sizeof(int);

// notes in the melody:
int imperial_march[] = {
    NOTE_G2,6, 0,3, NOTE_G2,6, 0,3, NOTE_G2,10, NOTE_G2,10, NOTE_G2,10, NOTE_G2,10, 0,3, NOTE_G2,10, NOTE_G2,10, NOTE_G2,10, NOTE_DS3,10, NOTE_DS3,10, NOTE_DS3,10, \
    NOTE_G2,6, 0,3, NOTE_G2,6, 0,3, NOTE_G2,10, NOTE_G2,10, NOTE_G2,10, NOTE_G2,10, 0,3, NOTE_G2,10, NOTE_G2,10, NOTE_G2,10, NOTE_FS3,10, NOTE_FS3,10, NOTE_FS3,10, \
    NOTE_G2,2, NOTE_G2,2, NOTE_G2,2, NOTE_DS2,3, NOTE_AS2,6, NOTE_G2,2, NOTE_DS2,3, NOTE_AS2,6, NOTE_G2,2, 0,2, \
    NOTE_D3,2, NOTE_D3,2, NOTE_D3,2, NOTE_DS3,3, NOTE_AS2,6, NOTE_FS2,2, NOTE_DS2,3, NOTE_AS2,6, NOTE_G2,2, 0,2, \
    NOTE_G3,2, NOTE_G2,3, NOTE_G2,6, NOTE_G3,2, NOTE_FS3,3, NOTE_F3,6, NOTE_E3,6, NOTE_DS3,6, NOTE_E3,6, 0,3,\
    NOTE_E2,6, NOTE_CS3,2, NOTE_C3,3, NOTE_B2,6, NOTE_AS2,6, NOTE_A2,6, NOTE_AS2,6, 0,3, \
    NOTE_DS2,6, NOTE_FS2,2, NOTE_DS2,3, NOTE_FS2,6, NOTE_AS2,2, NOTE_G2,3, NOTE_AS2,6, NOTE_D3,2, 0,2,\
    NOTE_G3,2, NOTE_G2,3, NOTE_G2,6, NOTE_G3,2, NOTE_FS3,3, NOTE_F3,6, NOTE_E3,6, NOTE_DS3,6, NOTE_E3,6, 0,3,\
    NOTE_E2,6, NOTE_CS3,2, NOTE_C3,3, NOTE_B2,6, NOTE_AS2,6, NOTE_A2,6, NOTE_AS2,6, 0,3, \
    NOTE_DS2,6, NOTE_FS2,2, NOTE_DS2,3, NOTE_AS2,6, NOTE_G2,2, NOTE_DS2,3, NOTE_AS2,6, NOTE_G2,2
};

int imperial_march_size = sizeof(imperial_march)/sizeof(int);

void setup() {
    
    pinMode(speaker, OUTPUT);
    pinMode(led_1, OUTPUT);
    pinMode(led_2, OUTPUT);
    pinMode(led_3, OUTPUT);
    pinMode(led_4, OUTPUT);
    pinMode(led_5, OUTPUT);
    pinMode(led_6, OUTPUT);
    pinMode(led_7, OUTPUT);
    pinMode(led_8, OUTPUT);
    pinMode(button_1, INPUT);
    pinMode(button_2, INPUT);
    pinMode(button_3, INPUT);
    pinMode(button_4, INPUT);
    pinMode(switch_1, INPUT);
    pinMode(switch_2, INPUT);
    pinMode(switch_3, INPUT);
    pinMode(switch_4, INPUT);
    
    int played_1 = 0;
    int played_2 = 0;
    int played_3 = 0;
    int played_4 = 0;
}

void loop() {
    
    // read the state of buttons and switches:
    button_1_state = digitalRead(button_1);
    button_2_state = digitalRead(button_2);
    button_3_state = digitalRead(button_3);
    button_4_state = digitalRead(button_4);
    switch_1_state = digitalRead(switch_1);
    switch_2_state = digitalRead(switch_2);
    switch_3_state = digitalRead(switch_3);
    switch_4_state = digitalRead(switch_4);
    
    // turn LEDs off:
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, LOW);
    digitalWrite(led_5, LOW);
    digitalWrite(led_6, LOW);
    digitalWrite(led_7, LOW);
    digitalWrite(led_8, LOW);
    
    // Second iteration of program, implement your own PWM signal
    
    // Generate a 500Hz tone
    if (button_4_state == HIGH) {
        double speaker_period = 1.0/500.0;
        for (int tone_duration = 0; tone_duration < 500; tone_duration++) {
            digitalWrite(speaker, HIGH);
            digitalWrite(speaker, LOW);
        }
        
    }
    
    /** First iteration of program
     // Set repeat on/off
     if (switch_4_state == HIGH) repeat = 1;
     else repeat = 0;
     
     if (switch_1_state == LOW && switch_2_state == LOW && switch_3_state == LOW && switch_4_state == LOW) {
     
     // check if the pushbutton is pressed.
     // if it is, the buttonState is HIGH:
     if (button_1_state == HIGH) {
     
     // turn LED on:
     digitalWrite(led_1, HIGH);
     play_melody(imperial_march, imperial_march_size);
     }
     else if (button_2_state == HIGH) {
     digitalWrite(led_1, HIGH);
     play_melody(test, test_size);
     }
     }
     
     // First set of notes
     else if (switch_3_state == LOW && switch_2_state == LOW && switch_1_state == LOW)
     assign_buttons(NOTE_AS2, NOTE_C3, NOTE_D3, NOTE_DS3);
     else if (switch_3_state == HIGH && switch_2_state == LOW && switch_1_state == LOW)
     assign_buttons(NOTE_D3, NOTE_DS3, NOTE_F3, NOTE_G3);
     else if (switch_3_state == LOW && switch_2_state == HIGH && switch_1_state == LOW)
     assign_buttons(NOTE_F3, NOTE_G3, NOTE_GS3, NOTE_AS3);
     else if (switch_3_state == HIGH && switch_2_state == HIGH && switch_1_state == LOW)
     assign_buttons(NOTE_AS2, NOTE_D3, NOTE_F3, NOTE_GS3);
     else if (switch_3_state == HIGH && switch_2_state == HIGH && switch_1_state == HIGH)
     assign_buttons(NOTE_G3, NOTE_GS3, NOTE_AS3, NOTE_C4);
     else if (switch_3_state == HIGH && switch_2_state == LOW && switch_1_state == HIGH)
     assign_buttons(NOTE_C3, NOTE_DS3, NOTE_F3, NOTE_G3);
     else if (switch_3_state == LOW && switch_2_state == LOW && switch_1_state == HIGH)
     assign_buttons(NOTE_D3, NOTE_DS3, NOTE_F3, NOTE_G3);
     else if (switch_3_state == LOW && switch_2_state == HIGH && switch_1_state == HIGH)
     assign_buttons(NOTE_C3, NOTE_D3, NOTE_DS3, NOTE_F3);**//*
}

// Notes are assigned in reversed order to correspond to button order
void assign_buttons(int note_4, int note_3, int note_2, int note_1) {
    
    // Button 1
    if (button_1_state == HIGH && played_1 == 0) {
        play_note(note_1);
        if (repeat == 0)
            played_1 = 1;
    }
    else if (button_1_state == LOW)
        played_1 = 0;
    
    // Button 2
    if (button_2_state == HIGH && played_2 == 0) {
        play_note(note_2);
        if (repeat == 0)
            played_2 = 1;
    }
    else if (button_2_state == LOW)
        played_2 = 0;
    
    // Button 3
    if (button_3_state == HIGH && played_3 == 0) {
        play_note(note_3);
        if (repeat == 0)
            played_3 = 1;
    }
    else if (button_3_state == LOW)
        played_3 = 0;
    
    // Button 4
    if (button_4_state == HIGH && played_4 == 0) {
        play_note(note_4);
        if (repeat == 0)
            played_4 = 1;
    }
    else if (button_4_state == LOW)
        played_4 = 0;
    
}

void play_note(int note) {
    digitalWrite(led_1, HIGH);
    double duration = rate/note_length;
    tone(speaker, note, duration);
    delay(duration);
    noTone(speaker);
}

void play_melody(int *melody, int melody_size) {
    int this_note = 0;
    // iterate over the notes of the melody:sizeof(*melody)
    while (this_note < melody_size) {
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        double note_duration = rate/melody[this_note+1];
        tone(speaker, melody[this_note],note_duration);
        
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        double pause_between_notes = note_duration * 1.30;
        delay(pause_between_notes);
        // stop the tone playing:
        noTone(speaker);
        this_note += 2;
    }
}*/









