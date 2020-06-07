#include<REG51F.H>


sbit BL=P0^0;
sbit RS=P0^1;
sbit RW=P0^2;
sbit EN=P0^3;

sbit Full=P1^0;
sbit Half=P1^1;
sbit Quarter=P1^2;
sbit Bottom=P1^3;
sbit Motorled=P1^4;

#define FULLMES "The Tank is full"
#define HALFMES	"The Tank is Half"
#define QUARTERMES "The Tank is 1/4th"
#define BOTTOMMES "The Tank is at Low level"
#define MOTORON "Motor ON"
#define MOTOROFF "Motor Off"

void commands(void);
void en(void);
void DW(unsigned int x);
void CW(unsigned int x);
void delay(unsigned int itime);
void lcd_init(void);
void lcd_str(unsigned char const *ptr);
void Uart_init(void);
void tx(unsigned char ch);
void rx(void);
void tx_str(unsigned char const *ch);

unsigned char const *ch=0;
unsigned char const *ptr=0;
unsigned char temp=0;


void main()
{
Full=Half=Quarter=Bottom=Motorled=1;
lcd_init();
Uart_init();
CW(0x80);
lcd_str("Level Indicator ");
tx_str('\t')  ;
tx_str("Level Indicator");
delay(1000);
lcd_str("F=Full");
lcd_str("H=Half");
lcd_str("Q=Quarter");
lcd_str("B=Bottom");
tx_str("F,H,Q,B");
delay(1000);

 
while(1)
{
CW(0x01);
rx();
commands();
}
}

void lcd_init()
{
 BL=1;
 CW(0x03);
 CW(0x03);
 CW(0x03);
 CW(0x02);
 CW(0x28);
 CW(0x01);
 CW(0x06);
 CW(0x0c);
}

void CW(unsigned int x)
{
RS=0;
RW=0;
P0=(P0&0x0f)| (x&0xf0);
en();
P0=(P0&0x0f)| (x<<4 & 0xf0);
en();
}

void DW(unsigned int x)
{
RW=0;	
RS=1;
P0=(P0&0x0f)| (x&0xf0);
en();
P0=(P0&0x0f)| (x<<4 & 0xf0);
en();
}

void en()
{
 EN=1;
 delay(5);
 EN=0;
}

void delay(unsigned int itime)
{
 int i,j;
 for(i=0;i<itime;i++)
 {
 for(j=0;j<120;j++);
 }
}

void Uart_init(void)
{
 TMOD=0x20;
 TH1=0xfd;
 TR1=1;
 SCON=0x50;
}


void lcd_str(unsigned char const *ptr)
{ CW(0x80);
 while(*ptr!='\0')
 {
  DW(*ptr);
  ptr++;
 }
}


void tx_str(unsigned char const *ch)
{
 while(*ch!='\0')
 {
  tx(*ch);
  ch++;
 }
}

void tx(unsigned char ch)
{
 SBUF=ch;
 while(TI==0);
 TI=0;
}

void rx(void)
{
 while(RI==0);
 temp=SBUF;
 RI=0;
}

void commands(void)
{
  if(temp=='F')
  {
   Full=0;
   Motorled=Bottom=Half=Quarter=1;
   lcd_str(FULLMES);
   tx_str(FULLMES);
   delay(1000);
   lcd_str(MOTOROFF);
   tx_str(MOTOROFF);
   delay(1000);
  }
  else if(temp=='H')
  {
   Half=0;
   Bottom=Full=Motorled=Quarter=1;
   lcd_str(HALFMES);
   tx_str(HALFMES);
  }
  else if(temp=='Q')
  {
   Quarter=Motorled=0;
   Full=Bottom=Half=1;
   
   lcd_str(QUARTERMES);
   tx_str(QUARTERMES);
   delay(1000);
   
   lcd_str(MOTOROFF);
   tx_str(MOTOROFF);
   delay(1000);
  }
  else if(temp=='B')
  {
   Bottom=0;
   Motorled=Full=Half=Quarter=1;

   lcd_str(BOTTOMMES);
   tx_str(BOTTOMMES);
  }
  else
  {
   lcd_str("Entered Value is incorrect");
   tx_str("Entered Value is incorrect");
  }
}