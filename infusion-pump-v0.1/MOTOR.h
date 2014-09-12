#ifndef MOTOR_INCLUDED
#define MOTOR_INCLUDED

/*Velocidade do motor de passo, espera 900 ciclos da CPU para executar a proxima instrução*/
#define ESPERA 900

/*Qtde de steps por grau*/
#define STEPSPORGRAU 11.4

/*INFORMACOES UTEIS*/
/* Cada step gira 0,08789 grau
 *  ou 11.377 steps de uma vez com 1 grau aproximadamente
 *  4096 passos pra uma volta completa
 */
extern unsigned short int halfstep[8] ; // Sequencia para meio passo
//extern unsigned int fullstep[8] = {0x09, 0x0c, 0x06, 0x03, 0x09, 0x0c, 0x06, 0x03}; // Sequencia para full step
//extern unsigned int fullstepwave[8] = {0x08, 0x04, 0x02, 0x01, 0x08, 0x04, 0x02, 0x01}; // Sequencia para full step wave

void half_pass_backward(const int*);
void half_pass_forward(const int*);

void giraHorarioSequenciaCheia(int);

#endif // MOTOR_INCLUDED