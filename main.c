#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "musicbox.h"
#include "setup.h"
#include "main_functions.h"
#include "status.h"
#include "example_songs.h"

int tone_length;
int tone;

// Index for button tones will be stored in these variables.
int btn1_set1 = 54;
int btn2_set1 = 49;
int btn3_set1 = 48;
int btn4_set1 = 47;
int btn5_set1 = 42;
int btn6_set1 = 44;
int btn7_set1 = 46;

int btn1_set2 = 54;
int btn2_set2 = 49;
int btn3_set2 = 48;
int btn4_set2 = 47;
int btn5_set2 = 42;
int btn6_set2 = 44;
int btn7_set2 = 46;

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













