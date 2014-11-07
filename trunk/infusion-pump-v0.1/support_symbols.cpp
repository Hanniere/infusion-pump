#include "GLCD.h"
#include "DISPLAY.h"
#include <math.h>

unsigned short int tam_battery = 19;//tam = 19
unsigned short int size_bell = 19;
unsigned short int size_clock = 9;
unsigned short int size_arrow = 7;
unsigned short int size_stop = 23;
unsigned short int size_syringe = 19;
unsigned short int space_lcorner_battery = 3;
unsigned short int space_battery_bell = 5;
unsigned short int space_bell_clock = 5;
unsigned short int space_clock_arrow = 5;
unsigned short int space_arrow_stop = 5;
unsigned short int space_stop_syringe = 5;
unsigned short int space_syringe_rcorner = 3;

unsigned short int ref_battery(){
    return 131-(space_lcorner_battery);
}
unsigned short int ref_bell(){
    return 131-(space_lcorner_battery)-(tam_battery)-(space_battery_bell);
}
unsigned short int ref_clock(){
    return 131-space_lcorner_battery-tam_battery-space_battery_bell-size_bell-space_bell_clock;
}
unsigned short int ref_arrow(){
    return 131-space_lcorner_battery-tam_battery-space_battery_bell-size_bell-space_bell_clock-size_clock-space_clock_arrow;
}
unsigned short int ref_stop(){
    return 131-space_lcorner_battery-tam_battery-space_battery_bell-size_bell-space_bell_clock-size_clock-space_clock_arrow-size_arrow-space_arrow_stop;
}
unsigned short int ref_syringe(){
    return 131-space_lcorner_battery-tam_battery-space_battery_bell-size_bell-space_bell_clock-size_clock-space_clock_arrow-size_arrow-space_arrow_stop-size_stop-space_stop_syringe;
}

void battery_off()
{
    unsigned short int i;
    for(i=0; i<tam_battery; i++)
    {
        glcd_gotoxy(0x0,ref_battery()-i,0);
        glcd_write_data(0x0,1);
    }
}

void battery_on()
{
    unsigned short int i, ref;
    ref = ref_battery();
    glcd_gotoxy(0x0,ref,0);
    glcd_write_data(0x3E,1);
    for (i=0; i<16; i++)
    {
        glcd_gotoxy(0x0,(ref-1)-i,0);
        glcd_write_data(0x22,1);
    }
    glcd_gotoxy(0x0,ref-17,0);
    glcd_write_data(0x3E,1);
    glcd_gotoxy(0x0,ref-18,0);
    glcd_write_data(0x1C,1);
}

void battery_life_0()
{
    unsigned short int i, ref;
    ref = ref_battery();
    for (i=0; i<16; i++)
    {
        glcd_gotoxy(0x0,(ref-1)-i,0);
        glcd_write_data(0x22,1);
    }
}

