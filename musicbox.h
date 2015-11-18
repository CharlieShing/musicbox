/* musicbox.h
Header file for all files included in musicbox project
*/

/* Declare helper functions from help_meth.c*/
int getbtns(void);
int getsw(void);

/* Declare main functions from musicbox.c*/
int main(void);
int setup(void);
int update_status(void);
int on(unsigned int led);
int off(unsigned int led);
int play_sound(void);
int wave(void);