#include <REG51F.H>
sbit r1=P2^0;
sbit r2=P2^1;
sbit r3=P2^2;
sbit r4=P2^3;
sbit c1=P2^4;
sbit c2=P2^5;
sbit c3=P2^6;
sbit c4=P2^7;

void keypad(void);
void delay(unsigned int itime);
void main()
{
   while(1)
   {
	keypad();
	delay(500);
   }

}

void keypad(void)
{
 	r1=0;
 	r2=r3=r4=1;
	{
	 if(c1==0)
 		{
 		 P0=0;
 		}
 	if(c2==0)
  		{
  		 P0=1;
  		}
 	if(c3==0)
 		{
 		 P0=2;
		 }
 	if(c4==0)
 		{
 		 P0=3;
 		}
	}

 	r2=0;
 	r1=r3=r4=1;
 	{
 	 if(c1==0)
 		{
  		P0=4;
		 }
 	if(c2==0)
  		{
   		P0=5;
  		}
 	if(c3==0)
 		{
 		 P0=6;
		}
 	if(c4==0)
 		{
 	 P0=7;
 		}
	}

	 r3=0;
	 r2=r1=r4=1;
	{
	 if(c1==0)
 		{
 		 P0=8;
 		}
 	if(c2==0)
  		{
  		 P0=9;
  		}
 	if(c3==0)
		 {
 		 P0=10;
 		}
 	if(c4==0)
 		{
  		P0=11;
		 }
	}
 	r4=0;
	 r2=r3=r1=1;
	 {
	 if(c1==0)
 		{
  		P0=12;
		 }
 	if(c2==0)
  		{
  		 P0=13;
 		}
 	if(c3==0)
 		{
 		 P0=14;
 		}
 	if(c4==0)
 		{
 		 P0=15;
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