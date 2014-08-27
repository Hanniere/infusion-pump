#include "msp430FG439.h"
#include "GLCD.h"

double profiles[5][25];

void main(void) {
	WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer to prevent time out reset
	FLL_CTL0 |= XCAP18PF; // Set load capacitance for xtal
        
    glcd_turn_on();
	glcd_fill(0);
    
}