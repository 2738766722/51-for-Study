#include <REGX52.H>

sbit Led=P2^0;
sbit Bu1=P3^1;

//=========变量定义==========
unsigned int TimerCount=0;
static unsigned int Compare=0;

//============定时器初始化函数==========
void Timer_Init()
{
	TMOD=0x01;
	TF0=0;
	TR0=1;
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	
	ET0=1;
	EA=1;
}
//=======================================



void Delay(unsigned char t)
{
while(t--);
}

void main()
{
	Timer_Init();
	while(1)
	{
		if(Bu1==0)
		{
		Delay(10);
			if(Bu1==0)
			{
				if(Compare==0)
					{
					Compare=10;
					}
				else if(Compare==10)
					{
					Compare=50;
					}
				else if(Compare==50)
					{
					Compare=90;
					}
				else if(Compare==90)
					{
					Compare=0;
					}
				while(Bu1==0);
			}
		}
	}
}//==========定时器中断服务函数========
void Timer_Servor() interrupt 1
{
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TimerCount++;
	TimerCount%=101;
	if(TimerCount>Compare)
	{
		Led=1;
	}
	else Led=0;
}