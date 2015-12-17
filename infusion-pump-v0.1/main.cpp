#include "msp430FG437.h"
#include "MAIN.h"
#include "DISPLAY.h"
#include "GUI_FUNCTIONS.h"
#include "INFUSION.h"


volatile unsigned short button_1_pressed; // botão a esquerda
volatile unsigned short button_2_pressed; //botao acima
volatile unsigned short button_3_pressed; // botão a direita
volatile unsigned short button_4_pressed;


void initialize_active_basal_profile(){
    unsigned short i = 0;

    for(i = 0; i < DAY_HOURS; i++){
        active_basal_profile[i] = (float) 0.0;
    }
}


void configure_buttons(){
    
    // /*Configuracao do botao 1*/
    // P1IE |= BIT5; // P1.5 interrupt enabled
    // P1IFG &= ~BIT5; // P1.5 IFG cleared
    // P1IES &= ~BIT5; //low to hight
    // //P1IES |= BIT5; //high to low
    
    button_1_pressed = 0;
    button_2_pressed = 0;
    button_3_pressed = 0;
    button_4_pressed = 0;
    
    /*Configuracao do botao 2*/
    P1IE |= BUTTON2; // P1.5 interrupt enabled
    P1IFG &= ~BUTTON2; // P1.5 IFG cleared
    P1IES &= ~BUTTON2; //low to hight
    //P1IES |= BUTTON2; //high to low
    
    /*Configuracao do botao 3*/
    P2IE |= BUTTON3; // P2.4 interrupt enabled
    P2IFG &= ~BUTTON3; // P2.4 IFG cleared
    P2IES &= ~BUTTON3; //low to hight
    //P1IES |= BIT5; //high to low
    
    /*Configuracao do botao 4*/
    P2IE |= BUTTON4; // P2.3 interrupt enabled
    P2IFG &= ~BUTTON4; // P2.3 IFG cleared
    P2IES &= ~BUTTON4; //low to hight
    //P1IES |= BIT5; //high to low
    
    
    __enable_interrupt(); 
}


void initialize_system(){
    
    WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
    //FLL_CTL0 |= XCAP18PF;                 // Set load capacitance for xtal  
    configure_display();
    
    P1DIR = BIT6;//Pino 1.6 setado para saida
    P1OUT = BIT6;//Pino 1.6 setado para 1 (manter a placa ligada)
    //Pino 1.6 setado para entrada (Pinos sao de entrada por default)
    //P1DIR &= ~BIT6;
    configure_buttons();
    initialize_active_basal_profile();
    
    stop_symbol(1);
    battery_symbol(2);
    syringe_symbol(2);
    // bell(0);
    // clock(0);
    // hand(0);
    // bolus(0);
}


int main(void)
{
    initialize_system();
    write_lower_string("home");
       
    while(1){
        
        
        //caso aperte o botao 2, configura infusao basal     
        if(button_2_pressed){
           configure_ative_basal_profile();
           write_lower_string("home");
           
           //save_active_basal_profile();
           //WriteFlash(SEG_A, segmentA_memory, TAM_SEG);
            /*configura o perfil basal corrente na respectiva hora da bomba*/
           // configura_hora_corrente(&active_basal_profile[horas]);

           //__delay_cycles(150000);
        }
        //caso aperte o botao 4, configura infusao bolus 
        if(button_3_pressed){
           configure_bolus_infusion();
           write_lower_string("home");
           //save_active_basal_profile();
           //WriteFlash(SEG_A, segmentA_memory, TAM_SEG);
            /*configura o perfil basal corrente na respectiva hora da bomba*/
           // configura_hora_corrente(&active_basal_profile[horas]);

           //__delay_cycles(150000);
        }
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
}
//#pragma vector=WDT_VECTOR
//__interrupt void WDT_ISR(void)
//{
//  
//  SFRIFG1 &= ~WDTIFG;
//  SFRIE1 &= ~WDTIE;
//  WDTCTL = WDTPW + WDTHOLD;
//  P2IE |= (Which_ever_pin_interrupt_is_on);  
//}
