/**************************************************************************************

	Funcoes para utilizar o display glcd da placa.

	lower_segment.cpp
    upper_segment.cpp
	
	Autor: Hanniere de Faria Veloso dos Santos
	Data: agosto, 2014


********************************************************************************************/

#define TAMANHO_FRASE 15

//superior
void upper_number_float(float num);
void numero(unsigned short numero, unsigned short pos);
void units(unsigned short mode);
void hours(unsigned short mode);
void percent(unsigned short mode);
void bolus(unsigned short mode);
void basal(unsigned short mode);
void point(unsigned short mode);
//inferior
void cout(unsigned char frase[TAMANHO_FRASE]);
//simbolos de suporte - posiçao: inferior
void battery(float percent);//representa a quantidade de carga da bateria
void syringe(unsigned short int mode);//precisa mudar! funcionará como a bateria
void stop(unsigned short int mode);
void arrow(unsigned short int mode);
void clock(unsigned short int mode);
void bell(unsigned short int mode);