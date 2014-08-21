#include "msp430FG437.h"

#define TAMANHO_FRASE 60

void verificando_motor()
{
  cout("verificando motor");
}

void testando_display()
{
    short i;
    battery_on();
    battery_life_4();
    sino_on();
    clock_on();
    arrow_on();
    stop_on();
    seringa_on();
    continuo_on();
    bolt_on();
    ponto_on();
    units_on();
    h_on();
    percent_on();
    numero(8,0);
    numero(8,1);
    numero(8,2);
    more_symbol(1);
    less_symbol(0);
    for (i=0; i<6; i++)
    {
        clean_letters();
        letter_t(0-i);
        letter_e(1-i);
        letter_s(2-i);
        letter_t(3-i);
        letter_a(4-i);
        letter_n(5-i);
        letter_d(6-i);
        letter_o(7-i);
        letter_off(8-i);
        letter_d(9-i);
        letter_i(10-i);
        letter_s(11-i);
        letter_p(12-i);
        letter_l(13-i);
        letter_a(14-i);
        letter_y(15-i);
        more_symbol(1);
        less_symbol(1);
        __delay_cycles(1000000);
    }
    more_symbol(0);
    less_symbol(1);
}
void welcome()
{


}



void verify()
{
    cout(" bem vindo");//imprime "bem vindo"
    __delay_cycles(3000000);
    glcd_free();
    cout("verificando motor");//imprime "verificando motor"
    __delay_cycles(1000000);
    glcd_free();
    testando_display();//funcao que abresenta o cout porém possui a ativaçao de todos os simbolos do display para teste.
    __delay_cycles(1000000);
    glcd_free();
    welcome();//abre a tela inicial da bomba
}

void verify_profile(){
  double profiles[5][25];
  double verify[5];
  short i, j;
  j=0;
  for(i=0;i<5;i++){
    verify[i] = 0;
  }
  for(i=0;i<5;i++){
    if(profiles[i][25]==1){
      verify[j] = 1;
      j++;
    }
  }
  char phrase[TAMANHO_FRASE] = "hello";

}

void home_screen_none()
{

}

void home_screen_activate()
{

}


double edit_infusion(short mode, double number)
{
    short espaco_tabela = 131-4;
    char l1 = 0;
    char l2 = 1;
    char l3 = 2;
    char l4 = 3;
    char l5 = 4;
    char l6 = 5;
    char l7 = 6;
    char l8 = 7;
    short n1, n2, decimal, m, n;
    double r;
    m = mode/4;
    n = mode-(4*m);
    n++;
    char linha;
    if (m == 0)
    {
        linha = l7;
    }
    else
    {
        if (m == 1)
        {
            linha = l4;
        }
        else
        {
            if (m == 2)
            {
                linha = l1;
            }
            else
            {
                if (m == 3)
                {
                    linha = l7;
                }
                else
                {
                    if (m == 4)
                    {
                        linha = l4;
                    }
                    else
                    {
                        if (m == 5)
                        {
                            linha = l1;
                        }
                    }
                }
            }
        }
    }
    n1 = number/10;
    n2 = (number - (n1*10));
    decimal = (number*10)-(n2*10);
    P3DIR |= 0x5;
    while(!(P3IN&BIT3)==0)
    {
        num_table(n1, linha, n, 1);
        num_table(n2, linha, n, 2);
        num_table(decimal, linha, n, 3);
        __delay_cycles(400000);
        num_table_null(linha, n, 1);
        num_table_null(linha, n, 2);
        num_table_null(linha, n, 3);
        __delay_cycles(400000);
        if ((P3IN&BIT5)==0)
        {
            if (decimal == 9)
            {
                decimal = 0;
                if (n2 == 9)
                {
                    n2 = 0;
                    if (n1 == 9)
                    {
                        n1 = 0;
                    }
                    else
                    {
                        n1++;
                    }
                }
                else
                {
                    n2++;
                }
            }
            else
            {
                decimal++;
            }
        }
        if ((P3IN&BIT6)==0)
        {
            if (decimal == 0)
            {
                decimal = 9;
                if (n2 == 0)
                {
                    n2 = 9;
                    if (n1 == 0)
                    {
                        n1 = 9;
                    }
                    else
                    {
                        n1--;
                    }
                }
                else
                {
                    n2--;
                }
            }
            else
            {
                decimal--;
            }
        }
    }
    r = (double)(n1*10)+(double)(n2)+ ((double)(decimal)/10);
    return r;
}

/*void insertion_insulin()
{
    short i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 24; j++)
        {
            profiles[i][j] = 1.4;
        }
    }

    P3DIR |= 0x5;

    tabela_1_on();
    for (i=0; i<12; i++)
    {
        fill_table_profile(profiles[1][i], i);
    }
    for (i=0; i<12; i++)
    {
        profiles[1][i] = edit_infusion(i, profiles[1][i]);
        fill_table_profile(profiles[1][i], i);
        __delay_cycles(1000000);
    }
    glcd_free();
}*/
