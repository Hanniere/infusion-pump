#include "msp430FG437.h"

short tam_battery = 19;//tam = 19
short tam_sino = 19;
short tam_clock = 9;
short tam_arrow = 7;
short tam_stop = 23;
short tam_seringa = 19;
short tam_faixa_1 = 3;
short tam_faixa_2 = 5;
short tam_faixa_3 = 5;
short tam_faixa_4 = 5;
short tam_faixa_5 = 5;
short tam_faixa_6 = 5;
short tam_faixa_7 = 3;
short ref_battery = 0;
short ref_sino = 0;
short ref_clock = 0;
short ref_arrow = 0;
short ref_stop = 0;
short ref_seringa = 0;

//ref_battery = 131-(tam_faixa_1);
//ref_sino = 131-(tam_faixa_1)-(tam_battery)-(tam_faixa_2);
//ref_clock = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3;
//ref_arrow = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3-tam_clock-tam_faixa_4;
//ref_stop = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3-tam_clock-tam_faixa_4-tam_arrow-tam_faixa_5;
//ref_seringa = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3-tam_clock-tam_faixa_4-tam_arrow-tam_faixa_5-tam_stop-tam_faixa_6;

void seringa_on()
{
    short i;
    ref_seringa = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3-tam_clock-tam_faixa_4-tam_arrow-tam_faixa_5-tam_stop-tam_faixa_6;
    glcd_gotoxy(0x0,ref_seringa,0);
    glcd_write_data(0x7F,1);
    for(i=0; i<16; i++)
    {
        glcd_gotoxy(0x0,ref_seringa-1-i,0);
        glcd_write_data(0x22,1);
    }
    glcd_gotoxy(0x0,ref_seringa-17,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,ref_seringa-18,0);
    glcd_write_data(0x08,1);
}

void seringa_off()
{
    short i;
    ref_seringa = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3-tam_clock-tam_faixa_4-tam_arrow-tam_faixa_5-tam_stop-tam_faixa_6;
    for(i=0; i<tam_seringa; i++)
    {
        glcd_gotoxy(0x0,ref_seringa-i,0);
        glcd_write_data(0x0,1);
    }
}

void stop_on()
{
    short i;
    ref_stop = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3-tam_clock-tam_faixa_4-tam_arrow-tam_faixa_5;
    glcd_gotoxy(0x0,ref_stop,0);
    glcd_write_data(0x79,1);
    for(i=0; i<3; i++)
    {
        glcd_gotoxy(0x0,ref_stop-i-1,0);
        glcd_write_data(0x49,1);
    }
    glcd_gotoxy(0x0,ref_stop-4,0);
    glcd_write_data(0x4F,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(0x0,ref_stop-i-6,0);
        glcd_write_data(0x40,1);
    }
    glcd_gotoxy(0x0,ref_stop-8,0);
    glcd_write_data(0x7F,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(0x0,ref_stop-i-9,0);
        glcd_write_data(0x40,1);
    }
    glcd_gotoxy(0x0,ref_stop-12,0);
    glcd_write_data(0x7F,1);
    for(i=0; i<3; i++)
    {
        glcd_gotoxy(0x0,ref_stop-13-i,0);
        glcd_write_data(0x41,1);
    }
    glcd_gotoxy(0x0,ref_stop-16,0);
    glcd_write_data(0x7F,1);
    glcd_gotoxy(0x0,ref_stop-18,0);
    glcd_write_data(0x7F,1);
    for(i=0; i<3; i++)
    {
        glcd_gotoxy(0x0,ref_stop-19-i,0);
        glcd_write_data(0x48,1);
    }
    glcd_gotoxy(0x0,ref_stop-22,0);
    glcd_write_data(0x78,1);


}

void stop_off()
{
    short i;
    ref_stop = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3-tam_clock-tam_faixa_4-tam_arrow-tam_faixa_5;
    for(i=0; i<tam_stop; i++)
    {
        glcd_gotoxy(0x0,ref_stop-i,0);
        glcd_write_data(0x0,1);
    }
}

