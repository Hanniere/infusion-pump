#include <msp430FG439.h>
#include "INFUSION.h"
#include "TIME.h"
#include "MOTOR.h"
#include "DISPLAY.h"
#include "stdio.h"
#include <string.h>




int qtd_infusoes_hr;
float qtde_infundida_total;
float qtde_infundida_hr;
int conta_infusoes[DAY_HOURS];
unsigned int intervalo_inf_basal;
unsigned int contador_intervalo;

float active_basal_profile[DAY_HOURS];
short int flag_infusao_basal;
short int flag_infusao_bolus;
short int flag_reverse_engine;
float qtde_infusao_bolus;


//verifica se o contador de segundos chegou no intervalo que deve ocorrer a infusao
void verifica_infusao(){
	/*incrementa o contador que e utilizado pra infundir a insulina*/
	contador_intervalo++;
	/*caso tenha chegado no intervalo que deve ocorrer a infusao*/
	if(contador_intervalo == intervalo_inf_basal){
		conta_infusoes[horas]++;
		if(!qtde_infundida_hr >= active_basal_profile[horas]){
			flag_infusao_basal = 1;
		}
		contador_intervalo = 0;
	}
}

//funcao que e chamada em um loop infinito que aplica o perfil ativo corrente
void ativa_infusao() {
	
	float qtde_total_infusao = 0.0;
	/*caso deva ser infundido insulina em perfil basal*/
	if(flag_infusao_basal == 1){
		
		flag_infusao_basal = 0;
		qtde_total_infusao += QTDEMININFUSAO;
		
		/*atualizando quantidade de insulina infundida na hora corrente*/
		qtde_infundida_hr += QTDEMININFUSAO;

	}
	
	if(flag_infusao_bolus == 1){
		flag_infusao_bolus = 0;
		qtde_total_infusao += qtde_infusao_bolus;
	}
	
	if(qtde_total_infusao != 0.0){
		
		int passos = (int) (FATOR * qtde_total_infusao);
		half_pass_forward(&passos);
		qtde_infundida_total += qtde_total_infusao;
	}
    
    if(flag_reverse_engine == 1){
    
        int passos = (int) (FATOR * 0.1);
        half_pass_backward(&passos);
        flag_reverse_engine = 0;
    }
}

//funcao que configura o perfil basal ativo para as 24 horas do dia DAY_HOURS
void configure_active_basal_profile(){
      units(1);
      hours(1);
      basal(1);
      point(1);
      unsigned short i = 0;
      float insulina_unit = 0.0;
      
      
      for(i=0 ; i < DAY_HOURS; i++){
    
        insulina_unit = active_basal_profile[i];
        /*Escreve o valor no segmento superior salvo no vetor de profile*/
        upper_number_float(insulina_unit);
        
        char cBuffer[2] = {0};
        sprintf(cBuffer, "%d", i);

        cout((unsigned char*)strcat(cBuffer,"hr"));
        
        while(1){
            //lembrar que esta havendo um delay     
            ativa_infusao();
            
            __delay_cycles(150000);

            if((P3IN & BUTTON2)==0){ // botao pressionado retorna falso, pois coloca o pino no terra
                P3OUT |= LED1; // ascende o LED1 enquanto o botao estiver pressionado
                
                if(insulina_unit > 0.0){
                    insulina_unit = insulina_unit - 0.1;
                    upper_number_float(insulina_unit);
                }
                
                P3OUT &= ~LED1;
            }

             if((P3IN & BUTTON3)==0){
                
                P3OUT |= LED1; // ascende o LED1 enquanto o botao estiver pressionado
                
                if(insulina_unit <= 90.0){
                    insulina_unit = insulina_unit + 0.1;
                    upper_number_float(insulina_unit);
                }
                
                P3OUT &= ~LED1;
             }

            //Confirma edicao da quantidade de unidades da infusao basal para cada hora
            if((P3IN & BUTTON5)==0){
                
                /*inicializando perfil basal1 para simulacao em apenas uma hora*/
                conta_infusoes[i] = 0;
                
                /*9 unidades em uma hora, 0.1 a cada 4 segundos*/
                active_basal_profile[i] = insulina_unit;
        
                /*Sai do while*/
                break;
            }
        }
        
    }
    cout("home");
    units(0);
    hours(0);
    basal(0);
    point(0);
}

/*funcao que calcula os intervalos de aplicacao de insulina
de acordo com a quantidade minima da bomba e os segundos que faltam na hora
corrente*/
void configura_hora_corrente(const float* unidades){
	
    unsigned int intervalo_seg_inteiro;
    
	/*Statement separado por causa do acesso a duas variavels "volatile" no mesmo stament*/
    short int segundos_minuto = (60 - segundos);
    
    /*Calcula-se os segundos restantes da hora corrente*/
	int segundos_restantes = (60 - minutos)*60 + segundos_minuto;

	/*Quantidade que falta de insulina*/
	float insulina_restante_hr = *unidades - qtde_infundida_hr;

	/*Retorna numero de infusoes que devem ser feitas em uma hora
	exemplo: 3unidades/0.1 = 30 infusoes em uma hora.*/
	qtd_infusoes_hr = (int)(insulina_restante_hr/QTDEMININFUSAO);

	/*Pega parte inteira do intervalo ex: 7 */
	intervalo_seg_inteiro = (unsigned int)(segundos_restantes/qtd_infusoes_hr);

	/*Intervalo de infusao, comeca com o valor calculado*/
	intervalo_inf_basal = intervalo_seg_inteiro;

	/*zera contador de segundos para infusao*/
	contador_intervalo = 0;
	
}