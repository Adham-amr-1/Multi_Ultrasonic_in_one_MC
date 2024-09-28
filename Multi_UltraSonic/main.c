/*
 * main.c
 *
 *  Created on: Sep 21, 2024
 *      Author: ADHam
 */
#include "UltraSonic.h"
#include "LCD.h"
#include "Timers.h"
int main(void)
{
	u16 UltraSonic_1, UltraSonic_2, UltraSonic_3,UltraSonic_4;
	LCD_vInit();
	UltraSonic_vint(PORT_C,PIN_NO_0); // Ultra 1
	UltraSonic_vint(PORT_C,PIN_NO_1); // Ultra 2
	UltraSonic_vint(PORT_C,PIN_NO_2); // Ultra 3
	UltraSonic_vint(PORT_C,PIN_NO_3); // Ultra 4
	Timer1_Set_OverFlow_Mode();
	Timer1_Stop_Count();
	LCD_DiplayON_CursorOff();
	while(1)
	{
		UltraSonic_1 = UltraSonic_ICR_Read(PORT_C,PIN_NO_0);
		UltraSonic_2 = UltraSonic_ICR_Read(PORT_C,PIN_NO_1);
		UltraSonic_3 = UltraSonic_ICR_Read(PORT_C,PIN_NO_2);
		UltraSonic_4 = UltraSonic_ICR_Read(PORT_C,PIN_NO_3);
		LCD_Move_Cursor(1,1);
		LCD_vSendString("Front:");
		LCD_vSendChar((UltraSonic_1/10) + 48);
		LCD_vSendChar((UltraSonic_1%10) + 48);
		LCD_Move_Cursor(1,10);
		LCD_vSendString("Back:");
		LCD_vSendChar((UltraSonic_2/10) + 48);
		LCD_vSendChar((UltraSonic_2%10) + 48);
		LCD_Move_Cursor(2,1);
		LCD_vSendString("Right:");
		LCD_vSendChar((UltraSonic_3/10) + 48);
		LCD_vSendChar((UltraSonic_3%10) + 48);
		LCD_Move_Cursor(2,10);
		LCD_vSendString("Left:");
		LCD_vSendChar((UltraSonic_4/10) + 48);
		LCD_vSendChar((UltraSonic_4%10) + 48);
		_delay_ms(100);


	}
}

