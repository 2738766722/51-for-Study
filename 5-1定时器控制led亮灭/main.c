#include <REGX52.H>

void Timer_Init()
{
	TMOD=0x01;       //定时器0工作在模式一
	TF0=0;          //定时器0的中断溢出标志位
	TR0=1;          //定时器0的运行允许
	TL0=(65535-50000)%256;  //给定时器赋初始值
	TH0=(65535-50000)/256;
	ET0=1;          //定时器0的中断开关
	EA=1;					//中断总开关
}
		static unsigned int T0Count;
		static unsigned int T0Count1;

void Timer_Servor() interrupt 1  //定时器0的中断服务函数
{
	TL0=(65535-50000)%256;  //给定时器赋初始值
	TH0=(65535-50000)/256;
	
	T0Count++;
	T0Count1++;
	
	if(T0Count==10)
	{
	T0Count=0;
	P2_0=~P2_0;
	}
	
	if(T0Count1==100)
	{
	T0Count1=0;
	P2_7=~P2_7;
	}
}

void main()
{
	Timer_Init();
	while(1)
	{

	}
}
