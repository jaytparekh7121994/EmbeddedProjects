#include <REG51F.H>

void delay(unsigned int itime);

void main()
{
while(1)
{
 P0=0xFF;
delay(5000);
 P0=0x00;
delay(5000);
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