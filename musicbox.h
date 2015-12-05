/* musicbox.h
Header file for all files included in musicbox project
*/

// Declare main functions from musicbox.c
int main(void);

// Functions from input_status
int getbtns(void);
int getsw(void);

// Functions from main_functions
int setup(void);
int update_status(void);
int on(unsigned int led);
int off(unsigned int led);
int play_sound(void);

// Functions from tone_changer
void change_tone(int* Button);
