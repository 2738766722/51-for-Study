#include <REGX52.H>

sbit Led1=P2^0;
sbit Led8=P2^7;

void DelayMs(unsigned char n)
{
	unsigned char i,j;
	for(i=0;i<n;i++)
		for(j=0;j<123;j++);
}
void Working()
{
	Led1=0;
	DelayMs(500);
	Led1=1;
	DelayMs(500);
}
//�ж���غ���
 void Init_INT1()   //�жϳ�ʼ������ 
 {
		IT1=0;
		EX1=1;
		EA=1;
 }

 void ServiceInt1() interrupt 2  //�жϷ�����
 {
	Led8=~Led8;
////	 DelayMs(10000);
////	 Led8=1;
 }
 
//
void main()
{
	 Init_INT1();  
	while(1)
	{
	Working();
	}
}
