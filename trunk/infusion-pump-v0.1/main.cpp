#include "msp430FG439.h"
#include "GLCD.h"
#include "DISPLAY.h"
#include "INFUSION.h"
#include "TIME.h"
#include "MSP_FLASH.h"
#include "math.h"


void save_active_basal_profile();
void load_active_basal_profile();

void inicializa(){
	
	WDTCTL = WDTPW + WDTHOLD; // Parando watchdog timer
    FLL_CTL0 |= XCAP18PF; // Set load capacitance for xtal
	
	unsigned int j = 0;
	/*For para esperar a estabilização do clock*/
	for(j = 0;j < 50000;j++){ 
		_NOP();
	}
    /*Inicializacao do GLCD*/
    glcd_turn_on();
	glcd_fill(0);
    point(1);
	upper_number_float(0);
    
	/*Configuracao dos pinos de saida do motor*/
	P4OUT = 0x00; // jogando sinal logico 0 em todos os pinos da porta 4
	P4DIR |= BIT0 + BIT1 + BIT2 + BIT3; //Da problema BIT0 E BIT1

	
	P3OUT = 0x00; // jogando sinal logico 0 em todos os pinos da porta 3
    
    /*define pino do LED1 e LED2 e LED3 como saida
    Os demais pinos da P3 sao entrada por default*/
	P3DIR |= LED1 + LED2 + LED3;

	/*inicializacao de variaveis de contagem do tempo*/
	tick = 0;
	contador_intervalo = 0;
	
	/*Flags de infusao basal e bolus*/
	flag_infusao_basal = 0;
	flag_infusao_bolus = 0;
    flag_reverse_engine = 0;
	
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
    
    /*Le 128 bytes do segmento A e joga para o vetor que representa a memoria*/
    ReadFlash(SEG_A, segmentA_memory, TAM_SEG);
    
    /*Inicializando vetor do perfil basal ativo*/
    unsigned short i = 0;
    for(i = 0; i < DAY_HOURS; i++){
        active_basal_profile[i] = 0.0;
    }
    
    /*Carrega para o vetor de perfil basal ativo os valores do vetor que representa a memoria*/
    load_active_basal_profile();
    

    /*Configurando timer para iniciar a contagem de relogio*/
	configura_timerA();

}

void load_active_basal_profile(){
    unsigned short i = 0;

    for(i = 0; i < DAY_HOURS; i++){
        active_basal_profile[i] =  (unsigned short)segmentA_memory[(i*2)] + (float)(segmentA_memory[(i*2)+1])/10;
    }
}

void save_active_basal_profile(){

    unsigned short i = 0;
    unsigned short inteiro = 0;
    unsigned short fracionario = 0;

    for(i = 0; i < DAY_HOURS; i++){
        inteiro = (unsigned short)active_basal_profile[i];
        fracionario = (unsigned short)round((active_basal_profile[i] - inteiro) * 10);

        segmentA_memory[(i*2)] =  (char)inteiro;
        segmentA_memory[(i*2)+1] = (char)fracionario;
    }

}

void main(void) {
    inicializa();
    //percent(1);

   while(1){
       //lembrar que esta havendo um delay para verificar se tem infusao basal
       //ativa_infusao();

       //caso aperte o botao 2, configura infusao basal novamente     
       if((P3IN & BUTTON5) == 0){
           configure_ative_basal_profile();
           save_active_basal_profile();
           WriteFlash(SEG_A, segmentA_memory, TAM_SEG);
            /*configura o perfil basal corrente na respectiva hora da bomba*/
           // configura_hora_corrente(&active_basal_profile[horas]);
           units(0);
           hours(0);
           basal(0);
           __delay_cycles(150000);
       }
       
       //Botao para voltar o motor
       if((P3IN & BUTTON2) == 0){
           flag_reverse_engine = 1;        
       }

       //caso aperte o botao 5 simula infusao bolus
       if((P3IN & BUTTON3) == 0){ // se BUTTON5 estiver pressionado retorna falso pelo resistor de pull-up externo da placa
         P3OUT |= LED1; // ascende o LED1 enquanto o botao estiver pressionada
         flag_infusao_bolus = 1;
         bolus(1);
       }
       else{  // botao solto retorna verdadeiro, pois coloca liga novamente o pino
         P3OUT &= ~LED1; // LED1 apagado
         bolus(0);
       }
   }
 
    
}