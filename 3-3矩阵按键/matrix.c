#include <REGX52.H>
void delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
unsigned char KeyNumber=0;

void ScanKey()
{
	P1=0xff;
	P1_3=0;
	if(P1_7==0){delay(20);while(P1_7==0);delay(10);KeyNumber=0;}
	if(P1_6==0){delay(20);while(P1_6==0);delay(10);KeyNumber=4;}
	if(P1_5==0){delay(20);while(P1_5==0);delay(10);KeyNumber=8;}
	if(P1_4==0){delay(20);while(P1_4==0);delay(10);KeyNumber=12;}
	
	P1=0xff;
	P1_2=0;
	if(P1_7==0){delay(20);while(P1_7==0);delay(10);KeyNumber=1;}
	if(P1_6==0){delay(20);while(P1_6==0);delay(10);KeyNumber=5;}
	if(P1_5==0){delay(20);while(P1_5==0);delay(10);KeyNumber=9;}
	if(P1_4==0){delay(20);while(P1_4==0);delay(10);KeyNumber=13;}
	
	P1=0xff;
	P1_1=0;
	if(P1_7==0){delay(20);while(P1_7==0);delay(10);KeyNumber=2;}
	if(P1_6==0){delay(20);while(P1_6==0);delay(10);KeyNumber=6;}
	if(P1_5==0){delay(20);while(P1_5==0);delay(10);KeyNumber=10;}
	if(P1_4==0){delay(20);while(P1_4==0);delay(10);KeyNumber=14;}
	
	P1=0xff;
	P1_0=0;
	if(P1_7==0){delay(20);while(P1_7==0);delay(10);KeyNumber=3;}
	if(P1_6==0){delay(20);while(P1_6==0);delay(10);KeyNumber=7;}
	if(P1_5==0){delay(20);while(P1_5==0);delay(10);KeyNumber=11;}
	if(P1_4==0){delay(20);while(P1_4==0);delay(10);KeyNumber=15;}
	
}
