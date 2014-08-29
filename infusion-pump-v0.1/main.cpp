#include "msp430FG439.h"
#include "GLCD.h"
#include "display.h" 

double profiles[5][25];

void main(void) {
	WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer to prevent time out reset
	FLL_CTL0 |= XCAP18PF; // Set load capacitance for xtal
    
    glcd_turn_on();
    
	glcd_fill(0);
    
    cout("teste");
    numero(2, 0);
    numero(3, 1);
    numero(4, 2);
    point(1);
    units(1);
    hours(1);
    percent(1);
    bolus(1);
    basal(1);
 
    
}