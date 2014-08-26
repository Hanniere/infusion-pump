#include "msp430FG437.h"

double profiles[5][25];

void main(void) {
	WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer to prevent time out reset
	FLL_CTL0 |= XCAP18PF; // Set load capacitance for xtal
        
        glcd_turn_on();
	glcd_fill(0);
        verify();
        
        
        
      
        double profiles[5][25];
        /*Perfis em forma de matriz: 
        Cada linha representaum perfil.
        Cada coluna representa a quantidade de insulina em um intervalo de uma hora*/
        
        short i, j;
        
        for (i = 0; i < 5; i++){
          for (j = 0; j < 24; j++){
            profiles[i][j] = 1.4;
          }
        }
        
        P3DIR |= 0x5; 
        
          tabela_1_on();
          for (i=0;i<12; i++){
            fill_table_profile(profiles[1][i], i);
          }
          for (i=0;i<12; i++){
          profiles[1][i] = edit_infusion(i, profiles[1][i]);
          fill_table_profile(profiles[1][i], i);
          __delay_cycles(1000000);
          }
          glcd_free();
          
          
        battery_on();
        sino_on();
        clock_on();
        arrow_on();
        stop_on();
        seringa_on();
        ponto_on();
        
        units_on();
        h_on();
        percent_on();
        
        bolt_on();
        continuo_on();
        
        battery_life_1();
        
        while(1){  
        battery_life_2();
        less_symbol_on();
        more_symbol_on();
        write_hello();
        numero(8,0);
        numero(8,1);
        numero(8,2);
        }
        __delay_cycles(100000);
	
	
//Direciona P1 para saída de dados: som e leds
	
        P1DIR |= 0x47;
}