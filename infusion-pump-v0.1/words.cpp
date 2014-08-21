#include "msp430FG437.h"
#define TAMANHO_FRASE 60

void write_hello()
{
    letter_off(0);
    letter_b(1);
    letter_e(2);
    letter_m(3);
    letter_off(4);
    letter_v(5);
    letter_i(6);
    letter_n(7);
    letter_d(8);
    letter_o(9);
    letter_off(10);
    more_symbol(0);
    less_symbol(0);
}

void write_infusao()
{
    cout("infusao");
}

void write_continuo_menu()
{
    letter_c(0);
    letter_o(1);
    letter_n(2);
    letter_t(3);
    letter_i(4);
    letter_n(5);
    letter_u(6);
    letter_a(7);
    letter_off(8);
    letter_off(9);
    letter_off(10);
    more_symbol(1);
    less_symbol(0);
}

void write_rapida_menu()
{
    letter_r(0);
    letter_a(1);
    letter_p(2);
    letter_i(3);
    letter_d(4);
    letter_a(5);
    letter_off(6);
    letter_off(7);
    letter_off(8);
    letter_off(9);
    letter_off(10);
    more_symbol(0);
    less_symbol(1);
}

void write_ativar_perfil_menu()
{
    letter_a(0);
    letter_t(1);
    letter_i(2);
    letter_v(3);
    letter_a(4);
    letter_r(5);
    letter_off(6);
    letter_off(7);
    letter_off(8);
    letter_off(9);
    letter_off(10);
    more_symbol(1);
    less_symbol(0);
}

void write_configurar_perfil_menu()
{
    letter_c(0);
    letter_o(1);
    letter_n(2);
    letter_f(3);
    letter_i(4);
    letter_g(5);
    letter_u(6);
    letter_r(7);
    letter_a(8);
    letter_r(9);
    letter_off(10);
    more_symbol(0);
    less_symbol(1);
}

void write_sem_perfil()
{
    letter_s(0);
    letter_e(1);
    letter_m(2);
    letter_off(3);
    letter_p(4);
    letter_e(5);
    letter_r(6);
    letter_f(7);
    letter_i(8);
    letter_l(9);
    letter_off(10);
    more_symbol(0);
    less_symbol(0);
}
