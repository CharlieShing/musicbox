//
//  main_functions.h
//  
//
//  Created by Christoffer Alenskog Berg on 05/12/15.
//
//

#ifndef main_functions_h
#define main_functions_h
//Global variables
/*
extern int example_twinkle[];
extern int example_zelda[];
*/
// tonestone pause_whole = {0, 0.5*SPEED};
/*
extern Tone pause_half;
extern Tone pause_fourth;
extern Tone pause_eighth;
extern Tone pause_sixteenth;
*/
extern struct Tone c6_whole;
/*extern Tone c6_half;
extern Tone c6_fourth;
extern Tone c6_eighth;
extern Tone c6_sixteenth;

extern Tone f5_whole;
extern Tone f5_half;
extern Tone f5_fourth;
extern Tone f5_eighth;
extern Tone f5_sixteenth;

extern struct tone e5_whole;
extern struct tone e5_half;
extern struct tone e5_fourth;
extern struct tone e5_eighth;
extern struct tone e5_sixteenth;

extern struct tone d5_whole;
extern struct tone d5_half;
extern struct tone d5_fourth;
extern struct tone d5_eighth;
extern struct tone d5_sixteenth;

extern struct tone c5_whole;
extern struct tone c5_half;
extern struct tone c5_fourth;
extern struct tone c5_eighth;
extern struct tone c5_sixteenth;

extern struct tone c4_whole;
extern struct tone c4_half;
extern struct tone c4_fourth;
extern struct tone c4_eighth;
extern struct tone c4_sixteenth;

extern struct tone c3_whole;
extern struct tone c3_half;
extern struct tone c3_fourth;
extern struct tone c3_eighth;
extern struct tone c3_sixteenth;

extern struct tone tone_btn1;
extern struct tone tone_btn2;
extern struct tone tone_btn3;
extern struct tone tone_btn4;
extern struct tone tone_btn5;
extern struct tone tone_btn6;
extern struct tone tone_btn7;
*/
//Global functions

extern int C3;
extern int C4;
extern int C5;
extern int D5;
extern int E5;
extern int F5;
extern int C6;

extern int setup(void);
int init_tones(void);
#endif
