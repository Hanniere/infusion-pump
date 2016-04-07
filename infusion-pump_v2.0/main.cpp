#include "msp430FG437.h"
#include "MAIN.h"
#include "DISPLAY.h"
#include "GUI_FUNCTIONS.h"
#include "INFUSION.h"
#include "MSP_FLASH.h"
#include "TIME.h"
#include "math.h"


volatile unsigned short button_1_pressed; // botão abaixo
volatile unsigned short button_2_pressed; //botao acima
volatile unsigned short button_3_pressed; // botão a esquerda
volatile unsigned short button_4_pressed; // botao a direita


void configure_buttons(){
    
    // /*Configuracao do botao 1*/
    // P1IE |= BUTTON1; // P1.5 interrupt enabled
    // P1IFG &= ~BUTTON1; // P1.5 IFG cleared
    // P1IES &= ~BUTTON1; //low to hight
    // //P1IES |= BUTTON1; //high to low
    
    button_1_pressed = 0;
    button_2_pressed = 0;
    button_3_pressed = 0;
    button_4_pressed = 0;
    
    /*Configuracao do botao 2*/
    P1IE |= BUTTON2; // P1.5 interrupt enabled
    P1IFG &= ~BUTTON2; // P1.5 IFG cleared
    //P1IES &= ~BUTTON2; //low to hight
    P1IES |= BUTTON2; //high to low
    
    /*Configuracao do botao 3*/
    P2IE |= BUTTON3; // P2.4 interrupt enabled
    P2IFG &= ~BUTTON3; // P2.4 IFG cleared
    //P2IES &= ~BUTTON3; //low to hight
    P2IES |= BUTTON3; //high to low
    
    /*Configuracao do botao 4*/
    P2IE |= BUTTON4; // P2.3 interrupt enabled
    P2IFG &= ~BUTTON4; // P2.3 IFG cleared
    //P2IES &= ~BUTTON4; //low to hight
    P2IES |= BUTTON4; //high to low
    
    
    //__enable_interrupt();
}


