/**************************************************************************************

	Funcoes para que calculam intervalo de infusao e ativa infusoes basal
    e bolus se necessario.

	infusion.cpp
	
	Autor: Hanniere de Faria Veloso dos Santos
	Data: julho, 2014


********************************************************************************************/
#ifndef INFUSAO_INCLUDED
#define INFUSAO_INCLUDED


/*Definicao da quantidade minima de infusao da bomba*/
#define QTDEMININFUSAO 0.1

/*Quantidade minima de insulina em uma hora*/
#define MIN_INSULINA 0.0

/*Quantidade maxima de insulina em uma hora*/
#define MAX_INSULINA 90.0

/*Qtde de graus que o motor precisa girar por qtde minima de infusao (isso deve ser calculado)*/
#define GRAUMINIMO 90

/*Tamanho do vetor de perfil*/
#define DAY_HOURS 24

/*Fator de multiplicacao para calculo do numero de passos de acordo com unidades a serem infundidas*/
#define FATOR (STEPSPORGRAU * GRAUMINIMO) / QTDEMININFUSAO


/*numeros de infusoes minimas na respectiva hora.
ex: 900 infusoes de 0.1 unidades ao longo de uma hora*/
extern int qtd_infusoes_hr;

/*intervalo real em segundos para infusao minima de insulina*
ex: a cada 200 segundos, aplica-se 0.1 unidades*/
extern float intervalo_seg_real;

/*Variavel que auxilia na distribuicao de insulina ao longo de uma hora
  esta variavel */
extern int intervalo_seg_inteiro;

/*Segundos de uma hora, conta ate o intervalo de infusao. Intervalo maximo � 127 segundos*/
extern short contador_intervalo;

/*Intervalo em segundos que deve-se somar 1 ao intervalo_inf_basal*/
extern short limite_intervalo;

/*Intervalo que o contador_intervalo deve chegar antes de infundir*/
extern volatile short intervalo_inf_basal;

/*Contador auxiliar do numero de infusao basal, este contador e utilizando
para contar ate o limite_intervalo e assim soma-se 1s ao intervalo_inf_basal e 
assim sucessivamente*/
extern short cont_inf_basal;

/*Qtde insulina ja infundida ao todo*/
extern float qtde_infundida_total;

/*Qtde insulina no modo basal ja infundida na hora corrente*/
extern float qtde_infundida_hr;

/*Perfil de utilizacao basal 1, cada posicao representa uma hora do dia*/
/* Vetor responsavel por armazenar as quantidades em unidades para determinada hora*/
extern float active_basal_profile[DAY_HOURS];

/*Conta quantidade de infusao minima do perfil basal para cada hora*/
extern int conta_infusoes[DAY_HOURS];

/*0 caso nao deva ocorrer infusao, 1 caso deva ocorrer*/
extern short int flag_infusao_basal;
/*0 caso nao deva ocorrer infusao, 1 caso deva ocorrer*/
extern short int flag_infusao_bolus;
/*Quantidade de infusao bolus setada pelo usuario*/
extern float qtde_infusao_bolus;

extern short int flag_reverse_engine;

void ativa_infusao();

void configura_hora_corrente(const float*);


#endif // INFUSAO_INCLUDED