#include "msp430FG439.h"
#include "GLCD.h"
#include "display.h" 

void inicializa(){
	
	WDTCTL = WDTPW + WDTHOLD; // Parando watchdog timer
    FLL_CTL0 |= XCAP18PF; // Set load capacitance for xtal
	
	unsigned int j = 0;
	/*For para esperar a estabilização do clock*/
	for(j = 0;j < 50000;j++){ 
		_NOP();
	}
	
	/*Configuracao dos pinos de saida do motor*/
	P4OUT = 0x00; // jogando sinal logico 0 em todos os pinos
	P4DIR |= BIT0 + BIT1 + BIT2 + BIT3; //Da problema BIT0 E BIT1

	
	/*Configuracao para botao 1 simular infusao bolus */
	P3OUT = 0x00;
	P3DIR |= LED1 + LED2; // define pino do LED1 e LED2 como saida
	P3DIR &= ~BUTTON1; // define pino BUTTON1 como entrada
	
	
	/*inicializacao de variaveis de contagem do tempo*/
	tick = 0;
	contador_intervalo = 0;
	
	/*Flags de infusao basal e bolus*/
	flag_infusao_basal = 0;
	flag_infusao_bolus = 0;
	
	intervalo_seg_real = 0.0;
	intervalo_seg_inteiro = limite_intervalo = cont_inf_basal = 0;
	
	/*simulando as horas da bomba e consumo ate o momento*/
	horas = 0;
	minutos = 0;
	segundos = 0;
	qtde_infundida_hr = 0.0;
	qtde_infundida_total = 0.0;
	
	
	/*simulando quantidade de insulina configurada por um usuario em perfil bolus*/
	qtde_infusao_bolus = 0.1;
	
	short int i = 0;
	/*inicializando perfil basal1 para simulacao*/
	for(i = 0; i < QTDEPERFIS; i++){
		conta_infusoes[i] = 0;
		/*9 unidades em uma hora, 0.1 a cada 4 segundos*/
		perfil_basal1[i] = 90;
	}
	
	/*configura o perfil basal corrente na respectiva hora da bomba*/
	configura_hora_corrente(&perfil_basal1[horas]);

}

void main(void) {
	
    
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