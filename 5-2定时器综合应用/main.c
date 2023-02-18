#include <REGX52.H>
#include "Digital.h"

sbit S4=P3^0;
sbit S5=P3^1;

unsigned char TimerCount;
unsigned char t_feng=0;
unsigned char t_miao=0;
unsigned char t_haomiao=0;

void delayk(unsigned char t)
{
	while(t--);
}
//=============定时器初始化函数==========
void Timer_Init()
{
	TMOD=0x01;
	TF0=0;
	TR0=1;
	TL0=(65536-50000)%256;
	TH0=(65536-50000)/256;
	
	ET0=1;
	EA=1;
}
//===========================================

void  SmgDispaly()
{
	Dispaly(8,t_haomiao%10);
	delayk(255);
	Dispaly(7,t_haomiao/10);
	delayk(255);
	Dispaly(6,16);
	delayk(255);
	Dispaly(5,t_miao%10);
	delayk(255);
	Dispaly(4,t_miao/10);
	delayk(255);
	Dispaly(3,16);
	delayk(255);
	Dispaly(2,t_feng%10);
	delayk(255);
	Dispaly(1,t_feng/10);
	delayk(255);
}

//==============中断服务函数================
void Timer_Servor() interrupt 1  
{
	TL0=(65536-50000)%256;
	TH0=(65536-50000)/256;
	
	t_haomiao++;
	if(t_haomiao>=20)
	{
		t_haomiao=0;
		t_miao++;
		if(t_miao>=60)
		{
		t_miao=0;
		t_feng++;
		}
	}
}
//=================================================
void main()
{
	Timer_Init();
	while(1)
	{
		SmgDispaly();
		if(S4==0)
		{
		delayk(100);
			if(S4==0)
			{
				t_haomiao=0;
				t_miao=0;
				t_feng=0;
				while(S4==0)
				{
				SmgDispaly();
				}}
		}
		
		if(S5==0)
		{
		delayk(100);
			if(S5==0)
			{
			TR0=~TR0;
				while(S5==0)
				{
				SmgDispaly();
				}
			}
		}
	}
}