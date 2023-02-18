#include <REGX52.H>

unsigned char date;
//========串口初始化==========
	void Uart_Init(void)		//4800bps@12.000MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xF3;		//设定定时初值
	TH1 = 0xF3;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	
	EA=1;     
	ES=1;        //打开中断(主要是为接收中断服务)
}
//============================
void Delay(unsigned char t)
{
	while(t--);
}
//=========发送一个字节========
void Uart_SentBit(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

//========接收一个字节=========
void Uart_RecevBit() interrupt 4
{
	if(RI==1)
		{
		RI=0;
		date=SBUF;
		Uart_SentBit(date+1);
		}
}

//=============================
//=============================
void main()
{
	Uart_Init();
	Uart_SentBit(0x5a);
	Delay(255);
	Uart_SentBit(0xa5);
	while(1)
	{
		
	}
}