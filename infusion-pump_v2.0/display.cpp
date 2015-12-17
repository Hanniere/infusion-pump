#include "DISPLAY.h"
#include "msp430FG437.h"
#include <math.h>
#include <stdio.h>

//Essa struct e utilizada para mapeamento de cada letra dos 5 displays de 11 segmentos
struct lower_position_struct
{    
    unsigned short position; //posicao do MEM_LCD correspondente
    unsigned short bit;        //Bit a ser setado correspondente
};
 

//Essa funcao mapeia os numeros dos digitos superiores, todos os tres digitos utilizam o mesmo mapeamento.
char number_gen_upper_segment (unsigned short num){
    
    unsigned int a = BIT7;
    unsigned int b = BIT6;
    unsigned int c = BIT5;
    unsigned int d = BIT0;
    unsigned int e = BIT1;
    unsigned int f = BIT3;
    unsigned int g = BIT2;
    
    char number_gen[] = {
      
        a+b+c+d+e+f,                          // Displays "0"
        b+c,                                  // Displays "1"
        a+b+d+e+g,                            // Displays "2"
        a+b+c+d+g,                            // Displays "3"
        b+c+f+g,                              // Displays "4"
        a+c+d+f+g,                            // Displays "5"
        a+c+d+e+f+g,                          // Displays "6"
        a+b+c,                                // Displays "7"
        a+b+c+d+e+f+g,                        // Displays "8"
        a+b+c+d+f+g,                          // Displays "9"
        ~a&~b&~c&~d&~e&~f&~g                  //all bits to zero
    };
    
    return number_gen[num];
}


//Essa funcao mapeia os segmentos dos digito 4 (digito inferior).
struct lower_position_struct map_digit4_lower_segment (unsigned short char_position){
    
    struct lower_position_struct digit4[11];
    
    //A
    digit4[0].position = 4;
    digit4[0].bit = BIT0;
    //B
    digit4[1].position = 4;
    digit4[1].bit = BIT1;
    //C
    digit4[2].position = 4;
    digit4[2].bit = BIT2;
    //D
    digit4[3].position = 4;
    digit4[3].bit = BIT7;
    //E
    digit4[4].position = 5;
    digit4[4].bit = BIT2;
    //F
    digit4[5].position = 5;
    digit4[5].bit = BIT1;
    //G
    digit4[6].position = 4;
    digit4[6].bit = BIT5;
    //H
    digit4[7].position = 5;
    digit4[7].bit = BIT0;
    //I
    digit4[8].position = 4;
    digit4[8].bit = BIT4;
    //J
    digit4[9].position = 4;
    digit4[9].bit = BIT3;
    //K
    digit4[10].position = 4;
    digit4[10].bit = BIT6;  
    
    return digit4[char_position];
}

//Essa funcao mapeia os segmentos dos digito 5 (digito inferior).
struct lower_position_struct map_digit5_lower_segment (unsigned short char_position){
    
    struct lower_position_struct digit4[11];
    
    //A
    digit4[0].position = 5;
    digit4[0].bit = BIT4;
    //B
    digit4[1].position = 5;
    digit4[1].bit = BIT5;
    //C
    digit4[2].position = 5;
    digit4[2].bit = BIT6;
    //D
    digit4[3].position = 6;
    digit4[3].bit = BIT3;
    //E
    digit4[4].position = 6;
    digit4[4].bit = BIT6;
    //F
    digit4[5].position = 6;
    digit4[5].bit = BIT5;
    //G
    digit4[6].position = 6;
    digit4[6].bit = BIT1;
    //H
    digit4[7].position = 6;
    digit4[7].bit = BIT4;
    //I
    digit4[8].position = 6;
    digit4[8].bit = BIT0;
    //J
    digit4[9].position = 5;
    digit4[9].bit = BIT7;
    //K
    digit4[10].position = 6;
    digit4[10].bit = BIT2;  
    
    return digit4[char_position];
}

//Essa funcao mapeia os segmentos dos digito 6 (digito inferior).
struct lower_position_struct map_digit6_lower_segment (unsigned short char_position){
    
    struct lower_position_struct digit6[11];
    
