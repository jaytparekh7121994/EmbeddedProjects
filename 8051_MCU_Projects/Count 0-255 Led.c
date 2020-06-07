#include <REG51F.H>
void delay(unsigned int itime);
void main()
{
 unsigned int i;
 while(1)
 {
 	for(i=0;i<255;i++)
 	{ 	
 		P0=i;
 		delay(1000);
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