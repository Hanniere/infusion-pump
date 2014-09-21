#include "MSP_FLASH.h"
#include <msp430FG439.h>
#include <string.h>

unsigned char segmentA_memory[TAM_SEG];

void WriteFlash(unsigned int segment, unsigned char *value, unsigned char lenght)
{
  char * Flash_ptr;                         // Declara ponteiro para acesso a memoria
  Flash_ptr = (char *) segment;              // Inicializa o ponteiro no endereco do segmento desejado (datasheet)
  
  __disable_interrupt();                    // Desabilita interrupcoes enquanto
                                            // a memoria e apagada
                                            // 
  while (FCTL3 & BUSY);
  FCTL3 = FWKEY;                            // Limpa bit de protecao
  FCTL1 = FWKEY+ERASE;                      // Seta bit para apagar
  *(unsigned int *)Flash_ptr = 0;           // Escreve zero para apagar 
  FCTL1 = FWKEY+WRT;                        // Seta bit WRT para operacao de escrita

  
  memcpy(Flash_ptr,value,lenght);           // realiza copia dos dados do vetor a ser gravado para a memoria flash

  FCTL1 = FWKEY;                            // Limpa bit WRT
  FCTL3 = FWKEY+LOCK;                       // Seta bit de protecao
  
  __enable_interrupt();                     // Reabilita interrupcoes se necessario

}

void ReadFlash(unsigned int segment, unsigned char *ptr, unsigned char lenght)
{
  
  unsigned char *Flash_ptrC;                    // Declara ponteiro para acesso a memoria
  Flash_ptrC = (unsigned char *) segment;       // Inicializa o ponteiro no endereco do segmento desejado (datasheet)
  
  __disable_interrupt();                        // desabilita interrupcoes durante processo de leitura
  
  memcpy(ptr,Flash_ptrC,lenght);                // copia para o vetor destino os valores da memoria flash
  
  __enable_interrupt();                         //habilita interrupcoes se necessario
  
}