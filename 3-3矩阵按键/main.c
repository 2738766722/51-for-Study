#include <REGX52.H>
#include "Lcd1602.h"
#include "matrix.h"

extern unsigned char KeyNumber;

void main()
{

	LCD_Init();

	while(1)
	{
		ScanKey();
		if(KeyNumber<30)
		{
		LCD_ShowNum(1,1,KeyNumber,2);
		}
	}
}