    //A
    digit6[0].position = 7;
    digit6[0].bit = BIT0;
    //B
    digit6[1].position = 7;
    digit6[1].bit = BIT1;
    //C
    digit6[2].position = 7;
    digit6[2].bit = BIT2;
    //D
    digit6[3].position = 8;
    digit6[3].bit = BIT3;
    //E
    digit6[4].position = 8;
    digit6[4].bit = BIT6;
    //F
    digit6[5].position = 8;
    digit6[5].bit = BIT5;
    //G
    digit6[6].position = 8;
    digit6[6].bit = BIT1;
    //H
    digit6[7].position = 8;
    digit6[7].bit = BIT4;
    //I
    digit6[8].position = 8;
    digit6[8].bit = BIT0;
    //J
    digit6[9].position = 7;
    digit6[9].bit = BIT3;
    //K
    digit6[10].position = 8;
    digit6[10].bit = BIT2;  
    
    return digit6[char_position];
}


//Essa funcao mapeia os segmentos dos digito 7 (digito inferior).
struct lower_position_struct map_digit7_lower_segment (unsigned short char_position){
    
    struct lower_position_struct digit7[11];
    
    //A
    digit7[0].position = 9;
    digit7[0].bit = BIT0;
    //B
    digit7[1].position = 9;
    digit7[1].bit = BIT1;
    //C
    digit7[2].position = 9;
    digit7[2].bit = BIT2;
    //D
    digit7[3].position = 9;
    digit7[3].bit = BIT7;
    //E
    digit7[4].position = 10;
    digit7[4].bit = BIT2;
    //F
    digit7[5].position = 10;
    digit7[5].bit = BIT1;
    //G
    digit7[6].position = 9;
    digit7[6].bit = BIT5;
    //H
    digit7[7].position = 10;
    digit7[7].bit = BIT0;
    //I
    digit7[8].position = 9;
    digit7[8].bit = BIT4;
    //J
    digit7[9].position = 9;
    digit7[9].bit = BIT3;
    //K
    digit7[10].position = 9;
    digit7[10].bit = BIT6;  
    
    return digit7[char_position];
}

//Essa funcao mapeia os segmentos dos digito 8 (digito inferior).
struct lower_position_struct map_digit8_lower_segment (unsigned short char_position){
    
    struct lower_position_struct digit8[11];
    
    //A
    digit8[0].position = 10;
    digit8[0].bit = BIT4;
    //B
    digit8[1].position = 10;
    digit8[1].bit = BIT5;
    //C
    digit8[2].position = 10;
    digit8[2].bit = BIT6;
    //D
    digit8[3].position = 11;
    digit8[3].bit = BIT3;
    //E
    digit8[4].position = 11;
    digit8[4].bit = BIT6;
    //F
    digit8[5].position = 11;
    digit8[5].bit = BIT5;
    //G
    digit8[6].position = 11;
    digit8[6].bit = BIT1;
    //H
    digit8[7].position = 11;
    digit8[7].bit = BIT4;
    //I
    digit8[8].position = 11;
    digit8[8].bit = BIT0;
    //J
    digit8[9].position = 10;
    digit8[9].bit = BIT7;
    //K
    digit8[10].position = 11;
    digit8[10].bit = BIT2;  
    
    return digit8[char_position];
}

//Essa funcao e responsavel por obter o mapeamento de um segmento especifico(a,b,c,d...k) para algum digito inferior (4,5,6,7 ou 8).
struct lower_position_struct retrieve_map_digit_lower_segment(unsigned short segment, unsigned short digit){
    struct lower_position_struct segment_adress ;
    segment_adress.bit = 0;
    segment_adress.position = 0;
   
    switch(digit){
        case 1:
            return map_digit8_lower_segment(segment); 
        case 2:
            return map_digit7_lower_segment(segment);
        case 3:
            return map_digit6_lower_segment(segment);      
        case 4:
            return map_digit5_lower_segment(segment);
        case 5:
            return map_digit4_lower_segment(segment);
        default:
          return segment_adress;
    }
    
    
}

