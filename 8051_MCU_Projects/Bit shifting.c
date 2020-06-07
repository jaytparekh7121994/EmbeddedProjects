#include <REG51F.H>
void delay(unsigned int itime);
void main()
{
 int i;
 while(1)
 { 
 P0=0x01;
 delay(500);
 for(i=0;i<8;i++)
 {
   P0=P0<<1;
   delay(500);
 }
 }
}

void delay(unsigned int itime)
{
  int i,j;
  for(i=0;i<itime;i++)
  {
   for(j=0;j<120;j++);
  }
}