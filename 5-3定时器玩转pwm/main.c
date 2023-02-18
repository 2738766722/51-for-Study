#include <REGX52.H>

sbit Led=P2^0;
sbit Bu1=P3^1;

//=========��������==========
unsigned int TimerCount=0;
static unsigned int Compare=0;

//============��ʱ����ʼ������==========
void Timer_Init()
{
	TMOD=0x01;
	TF0=0;
	TR0=1;
	TL0 = 0xA4;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	
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
}//==========��ʱ���жϷ�����========
void Timer_Servor() interrupt 1
{
	TL0 = 0xA4;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TimerCount++;
	TimerCount%=101;
	if(TimerCount>Compare)
	{
		Led=1;
	}
	else Led=0;
}