//Essa funcao recebe como parametro um digito inferior desejado e a letra/numero para ser exibido.
void plot_in_low_digit(char letter, unsigned short pos){
    unsigned short int a = 0;
    unsigned short int b = 1;
    unsigned short int c = 2;
    unsigned short int d = 3;
    unsigned short int e = 4;
    unsigned short int f = 5;
    unsigned short int g = 6;
    unsigned short int h = 7;
    unsigned short int i = 8;
    unsigned short int j = 9;
    unsigned short int k = 10;
  
    unsigned short int cont = 0;
    unsigned short int digit_to_print[11];
    
    switch (letter){
        
        case '1':{
            
            unsigned short int digit_vet[2] = {b, c};
            
            for(cont = 0;cont < 2; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 2;
        }
        break;
        case '2':{
            unsigned short int digit_vet[5] = {a, b, g, d, e};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break;
        
        case '3':{
            unsigned short int digit_vet[5] = {a, b, g, d, c};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break;
        
        case '4':{
            unsigned short int digit_vet[4] = {b, c, f, g};
                
            for(cont = 0;cont < 4; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 4;
        }
        break;
        
        case '5':{
            unsigned short int digit_vet[5] = {a, f, g, c, d};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break;
       
        case '6':{
            unsigned short int digit_vet[5] = {f, e, g, c, d};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break; 
        
        case '7':{
                unsigned short int digit_vet[3] = {a, b, c};
                
            for(cont = 0;cont < 3; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 3;
        }
        break;
        
        case '8':{
            unsigned short int digit_vet[7] = {a, b, c, d, e, f, g};
                
            for(cont = 0;cont < 7; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 7;
        }
        break;
        
        case '9':{
            unsigned short int digit_vet[5] = {a, f, g, b, c};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break;
        
        case '0':{
            unsigned short int digit_vet[8] = {a, b, c, d, e, f, i, k};
                
            for(cont = 0;cont < 8; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 8;
        }
        break;
        //Mapeamento das letras
        
        case 'a':{
            unsigned short int digit_vet[6] = {a, b, c, e, f, g};
                
            for(cont = 0;cont < 6; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 6;
        }
        break;
        
        case 'b':{
            unsigned short int digit_vet[7] = {a, b, c, d, e, f, g};
                
            for(cont = 0;cont < 7; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 7;
        }
        break;
        
        case 'c':{
            unsigned short int digit_vet[4] = {a, d, e, f};
                
            for(cont = 0;cont < 4; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 4;
        }
        break;
        case 'd':{
            unsigned short int digit_vet[6] = {a, b, c, d, e, f};
                
            for(cont = 0;cont < 6; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 6;
        }
        break;
        case 'e':{
            unsigned short int digit_vet[5] = {a, f, e, d, g};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break;
        
        case 'f':{
            unsigned short int digit_vet[4] = {a, f, g, e};
                
            for(cont = 0;cont < 4; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 4;
        }
        break;        
        case 'g':{
            unsigned short int digit_vet[6] = {a, f, e, d, c, g};
                
            for(cont = 0;cont < 6; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 6;
        }
        break;
        case 'h':{
            unsigned short int digit_vet[5] = {f, e, b, c, g};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break;
        case 'i':{
            unsigned short int digit_vet[2] = {f, e};
                
            for(cont = 0;cont < 2; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 2;
        }
        break;
        case 'j':{
            unsigned short int digit_vet[4] = {b, c, d, e};
                
            for(cont = 0;cont < 4; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 4;
        }
        break;
        case 'k':{
            unsigned short int digit_vet[4] = {f, e, i, j};
                
            for(cont = 0;cont < 4; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 4;
        }
        break;
        case 'l':{
            unsigned short int digit_vet[3] = {f, e, d};
                
            for(cont = 0;cont < 3; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 3;
        }
        break;
        case 'm':{
            unsigned short int digit_vet[7] = {f, e, b, c, h, i, a};
                
            for(cont = 0;cont < 7; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 7;
        }
        break;
        case 'n':{
            unsigned short int digit_vet[6] = {f, e, h, j, c, b};
                
            for(cont = 0;cont < 6; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 6;
        }
        break;
        case 'o':{
            unsigned short int digit_vet[6] = {a, b, c, d, e, f};
                
            for(cont = 0;cont < 6; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 6;
        }
        break;
        case 'p':{
            unsigned short int digit_vet[5] = {f, a, b, g, e};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break;
        case 'q':{
            unsigned short int digit_vet[7] = {a, b, c, d, e, f, j};
                
            for(cont = 0;cont < 7; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 7;
        }
        break;
        case 'r':{
            unsigned short int digit_vet[6] = {a, b, g, f, e, j};
                
            for(cont = 0;cont < 6; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 6;
        }
        break;
        case 's':{
            unsigned short int digit_vet[5] = {a, f, g, c, d};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break;
        case 't':{
            unsigned short int digit_vet[4] = {f, e, d, g};
                
            for(cont = 0;cont < 4; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 4;
        }
        break;
        case 'u':{
            unsigned short int digit_vet[5] = {f, e, d, c, b};
                
            for(cont = 0;cont < 5; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 5;
        }
        break;
        case 'v':{
            unsigned short int digit_vet[3] = {e, d, c};
                
            for(cont = 0;cont < 3; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 3;
        }
        break;
        case 'w':{
            unsigned short int digit_vet[7] = {f, e, k , j, d, c, b};
                
            for(cont = 0;cont < 7; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 7;
        }
        break;
        case 'x':{
            unsigned short int digit_vet[4] = {h, i, k, j};
                
            for(cont = 0;cont < 4; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 4;
        }
        break;
        case 'y':{
            unsigned short int digit_vet[3] = {h, i, k};
                
            for(cont = 0;cont < 3; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 3;
        }
        break;        
        case 'z':{
            unsigned short int digit_vet[4] = {a, i, k, d};
                
            for(cont = 0;cont < 4; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 4;
        }
        break;
        case '-':{
            unsigned short int digit_vet[4] = {g};
                
            for(cont = 0;cont < 1; cont++){
                digit_to_print[cont] = digit_vet[cont];
            }
            
            cont = 1;
        }
        break;
        case ' ':{       
            cont = 0;
        }
        break;
    }
    
    //Desenhando o digito
    unsigned short int cont_1 = 0;
    //Limpando digito
    unsigned short int digit_clean[11] = {a, b, c, d, e, f, g, h, i, j, k};
    for(cont_1 = 0; cont_1 < 11; cont_1++){
        struct lower_position_struct number1_struct = retrieve_map_digit_lower_segment(digit_clean[cont_1], pos);
        LCDMEM[number1_struct.position] &= ~number1_struct.bit;
    }
    
    for(cont_1 = 0; cont_1 < cont; cont_1++){
        struct lower_position_struct number1_struct = retrieve_map_digit_lower_segment(digit_to_print[cont_1], pos);
        LCDMEM[number1_struct.position] |= number1_struct.bit;
    }
    
}

void battery_symbol(unsigned short int digit){
	
	switch(digit){
		//bateria vazia ou limpar segmentos da bateria
		case 0:
			LCDMEM[12] = BIT3;
        break;
		case 1:
			LCDMEM[12] = BIT0+BIT3;
        break;
		case 2:
			LCDMEM[12] = BIT0+BIT1+BIT3;
		break;
		case 3:
			LCDMEM[12] = BIT0+BIT1+BIT2+BIT3;		
		break;
	}
}


void syringe_symbol(unsigned short int digit){
	
	LCDMEM[3] |= BIT0;
	LCDMEM[3] &= ~BIT4 & ~BIT5 & ~BIT6 & ~BIT7;
	
	switch(digit){
		//bateria vazia ou limpar segmentos da bateria
		case 0:
			//LCDMEM[3] |= BIT0;
		break;			
		case 1:
			LCDMEM[3] |= BIT4;
		break;
		case 2:
			LCDMEM[3] |= BIT4+BIT5;
		break;
		case 3:
			LCDMEM[3] |= BIT4+BIT5+BIT6;
		break;
		case 4:
			LCDMEM[3] |= BIT4+BIT5+BIT6+BIT7;
		break;
	}
}

void stop_symbol(unsigned short int digit){
	switch(digit){
		//bateria vazia ou limpar segmentos da bateria
		case 0:
			LCDMEM[5] &= ~BIT3;
		break;			
		case 1:
			LCDMEM[5] |= BIT3;
		break;
	}
}

void bell_symbol(unsigned short int digit){
	switch(digit){
		//bateria vazia ou limpar segmentos da bateria
		case 0:
			LCDMEM[10] &= ~BIT3;
		break;			
		case 1:
			LCDMEM[10] |= BIT3;
		break;
	}
}

void clock_symbol(unsigned short int digit){
	switch(digit){
		//bateria vazia ou limpar segmentos da bateria
		case 0:
			LCDMEM[8] &= ~BIT7;
		break;			
		case 1:
			LCDMEM[8] |= BIT7;
		break;
	}
}

void hand_symbol(unsigned short int digit){
	switch(digit){
		//bateria vazia ou limpar segmentos da bateria
		case 0:
			LCDMEM[6] &= ~BIT7;
		break;			
		case 1:
			LCDMEM[6] |= BIT7;
		break;
	}
}

void bolus_symbol(unsigned short int digit){
	switch(digit){
		//bateria vazia ou limpar segmentos da bateria
		case 0:
			LCDMEM[11] &= ~BIT7;
		break;			
		case 1:
			LCDMEM[11] |= BIT7;
		break;
	}
}

void basal_symbol(unsigned short int digit){
	switch(digit){
		//bateria vazia ou limpar segmentos da bateria
		case 0:
			LCDMEM[0] &= ~BIT4;
		break;			
		case 1:
			LCDMEM[0] |= BIT4;
		break;
	}
}

void colon_symbol(unsigned short int digit){
	switch(digit){
		//bateria vazia ou limpar segmentos da bateria
		case 0:
			LCDMEM[7] &= ~BIT4;
		break;			
		case 1:
			LCDMEM[7] |= BIT4;
		break;
	}
}

void write_lower_string(unsigned char phrase[TAMANHO_FRASE]){

    unsigned short int i, contador;
    contador = 1;
    colon_symbol(SYMBOL_OFF);
    
    while(phrase[contador-1]!='\0'){
        contador++;
    }
 
    for (i = 0; i < contador; i++){
        plot_in_low_digit(phrase[i], i + 1);
    }
  
}

//Essa funcao recebe como parametro um numero float para ser exibido nos digitos superiores.
void write_in_upper_digits(float num){

    unsigned short dezena = 0;
    unsigned short unidade = 0;
    unsigned short fracionaria = 0;
    
    LCDMEM[0] &= number_gen_upper_segment(10);
    LCDMEM[1] &= number_gen_upper_segment(10);
    LCDMEM[2] &= number_gen_upper_segment(10);
    
    if(num < 0){
        LCDMEM[1] &= ~BIT4;   //desligar ponto
    }
    else{
        fracionaria = (unsigned short) round((num - (unsigned short) num) * 10);

        if(fracionaria > 9){
            fracionaria = 0;
            num = round(num);
        } 

        dezena = (unsigned short)(num / 10);
        unidade = (unsigned short)((unsigned short)num % 10);
        
        
        LCDMEM[0] |= number_gen_upper_segment(dezena);
        LCDMEM[1] |= number_gen_upper_segment(unidade);
        LCDMEM[1] |= BIT4;
        //LCDMEM[1] &= ~BIT4;   //desligar ponto
        LCDMEM[2] |= number_gen_upper_segment(fracionaria);
    }
    
}

void configure_display(){
    
    LCDCTL = LCDON + LCDSG0_4 + LCD4MUX;  // 4mux LCD, segs0-27 = outputs
    BTCTL = BT_fLCD_DIV128;               // Set LCD frame freq = ACLK/128
    P5SEL  = 0xFC;                        // Set Rxx and COM pins for LCD
                                        // For P5.1, P5.2, P5.3, P5.4 setting
                                        // SEL bits selects Analog for the FG
    int i = 0;
    for( i = 0; i < 27; i ++){
        LCDMEM[i] = 0;// Clear LCD
    }
       
}

/*
 * Essa funcao escreve horas em formato de intervalo "HH-HH" ou formato "HH:MM". Se algum dos numeros for
 * negativo, todos os digitos inferiores sao limpados.
 */
void write_hours(unsigned short hour1, unsigned short hour2, unsigned short type){
    
    unsigned char numbers[5];
    
    numbers[0] = hour1 / 10 + 0x30;
    numbers[1] = hour1 % 10 + 0x30;
    numbers[2] = '-';
    numbers[3] = hour2 / 10 + 0x30;
    numbers[4] = hour2 % 10 + 0x30;                

    if(type == TYPE_HOUR){
        numbers[2] = ' ';
        colon_symbol(SYMBOL_ON);    
    }
    
    write_lower_string(numbers);
}

