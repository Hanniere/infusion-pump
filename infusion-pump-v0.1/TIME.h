/**************************************************************************************

	Funcoes para contagem e configuracao do tempo.
    

	time.cpp
	
	Autor: Hanniere de Faria Veloso dos Santos
	Data: julho, 2014


********************************************************************************************/
#ifndef _TIME_H_
#define _TIME_H_


/*--------------------DEFINICOES---------------------------*/
//Ticks que sao contados pelo contador do timerA ate 1 segundo
#define TICKS_PER_SECOND 2

//Velocidade do clock principal 1Mhz
#define MAIN_CLOCK 1000000


/*-------------------VARIAVEIS GLOBAIS-----------------------*/
extern volatile short int tick;
extern volatile short int segundos;
extern volatile short int minutos;
extern volatile short int horas;



void configura_timerA(void);

__interrupt void Timer_A (void);


#endif