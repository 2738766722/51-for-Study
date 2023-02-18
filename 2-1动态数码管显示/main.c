#include <REGX52.H>
#include "Digital.h"
unsigned char i=1;
extern void Delay(unsigned int xms);

void display ()
{
	   Dispaly(1,2);
		Dispaly(2,0);
		Dispaly(3,2);
		Dispaly(4,2);
		Dispaly(5,16);
		Dispaly(6,16);
		Dispaly(7,(i/10));
		Dispaly(8,(i%10));
}
void delay1(unsigned char t)  //对数码管整体显示延时
{
	while(t--)
	{
	display();
	}
}

void main()
{
	while(1)
	{
//	display();
		i++;
		if(i>12)
		{i=1;}
		delay1(100);
	}
}