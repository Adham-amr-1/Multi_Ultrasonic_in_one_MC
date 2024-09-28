#include "UltraSonic.h"

void UltraSonic_vint(u8 TRIGGER_PORT, u8 TRIGGER_PIN)
{
	DIO_Set_Pin_Direction(TRIGGER_PORT, TRIGGER_PIN, OUTPUT);
}
void Trigger(u8 TRIGGER_PORT, u8 TRIGGER_PIN)
{
	DIO_Write_Pin(TRIGGER_PORT, TRIGGER_PIN, HIGH);
	_delay_us(50);
	DIO_Write_Pin(TRIGGER_PORT, TRIGGER_PIN, LOW);
}

u16 UltraSonic_ICR_Read(u8 TRIGGER_PORT, u8 TRIGGER_PIN)
{
	u16 High;
	Timer1_Clear_TCNT1();
	//Timer1_Set_OverFlow_Mode();
	Timer1_Start_Count();
	Timer1_Clear_ICF1_BIT();
	Trigger(TRIGGER_PORT, TRIGGER_PIN);
	Timer1_Set_ICU_Rising_Edge();
	while(Timer1_Check_ICF1_BIT() == 0);
	u16 RISING_CAPTURE = ICR1;
	Timer1_Clear_ICF1_BIT();
	Timer1_Set_ICU_Falling_Edge();
	while(Timer1_Check_ICF1_BIT() == 0);
	u16 FALLING_CAPTURE = ICR1;
	Timer1_Clear_ICF1_BIT();
	Timer1_Stop_Count();
	Timer1_Clear_TCNT1();
	High = FALLING_CAPTURE - RISING_CAPTURE;

	return (High * 2.2144);
}
