#include "MOTOR.h"
#include <msp430fg439.h>
unsigned short int halfstep[8] = {0x08, 0x0c, 0x04, 0x06, 0x02, 0x03, 0x01, 0x09}; // Sequencia para meio passo



/*Gira o motor no sentido horario de acordo com a quantidade de steps definido*/
void half_pass_backward(const int *steps){
	int i = 0;
	
	for (i = 0; i < *steps; i++) {
        P4OUT = halfstep[i%8];
        __delay_cycles(ESPERA);
	}
	P4OUT = 0x00;
}

/*Gira o motor no sentido anti horario de acordo com a quantidade de steps definido*/
void half_pass_forward(const int *steps){
    int i = 0;
    
    for (i = *steps-1; i >= 0; i--) {
        P4OUT = halfstep[i%8];
        __delay_cycles(ESPERA);
    }
    P4OUT = 0x00;
}



/*Gira o motor no sentido horario aplicando as 8 sequencias do motor de uma vez
Deve-se dividir por 8 a quantidade de passos. 
Exemplo: 4096 (volta cheia)/8 = 512(volta cheia para essa funcao)*/
void giraHorarioSequenciaCheia(int steps){
	short int i = 0;
	int cont = 0;  
	while(cont < steps){
		for(i = 0;i < 8;i++){
			P4OUT = halfstep[i];
			__delay_cycles(ESPERA);
		}
		cont++;
	}
	P4OUT = 0x00;
}