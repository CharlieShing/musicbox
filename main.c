
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */

int main(void) {
	TRISE &= ~0xf;
	
	TRISF |= 0x2;
	while(1){
		PORTE = (PORTF >> 1) & 0x1;			
	}
}