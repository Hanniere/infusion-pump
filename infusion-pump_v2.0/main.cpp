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
volatile unsigned short basal_active; // status da infusao basal


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
		if(active_basal_profile[i] < MIN_INSULINA || active_basal_profile[i] >= MAX_INSULINA){
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
        fracionario = (unsigned short)round(fabs(active_basal_profile[i] - trunc(active_basal_profile[i])) * 10);

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
    
    P1DIR = BIT6 + BIT7;//Pino 1.6 setado para saida(pino que mantem a placa ligada) e 1.7 (pino 1 do motor)
    P1OUT = BIT6;//Pino 1.6 setado para 1 (manter a placa ligada)
    P2DIR |= BIT0 + BIT1 + BIT2; //demais pinos do motor
    //Pino 1.6 setado para entrada (Pinos sao de entrada por default)
    //P1DIR &= ~BIT6;
    
    basal_active = 0;
    
    load_active_basal_profile();
    
    /*inicializando hora da bomba*/
    horas = 0;
    minutos = 0;
    segundos = 0;
    
    stop_symbol(!basal_active);
    battery_symbol(2);
    syringe_symbol(2);
    
    //comeca a contagem do tempo
    configura_timerA();
    configure_buttons();
    
    write_lower_string("home");
    
    put_cpu_to_sleep();
}


int main(void){
    
    initialize_system();
    unsigned int active_menu = MENU_HOME;//Home.
        
    while(1){
        
        //Botao 2 utilizado para navegar nas opcoes de menu disponiveis
        if(button_2_pressed){
            button_2_pressed = 0;
            active_menu = active_menu % 4;
            active_menu++;
            
            switch(active_menu){
                case MENU_BASAL:
                    write_lower_string("basal");
                    break;
                case MENU_BOLUS:
                    write_lower_string("bolus");
                    break;
                case MENU_TIME:
                    write_lower_string("time");
                    break;
                case MENU_HOME:
                    write_lower_string("home");
                    break;
            }
        }
        //caso aperte o botao 4, entra na opcao selecionada
        if(button_4_pressed){
            button_4_pressed = 0;
            
            switch(active_menu){
                case MENU_BASAL:
                    configure_ative_basal_profile();
                    save_active_basal_profile();
                    WriteFlash(SEG_A, segmentA_memory, TAM_SEG);
                    break;
                case MENU_BOLUS:
                    configure_bolus_infusion();
                    break;
                case MENU_TIME:
                    configure_system_time();
                    break;
            }
            write_lower_string("home");
        }
        //caso aperte o botao 3, inicializa ou paraliza a infusao basal
        if(button_3_pressed){
            button_3_pressed = 0;
            
            basal_active = !basal_active;
            stop_symbol(!basal_active);
        }
        put_cpu_to_sleep();
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