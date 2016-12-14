/**************************************************************************************

	Header do

	main.c
	
	Autor: Hanniere de Faria Veloso dos Santos
	Data: novembro, 2015


********************************************************************************************/

#ifndef STEPPER_MOTOR_INCLUDED
#define STEPPER_MOTOR_INCLUDED

/*Velocidade do motor de passo, espera 900 ciclos da CPU para executar a proxima instrução*/
#define MOTOR_DELAY 500000

//mapeamento dos pinos do motor
#define FIO_1 BIT7
#define FIO_2 BIT0
#define FIO_3 BIT1
#define FIO_4 BIT2



void activate_motor(const int*);

#endif // STEPPER_MOTOR_INCLUDED