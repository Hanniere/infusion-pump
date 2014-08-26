#include "msp430FG439.h"

short espaco = 131-24;
char f3 = 5;
char f4 = 6;
char f5 = 7;

void faixa1(short numero, short pos)
{
    short i;
    if (numero == 5|| numero==6)
    {
        glcd_gotoxy(f5,espaco-5-(31*pos),0);
        glcd_write_data(0x3F,1);
        glcd_gotoxy(f5,espaco-6-(31*pos),0);
        glcd_write_data(0xDF,1);
        glcd_gotoxy(f5,espaco-7-(31*pos),0);
        glcd_write_data(0xEF,1);
        glcd_gotoxy(f5,espaco-8-(31*pos),0);
        glcd_write_data(0xF7,1);
        glcd_gotoxy(f5,espaco-9-(31*pos),0);
        glcd_write_data(0xFB,1);
        glcd_gotoxy(f5,espaco-10-(31*pos),0);
        glcd_write_data(0xFC,1);
        for(i=0; i<10; i++)
        {
            glcd_gotoxy(f5,espaco-11-i-(31*pos),0);
            glcd_write_data(0xFE,1);
        }
        glcd_gotoxy(f5,espaco-21-(31*pos),0);
        glcd_write_data(0xFC,1);
        glcd_gotoxy(f5,espaco-22-(31*pos),0);
        glcd_write_data(0xF8,1);
        glcd_gotoxy(f5,espaco-23-(31*pos),0);
        glcd_write_data(0xF0,1);
        glcd_gotoxy(f5,espaco-24-(31*pos),0);
        glcd_write_data(0xE0,1);
        glcd_gotoxy(f5,espaco-25-(31*pos),0);
        glcd_write_data(0xC0,1);
    }
    else
    {
        if (numero == 7||numero == 8|| numero == 9 || numero == 0)
        {
            glcd_gotoxy(f5,espaco-5-(31*pos),0);
            glcd_write_data(0x3F,1);
            glcd_gotoxy(f5,espaco-6-(31*pos),0);
            glcd_write_data(0xDF,1);
            glcd_gotoxy(f5,espaco-7-(31*pos),0);
            glcd_write_data(0xEF,1);
            glcd_gotoxy(f5,espaco-8-(31*pos),0);
            glcd_write_data(0xF7,1);
            glcd_gotoxy(f5,espaco-9-(31*pos),0);
            glcd_write_data(0xFB,1);
            glcd_gotoxy(f5,espaco-10-(31*pos),0);
            glcd_write_data(0xFC,1);
            for(i=0; i<10; i++)
            {
                glcd_gotoxy(f5,espaco-11-i-(31*pos),0);
                glcd_write_data(0xFE,1);
            }
            glcd_gotoxy(f5,espaco-21-(31*pos),0);
            glcd_write_data(0xFC,1);
            glcd_gotoxy(f5,espaco-22-(31*pos),0);
            glcd_write_data(0xFB,1);
            glcd_gotoxy(f5,espaco-23-(31*pos),0);
            glcd_write_data(0xF7,1);
            glcd_gotoxy(f5,espaco-24-(31*pos),0);
            glcd_write_data(0xEF,1);
            glcd_gotoxy(f5,espaco-25-(31*pos),0);
            glcd_write_data(0xDF,1);
            glcd_gotoxy(f5,espaco-26-(31*pos),0);
            glcd_write_data(0x3F,1);
        }
        else
        {
            if (numero == 2||numero == 3)
            {
                glcd_gotoxy(f5,espaco-5-(31*pos),0);
                glcd_write_data(0x0,1);
                glcd_gotoxy(f5,espaco-6-(31*pos),0);
                glcd_write_data(0xC0,1);
                glcd_gotoxy(f5,espaco-7-(31*pos),0);
                glcd_write_data(0xE0,1);
                glcd_gotoxy(f5,espaco-8-(31*pos),0);
                glcd_write_data(0xF0,1);
                glcd_gotoxy(f5,espaco-9-(31*pos),0);
                glcd_write_data(0xF8,1);
                glcd_gotoxy(f5,espaco-10-(31*pos),0);
                glcd_write_data(0xFC,1);
                for(i=0; i<10; i++)
                {
                    glcd_gotoxy(f5,espaco-11-i-(31*pos),0);
                    glcd_write_data(0xFE,1);
                }
                glcd_gotoxy(f5,espaco-21-(31*pos),0);
                glcd_write_data(0xFC,1);
                glcd_gotoxy(f5,espaco-22-(31*pos),0);
                glcd_write_data(0xFB,1);
                glcd_gotoxy(f5,espaco-23-(31*pos),0);
                glcd_write_data(0xF7,1);
                glcd_gotoxy(f5,espaco-24-(31*pos),0);
                glcd_write_data(0xEF,1);
                glcd_gotoxy(f5,espaco-25-(31*pos),0);
                glcd_write_data(0xDF,1);
                glcd_gotoxy(f5,espaco-26-(31*pos),0);
                glcd_write_data(0x3F,1);
            }
            else
            {
                if (numero == 1)
                {
                    glcd_gotoxy(f5,espaco-5-(31*pos),0);
                    glcd_write_data(0x0,1);
                    glcd_gotoxy(f5,espaco-6-(31*pos),0);
                    glcd_write_data(0x0,1);
                    glcd_gotoxy(f5,espaco-7-(31*pos),0);
                    glcd_write_data(0x0,1);
                    glcd_gotoxy(f5,espaco-8-(31*pos),0);
                    glcd_write_data(0x0,1);
                    glcd_gotoxy(f5,espaco-9-(31*pos),0);
                    glcd_write_data(0x0,1);
                    glcd_gotoxy(f5,espaco-10-(31*pos),0);
                    glcd_write_data(0x0,1);
                    for(i=0; i<10; i++)
                    {
                        glcd_gotoxy(f5,espaco-11-i-(31*pos),0);
                        glcd_write_data(0x0,1);
                    }
                    glcd_gotoxy(f5,espaco-21-(31*pos),0);
                    glcd_write_data(0x00,1);
                    glcd_gotoxy(f5,espaco-22-(31*pos),0);
                    glcd_write_data(0x03,1);
                    glcd_gotoxy(f5,espaco-23-(31*pos),0);
                    glcd_write_data(0x07,1);
                    glcd_gotoxy(f5,espaco-24-(31*pos),0);
                    glcd_write_data(0x0F,1);
                    glcd_gotoxy(f5,espaco-25-(31*pos),0);
                    glcd_write_data(0x1F,1);
                    glcd_gotoxy(f5,espaco-26-(31*pos),0);
                    glcd_write_data(0x3F,1);
                }
                else
                {
                    if (numero == 4)
                    {
                        glcd_gotoxy(f5,espaco-5-(31*pos),0);
                        glcd_write_data(0x3F,1);
                        glcd_gotoxy(f5,espaco-6-(31*pos),0);
                        glcd_write_data(0x1F,1);
                        glcd_gotoxy(f5,espaco-7-(31*pos),0);
                        glcd_write_data(0x0F,1);
                        glcd_gotoxy(f5,espaco-8-(31*pos),0);
                        glcd_write_data(0x07,1);
                        glcd_gotoxy(f5,espaco-9-(31*pos),0);
                        glcd_write_data(0x03,1);
                        glcd_gotoxy(f5,espaco-10-(31*pos),0);
                        glcd_write_data(0x0,1);
                        for(i=0; i<10; i++)
                        {
                            glcd_gotoxy(f5,espaco-11-i-(31*pos),0);
                            glcd_write_data(0x0,1);
                        }
                        glcd_gotoxy(f5,espaco-21-(31*pos),0);
                        glcd_write_data(0x00,1);
                        glcd_gotoxy(f5,espaco-22-(31*pos),0);
                        glcd_write_data(0x03,1);
                        glcd_gotoxy(f5,espaco-23-(31*pos),0);
                        glcd_write_data(0x07,1);
                        glcd_gotoxy(f5,espaco-24-(31*pos),0);
                        glcd_write_data(0x0F,1);
                        glcd_gotoxy(f5,espaco-25-(31*pos),0);
                        glcd_write_data(0x1F,1);
                        glcd_gotoxy(f5,espaco-26-(31*pos),0);
                        glcd_write_data(0x3F,1);
                    }
                }
            }
        }
    }
}

