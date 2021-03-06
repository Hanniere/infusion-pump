#include <msp430FG439.h>
#include "INFUSION.h"
#include "TIME.h"
#include "MAIN.h"
#include <math.h>




int qtd_infusoes_hr;
short contador_intervalo;
float qtde_infundida_total;
float qtde_infundida_hr;
int conta_infusoes[DAY_HOURS];
float intervalo_seg_real;
int intervalo_seg_inteiro;
short limite_intervalo;
volatile short intervalo_inf_basal;
short cont_inf_basal;

float active_basal_profile[DAY_HOURS];
short int flag_infusao_basal;
short int flag_infusao_bolus;
short int flag_reverse_engine;
float qtde_infusao_bolus;


// //verifica se o contador de segundos chegou no intervalo que deve ocorrer a infusao
// void verifica_infusao(){
	// /*incrementa o contador que e utilizado pra infundir a insulina*/
	// contador_intervalo++;
	// /*caso tenha chegado no intervalo que deve ocorrer a infusao*/
	// if(contador_intervalo == intervalo_inf_basal){
		// cont_inf_basal++;
		// conta_infusoes[horas]++;
		// flag_infusao_basal = 1;
		// contador_intervalo = 0;
	// }
// }

// //funcao que e chamada em um loop infinito que aplica o perfil ativo corrente
// void ativa_infusao() {
	
	// float qtde_total_infusao = 0.0;
	// /*caso deva ser infundido insulina em perfil basal*/
	// if(flag_infusao_basal == 1){
		
		// flag_infusao_basal = 0;
		// qtde_total_infusao += QTDEMININFUSAO;
		
		// /*atualizando quantidade de insulina infundida na hora corrente*/
		// qtde_infundida_hr += QTDEMININFUSAO;

		// /*Caso o numero de vezes infundido, tenha atingido limite_intervalo*/
		// if((cont_inf_basal == limite_intervalo) && limite_intervalo != 0){
			// cont_inf_basal = -1;
			// intervalo_inf_basal = intervalo_seg_inteiro + 1;
		// }
		// else intervalo_inf_basal = intervalo_seg_inteiro;
	// }
	
	// if(flag_infusao_bolus == 1){
		// flag_infusao_bolus = 0;
		// qtde_total_infusao += qtde_infusao_bolus;
	// }
	
	// if(qtde_total_infusao != 0.0){
		
		// int passos = (int) (FATOR * qtde_total_infusao);
		// half_pass_forward(&passos);
		// qtde_infundida_total += qtde_total_infusao;
	// }
    
    // if(flag_reverse_engine == 1){
    
        // int passos = (int) (FATOR * 0.1);
        // half_pass_backward(&passos);
        // flag_reverse_engine = 0;
    // }
// }


///*funcao que calcula os intervalos de aplicacao de insulina
//de acordo com a quantidade minima da bomba e os segundos que faltam na hora
//corrente*/
//void configura_hora_corrente(const float* unidades){
//	
//	/*Calcula-se os segundos restantes da hora corrente*/
//	int segundos_restantes = (60 - minutos)*60;
//	
//	/*Quantidade que falta de insulina*/
//	float insulina_restante_hr = *unidades - qtde_infundida_hr;
//	
//	/*Retorna numero de infusoes que devem ser feitas em uma hora
//	exemplo: 3unidades/0.1 = 30 infusoes em uma hora.*/
//	qtd_infusoes_hr = (int)(insulina_restante_hr/QTDEMININFUSAO);
//	
//	/*intervalo em segundos que faltam na hora corrente para aplicacao da 
//	qtde minima de infusao ex: 7.2s*/
//	intervalo_seg_real = (float)segundos_restantes/qtd_infusoes_hr;
//
//	/*Pega parte inteira do intervalo ex: 7 */
//	intervalo_seg_inteiro = (int)intervalo_seg_real;
//
//	/*Pega parte fracionaria do intervalo ex: 0.2*/
//	float decimo_intervalo = (float)intervalo_seg_real-intervalo_seg_inteiro;
//
//	/*Obtem a quantidade de vezes para se trocar o valor do intervalo_inf_basal alternadamente*/
//	if(decimo_intervalo > 0.0){
//		limite_intervalo = (int)round(1 / decimo_intervalo);
//	}
//	else{
//		limite_intervalo = 0;
//	}
//
//	/*Intervalo de infusao, comeca com o valor calculado*/
//	intervalo_inf_basal = intervalo_seg_inteiro;
//
//	/*zera contador de segundos para infusao*/
//	contador_intervalo = 0;
//	
//}