#include <REGX52.H>

unsigned char date;
//========���ڳ�ʼ��==========
	void Uart_Init(void)		//4800bps@12.000MHz
{
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;		//8λ����,�ɱ䲨����
	
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xF3;		//�趨��ʱ��ֵ
	TH1 = 0xF3;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
	
	EA=1;     
	ES=1;        //���ж�(��Ҫ��Ϊ�����жϷ���)
}
//============================
void Delay(unsigned char t)
{
	while(t--);
}
//=========����һ���ֽ�========
void Uart_SentBit(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

//========����һ���ֽ�=========
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