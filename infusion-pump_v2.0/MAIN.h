/**************************************************************************************

	Header do main do sistema.

	main.c
	
	Autor: Hanniere de Faria Veloso dos Santos
	Data: novembro, 2015


********************************************************************************************/

#define BUTTON3 BIT4
#define BUTTON4 BIT3
#define BUTTON2 BIT5
#define BUTTON1 BIT6

/*Intervalo que o contador_intervalo deve chegar antes de infundir*/
extern volatile unsigned short button_3_pressed; // flag botão a esquerda
extern volatile unsigned short button_2_pressed; // flag botao acima
extern volatile unsigned short button_4_pressed; // flag botao a direita

