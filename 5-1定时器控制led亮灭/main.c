#include <REGX52.H>

void Timer_Init()
{
	TMOD=0x01;       //��ʱ��0������ģʽһ
	TF0=0;          //��ʱ��0���ж������־λ
	TR0=1;          //��ʱ��0����������
	TL0=(65535-50000)%256;  //����ʱ������ʼֵ
	TH0=(65535-50000)/256;
	ET0=1;          //��ʱ��0���жϿ���
	EA=1;					//�ж��ܿ���
}
		static unsigned int T0Count;
		static unsigned int T0Count1;

void Timer_Servor() interrupt 1  //��ʱ��0���жϷ�����
{
	TL0=(65535-50000)%256;  //����ʱ������ʼֵ
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
