#include <REGX52.H>
//按键定义
sbit s7=P3^1;
sbit s6=P3^0;
sbit s5=P3^2;
sbit s4=P3^3;

//led定义
sbit L1=P2^0;
sbit L2=P2^1;
sbit L3=P2^2;
sbit L4=P2^3;
sbit L5=P2^4;
sbit L6=P2^5;
sbit L7=P2^6;
sbit L8=P2^7;

//延时函数
void delay(unsigned char t)
{
while(t--);
}	

//按键扫描函数
void Scankey_Alone()
{
	if(s7==0)
	{
		delay(100);
		if(s7==0)
		{L1=0;
		while(s7==0);
		L1=1;
	}}
	if(s6==0)
	{
		delay(100);
		if(s6==0)
		{L2=0;
		while(s6==0);
		L2=1;
	}}
	if(s5==0)
	{
		delay(100);
		if(s5==0)
		{L3=0;
			while(s5==0);
			L3=1;
	}}
	if(s4==0)
	{
		delay(100);
		if(s4 == 0)
		{	L4=0;
			while(s4==0);
			L4=1;
		}
	}
}
//主函数
void main()
{
	while(1)
	{
Scankey_Alone();
	}
}