#include "msp430FG439.h"

#define RSout P2DIR |= 0x04  //A0
#define RWout P2DIR |= 0x02  //WR
#define ENout P2DIR |= 0x01  //R0
#define CS1out P5DIR |= 0x80  //CS1
//#define CS2out P5DIR |= 0x80  //CS2
#define RSTout P2DIR |= 0x08   //Res
#define DATAout P1DIR = 0xFF	

#define RSset P2OUT |= 0x04
#define RWset P2OUT |= 0x02
#define ENset P2OUT |= 0x01
#define CS1set P5OUT |= 0x80
//#define CS2set P5OUT |= 0x80
#define RSTset P2OUT |= 0x08
#define DATAset P1OUT = 0xFF

#define RSclr P2OUT &= ~0x04
#define RWclr P2OUT &= ~0x02
#define ENclr P2OUT &= ~0x01
#define CS1clr P5OUT &= ~0x80
//#define CS2clr P5OUT &= ~0x80
#define RSTclr P2OUT &= ~0x08
#define DATAout P1OUT &= ~0xFF

#define BLUE 1
#define WHITE 0

#define LINE  0
#define BAR  1

#define direito 0
#define esquerdo 1
#define DIR 0
#define ESQ 1

#define RIGHT_ARROW 'z' + 4
#define WriteData(data) P1OUT = data;

#define DATAshf	0