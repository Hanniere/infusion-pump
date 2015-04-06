#include "MOTOR.h"
#include <msp430fg439.h>

unsigned short int halfstep[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09};//Sequencia para meio passo
unsigned short int halfstep_p5[8] = {0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x09}; // Sequencia para meio passo P5
unsigned short int halfstep_p4[8] = {0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0x40, 0x40}; // Sequencia para meio passo P4
unsigned short int halfstep_antihorario[8] = {0x08, 0x0c, 0x04, 0x06, 0x02, 0x03, 0x01, 0x09}; // 
unsigned short int halfstep_p5_antihorario[8] = {0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x02};
unsigned short int halfstep_p4_antihorario[8] = {0x40, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x40};
//ANTIGOOOOO


/*Gira o motor no sentido horario de acordo com a quantidade de steps definido*/
void half_pass_backward(const int *steps){
	int i = 0;
	for (i = 0; i < *steps; i++) {
        P5OUT = halfstep_p5_antihorario[i];
        P4OUT = halfstep_p4_antihorario[i];
        __delay_cycles(ESPERA);
	}
	P4OUT = 0x00;
    P5OUT = 0x00;
}

/*Gira o motor no sentido anti horario de acordo com a quantidade de steps definido*/
void half_pass_forward(const int *steps){
    int i = 0;
    for (i = *steps-1; i >= 0; i--) {
        P5OUT = ~halfstep_p5[i];
        P4OUT = ~halfstep_p4[i];
        __delay_cycles(ESPERA);
    }
    P4OUT = 0x00;
    P5OUT = 0x00;
}

/*Gira o motor no sentido horario aplicando as 8 sequencias do motor de uma vez
Deve-se dividir por 8 a quantidade de passos. 
Exemplo: 4096 (volta cheia)/8 = 512(volta cheia para essa funcao)*/

void giraAntiSequenciaCheia(long int steps){
    long int cycles = steps/8;
    short int i = 0;
	long int cont = 0;  
	while(cont < cycles){
		for(i = 0;i < 8;i++){
            P5OUT = halfstep_p5_antihorario[i];
            P4OUT = halfstep_p4_antihorario[i];
			__delay_cycles(ESPERA);
		}
        cont++;
	}
	P4OUT = 0x00;
    P5OUT = 0x00;
}

void giraHorarioSequenciaCheia(long int steps){
    long int cycles = steps/8;
    short int i = 0;
	long int cont = 0;  
	while(cont < cycles){
		for(i = 0;i < 8;i++){
			P5OUT = ~halfstep_p5[i];
            P4OUT = ~halfstep_p4[i];
			__delay_cycles(ESPERA);
		}        
        cont++;
	}
	P4OUT = 0x00;
    P5OUT = 0x00;
}