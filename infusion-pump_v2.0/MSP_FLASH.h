/**************************************************************************************

	Funcoes para leitura e escrita de dados na memoria do MSP430FG439

	msp_flash.cpp
	
	Autor: Hanniere de Faria Veloso dos Santos
	Data: setembro, 2014


********************************************************************************************/

//Definição de segmentos, nesse caso segmento A e B do MSP430FG439
#define SEG_A 0x1080
#define SEG_B 0x1000
#define TAM_SEG 128



/*
 *Vetor de char que representa o segmento A da memoria flash
 *deve-se sempre atualiza-lo e salva-lo inteiro na memoria flash
 */
extern unsigned char segmentA_memory[TAM_SEG];


/*******************************************************************************
* Descricao: funcao para gravar dados na memoria Flash
* Parametros: segment --> endereco do segmento a ser gravado
*             value --> ponteiro para valores a serem gravados
*             lenght --> numero de bytes a serem gravados
*
*******************************************************************************/
void WriteFlash(unsigned int segment, unsigned char *value, unsigned char lenght);

/*******************************************************************************
* Descricao: funcao para leitura de dados da memoria Flash
* Parametros: segment --> endereco do segmento a ser lido
*             value --> ponteiro onde sera retornado valores lidos
*             lenght --> numero de bytes a serem lidos
*
*******************************************************************************/
void ReadFlash(unsigned int segment, unsigned char *ptr, unsigned char lenght);
