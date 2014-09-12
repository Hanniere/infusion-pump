#include "msp430FG439.h"
#include "GLCD.h"
#include "display.h"
#include "INFUSION.h"
#include "TIME.h"
#include "math.h"

#define BUTTON1 BIT7
#define BUTTON2 BIT6
#define BUTTON3 BIT5
#define BUTTON4 BIT4
#define BUTTON5 BIT3

#define LED1 BIT2
#define LED2 BIT1
#define LED3 BIT0


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
	
	/*Configuracao dos pinos de saida do motor*/
	P4OUT = 0x00; // jogando sinal logico 0 em todos os pinos da porta 4
	P4DIR |= BIT0 + BIT1 + BIT2 + BIT3; //Da problema BIT0 E BIT1

	
	P3OUT = 0x00; // jogando sinal logico 0 em todos os pinos da porta 3
    
    // define pino do LED1 e LED2 e LED3 como saida
    //Os demais pinos da P3 sao entrada por default
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
    
    /*Configurando timer para iniciar a contagem de relogio*/
	configura_timerA();

}

void numero_superior(float num){
    
    unsigned short int inteiro = (unsigned short int )num;
    
    unsigned short int dezena = (unsigned short int)(num / 10);
    unsigned short int unidade = (unsigned short int)(inteiro % 10);   
    unsigned short int fracionaria = (unsigned short int)round((num - inteiro)*10);
    numero(dezena, 0);
    numero(unidade, 1);
    numero(fracionaria, 2);
  
}

void configure_basal(){
      units(1);
      hours(1);
      basal(1);
      float insulina_unit = 0.0;
      //escreve o valor 0.0 no segmento superior do display
      numero_superior(insulina_unit);
      
      while(1){
        //lembrar que esta havendo um delay      
        ativa_infusao();
        __delay_cycles(150000);
        
        if((P3IN & BUTTON2)==0){ // botao pressionado retorna falso, pois coloca o pino no terra
            P3OUT |= LED1; // ascende o LED1 enquanto o botao estiver pressionado
            
            if(insulina_unit > 0.0){
                insulina_unit = insulina_unit - 0.1;
                numero_superior(insulina_unit);
            }
            
            P3OUT &= ~LED1;
        }
        
         if((P3IN & BUTTON3)==0){
            
            P3OUT |= LED1; // ascende o LED1 enquanto o botao estiver pressionado
            
            if(insulina_unit <= 90.0){
                insulina_unit = insulina_unit + 0.1;
                numero_superior(insulina_unit);
            }
            
            P3OUT &= ~LED1;
         }
        
        //Confirma edicao da quantidade de unidades da infusao basal
        if((P3IN & BUTTON5)==0){
            
            /*inicializando perfil basal1 para simulacao em apenas uma hora*/
            conta_infusoes[0] = 0;
            /*9 unidades em uma hora, 0.1 a cada 4 segundos*/
            perfil_basal1[0] = insulina_unit;
            /*configura o perfil basal corrente na respectiva hora da bomba*/
            configura_hora_corrente(&perfil_basal1[0]);
           
            return ;
        }
	}  
}

void main(void) {
	inicializa();

    cout("1-234");
   
    
    // percent(1);

    

    while(1){
        //lembrar que esta havendo um delay para verificar se tem infusao basal
        ativa_infusao();

        //caso aperte o botao 2, configura infusao basal novamente     
        if((P3IN & BUTTON5) == 0){
            configure_basal();
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