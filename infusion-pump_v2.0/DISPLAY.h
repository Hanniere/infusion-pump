/**************************************************************************************

	Funcoes para utilizar o display glcd da placa.

    display.c
	
	Autor: Hanniere de Faria Veloso dos Santos
	Data: novembro, 2015


********************************************************************************************/


#define TAMANHO_FRASE 5
#define TYPE_INTERVAL 1
#define TYPE_HOUR 2
#define SYMBOL_ON 1
#define SYMBOL_OFF 0
#define CLEAN_UPPER_DISPLAY -1.0

//symbols
void clock_symbol(unsigned short int mode);
void syringe_symbol(unsigned short int digit);
void battery_symbol(unsigned short int digit);
void stop_symbol(unsigned short int mode);
void bell_symbol(unsigned short int mode);
void hand_symbol(unsigned short int mode);
void bolus_symbol(unsigned short int mode);
void basal_symbol(unsigned short int mode);
void unit_symbol(unsigned short int digit);
void h_symbol(unsigned short int digit);
void percentage_symbol(unsigned short int digit);


//displays
void write_lower_string(unsigned char phrase[TAMANHO_FRASE]);
void write_in_upper_digits(float num);
void write_hours(unsigned short hour1, unsigned short hour2, unsigned short type);


//configure display
void configure_display();