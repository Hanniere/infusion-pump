#include "msp430FG437.h"

short espaco_tabela = 131-4;
char l1 = 0;
char l2 = 1;
char l3 = 2;
char l4 = 3;
char l5 = 4;
char l6 = 5;
char l7 = 6;
char l8 = 7;

void num_table_0(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x7F,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x41,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x7F,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x7F,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x41,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x7F,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x7F,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x41,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x7F,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x7F,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x41,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x7F,1);
                }
            }
        }
    }
}

void num_table_1(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x7F,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x0,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x0,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x7F,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x0,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x0,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x7F,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x0,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x0,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x7F,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x0,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x0,1);
                }
            }
        }
    }
}

void num_table_2(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x4F,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x49,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x79,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x4F,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x49,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x79,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x4F,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x49,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x79,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x4F,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x49,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x79,1);
                }
            }
        }
    }
}

void num_table_3(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x49,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x49,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x7F,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x49,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x49,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x7F,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x49,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x49,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x7F,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x49,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x49,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x7F,1);
                }
            }
        }
    }
}

void num_table_4(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x78,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x08,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x7F,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x78,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x08,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x7F,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x78,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x08,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x7F,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x78,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x08,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x7F,1);
                }
            }
        }
    }
}

void num_table_5(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x79,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x49,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x4F,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x79,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x49,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x4F,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x79,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x49,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x4F,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x79,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x49,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x4F,1);
                }
            }
        }
    }
}

void num_table_6(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x7F,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x49,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x4F,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x7F,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x49,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x4F,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x7F,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x49,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x4F,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x7F,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x49,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x4F,1);
                }
            }
        }
    }
}

void num_table_7(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x60,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x40,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x7F,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x60,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x40,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x7F,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x60,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x40,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x7F,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x60,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x40,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x7F,1);
                }
            }
        }
    }
}

void num_table_8(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x7F,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x49,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x7F,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x7F,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x49,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x7F,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x7F,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x49,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x7F,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x7F,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x49,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x7F,1);
                }
            }
        }
    }
}

void num_table_9(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x78,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x48,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x7F,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x78,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x48,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x7F,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x78,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x48,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x7F,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x78,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x48,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x7F,1);
                }
            }
        }
    }
}