void load_active_basal_profile(){
        
    /*Le 128 bytes do segmento A e joga para o vetor que representa a memoria*/
    ReadFlash(SEG_A, segmentA_memory, TAM_SEG);
    
    unsigned short i = 0, data_error = 0;

    for(i = 0; i < DAY_HOURS; i++){
        active_basal_profile[i] =  (unsigned short)segmentA_memory[(i*2)] + (float)(segmentA_memory[(i*2)+1])/10;
        //verificando se algum valor nao obedece o range permitido
		if(active_basal_profile[i] <= MIN_INSULINA || active_basal_profile[i] >= MAX_INSULINA){
			data_error = 1;
        }
    }
	//caso tenha algum valor q nao obdeca ao range, configura a primeira vez q liga a placa e os valores precisam ser zerados
	if (data_error){
		for(i = 0; i < DAY_HOURS; i++){
			active_basal_profile[i] = 0.0;
		}
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
/*Essa funcao entra em no low power mode 3 com as interrupcoes globais ativadas*/
void put_cpu_to_sleep(){
    __bis_SR_register(LPM3_bits + GIE);
}

void initialize_system(){
    int i =0;
    WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
    
	FLL_CTL0 |= XCAP14PF;                     // Configure load caps
    for (i = 0; i < 10000; i++);              // Delay for 32 kHz crystal to stabilize
    
    do
    {
      IFG1 &= ~OFIFG;                         // Clear osc fault flag
      for (i = 0; i < 1000; i++);             // Delay for osc to stabilize
    } while(IFG1 & OFIFG);                    // Check to see if osc flag is set

    configure_display();
    
    P1DIR = BIT6;//Pino 1.6 setado para saida
    P1OUT = BIT6;//Pino 1.6 setado para 1 (manter a placa ligada)
    //Pino 1.6 setado para entrada (Pinos sao de entrada por default)
    //P1DIR &= ~BIT6;
 
    load_active_basal_profile();
    
    /*simulando as horas da bomba e consumo ate o momento*/
	horas = 0;
	minutos = 0;
	segundos = 0;
	
	stop_symbol(1);
    battery_symbol(2);
    syringe_symbol(2);
    
	//comeca a contagem do tempo
    configura_timerA();
	
	configure_buttons();
    
    write_lower_string("home");
    
    put_cpu_to_sleep();
    // bell(0);
    // clock(0);
    // hand(0);
    // bolus(0);
}


int main(void)
{
    initialize_system();
        
    while(1){
        
        //caso aperte o botao 2, configura infusao basal     
        if(button_2_pressed){
          //__disable_interrupt();
           configure_ative_basal_profile();
           write_lower_string("home");
           
           save_active_basal_profile();
           WriteFlash(SEG_A, segmentA_memory, TAM_SEG);
            /*configura o perfil basal corrente na respectiva hora da bomba*/
           // configura_hora_corrente(&active_basal_profile[horas]);

           //__delay_cycles(150000);
        }
        //caso aperte o botao 3, configura infusao bolus 
        if(button_3_pressed){
           configure_bolus_infusion();
           write_lower_string("home");

           //__delay_cycles(150000);
        }
        //caso aperte o botao 4, configura a hora da bomba (hora, minuto)
        if(button_4_pressed){
           configure_system_time();
           write_lower_string("home");
           
            /*configura o perfil basal corrente na respectiva hora da bomba*/
           // configura_hora_corrente(&active_basal_profile[horas]);

           //__delay_cycles(150000);
        }
		
		put_cpu_to_sleep();
//        if((P1IN & BIT5)){ //verificando se botao S1 (P1.5) esta apertado (Botao oposto ao s1)
//            P1OUT &= ~BIT6; //Desliga a placa
//        }
//        
//        if((P2IN & BIT3)){ //verificando se botao S2 (P1.3) esta apertado (Botao do lado esquerdo do S1)
//            P1OUT &= ~BIT6; //Desliga a placa
//        }
//        
//        if((P2IN & BIT4)){ //verificando se botao S2 (P2.4) esta apertado (Botao do lado direito do S1)
//            P1OUT &= ~BIT6; //Desliga a placa
//        }
//        
//        if((P1IN & BIT6)==0){ //verificando se botao S2 (P1.6) esta apertado (Mesmo botao q liga a placa) botao s1
//            P1OUT &= ~BIT6; //Desliga a placa
//        }
    }

}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void){
    
    if(P1IFG & BUTTON2) {
        button_2_pressed = 1;
        P1IFG &= ~BUTTON2; // P1.5 IFG cleared
    }
    //ativa CPU (sai do low power mode 3)
    __bic_SR_register_on_exit(LPM3_bits);
    //P1OUT &= ~BIT6; //Desliga a placa
    //qtde_infundida_hr += 0.1;
    //write_in_upper_digits(qtde_infundida_hr);
   // write_in_upper_digits(-1.0);
    
    
    
//    P1IE &= ~BIT5;// Temporarily disable the interrupt
//    //WDT as 250ms interval counter
//    SFRIFG1 &= ~WDTIFG;
//    WDTCTL = WDTPW + WDTSSEL_1 + WDTTMSEL + WDTCNTCL + WDTIS_5;
//    SFRIE1 |= WDTIE;
//  
//    //Exits ISR, returns to active mode to execute code servicing the button press
//    __bic_SR_register_on_exit(LPM3_bits);
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void){
    
    if(P2IFG & BUTTON3) {
        button_3_pressed = 1;
        P2IFG &= ~BUTTON3; // P2.4IFG cleared
    }
    if(P2IFG & BUTTON4) {
        button_4_pressed = 1;
        P2IFG &= ~BUTTON4; // P2.3IFG cleared
    }
	//ativa CPU (sai do low power mode 3)
	__bic_SR_register_on_exit(LPM3_bits);
}

//Verificar se algum botao continua ainda pressionado (Button debouncer)
//#pragma vector=WDT_VECTOR
//__interrupt void WDT_ISR(void)
//{
//  
//  SFRIFG1 &= ~WDTIFG;
//  SFRIE1 &= ~WDTIE;
//  WDTCTL = WDTPW + WDTHOLD;
//  P2IE |= (Which_ever_pin_interrupt_is_on);  
//}