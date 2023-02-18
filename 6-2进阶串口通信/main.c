#include <REGX52.H>

unsigned char command=0;
//======串口初始化函数======
void Uart_Init(void)		//4800bps@12.000MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
//	AUXR &= 0xBF;		//定时器1时钟为Fosc/12,即12T
//	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xF3;		//设定定时初值
	TH1 = 0xF3;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	
	ES=1;
	EA=1;
}


void delay(unsigned char t)
{
	while(t--);
}
//==========发送一个字节==========
void Send_Byte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}
//================================

//==========发送一个字符串========
void Send_String(unsigned char *str)
{
	while(*str!='\0')
	{
		Send_Byte(*str++);
		delay(255);
	}
}
//==========接收一个字节==========
void Receiv_Byte() interrupt 4
{
	if(RI==1)
	{
	RI=0;
	command=SBUF;
	}
}
//================================
void work()
{
	if(command!=0x00)
	{
		switch(command & 0xf0)
		{
			case 0xa0:P2=(P2 |0x0f)&(~command|0xf0);command=0;break;
			case 0xb0:P2=(P2 |0xf0)&(~command << 4|0x0f);command=0;break;
			case 0xc0:Send_String("The System is Running...");command=0;break;
		}
	}
}
void main()
{
	Uart_Init();
	Send_String("Welcome to XMF system!");
	while(1)
	{
		work();
	}
}