void faixa2(short numero, short pos)
{
    short i;
    if (numero == 1|| numero==2 || numero==3)
    {
        for (i=0; i<17; i++)
        {
            glcd_gotoxy(f4,espaco-5-i-(31*pos),0);
            glcd_write_data(0x0,1);
        }
        for (i=0; i<5; i++)
        {
            glcd_gotoxy(f4,espaco-22-i-(31*pos),0);
            glcd_write_data(0xFF,1);
        }
    }
    else
    {
        if (numero == 4 || numero == 7 || numero == 8 || numero == 9 || numero == 0)
        {
            for (i=0; i<5; i++)
            {
                glcd_gotoxy(f4,espaco-5-i-(31*pos),0);
                glcd_write_data(0xFF,1);
            }
            for (i=0; i<12; i++)
            {
                glcd_gotoxy(f4,espaco-10-i-(31*pos),0);
                glcd_write_data(0x0,1);
            }
            for (i=0; i<5; i++)
            {
                glcd_gotoxy(f4,espaco-22-i-(31*pos),0);
                glcd_write_data(0xFF,1);
            }
        }
        else
        {
            if (numero == 5 || numero == 6)
            {
                for (i=0; i<5; i++)
                {
                    glcd_gotoxy(f4,espaco-5-i-(31*pos),0);
                    glcd_write_data(0xFF,1);
                }
                for (i=0; i<17; i++)
                {
                    glcd_gotoxy(f4,espaco-10-i-(31*pos),0);
                    glcd_write_data(0x0,1);
                }
            }
        }
    }
}

