#include <msp430FG439.h>

#define TAMANHO_FRASE 15
//superior
void numero(unsigned short numero, unsigned short pos);
void units(unsigned short mode);
void hours(unsigned short mode);
void percent(unsigned short mode);
void bolus(unsigned short mode);
void basal(unsigned short mode);
void point(unsigned short mode);
//inferior
void cout(char frase[TAMANHO_FRASE]);