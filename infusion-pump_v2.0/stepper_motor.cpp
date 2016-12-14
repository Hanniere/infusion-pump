#include "STEPPER_MOTOR.h"
#include <msp430fg437.h>


void one_step(const unsigned short int *pos){

    switch(*pos){
        case 0:
            P2OUT &= ~FIO_2; //desligando fio 2
            
            P1OUT |= FIO_1;
            P2OUT |= FIO_4;
        break;

        case 1:
            P2OUT &= ~FIO_4;//desligando fio 4
            
            P1OUT |= FIO_1;
            P2OUT |= FIO_3;
        break;
        case 2:
            P1OUT &= ~FIO_1; //desligando fio 1
                            
            P2OUT |= FIO_2 + FIO_3;
        break;
        case 3:
            P2OUT &= ~FIO_3; //desligando fio 3
            
            P2OUT |= FIO_2 + FIO_4;
        break;        
    }
  
}

void activate_motor(const int *steps){
	
    unsigned short int i = 0;
	int cont = 0;
	
	while(cont < *steps){
		one_step(&i);
		__delay_cycles(MOTOR_DELAY);
		i = (i+1)%4;
		cont++;
	}
    
    //desligando pinos
	P1OUT &= ~FIO_1;
    P2OUT &= ~FIO_2 & ~FIO_3 & ~FIO_4;
        
}