void faixa3(short numero, short pos)
{
    short i;
    if (numero == 1|| numero==7)
    {
        for (i=0; i<17; i++)
        {
            glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
            glcd_write_data(0x0,1);
        }
        glcd_gotoxy(f3,espaco-22-(31*pos),0);
        glcd_write_data(0x81,1);
        glcd_gotoxy(f3,espaco-23-(31*pos),0);
        glcd_write_data(0xC3,1);
        for (i=0; i<3; i++)
        {
            glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
            glcd_write_data(0xE7,1);
        }
    }
    else
    {
        if (numero == 0)
        {
            for (i=0; i<3; i++)
            {
                glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
                glcd_write_data(0xE7,1);
            }
            glcd_gotoxy(f3,espaco-8-(31*pos),0);
            glcd_write_data(0xC3,1);
            glcd_gotoxy(f3,espaco-9-(31*pos),0);
            glcd_write_data(0x81,1);

            for (i=0; i<12; i++)
            {
                glcd_gotoxy(f3,espaco-10-i-(31*pos),0);
                glcd_write_data(0x0,1);
            }
            glcd_gotoxy(f3,espaco-22-(31*pos),0);
            glcd_write_data(0x81,1);
            glcd_gotoxy(f3,espaco-23-(31*pos),0);
            glcd_write_data(0xC3,1);
            for (i=0; i<3; i++)
            {
                glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
                glcd_write_data(0xE7,1);
            }
        }
        else
        {
            if (numero == 2)
            {
                for (i=0; i<3; i++)
                {
                    glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
                    glcd_write_data(0x07,1);
                }
                glcd_gotoxy(f3,espaco-8-(31*pos),0);
                glcd_write_data(0x1B,1);
                glcd_gotoxy(f3,espaco-9-(31*pos),0);
                glcd_write_data(0x3D,1);
                for(i=0; i<12; i++)
                {
                    glcd_gotoxy(f3,espaco-10-i-(31*pos),0);
                    glcd_write_data(0x7E,1);
                }
                glcd_gotoxy(f3,espaco-22-(31*pos),0);
                glcd_write_data(0xBC,1);
                glcd_gotoxy(f3,espaco-23-(31*pos),0);
                glcd_write_data(0xD8,1);
                for (i=0; i<3; i++)
                {
                    glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
                    glcd_write_data(0xE0,1);
                }
            }
            else
            {
                if (numero == 3)
                {
                    for (i=0; i<3; i++)
                    {
                        glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
                        glcd_write_data(0x0,1);
                    }
                    glcd_gotoxy(f3,espaco-8-(31*pos),0);
                    glcd_write_data(0x18,1);
                    glcd_gotoxy(f3,espaco-9-(31*pos),0);
                    glcd_write_data(0x3C,1);
                    for(i=0; i<12; i++)
                    {
                        glcd_gotoxy(f3,espaco-10-i-(31*pos),0);
                        glcd_write_data(0x7E,1);
                    }
                    glcd_gotoxy(f3,espaco-22-(31*pos),0);
                    glcd_write_data(0x81,1);
                    glcd_gotoxy(f3,espaco-23-(31*pos),0);
                    glcd_write_data(0xC3,1);
                    for (i=0; i<3; i++)
                    {
                        glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
                        glcd_write_data(0xE7,1);
                    }
                }
                else
                {
                    if(numero == 4)
                    {
                        for (i=0; i<3; i++)
                        {
                            glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
                            glcd_write_data(0xE0,1);
                        }
                        glcd_gotoxy(f3,espaco-8-(31*pos),0);
                        glcd_write_data(0xD8,1);
                        glcd_gotoxy(f3,espaco-9-(31*pos),0);
                        glcd_write_data(0xBC,1);
                        for(i=0; i<12; i++)
                        {
                            glcd_gotoxy(f3,espaco-10-i-(31*pos),0);
                            glcd_write_data(0x7E,1);
                        }
                        glcd_gotoxy(f3,espaco-22-(31*pos),0);
                        glcd_write_data(0x81,1);
                        glcd_gotoxy(f3,espaco-23-(31*pos),0);
                        glcd_write_data(0xC3,1);
                        for (i=0; i<3; i++)
                        {
                            glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
                            glcd_write_data(0xE7,1);
                        }
                    }
                    else
                    {
                        if(numero == 5)
                        {
                            for (i=0; i<3; i++)
                            {
                                glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
                                glcd_write_data(0xE0,1);
                            }
                            glcd_gotoxy(f3,espaco-8-(31*pos),0);
                            glcd_write_data(0xD8,1);
                            glcd_gotoxy(f3,espaco-9-(31*pos),0);
                            glcd_write_data(0xBC,1);
                            for(i=0; i<12; i++)
                            {
                                glcd_gotoxy(f3,espaco-10-i-(31*pos),0);
                                glcd_write_data(0x7E,1);
                            }
                            glcd_gotoxy(f3,espaco-22-(31*pos),0);
                            glcd_write_data(0x3D,1);
                            glcd_gotoxy(f3,espaco-23-(31*pos),0);
                            glcd_write_data(0x1B,1);
                            for (i=0; i<3; i++)
                            {
                                glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
                                glcd_write_data(0x07,1);
                            }
                        }
                        else
                        {
                            if (numero == 6)
                            {
                                for (i=0; i<3; i++)
                                {

                                    glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
                                    glcd_write_data(0xE7,1);

                                }
                                glcd_gotoxy(f3,espaco-8-(31*pos),0);
                                glcd_write_data(0xC3,1);
                                glcd_gotoxy(f3,espaco-9-(31*pos),0);
                                glcd_write_data(0x81,1);
                                for(i=0; i<12; i++)
                                {

                                    glcd_gotoxy(f3,espaco-10-i-(31*pos),0);
                                    glcd_write_data(0x7E,1);

                                }
                                glcd_gotoxy(f3,espaco-22-(31*pos),0);
                                glcd_write_data(0x3D,1);
                                glcd_gotoxy(f3,espaco-23-(31*pos),0);
                                glcd_write_data(0x1B,1);
                                for (i=0; i<3; i++)
                                {
                                    glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
                                    glcd_write_data(0x07,1);
                                }
                            }
                            else
                            {
                                if(numero == 7)
                                {
                                    for (i=0; i<3; i++)
                                    {
                                        glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
                                        glcd_write_data(0xE0,1);
                                    }
                                    glcd_gotoxy(f3,espaco-8-(31*pos),0);
                                    glcd_write_data(0xD8,1);
                                    glcd_gotoxy(f3,espaco-9-(31*pos),0);
                                    glcd_write_data(0xBC,1);
                                    for(i=0; i<12; i++)
                                    {
                                        glcd_gotoxy(f3,espaco-10-i-(31*pos),0);
                                        glcd_write_data(0x7E,1);
                                    }
                                    glcd_gotoxy(f3,espaco-22-(31*pos),0);
                                    glcd_write_data(0x81,1);
                                    glcd_gotoxy(f3,espaco-23-(31*pos),0);
                                    glcd_write_data(0xC3,1);
                                    for (i=0; i<3; i++)
                                    {
                                        glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
                                        glcd_write_data(0xE7,1);
                                    }
                                }
                                else
                                {
                                    if(numero == 8)
                                    {
                                        for (i=0; i<3; i++)
                                        {
                                            glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
                                            glcd_write_data(0xE7,1);
                                        }
                                        glcd_gotoxy(f3,espaco-8-(31*pos),0);
                                        glcd_write_data(0xDB,1);
                                        glcd_gotoxy(f3,espaco-9-(31*pos),0);
                                        glcd_write_data(0xBD,1);
                                        for(i=0; i<12; i++)
                                        {
                                            glcd_gotoxy(f3,espaco-10-i-(31*pos),0);
                                            glcd_write_data(0x7E,1);
                                        }
                                        glcd_gotoxy(f3,espaco-22-(31*pos),0);
                                        glcd_write_data(0xBD,1);
                                        glcd_gotoxy(f3,espaco-23-(31*pos),0);
                                        glcd_write_data(0xDB,1);
                                        for (i=0; i<3; i++)
                                        {
                                            glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
                                            glcd_write_data(0xE7,1);
                                        }
                                    }
                                    else
                                    {
                                        if(numero==9)
                                        {
                                            for (i=0; i<3; i++)
                                            {
                                                glcd_gotoxy(f3,espaco-5-i-(31*pos),0);
                                                glcd_write_data(0xE0,1);
                                            }
                                            glcd_gotoxy(f3,espaco-8-(31*pos),0);
                                            glcd_write_data(0xD8,1);
                                            glcd_gotoxy(f3,espaco-9-(31*pos),0);
                                            glcd_write_data(0xBC,1);
                                            for(i=0; i<12; i++)
                                            {
                                                glcd_gotoxy(f3,espaco-10-i-(31*pos),0);
                                                glcd_write_data(0x7E,1);
                                            }
                                            glcd_gotoxy(f3,espaco-22-(31*pos),0);
                                            glcd_write_data(0xBD,1);
                                            glcd_gotoxy(f3,espaco-23-(31*pos),0);
                                            glcd_write_data(0xDB,1);
                                            for (i=0; i<3; i++)
                                            {
                                                glcd_gotoxy(f3,espaco-24-i-(31*pos),0);
                                                glcd_write_data(0xE7,1);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void faixa4(short numero, short pos)
{
    char f2 = 4;
    short i;
    if (numero == 1|| numero==3 || numero==4 || numero==5 || numero==7 || numero ==9)
    {
        for (i=0; i<17; i++)
        {
            glcd_gotoxy(f2,espaco-5-i-(31*pos),0);
            glcd_write_data(0x0,1);
        }
        for (i=0; i<5; i++)
        {
            glcd_gotoxy(f2,espaco-22-i-(31*pos),0);
            glcd_write_data(0xFF,1);
        }
    }
    else
    {
        if ( numero == 8 || numero == 0 || numero==6)
        {
            for (i=0; i<5; i++)
            {
                glcd_gotoxy(f2,espaco-5-i-(31*pos),0);
                glcd_write_data(0xFF,1);
            }
            for (i=0; i<12; i++)
            {
                glcd_gotoxy(f2,espaco-10-i-(31*pos),0);
                glcd_write_data(0x0,1);
            }
            for (i=0; i<5; i++)
            {
                glcd_gotoxy(f2,espaco-22-i-(31*pos),0);
                glcd_write_data(0xFF,1);
            }
        }
        else
        {
            if (numero == 2)
            {
                for (i=0; i<5; i++)
                {
                    glcd_gotoxy(f2,espaco-5-i-(31*pos),0);
                    glcd_write_data(0xFF,1);
                }
                for (i=0; i<17; i++)
                {
                    glcd_gotoxy(f2,espaco-10-i-(31*pos),0);
                    glcd_write_data(0x0,1);
                }
            }
        }
    }
}

void faixa5(short numero, short pos)
{
    char f1 = 0x3;
    short i;
    if (numero == 5|| numero== 3)
    {
        glcd_gotoxy(f1,espaco-5-(31*pos),0);
        glcd_write_data(0x0,1);
        glcd_gotoxy(f1,espaco-6-(31*pos),0);
        glcd_write_data(0x02,1);
        glcd_gotoxy(f1,espaco-7-(31*pos),0);
        glcd_write_data(0x06,1);
        glcd_gotoxy(f1,espaco-8-(31*pos),0);
        glcd_write_data(0x0E,1);
        glcd_gotoxy(f1,espaco-9-(31*pos),0);
        glcd_write_data(0x1E,1);
        for(i=0; i<12; i++)
        {
            glcd_gotoxy(f1,espaco-10-i-(31*pos),0);
            glcd_write_data(0x3E,1);
        }
        glcd_gotoxy(f1,espaco-22-(31*pos),0);
        glcd_write_data(0xDE,1);
        glcd_gotoxy(f1,espaco-23-(31*pos),0);
        glcd_write_data(0xEE,1);
        glcd_gotoxy(f1,espaco-24-(31*pos),0);
        glcd_write_data(0xF6,1);
        glcd_gotoxy(f1,espaco-25-(31*pos),0);
        glcd_write_data(0xFA,1);
        glcd_gotoxy(f1,espaco-26-(31*pos),0);
        glcd_write_data(0xFC,1);
    }
    else
    {
        if (numero == 7 || numero == 1 || numero == 4 || numero == 9)
        {
            for(i=0; i<17; i++)
            {
                glcd_gotoxy(f1,espaco-5-i-(31*pos),0);
                glcd_write_data(0x0,1);
            }
            glcd_gotoxy(f1,espaco-22-(31*pos),0);
            glcd_write_data(0xC0,1);
            glcd_gotoxy(f1,espaco-23-(31*pos),0);
            glcd_write_data(0xE0,1);
            glcd_gotoxy(f1,espaco-24-(31*pos),0);
            glcd_write_data(0xF0,1);
            glcd_gotoxy(f1,espaco-25-(31*pos),0);
            glcd_write_data(0xF8,1);
            glcd_gotoxy(f1,espaco-26-(31*pos),0);
            glcd_write_data(0xFC,1);
        }
        else
        {
            if (numero == 0 || numero == 6 || numero == 8)
            {
                glcd_gotoxy(f1,espaco-5-(31*pos),0);
                glcd_write_data(0xFC,1);
                glcd_gotoxy(f1,espaco-6-(31*pos),0);
                glcd_write_data(0xFA,1);
                glcd_gotoxy(f1,espaco-7-(31*pos),0);
                glcd_write_data(0xF6,1);
                glcd_gotoxy(f1,espaco-8-(31*pos),0);
                glcd_write_data(0xEE,1);
                glcd_gotoxy(f1,espaco-9-(31*pos),0);
                glcd_write_data(0xDE,1);
                for(i=0; i<12; i++)
                {
                    glcd_gotoxy(f1,espaco-10-i-(31*pos),0);
                    glcd_write_data(0x3E,1);
                }
                glcd_gotoxy(f1,espaco-22-(31*pos),0);
                glcd_write_data(0xDE,1);
                glcd_gotoxy(f1,espaco-23-(31*pos),0);
                glcd_write_data(0xEE,1);
                glcd_gotoxy(f1,espaco-24-(31*pos),0);
                glcd_write_data(0xF6,1);
                glcd_gotoxy(f1,espaco-25-(31*pos),0);
                glcd_write_data(0xFA,1);
                glcd_gotoxy(f1,espaco-26-(31*pos),0);
                glcd_write_data(0xFC,1);
            }
            else
            {
                if (numero == 2)
                {
                    glcd_gotoxy(f1,espaco-5-(31*pos),0);
                    glcd_write_data(0xFC,1);
                    glcd_gotoxy(f1,espaco-6-(31*pos),0);
                    glcd_write_data(0xFA,1);
                    glcd_gotoxy(f1,espaco-7-(31*pos),0);
                    glcd_write_data(0xF6,1);
                    glcd_gotoxy(f1,espaco-8-(31*pos),0);
                    glcd_write_data(0xEE,1);
                    glcd_gotoxy(f1,espaco-9-(31*pos),0);
                    glcd_write_data(0xDE,1);
                    for(i=0; i<12; i++)
                    {
                        glcd_gotoxy(f1,espaco-10-i-(31*pos),0);
                        glcd_write_data(0x3E,1);
                    }
                    glcd_gotoxy(f1,espaco-22-(31*pos),0);
                    glcd_write_data(0x1E,1);
                    glcd_gotoxy(f1,espaco-23-(31*pos),0);
                    glcd_write_data(0x0E,1);
                    glcd_gotoxy(f1,espaco-24-(31*pos),0);
                    glcd_write_data(0x06,1);
                    glcd_gotoxy(f1,espaco-25-(31*pos),0);
                    glcd_write_data(0x02,1);
                    glcd_gotoxy(f1,espaco-26-(31*pos),0);
                    glcd_write_data(0x0,1);
                }
            }
        }
    }
}

void numero(short numero, short pos)
{
    faixa1(numero,pos);
    faixa2(numero,pos);
    faixa3(numero,pos);
    faixa4(numero,pos);
    faixa5(numero,pos);
}

void units_on()
{
    short i;
    glcd_gotoxy(f5,espaco-33-(31*2),0);
    glcd_write_data(0x7C,1);
    glcd_gotoxy(f5,espaco-34-(31*2),0);
    glcd_write_data(0x06,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f5,espaco-35-i-(31*2),0);
        glcd_write_data(0x02,1);
    }
    glcd_gotoxy(f5,espaco-37-(31*2),0);
    glcd_write_data(0x06,1);
    glcd_gotoxy(f5,espaco-38-(31*2),0);
    glcd_write_data(0x7C,1);

}

void units_off()
{
    short i;
    for(i=0; i<7; i++)
    {
        glcd_gotoxy(f5,espaco-33-i-(31*2),0);
        glcd_write_data(0x0,1);
    }
}

void h_on()
{
    short i;
    for(i=0; i<4; i++)
    {
        glcd_gotoxy(f4,espaco-30-i-(31*2),0);
        glcd_write_data(0x80,1);
    }
    glcd_gotoxy(f4,espaco-34-(31*2),0);
    glcd_write_data(0xBF,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f4,espaco-35-i-(31*2),0);
        glcd_write_data(0x84,1);
    }
    glcd_gotoxy(f4,espaco-37-(31*2),0);
    glcd_write_data(0x87,1);
    for(i=0; i<5; i++)
    {
        glcd_gotoxy(f4,espaco-38-i-(31*2),0);
        glcd_write_data(0x80,1);
    }
}

void h_off()
{
    short i;
    for(i=0; i<9; i++)
    {
        glcd_gotoxy(f4,espaco-30-i-(31*2),0);
        glcd_write_data(0x0,1);
    }
}

void percent_on()
{
    espaco = 131-27;
    char f1 = 3;
    char f2 = 4;
    short i;
    glcd_gotoxy(f1,espaco-28-(31*2),0);
    glcd_write_data(0xC0,1);
    glcd_gotoxy(f1,espaco-29-(31*2),0);
    glcd_write_data(0x80,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f1,espaco-34-i-(31*2),0);
        glcd_write_data(0xC0,1);
    }
    glcd_gotoxy(f2,espaco-29-(31*2),0);
    glcd_write_data(0xC1,1);
    glcd_gotoxy(f2,espaco-30-(31*2),0);
    glcd_write_data(0xC3,1);
    glcd_gotoxy(f2,espaco-31-(31*2),0);
    glcd_write_data(0x06,1);
    glcd_gotoxy(f2,espaco-32-(31*2),0);
    glcd_write_data(0x0C,1);
    glcd_gotoxy(f2,espaco-33-(31*2),0);
    glcd_write_data(0x18,1);
    glcd_gotoxy(f2,espaco-34-(31*2),0);
    glcd_write_data(0x30,1);
    glcd_gotoxy(f2,espaco-35-(31*2),0);
    glcd_write_data(0x60,1);
    glcd_gotoxy(f2,espaco-36-(31*2),0);
    glcd_write_data(0xC0,1);
    espaco = 131-24;
}

void percent_off()
{
    espaco = 131-27;
    char f2 = 4;
    short i;
    for(i=0; i<9; i++)
    {
        glcd_gotoxy(f2,espaco-28-(31*2)-i,0);
        glcd_write_data(0x0,1);
    }
    for(i=0; i<10; i++)
    {
        glcd_gotoxy(f3,espaco-28-(31*2)-i,0);
        glcd_write_data(0x0,1);
    }
    espaco = 131-24;
}

void bolt_on()
{
    espaco = 127;
    char f1 = 3;
    char f2 = 4;
    short i;
    glcd_gotoxy(f2,espaco,0);
    glcd_write_data(0x1,1);
    glcd_gotoxy(f2,espaco-1,0);
    glcd_write_data(0x2,1);
    glcd_gotoxy(f2,espaco-2,0);
    glcd_write_data(0x4,1);
    glcd_gotoxy(f2,espaco-3,0);
    glcd_write_data(0x8,1);
    glcd_gotoxy(f2,espaco-4,0);
    glcd_write_data(0x10,1);
    glcd_gotoxy(f2,espaco-5,0);
    glcd_write_data(0x26,1);
    glcd_gotoxy(f2,espaco-6,0);
    glcd_write_data(0x5A,1);
    glcd_gotoxy(f2,espaco-7,0);
    glcd_write_data(0x62,1);
    glcd_gotoxy(f2,espaco-8,0);
    glcd_write_data(0x2,1);
    glcd_gotoxy(f2,espaco-9,0);
    glcd_write_data(0x3,1);

    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f1,espaco-i,0);
        glcd_write_data(0x80,1);
    }
    glcd_gotoxy(f1,espaco-2,0);
    glcd_write_data(0x8C,1);
    glcd_gotoxy(f1,espaco-3,0);
    glcd_write_data(0xB4,1);
    glcd_gotoxy(f1,espaco-4,0);
    glcd_write_data(0xC8,1);
    glcd_gotoxy(f1,espaco-5,0);
    glcd_write_data(0x10,1);
    glcd_gotoxy(f1,espaco-6,0);
    glcd_write_data(0x20,1);
    glcd_gotoxy(f1,espaco-7,0);
    glcd_write_data(0x40,1);
    glcd_gotoxy(f1,espaco-8,0);
    glcd_write_data(0x80,1);
    espaco = 131-24;
}

void bolt_off()
{
    short espaco = 127;
    char f1 = 3;
    char f2 = 4;
    short i;
    for(i=0; i<9; i++)
    {
        glcd_gotoxy(f2,espaco-i,0);
        glcd_write_data(0x0,1);
    }
    for(i=0; i<9; i++)
    {
        glcd_gotoxy(f1,espaco-i,0);
        glcd_write_data(0x0,1);
    }
}

void continuo_on()
{
    short espaco = 130;
    char f1 = 6;
    char f2 = 5;
    short i;
    glcd_gotoxy(f1,espaco,0);
    glcd_write_data(0x1F,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f1,espaco-1-i,0);
        glcd_write_data(0x10,1);
    }
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f1,espaco-3-i,0);
        glcd_write_data(0x11,1);
    }
    glcd_gotoxy(f1,espaco-5,0);
    glcd_write_data(0x1F,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f1,espaco-6-i,0);
        glcd_write_data(0x10,1);
    }
    glcd_gotoxy(f1,espaco-8,0);
    glcd_write_data(0x11,1);
    glcd_gotoxy(f1,espaco-9,0);
    glcd_write_data(0x13,1);
    glcd_gotoxy(f1,espaco-10,0);
    glcd_write_data(0x1F,1);
    for (i=0; i<3; i++)
    {
        glcd_gotoxy(f1,espaco-11-i,0);
        glcd_write_data(0x13,1);
    }
    glcd_gotoxy(f1,espaco-14,0);
    glcd_write_data(0x11,1);
    glcd_gotoxy(f1,espaco-15,0);
    glcd_write_data(0x1F,1);

    glcd_gotoxy(f2,espaco,0);
    glcd_write_data(0xFE,1);
    glcd_gotoxy(f2,espaco-1,0);
    glcd_write_data(0x62,1);
    glcd_gotoxy(f2,espaco-2,0);
    glcd_write_data(0xE2,1);
    for (i=0; i<2; i++)
    {
        glcd_gotoxy(f2,espaco-3-i,0);
        glcd_write_data(0x82,1);
    }
    glcd_gotoxy(f2,espaco-5,0);
    glcd_write_data(0xFE,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f2,espaco-6-i,0);
        glcd_write_data(0x62,1);
    }
    glcd_gotoxy(f2,espaco-8,0);
    glcd_write_data(0xC2,1);
    glcd_gotoxy(f2,espaco-9,0);
    glcd_write_data(0x82,1);
    glcd_gotoxy(f2,espaco-10,0);
    glcd_write_data(0xFE,1);
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f2,espaco-11-i,0);
        glcd_write_data(0x02,1);
    }
    for(i=0; i<2; i++)
    {
        glcd_gotoxy(f2,espaco-13-i,0);
        glcd_write_data(0x82,1);
    }
    glcd_gotoxy(f2,espaco-15,0);
    glcd_write_data(0xFE,1);
}

void continuo_off()
{
    short espaco = 130;
    char f1 = 6;
    char f2 = 5;
    short i;
    for (i=0; i<16; i++)
    {
        glcd_gotoxy(f2,espaco-i,0);
        glcd_write_data(0x0,1);
        glcd_gotoxy(f1,espaco-i,0);
        glcd_write_data(0x0,1);
    }
}

void ponto_on()
{
    char f1 = 0x3;
    short i;
    for(i=0; i<7; i++)
    {
        glcd_gotoxy(f1,espaco-28-i-(31*1),0);
        glcd_write_data(0x7E,1);
    }
}

void ponto_off()
{
    char f1 = 0x3;
    short i;
    for(i=0; i<7; i++)
    {
        glcd_gotoxy(f1,espaco-28-i-(31*1),0);
        glcd_write_data(0x0,1);
    }
}
