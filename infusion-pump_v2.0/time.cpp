#include "TIME.h"
#include <msp430fg437.h>
#include "INFUSION.h"
#include "DISPLAY.h"


volatile unsigned short int segundos;
volatile unsigned short int minutos;
volatile unsigned short int horas;
unsigned short int clock_state = 0;

void configura_timerA(void){
	
	CCTL0 = CCIE; // CCR0 interrupcao ativada
	CCR0 = 8191; //Valor final de contagem no registrador ccr0
	TACTL = TASSEL_1 + MC_1 + ID_2; // ACLK, upmode 32khz/4
    //_BIS_SR(GIE);  // Ativa as interrupções
	
}


// Timer A0 rotina de interrupção para contagem do tempo
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void){
	

	segundos++;
	//verifica se deve ocorrer infusao
	//verifica_infusao();

	if (segundos > 59) {
		segundos = 0;
		minutos++;
		if (minutos > 59) {
			minutos = 0;
			horas++;

			if (horas > 23) {
				horas = 0;
			}
			qtde_infundida_hr = 0.0;
			//configura perfil de infusao da hr corrente
			//configura_hora_corrente(&active_basal_profile[horas]);
		}
	}
	
	if(clock_state==0){
		clock_state = 1;
	}
	else{
		clock_state = 0;
	}
	clock_symbol(clock_state);

}