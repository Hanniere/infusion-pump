/**************************************************************************************

	Funcoes de navegacao na interface do usuario

	gui_functions.cpp
	
	Autor: Hanniere de Faria Veloso dos Santos
	Data: setembro, 2016


********************************************************************************************/
#include <msp430FG437.h>
#include "INFUSION.h"
#include "GUI_FUNCTIONS.h"
#include "TIME.h"
#include "DISPLAY.h"
#include "MAIN.h"


//funcao que configura o perfil basal ativo para as 24 horas do dia DAY_HOURS
void configure_ative_basal_profile(){
    unsigned short i = 0;
    float insulina_unit = 0.0;
    
    //infusao basal deve ser paralisada
    if(basal_active)
        stop_symbol(1);
    
    //clock_symbol(0);
    basal_symbol(1);
    unit_symbol(1);
    h_symbol(1);
    load_active_basal_profile();
    
    //desativa infusao basal
    //ativa_infusao();
    for(i = 0 ; i < DAY_HOURS; i++){
        
        insulina_unit = active_basal_profile[i];
        /*Escreve o valor no segmento superior salvo no vetor de profile*/
        write_in_upper_digits(insulina_unit);
        /*Escreve o intervalo de hora para o qual esta sendo configurado*/
        write_hours((unsigned short)i, (unsigned short)i+1, TYPE_INTERVAL);
          
        while(1){
            put_cpu_to_sleep();
            if(button_3_pressed){ // botao pressionado retorna falso, pois coloca o pino no terra
                button_3_pressed = 0;                
                if(insulina_unit >= 0.1){
                    insulina_unit = insulina_unit - 0.1;
                    write_in_upper_digits(insulina_unit);
                }   
            }

             if(button_4_pressed){
                button_4_pressed = 0;
                if(insulina_unit <= 90.0){
                    insulina_unit = insulina_unit + 0.1;
                    write_in_upper_digits(insulina_unit);
                }
             }

            //Confirma edicao da quantidade de unidades da infusao basal para cada hora
            if(button_2_pressed){
                button_2_pressed = 0;
                /*inicializando perfil basal1 para simulacao em apenas uma hora*/
                conta_infusoes[i] = 0;
                /*9 unidades em uma hora, 0.1 a cada 4 segundos*/
                active_basal_profile[i] = insulina_unit;
                /*Sai do while*/
                break;
            }
        }
    }
    
    //simulando que a infusao basal foi ativada
    
    stop_symbol(0);
    unit_symbol(0);
    h_symbol(0);
    basal_symbol(0);
    //limpando display superior
    write_in_upper_digits(CLEAN_UPPER_DISPLAY);
}

//funcao que escolhe quantidade em unidades para uma infusao bolus
void configure_bolus_infusion(){
    float insulina_unit = 0.0;
    write_lower_string("bolus");
    write_in_upper_digits(insulina_unit);
    unit_symbol(1);
    bolus_symbol(1);
    while(1){
        put_cpu_to_sleep();
        //ativa_infusao();
        
        if(button_3_pressed){ // botao pressionado retorna falso, pois coloca o pino no terra
            button_3_pressed = 0;                
            if(insulina_unit > 0.0){
                insulina_unit = insulina_unit - 0.1;
                write_in_upper_digits(insulina_unit);
            }
            
        }

         if(button_4_pressed){
            button_4_pressed = 0;
            if(insulina_unit <= 90.0){
                insulina_unit = insulina_unit + 0.1;
                write_in_upper_digits(insulina_unit);
            }

         }

        //Confirma edicao da quantidade de unidades da infusao bolus para cada hora
        if(button_2_pressed){
            button_2_pressed = 0;
            //Infusao basal deve ser paralisada quando apertar em ok e infundir bolus
            break;
        }
    }
    
    bolus_symbol(0);
    unit_symbol(0);
    //limpando display superior
    write_in_upper_digits(CLEAN_UPPER_DISPLAY);
}

//funcao que configura o relogio da bomba
void configure_system_time(){
    unsigned short wait_user_flag = 1;
    unsigned short int horas_copy = horas;
    unsigned short int minutos_copy = minutos;
    //infusao deve ser paralisada
    //contagem do tempo deve ser parada
    stop_symbol(1);
    clock_symbol(0);
    write_hours(horas_copy, minutos_copy, TYPE_HOUR);
          
    while(wait_user_flag){
        put_cpu_to_sleep();
        
		if(button_3_pressed){
            button_3_pressed = 0;                
            if(horas_copy + 1 > 23){
                horas_copy = 0;
            }else{
                horas_copy++;
            }
            write_hours(horas_copy, minutos_copy, TYPE_HOUR);
        }

         if(button_4_pressed){
            button_4_pressed = 0;
            if(minutos_copy + 1 > 60){
                minutos_copy = 0;
            }else{
                minutos_copy++;
            }
           write_hours(horas_copy, minutos_copy, TYPE_HOUR);
         }

        //Confirma edicao da hora
        if(button_2_pressed){
            button_2_pressed = 0;
            minutos = minutos_copy;
            horas = horas_copy;
            segundos = 0;
            /*Sai do while*/
            wait_user_flag = 0;
            //simula o inicio da infusao basal novamente
            stop_symbol(0);
            clock_symbol(0);
        }
		
    }

    //limpando display superior
    write_in_upper_digits(CLEAN_UPPER_DISPLAY);
}