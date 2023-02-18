#include <REGX52.H>

unsigned char command=0;
//======���ڳ�ʼ������======
void Uart_Init(void)		//4800bps@12.000MHz
{
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;		//8λ����,�ɱ䲨����
//	AUXR &= 0xBF;		//��ʱ��1ʱ��ΪFosc/12,��12T
//	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xF3;		//�趨��ʱ��ֵ
	TH1 = 0xF3;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
	
	ES=1;
	EA=1;
}


void delay(unsigned char t)
{
	while(t--);
}
//==========����һ���ֽ�==========
void Send_Byte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}
//================================

//==========����һ���ַ���========
void Send_String(unsigned char *str)
{
	while(*str!='\0')
	{
		Send_Byte(*str++);
		delay(255);
	}
}
//==========����һ���ֽ�==========
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