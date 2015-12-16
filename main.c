#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"
#include "status.h"
#include "example_songs.h"

int tone_length;
int tone;

// Index for button tones will be stored in these variables.
int btn1_set1 = 10;
int btn2_set1 = 14;
int btn3_set1 = 17;
int btn4_set1 = 22;
int btn5_set1 = 34;
int btn6_set1 = 38;
int btn7_set1 = 46;

int btn1_set2 = 13;
int btn2_set2 = 17;
int btn3_set2 = 20;
int btn4_set2 = 25;
int btn5_set2 = 37;
int btn6_set2 = 38;
int btn7_set2 = 44;

int main(void){
    setup();	
	tone_length = 5;
    while(1){
    	update_status(); 
		if (sw == 0) {
	        if (btns & 0x1) {
				tone = tone_frq[btn1_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x2) {
				tone = tone_frq[btn2_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x4) {
				tone = tone_frq[btn3_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x8) {
				tone = tone_frq[btn4_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x10) {
				tone = tone_frq[btn5_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x20) {
				tone = tone_frq[btn6_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x40) {
				tone = tone_frq[btn7_set1];
				play_tone(tone, tone_length);      
			}
		} else if (sw == 0x1) {
			modify_pitch1(1);
		} else if (sw == 0x3) {
			modify_pitch1(-1);
		} else if (sw == 0x8) {
	        if (btns & 0x1) {
				tone = tone_frq[btn1_set2];
				play_tone(tone, tone_length);
	        } if (btns & 0x2) {
				tone = tone_frq[btn2_set2];
				play_tone(tone, tone_length);
	        } if (btns & 0x4) {
				tone = tone_frq[btn3_set2];
				play_tone(tone, tone_length);
	        } if (btns & 0x8) {
				tone = tone_frq[btn4_set2];
				play_tone(tone, tone_length);
	        } if (btns & 0x10) {
				tone = tone_frq[btn5_set2];
				play_tone(tone, tone_length);
	        } if (btns & 0x20) {
				tone = tone_frq[btn6_set2];
				play_tone(tone, tone_length);
	        } if (btns & 0x40) {
				tone = tone_frq[btn7_set2];
				play_tone(tone, tone_length);      
			}
		} else if (sw == 0x9) {
			modify_pitch2(1);
		} else if (sw == 0xb) {
			modify_pitch2(-1);
		} else if (sw == 0xc) {
			if (btns & 0x1) {
				melody_arabix();
			} else if (btns & 0x2) {
				melody_small();
			} if (btns & 0x4) {
				tone = tone_frq[btn3_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x8) {
				tone = tone_frq[btn4_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x10) {
				tone = tone_frq[btn5_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x20) {
				tone = tone_frq[btn6_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x40) {
				tone = tone_frq[btn7_set1];
				play_tone(tone, tone_length);      
			}
		} else if (sw == 0xd) {
			if (btns & 0x1) {
				tone = tone_frq[btn1_set1];
				play_tone(tone, tone_length);
			} else if (btns & 0x2) {
				melody_happy();
			} else if (btns & 0x4) {
				melody_sad();
			} else if (btns & 0x8) {
				play_song();
			} if (btns & 0x10) {
				tone = tone_frq[btn5_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x20) {
				tone = tone_frq[btn6_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x40) {
				tone = tone_frq[btn7_set1];
				play_tone(tone, tone_length);      
			}
		} else if (sw == 0xa) {
			if (btns & 0x1) {
				melody_sad();
			} if (btns & 0x2) {
				tone = tone_frq[btn2_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x4) {
				tone = tone_frq[btn3_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x8) {
				tone = tone_frq[btn4_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x10) {
				tone = tone_frq[btn5_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x20) {
				tone = tone_frq[btn6_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x40) {
				tone = tone_frq[btn7_set1];
				play_tone(tone, tone_length);      
			}
		}  else if (sw == 0xe) {
			if (btns & 0x1) {
				melody_slow();
			} if (btns & 0x2) {
				tone = tone_frq[btn2_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x4) {
				tone = tone_frq[btn3_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x8) {
				tone = tone_frq[btn4_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x10) {
				tone = tone_frq[btn5_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x20) {
				tone = tone_frq[btn6_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x40) {
				tone = tone_frq[btn7_set1];
				play_tone(tone, tone_length);      
			}
		} else if (sw == 0xf) {
			if (btns & 0x1) {
				melody_arabix();
			} if (btns & 0x2) {
				play_example(example_twinkle, twinkle_length);
	        } if (btns & 0x4) {
				play_example(example_imperial, imperial_length);
	        } if (btns & 0x8) {
				tone = tone_frq[btn4_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x10) {
				tone = tone_frq[btn5_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x20) {
				tone = tone_frq[btn6_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x40) {
				tone = tone_frq[btn7_set1];
				play_tone(tone, tone_length);      
			}
		} else {
	        if (btns & 0x1) {
				tone = tone_frq[btn1_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x2) {
				tone = tone_frq[btn2_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x4) {
				tone = tone_frq[btn3_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x8) {
				tone = tone_frq[btn4_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x10) {
				tone = tone_frq[btn5_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x20) {
				tone = tone_frq[btn6_set1];
				play_tone(tone, tone_length);
	        } if (btns & 0x40) {
				tone = tone_frq[btn7_set1];
				play_tone(tone, tone_length);      
			}
		}
        // Clear tones etc.
		PORTECLR = 0xff;
    }
	return 0;
}

int modify_pitch1(int change_pitch) {
	if (btns & 0x1) {
		btn1_set1 += change_pitch;
		tone = tone_frq[btn1_set1];
		play_tone(tone, tone_length);		
	} if (btns & 0x2) {
		btn2_set1 += change_pitch;		
		tone = tone_frq[btn2_set1];
		play_tone(tone, tone_length);		
	} if (btns & 0x4) {
		btn3_set1 += change_pitch;	
		tone = tone_frq[btn3_set1];
		play_tone(tone, tone_length);			
	} if (btns & 0x8) {
		btn4_set1 += change_pitch;	
		tone = tone_frq[btn4_set1];
		play_tone(tone, tone_length);			
	} if (btns & 0x10) {
		btn5_set1 += change_pitch;
		tone = tone_frq[btn5_set1];
		play_tone(tone, tone_length);				
	} if (btns & 0x20) {
		btn6_set1 += change_pitch;
		tone = tone_frq[btn6_set1];
		play_tone(tone, tone_length);				
	} if (btns & 0x40) {
		btn7_set1 += change_pitch;
		tone = tone_frq[btn7_set1];
		play_tone(tone, tone_length);		
	}	
	return 0;
}

int modify_pitch2(int change_pitch) {
	if (btns & 0x1) {
		btn1_set2 += change_pitch;
		tone = tone_frq[btn1_set2];
		play_tone(tone, tone_length);		
	} if (btns & 0x2) {
		btn2_set2 += change_pitch;		
		tone = tone_frq[btn2_set2];
		play_tone(tone, tone_length);		
	} if (btns & 0x4) {
		btn3_set2 += change_pitch;	
		tone = tone_frq[btn3_set2];
		play_tone(tone, tone_length);			
	} if (btns & 0x8) {
		btn4_set2 += change_pitch;	
		tone = tone_frq[btn4_set2];
		play_tone(tone, tone_length);			
	} if (btns & 0x10) {
		btn5_set2 += change_pitch;
		tone = tone_frq[btn5_set2];
		play_tone(tone, tone_length);				
	} if (btns & 0x20) {
		btn6_set2 += change_pitch;
		tone = tone_frq[btn6_set2];
		play_tone(tone, tone_length);				
	} if (btns & 0x40) {
		btn7_set2 += change_pitch;
		tone = tone_frq[btn7_set2];
		play_tone(tone, tone_length);		
	}	
	return 0;
}













