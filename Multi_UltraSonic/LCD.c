#include "LCD.h"
// Sending Pulse with 2 m sec Width To make the LCD take the data and store it or take the command and do it
void enable()
{
	DIO_Write_Pin(CONTROL_PORT,EN,HIGH);
	_delay_ms(2);
	DIO_Write_Pin(CONTROL_PORT,EN,LOW);
	_delay_ms(2);
}
// Write on Data Register ( Receive from data pins as a data to print )
void Data_Register_Select()
{
	DIO_Write_Pin(CONTROL_PORT,RS,HIGH);
}
// // Write on Instruction Register ( Receive from data pins as a CMD to do )
void Cmd_Register_Select()
{
	DIO_Write_Pin(CONTROL_PORT,RS,LOW);
}
// Set the Direction of data ( Read == 1 ) ( Write == 0 ) ( Pin 5 in LCD ) ( In case of connecting R/W With MC )
void LCD_Data_Direction(u8 DIRECTION)
{
	DIO_Write_Pin(CONTROL_PORT,RW,DIRECTION);
}
// Send Command to LCD to do
void LCD_Send_Cmd(u8 COMMAND)
{
	Cmd_Register_Select();
#if defined EIGHT_BIT_MODE
	DIO_WritePort(DATA_PORT,COMMAND);
	enable();
#elif defined FOUR_BIT_MODE
#if defined HIGH_NIBBLE
	DIO_Write_High_Nibble(DATA_PORT,COMMAND>>FOUR);
	enable();
	DIO_Write_High_Nibble(DATA_PORT,COMMAND);
	enable();
#elif defined LOW_NIBBLE
	DIO_Write_Low_Nibble(DATA_PORT,COMMAND>>FOUR);
	enable();
	DIO_Write_Low_Nibble(DATA_PORT,COMMAND);
	enable();
#endif // for Nibble
#endif // For Mode
}
// Clear LCD Screen
void LCD_Clear_Screen()
{
	LCD_Send_Cmd(CLR_SCREEN);
	_delay_ms(10);
}
//Return The Cursor at the beginning of LCD
void LCD_Return_Home()
{
	LCD_Send_Cmd(RETURN_HOME);
	_delay_ms(10);
}
// Make the cursor Move Right After writing a Char in the place where the Cursor stand
void EntryMode()
{
	LCD_Send_Cmd(ENTRY_MODE);
	_delay_ms(1);
}
void LCD_DiplayON_CursorON()
{
	LCD_Send_Cmd(DISPLAYON_CURSORON);
	_delay_ms(1);
}
void LCD_DiplayON_CursorOff()
{
	LCD_Send_Cmd(DISPLAYON_CURSOROFF);
	_delay_ms(1);
}
void LCD_DiplayON_CursorBlink()
{
	LCD_Send_Cmd(DISPLAYON_CURSORBLINK);
	_delay_ms(1);
}
void LCD_CursorToLeft()
{
	LCD_Send_Cmd(CURSOR_TO_LEFT);
}
void LCD_CursorToRight()
{
	LCD_Send_Cmd(CURSOR_TO_RIGHT);
}
void LCD_Writing_To_Left()
{
	LCD_Send_Cmd(WRITING_TO_LEFT);
	_delay_ms(1);
}
void LCD_Shift_Display_Right()
{
	LCD_Send_Cmd(SHIFT_DISPLAY_TO_RIGHT);
}
void LCD_Shift_Display_Left()
{
	LCD_Send_Cmd(SHIFT_DISPLAY_TO_LEFT);
}
void LCD_Move_Cursor(u8 ROW, u8 COLUMN){
	u8 COMMAND = 0x80;
	if (ROW > LCD_ROWS || ROW < 1 || COLUMN > LCD_COLUMNS || COLUMN < 1)
	{
		LCD_Send_Cmd(COMMAND);
	}
	else if (ROW == 1)
	{
		COMMAND = 0x80 + (COLUMN - 1);
		LCD_Send_Cmd(COMMAND);
	}
	else if (ROW == 2)
	{
		COMMAND = 0xC0 + (COLUMN - 1);
		LCD_Send_Cmd(COMMAND);
	}
	/*
	 * else if tany lw el rows zado
	 * bt3dl el command w el equation lw el rows zado aw el columns mn el datasheet
	 */

}
// Send character to LCD To display it
void LCD_vSendChar(u8 DATA)
{
	Data_Register_Select();
#if defined EIGH_BIT_MODE
	DIO_WritePort(DATA_PORT,DATA);
	enable();
#elif defined FOUR_BIT_MODE
#if defined HIGH_NIBBLE
	DIO_Write_High_Nibble(DATA_PORT,DATA>>FOUR);
	enable();
	DIO_Write_High_Nibble(DATA_PORT,DATA);
	enable();
#elif defined LOW_NIBBLE
	DIO_Write_Low_Nibble(DATA_PORT,DATA>>FOUR);
	enable();
	DIO_Write_Low_Nibble(DATA_PORT,DATA);
	enable();
#endif // for Nibble
#endif // for Mode
}
// Send String To Print It
void LCD_vSendString(u8 *DATA)
{
	while ((*DATA) != 0)
	{
		LCD_vSendChar(*DATA);
		DATA++;
	}
}
//Initializing LCD
void LCD_vInit()
{
	_delay_ms(200);
#if defined EIGHT_BIT_MODE
	DIO_Set_Port_Direction(DATA_PORT,FULL_PORT_OUTPUT);
	DIO_Set_Pin_Direction(CONTROL_PORT,RS,OUTPUT);
	DIO_Set_Pin_Direction(CONTROL_PORT,RW,OUTPUT);
	DIO_Set_Pin_Direction(CONTROL_PORT,EN,OUTPUT);
	//LCD_Data_Direction(0);
	LCD_Send_Cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_Return_Home();
	LCD_DiplayON_CursorON();
	LCD_Clear_Screen();
	EntryMode();
#elif defined FOUR_BIT_MODE
#if defined HIGH_NIBBLE
	DIO_Set_High_Nibble_Direction(DATA_PORT,OUTPUT);
#elif defined LOW_NIBBLE
	DIO_Set_Low_Nibble_Direction(DATA_PORT,OUTPUT);
#endif // For Nibble
	DIO_Set_Pin_Direction(CONTROL_PORT,RS,OUTPUT);
	DIO_Set_Pin_Direction(CONTROL_PORT,RW,OUTPUT);
	DIO_Set_Pin_Direction(CONTROL_PORT,EN,OUTPUT);
	//LCD_Data_Direction(0);
	LCD_Send_Cmd(FOUR_BITS_1);
	_delay_ms(1);
	LCD_Send_Cmd(FOUR_BITS_2);
	_delay_ms(1);
	LCD_Return_Home();
	LCD_DiplayON_CursorON();
	LCD_Clear_Screen();
	EntryMode();
#endif // For Mode
}
void LCD_Integer_To_String(uint16 DATA)
{
	char BUFF[16]; /* String to hold the ascii result */
	itoa(DATA,BUFF,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_vSendString(BUFF); /* Display the string */
}