void num_table_null(char m, short n, short num_character)
{
    short i;
    n = n--;
    if (num_character == 1)
    {
        glcd_gotoxy(m,espaco_tabela-(20*n),0);
        glcd_write_data(0x0,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-1,0);
        glcd_write_data(0x0,1);
        glcd_gotoxy(m,espaco_tabela-(20*n)-2,0);
        glcd_write_data(0x0,1);
    }
    else
    {
        if (num_character == 2)
        {
            glcd_gotoxy(m,espaco_tabela-(20*n)-4,0);
            glcd_write_data(0x0,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-5,0);
            glcd_write_data(0x0,1);
            glcd_gotoxy(m,espaco_tabela-(20*n)-6,0);
            glcd_write_data(0x0,1);
        }
        else
        {
            if (num_character == 3)
            {
                glcd_gotoxy(m,espaco_tabela-(20*n)-10,0);
                glcd_write_data(0x0,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-11,0);
                glcd_write_data(0x0,1);
                glcd_gotoxy(m,espaco_tabela-(20*n)-12,0);
                glcd_write_data(0x0,1);
            }
            else
            {
                if (num_character == 4)
                {
                    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
                    glcd_write_data(0x0,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
                    glcd_write_data(0x0,1);
                    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
                    glcd_write_data(0x0,1);
                }
            }
        }
    }
}

void num_table_symbol(char m, short n)
{
    short i;
    n = n--;
    glcd_gotoxy(m,espaco_tabela-(20*n)-8,0);
    glcd_write_data(0x08,1);
}

void unity_table (char m, short n)
{
    short i;
    n = n--;
    glcd_gotoxy(m,espaco_tabela-(20*n)-14,0);
    glcd_write_data(0x1E,1);
    glcd_gotoxy(m,espaco_tabela-(20*n)-15,0);
    glcd_write_data(0x02,1);
    glcd_gotoxy(m,espaco_tabela-(20*n)-16,0);
    glcd_write_data(0x1E,1);
}

void tabela_1_on()
{
    short i;
    char m;
    short n;
    m = l8;
    n = 1;
    num_table_0(m, n, 1);
    num_table_0(m, n, 2);
    num_table_symbol(m, n);
    num_table_0(m, n, 3);
    num_table_1(m, n, 4);
    n = 2;
    num_table_0(m, n, 1);
    num_table_1(m, n, 2);
    num_table_symbol(m, n);
    num_table_0(m, n, 3);
    num_table_2(m, n, 4);
    n = 3;
    num_table_0(m, n, 1);
    num_table_2(m, n, 2);
    num_table_symbol(m, n);
    num_table_0(m, n, 3);
    num_table_3(m, n, 4);
    n = 4;
    num_table_0(m, n, 1);
    num_table_3(m, n, 2);
    num_table_symbol(m, n);
    num_table_0(m, n, 3);
    num_table_4(m, n, 4);

    m = l5;
    n = 1;
    num_table_0(m, n, 1);
    num_table_4(m, n, 2);
    num_table_symbol(m, n);
    num_table_0(m, n, 3);
    num_table_5(m, n, 4);
    n = 2;
    num_table_0(m, n, 1);
    num_table_5(m, n, 2);
    num_table_symbol(m, n);
    num_table_0(m, n, 3);
    num_table_6(m, n, 4);
    n = 3;
    num_table_0(m, n, 1);
    num_table_6(m, n, 2);
    num_table_symbol(m, n);
    num_table_0(m, n, 3);
    num_table_7(m, n, 4);
    n = 4;
    num_table_0(m, n, 1);
    num_table_7(m, n, 2);
    num_table_symbol(m, n);
    num_table_0(m, n, 3);
    num_table_8(m, n, 4);

    m = l2;
    n = 1;
    num_table_0(m, n, 1);
    num_table_8(m, n, 2);
    num_table_symbol(m, n);
    num_table_0(m, n, 3);
    num_table_9(m, n, 4);
    n = 2;
    num_table_0(m, n, 1);
    num_table_9(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_0(m, n, 4);
    n = 3;
    num_table_1(m, n, 1);
    num_table_0(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_1(m, n, 4);
    n = 4;
    num_table_1(m, n, 1);
    num_table_1(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_2(m, n, 4);

    for (i = 0; i<22; i++)
    {
        glcd_gotoxy(l6,131-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l6,131-22,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l6,131-23-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l6,131-42,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l6,131-43-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l6,131-62,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l6,131-63-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l6,131-82,0);
    glcd_write_data(0xFF,1);


    for (i = 0; i<22; i++)
    {
        glcd_gotoxy(l3,131-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l3,131-22,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l3,131-23-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l3,131-42,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l3,131-43-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l3,131-62,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l3,131-63-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l3,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l8,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l8,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l8,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l8,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l7,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l7,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l7,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l7,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l5,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l5,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l5,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l5,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l4,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l4,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l4,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l4,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l2,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l2,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l2,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l2,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l1,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l1,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l1,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l1,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l7,131-12,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l7,131-32,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l7,131-52,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l7,131-72,0);
    glcd_write_data(0x01,1);

    glcd_gotoxy(l4,131-12,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l4,131-32,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l4,131-52,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l4,131-72,0);
    glcd_write_data(0x01,1);

    glcd_gotoxy(l1,131-12,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l1,131-32,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l1,131-52,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l1,131-72,0);
    glcd_write_data(0x01,1);

    for(i = 1; i<5; i++)
    {
        unity_table(l7, i);
    }
    for(i = 1; i<5; i++)
    {
        unity_table(l4, i);
    }
    for(i = 1; i<5; i++)
    {
        unity_table(l1, i);
    }
}

void tabela_2_on()
{
    short i;
    char m;
    short n;

    m = l8;
    n = 1;
    num_table_1(m, n, 1);
    num_table_2(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_3(m, n, 4);
    n = 2;
    num_table_1(m, n, 1);
    num_table_3(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_4(m, n, 4);
    n = 3;
    num_table_1(m, n, 1);
    num_table_4(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_5(m, n, 4);
    n = 4;
    num_table_1(m, n, 1);
    num_table_5(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_6(m, n, 4);

    m = l5;
    n = 1;
    num_table_1(m, n, 1);
    num_table_6(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_7(m, n, 4);
    n = 2;
    num_table_1(m, n, 1);
    num_table_7(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_8(m, n, 4);
    n = 3;
    num_table_1(m, n, 1);
    num_table_8(m, n, 2);
    num_table_symbol(m, n);
    num_table_1(m, n, 3);
    num_table_9(m, n, 4);
    n = 4;
    num_table_1(m, n, 1);
    num_table_9(m, n, 2);
    num_table_symbol(m, n);
    num_table_2(m, n, 3);
    num_table_0(m, n, 4);

    m = l2;
    n = 1;
    num_table_2(m, n, 1);
    num_table_0(m, n, 2);
    num_table_symbol(m, n);
    num_table_2(m, n, 3);
    num_table_1(m, n, 4);
    n = 2;
    num_table_2(m, n, 1);
    num_table_1(m, n, 2);
    num_table_symbol(m, n);
    num_table_2(m, n, 3);
    num_table_2(m, n, 4);
    n = 3;
    num_table_2(m, n, 1);
    num_table_2(m, n, 2);
    num_table_symbol(m, n);
    num_table_2(m, n, 3);
    num_table_3(m, n, 4);
    n = 4;
    num_table_2(m, n, 1);
    num_table_3(m, n, 2);
    num_table_symbol(m, n);
    num_table_2(m, n, 3);
    num_table_4(m, n, 4);

    for (i = 0; i<22; i++)
    {
        glcd_gotoxy(l6,131-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l6,131-22,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l6,131-23-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l6,131-42,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l6,131-43-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l6,131-62,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l6,131-63-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l6,131-82,0);
    glcd_write_data(0xFF,1);


    for (i = 0; i<22; i++)
    {
        glcd_gotoxy(l3,131-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l3,131-22,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l3,131-23-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l3,131-42,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l3,131-43-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l3,131-62,0);
    glcd_write_data(0xFF,1);
    for (i = 0; i<19; i++)
    {
        glcd_gotoxy(l3,131-63-i,0);
        glcd_write_data(0x08,1);
    }
    glcd_gotoxy(l3,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l8,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l8,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l8,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l8,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l7,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l7,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l7,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l7,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l5,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l5,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l5,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l5,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l4,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l4,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l4,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l4,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l2,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l2,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l2,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l2,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l1,131-22,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l1,131-42,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l1,131-62,0);
    glcd_write_data(0xFF,1);
    glcd_gotoxy(l1,131-82,0);
    glcd_write_data(0xFF,1);

    glcd_gotoxy(l7,131-12,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l7,131-32,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l7,131-52,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l7,131-72,0);
    glcd_write_data(0x01,1);

    glcd_gotoxy(l4,131-12,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l4,131-32,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l4,131-52,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l4,131-72,0);
    glcd_write_data(0x01,1);

    glcd_gotoxy(l1,131-12,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l1,131-32,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l1,131-52,0);
    glcd_write_data(0x01,1);
    glcd_gotoxy(l1,131-72,0);
    glcd_write_data(0x01,1);

    for(i = 1; i<5; i++)
    {
        unity_table(l7, i);
    }
    for(i = 1; i<5; i++)
    {
        unity_table(l4, i);
    }
    for(i = 1; i<5; i++)
    {
        unity_table(l1, i);
    }
}

void num_table(short num, short m, short n, short character)
{
    switch(num)
    {
    case 0:
        num_table_0(m, n, character);
        break;
    case 1:
        num_table_1(m, n, character);
        break;
    case 2:
        num_table_2(m, n, character);
        break;
    case 3:
        num_table_3(m, n, character);
        break;
    case 4:
        num_table_4(m, n, character);
        break;
    case 5:
        num_table_5(m, n, character);
        break;
    case 6:
        num_table_6(m, n, character);
        break;
    case 7:
        num_table_7(m, n, character);
        break;
    case 8:
        num_table_8(m, n, character);
        break;
    case 9:
        num_table_9(m, n, character);
        break;
    }
}

void fill_table_profile (double number, short mode)
{
    short n1, n2, decimal, m, n;
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
    num_table(n1, linha, n, 1);
    num_table(n2, linha, n, 2);
    num_table(decimal, linha, n, 3);
}