void arrow_on()
{
    ref_arrow = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3-tam_clock-tam_faixa_4;
    glcd_gotoxy(0x0,ref_arrow,0);
    glcd_write_data(0x04,1);
    glcd_gotoxy(0x0,ref_arrow-1,0);
    glcd_write_data(0x02,1);
    glcd_gotoxy(0x0,ref_arrow-2,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(0x0,ref_arrow-3,0);
    glcd_write_data(0x7F,1);
    glcd_gotoxy(0x0,ref_arrow-4,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(0x0,ref_arrow-5,0);
    glcd_write_data(0x02,1);
    glcd_gotoxy(0x0,ref_arrow-6,0);
    glcd_write_data(0x04,1);
}

void arrow_off()
{
    short i;
    ref_arrow = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3-tam_clock-tam_faixa_4;
    for(i=0; i<tam_arrow; i++)
    {
        glcd_gotoxy(0x0,ref_arrow-i,0);
        glcd_write_data(0x0,1);
    }
}

void clock_on()
{
    short i;
    ref_clock = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3;
    glcd_gotoxy(0x0,ref_clock,0);
    glcd_write_data(0x1C,1);
    glcd_gotoxy(0x0,ref_clock-1,0);
    glcd_write_data(0x2A,1);
    for (i=0; i<2; i++)
    {
        glcd_gotoxy(0x0,ref_clock-2-i,0);
        glcd_write_data(0x41,1);
    }
    glcd_gotoxy(0x0,ref_clock-4,0);
    glcd_write_data(0x7B,1);
    glcd_gotoxy(0x0,ref_clock-5,0);
    glcd_write_data(0x49,1);
    glcd_gotoxy(0x0,ref_clock-6,0);
    glcd_write_data(0x41,1);
    glcd_gotoxy(0x0,ref_clock-7,0);
    glcd_write_data(0x2A,1);
    glcd_gotoxy(0x0,ref_clock-8,0);
    glcd_write_data(0x1C,1);
}

void clock_off()
{
    short i;
    ref_clock = 131-tam_faixa_1-tam_battery-tam_faixa_2-tam_sino-tam_faixa_3;
    for(i=0; i<tam_clock; i++)
    {
        glcd_gotoxy(0x0,ref_clock-i,0);
        glcd_write_data(0x0,1);
    }
}

void sino_off()
{
    short i;
    ref_sino = 131-(tam_faixa_1)-(tam_battery)-(tam_faixa_2);
    for(i=0; i<tam_sino; i++)
    {
        glcd_gotoxy(0x0,ref_sino-i,0);
        glcd_write_data(0x0,1);
    }
}

void sino_on()
{
    short i;
    ref_sino = 131-(tam_faixa_1)-(tam_battery)-(tam_faixa_2);
    glcd_gotoxy(0x0,ref_sino,0);
    glcd_write_data(0x08,1);
    glcd_gotoxy(0x0,ref_sino-1,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,ref_sino-2,0);
    glcd_write_data(0x22,1);
    glcd_gotoxy(0x0,ref_sino-3,0);
    glcd_write_data(0x08,1);
    glcd_gotoxy(0x0,ref_sino-4,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,ref_sino-5,0);
    glcd_write_data(0x02,1);
    glcd_gotoxy(0x0,ref_sino-6,0);
    glcd_write_data(0x0E,1);
    glcd_gotoxy(0x0,ref_sino-7,0);
    glcd_write_data(0x1E,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(0x0,(ref_sino-8)-i,0);
        glcd_write_data(0x3F,1);
    }
    glcd_gotoxy(0x0,ref_sino-10,0);
    glcd_write_data(0x1E,1);
    glcd_gotoxy(0x0,ref_sino-11,0);
    glcd_write_data(0x0E,1);
    glcd_gotoxy(0x0,ref_sino-12,0);
    glcd_write_data(0x02,1);
    glcd_gotoxy(0x0,ref_sino-13,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,ref_sino-14,0);
    glcd_write_data(0x08,1);
    glcd_gotoxy(0x0,ref_sino-15,0);
    glcd_write_data(0x22,1);
    glcd_gotoxy(0x0,ref_sino-16,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,(ref_sino-17),0);
    glcd_write_data(0x08,1);
}

void battery_off()
{
    short i;
    ref_battery = 131-(tam_faixa_1);
    for(i=0; i<tam_battery; i++)
    {
        glcd_gotoxy(0x0,ref_battery-i,0);
        glcd_write_data(0x0,1);
    }
}

void battery_on()
{
    short i;
    ref_battery = 131-(tam_faixa_1);
    glcd_gotoxy(0x0,ref_battery,0);
    glcd_write_data(0x3E,1);
    for (i=0; i<16; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-1)-i,0);
        glcd_write_data(0x22,1);
    }
    glcd_gotoxy(0x0,ref_battery-17,0);
    glcd_write_data(0x3E,1);
    glcd_gotoxy(0x0,ref_battery-18,0);
    glcd_write_data(0x1C,1);
}

void battery_life_1()
{
    short i;
    ref_battery = 131-(tam_faixa_1);
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-1)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-5)-i,0);
        glcd_write_data(0x22,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-9)-i,0);
        glcd_write_data(0x22,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-13)-i,0);
        glcd_write_data(0x22,1);
    }
}

void battery_life_2()
{
    short i;
    ref_battery = 131-(tam_faixa_1);
    i=0;
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-1)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-5)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-9)-i,0);
        glcd_write_data(0x22,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-13)-i,0);
        glcd_write_data(0x22,1);
    }
}

void battery_life_3()
{
    short i;
    ref_battery = 131-(tam_faixa_1);
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-1)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-5)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-9)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-13)-i,0);
        glcd_write_data(0x22,1);
    }
}

void battery_life_4()
{
    short i;
    ref_battery = 131-(tam_faixa_1);
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-1)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-5)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-9)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<4; i++)
    {
        glcd_gotoxy(0x0,(ref_battery-13)-i,0);
        glcd_write_data(0x3E,1);
    }
}