void battery_life_1()
{
    unsigned short int i, ref;
    ref = ref_battery();
    for (i=0; i<6; i++)
    {
        glcd_gotoxy(0x0,(ref-1)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<5; i++)
    {
        glcd_gotoxy(0x0,(ref-7)-i,0);
        glcd_write_data(0x22,1);
    }
    for (i=0; i<5; i++)
    {
        glcd_gotoxy(0x0,(ref-12)-i,0);
        glcd_write_data(0x22,1);
    }
}

void battery_life_2()
{
    unsigned short int i, ref;
    ref = ref_battery();
    i=0;
    for (i=0; i<6; i++)
    {
        glcd_gotoxy(0x0,(ref-1)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<5; i++)
    {
        glcd_gotoxy(0x0,(ref-7)-i,0);
        glcd_write_data(0x3E,1);
    }
    for (i=0; i<5; i++)
    {
        glcd_gotoxy(0x0,(ref-12)-i,0);
        glcd_write_data(0x22,1);
    }
}

void battery_life_3()
{
    unsigned short int i, ref;
    ref = ref_battery();
    for (i=0; i<16; i++)
    {
        glcd_gotoxy(0x0,(ref-1)-i,0);
        glcd_write_data(0x3E,1);
    }
}

void battery(float percent){
    battery_on();
    if (percent>0.75 && percent<=1){
        battery_life_3();
    }else{
        if (percent>0.5 && percent<=0.75){
            battery_life_2();
        }else{
            if (percent>0.25 && percent<=0.5){
                battery_life_1();
            }else{
                if (percent>0 && percent<=0.25){
                    battery_life_0();
                }
            }
        }
    }
}

void syringe_on()
{
    unsigned short int i, ref;
    ref = ref_syringe();
    glcd_gotoxy(0x0,ref,0);
    glcd_write_data(0x7F,1);
    for(i=0; i<16; i++)
    {
        glcd_gotoxy(0x0,ref-1-i,0);
        glcd_write_data(0x22,1);
    }
    glcd_gotoxy(0x0,ref-17,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,ref-18,0);
    glcd_write_data(0x08,1);
}

void syringe_off()
{
    unsigned short int i;
    for(i=0; i<size_syringe; i++)
    {
        glcd_gotoxy(0x0,ref_syringe()-i,0);
        glcd_write_data(0x0,1);
    }
}

void syringe(unsigned short int mode){
    if(mode == 0){
        syringe_off();
    }else{
        syringe_on();
    }
}

void stop_on()
{
    unsigned short int i, ref;
    ref = ref_stop();
    glcd_gotoxy(0x0,ref,0);
    glcd_write_data(0x79,1);
    for(i=0; i<3; i++)
    {
        glcd_gotoxy(0x0,ref-i-1,0);
        glcd_write_data(0x49,1);
    }
    glcd_gotoxy(0x0,ref-4,0);
    glcd_write_data(0x4F,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(0x0,ref-i-6,0);
        glcd_write_data(0x40,1);
    }
    glcd_gotoxy(0x0,ref-8,0);
    glcd_write_data(0x7F,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(0x0,ref-i-9,0);
        glcd_write_data(0x40,1);
    }
    glcd_gotoxy(0x0,ref-12,0);
    glcd_write_data(0x7F,1);
    for(i=0; i<3; i++)
    {
        glcd_gotoxy(0x0,ref-13-i,0);
        glcd_write_data(0x41,1);
    }
    glcd_gotoxy(0x0,ref-16,0);
    glcd_write_data(0x7F,1);
    glcd_gotoxy(0x0,ref-18,0);
    glcd_write_data(0x7F,1);
    for(i=0; i<3; i++)
    {
        glcd_gotoxy(0x0,ref-19-i,0);
        glcd_write_data(0x48,1);
    }
    glcd_gotoxy(0x0,ref-22,0);
    glcd_write_data(0x78,1);


}

void stop_off()
{
    unsigned short int i;
    for(i=0; i<size_stop; i++)
    {
        glcd_gotoxy(0x0,ref_stop()-i,0);
        glcd_write_data(0x0,1);
    }
}

void stop(unsigned short int mode){
    if(mode == 0){
        stop_off();
    }else{
        stop_on();
    }
}

void arrow_on()
{
    unsigned short int ref;
    ref = ref_arrow();
    glcd_gotoxy(0x0,ref,0);
    glcd_write_data(0x04,1);
    glcd_gotoxy(0x0,ref-1,0);
    glcd_write_data(0x02,1);
    glcd_gotoxy(0x0,ref-2,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(0x0,ref-3,0);
    glcd_write_data(0x7F,1);
    glcd_gotoxy(0x0,ref-4,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(0x0,ref-5,0);
    glcd_write_data(0x02,1);
    glcd_gotoxy(0x0,ref-6,0);
    glcd_write_data(0x04,1);
}

void arrow_off()
{
    unsigned short int i;
    for(i=0; i<size_arrow; i++)
    {
        glcd_gotoxy(0x0,ref_arrow()-i,0);
        glcd_write_data(0x0,1);
    }
}

void arrow(unsigned short int mode){
    if(mode == 0){
        arrow_off();
    }else{
        arrow_on();
    }
}

void clock_on()
{
    unsigned short int i, ref;
    ref = ref_clock();
    glcd_gotoxy(0x0,ref,0);
    glcd_write_data(0x1C,1);
    glcd_gotoxy(0x0,ref-1,0);
    glcd_write_data(0x2A,1);
    for (i=0; i<2; i++)
    {
        glcd_gotoxy(0x0,ref-2-i,0);
        glcd_write_data(0x41,1);
    }
    glcd_gotoxy(0x0,ref-4,0);
    glcd_write_data(0x7B,1);
    glcd_gotoxy(0x0,ref-5,0);
    glcd_write_data(0x49,1);
    glcd_gotoxy(0x0,ref-6,0);
    glcd_write_data(0x41,1);
    glcd_gotoxy(0x0,ref-7,0);
    glcd_write_data(0x2A,1);
    glcd_gotoxy(0x0,ref-8,0);
    glcd_write_data(0x1C,1);
}

void clock_off()
{
    unsigned short int i;
    for(i=0; i<size_clock; i++)
    {
        glcd_gotoxy(0x0,ref_clock()-i,0);
        glcd_write_data(0x0,1);
    }
}

void clock(unsigned short int mode){
    if(mode == 0){
        clock_off();
    }else{
        clock_on();
    }
}

void bell_off()
{
    unsigned short int i;
    for(i=0; i<size_bell; i++)
    {
        glcd_gotoxy(0x0,ref_bell()-i,0);
        glcd_write_data(0x0,1);
    }
}

void bell_on()
{
    unsigned short int i, ref;
    ref = ref_bell();
    glcd_gotoxy(0x0,ref,0);
    glcd_write_data(0x08,1);
    glcd_gotoxy(0x0,ref-1,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,ref-2,0);
    glcd_write_data(0x22,1);
    glcd_gotoxy(0x0,ref-3,0);
    glcd_write_data(0x08,1);
    glcd_gotoxy(0x0,ref-4,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,ref-5,0);
    glcd_write_data(0x02,1);
    glcd_gotoxy(0x0,ref-6,0);
    glcd_write_data(0x0E,1);
    glcd_gotoxy(0x0,ref-7,0);
    glcd_write_data(0x1E,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(0x0,(ref-8)-i,0);
        glcd_write_data(0x3F,1);
    }
    glcd_gotoxy(0x0,ref-10,0);
    glcd_write_data(0x1E,1);
    glcd_gotoxy(0x0,ref-11,0);
    glcd_write_data(0x0E,1);
    glcd_gotoxy(0x0,ref-12,0);
    glcd_write_data(0x02,1);
    glcd_gotoxy(0x0,ref-13,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,ref-14,0);
    glcd_write_data(0x08,1);
    glcd_gotoxy(0x0,ref-15,0);
    glcd_write_data(0x22,1);
    glcd_gotoxy(0x0,ref-16,0);
    glcd_write_data(0x14,1);
    glcd_gotoxy(0x0,(ref-17),0);
    glcd_write_data(0x08,1);
}

void bell(unsigned short int mode){
    if(mode == 0){
        bell_off();
    }else{
        bell_on();
    }
}