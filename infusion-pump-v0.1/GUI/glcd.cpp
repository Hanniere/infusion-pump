#include "GLCD.h"
#include "msp430FG439.h"

void nt7538_12864_writecommand(char x)
{


    ENset;	// nt7538_12864_rd=1;


    
    
    P1OUT=x;

    RWclr;	//nt7538_12864_wr=0;
//   	OS_Delay(1);
    //for (unsigned short k = 0; k < 10; k++) ;

    RWset;	//nt7538_12864_wr=1;
}

void glcd_setup()
{
    //configura pinos de controle
    RSout;
    RWout;
    ENout;
    CS1out;
    //CS2out;
    RSTout;
    //BLout;
    DATAout;
    P1DIR = 0xFF;

    RSTclr;
    RSclr;
    RWclr;
    ENclr;
    CS1set;
    //CS2set;
    ENset;
//	BLclr;
//	BLset;

    RSclr;	//nt7538_12864_rs=0;

    RSTset;
    RSTclr;

    //OS_Delay(500);
    for (unsigned short k = 0; k < 10; k++);
    RSTset;
    for (unsigned short k = 0; k < 10; k++) ;
    //OS_Delay(500);


    nt7538_12864_writecommand(0xae); // DISPLAY OFF
    nt7538_12864_writecommand(0x40); // Display Start Line Set
    nt7538_12864_writecommand(0xb0); // Page Address Set
    nt7538_12864_writecommand(0x10); // Column Address Set
    nt7538_12864_writecommand(0x00); // Column Address Set
    nt7538_12864_writecommand(0xa1);
    nt7538_12864_writecommand(0xa6);
    nt7538_12864_writecommand(0xc0);
    nt7538_12864_writecommand(0x2f); // POWER CONTROL SETTING

    nt7538_12864_writecommand(0x25); // VO MAX
    nt7538_12864_writecommand(0x81); // SET CONTRAST
    nt7538_12864_writecommand(0x11); //
    nt7538_12864_writecommand(0x85);
    nt7538_12864_writecommand(0x13);
    nt7538_12864_writecommand(0xa2); //bias set
    nt7538_12864_writecommand(0xaf); //1 DISPLAY ON



    CS1clr;
    //CS2clr;


    nt7538_12864_writecommand(0xae); // DISPLAY OFF
    nt7538_12864_writecommand(0x40); // Display Start Line Set
    nt7538_12864_writecommand(0xb0); // Page Address Set
    nt7538_12864_writecommand(0x10); // Column Address Set
    nt7538_12864_writecommand(0x00); // Column Address Set
    nt7538_12864_writecommand(0xa1);
    nt7538_12864_writecommand(0xa6);
    nt7538_12864_writecommand(0xc0);
    nt7538_12864_writecommand(0x2f); // POWER CONTROL SETTING


    nt7538_12864_writecommand(0x25); // VO MAX
    nt7538_12864_writecommand(0x81); // SET CONTRAST
    nt7538_12864_writecommand(0x11); //
    nt7538_12864_writecommand(0x85);
    nt7538_12864_writecommand(0x13);
    nt7538_12864_writecommand(0xa2); //bias set
    nt7538_12864_writecommand(0xaf); //1 DISPLAY ON

}

void glcd_turn_off()
{
    RSclr;
    RWclr;
    ENclr;
    CS1clr;
    //CS2clr;
    RSTclr;
    //BLclr;
    WriteData(0x00);
}

void glcd_turn_on()
{
    glcd_setup();
}

void glcd_gotoxy(unsigned char x, unsigned char y, unsigned char lado)
{

    RSclr;
    nt7538_12864_writecommand((0xB0 + x)); // Column Address Set
    nt7538_12864_writecommand(0x10 + (y>>4)); // Column Address Set
    nt7538_12864_writecommand(0x00 + (y & 0x0F)); // Column Address Set
    RSset;

}

void glcd_write_data(unsigned char dataToWrite,unsigned char lado)
{

    RSset;
    nt7538_12864_writecommand(dataToWrite);

}

void glcd_fill(unsigned char data)
{
    short i, j;

    for (j = 0; j < 8; j++)
    {
        glcd_gotoxy(j, 0, esquerdo);

        for (i = 0; i < 132; i++)
        {
            glcd_write_data(data,0);
        }


    }
}

void glcd_free()
{
    short i, j;

    for (j = 0; j<8; j++)
    {
        for (i = 0; i<132; i++)
        {
            glcd_gotoxy(j, i, esquerdo);
            glcd_write_data(0x00,0);
        }
    }
}
