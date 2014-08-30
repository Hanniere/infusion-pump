#include "TIME.h"
#include <msp430fg439.h>
#include "INFUSION.h"

volatile short int tick;
volatile short int segundos;
volatile short int minutos;
volatile short int horas;

void configura_timerA(void){
	
	CCTL0 = CCIE; // CCR0 interrupcao ativada
	CCR0 = 62499; //Valor final de contagem no registrador ccr0
	TACTL = TASSEL_2 + MC_1 + ID_3; // SMCLK, upmode 1Mhz/8
	_BIS_SR(GIE);  // Ativa as interrupções
	
}


// Timer A0 rotina de interrupção para contagem do tempo
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void){
	
	tick++;
	
	if(tick >= TICKS_PER_SECOND){
		segundos++;
		//verifica se deve ocorrer infusao
		verifica_infusao();
		tick = 0;
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
				configura_hora_corrente(&perfil_basal1[horas]);
				
			}
		}
	}
	P3OUT ^= BIT1; //pisca o led para indicar contagem dos segundos
}