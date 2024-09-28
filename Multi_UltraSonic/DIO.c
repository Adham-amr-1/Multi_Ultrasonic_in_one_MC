#include "DIO.h"
//-------------------------------------------------------------------
/*
Controlling on One Pin
 */
/* Set Direction of pins { input ( 0 ) or Output ( 1 ) }  */
void DIO_Set_Pin_Direction(u8 PORT_NO,u8 PIN_NO,u8 PIN_DIRECTION)
{
	switch (PORT_NO)
	{
	case 'A':
	case 'a':
		switch(PIN_DIRECTION)
		{
		case OUTPUT:
			SET_BIT(DDRA,PIN_NO);
			break;
		case INPUT:
			CLEAR_BIT(DDRA,PIN_NO);
			break;
		}
		break;
	case 'B':
	case 'b':
		switch(PIN_DIRECTION)
		{
		case OUTPUT:
			SET_BIT(DDRB,PIN_NO);
			break;
		case INPUT:
			CLEAR_BIT(DDRB,PIN_NO);
			break;
		}
	break;
	case 'C':
	case 'c':
		switch(PIN_DIRECTION)
		{
		case OUTPUT:
			SET_BIT(DDRC,PIN_NO);
			break;
		case INPUT:
			CLEAR_BIT(DDRC,PIN_NO);
			break;
		}
		break;
		case 'D':
		case 'd':
			switch(PIN_DIRECTION)
			{
			case OUTPUT:
				SET_BIT(DDRD,PIN_NO);
				break;
			case INPUT:
				CLEAR_BIT(DDRD,PIN_NO);
				break;
			}
			break;
			default:
				break;
	}
}
// If The Pin Is Output set it out { High ( 1 ) or Low ( 0 ) }
void DIO_Write_Pin(u8 PORT_NO,u8 PIN_NO,u8 OUTPUT_VALUE)
{
	switch (PORT_NO)
	{
	case 'A':
	case 'a':
		switch(OUTPUT_VALUE)
		{
		case HIGH:
			SET_BIT(PORTA,PIN_NO);
			break;
		case LOW:
			CLEAR_BIT(PORTA,PIN_NO);
			break;
		}
		break;
	case 'B':
	case 'b':
		switch(OUTPUT_VALUE)
		{
		case HIGH:
			SET_BIT(PORTB,PIN_NO);
			break;
		case LOW:
			CLEAR_BIT(PORTB,PIN_NO);
			break;
		}
		break;
	case 'C':
	case 'c':
		switch(OUTPUT_VALUE)
		{
		case HIGH:
			SET_BIT(PORTC,PIN_NO);
			break;
		case LOW:
			CLEAR_BIT(PORTC,PIN_NO);
			break;
		}
		break;
	case 'D':
	case 'd':
		switch(OUTPUT_VALUE)
		{
		case HIGH:
			SET_BIT(PORTD,PIN_NO);
			break;
		case LOW:
			CLEAR_BIT(PORTD,PIN_NO);
			break;
		}
		break;
	default:
		break;
	}
}
// Change pin case from 1 to 0 and vice verse
void DIO_TogglePin(u8 PORT_NO,u8 PIN_NO)
{
	switch (PORT_NO)
	{
	case 'A':
	case 'a':
		TOGGLE_BIT(PORTA,PIN_NO);
		break;
	case 'B':
	case 'b':
		TOGGLE_BIT(PORTB,PIN_NO);
		break;
	case 'C':
	case 'c':
		TOGGLE_BIT(PORTC,PIN_NO);
		break;
	case 'D':
	case 'd':
		TOGGLE_BIT(PORTD,PIN_NO);
		break;
	default:
		break;
	}
}
// Check the I/P Device state
u8 DIO_u8ReadPin(u8 PORT_NO,u8 PIN_NO)
{
	u8 RETURN_VALUE = ZERO;
	switch (PORT_NO)
	{
	case 'A':
	case 'a':
		RETURN_VALUE = READ_BIT(PINA,PIN_NO);
		break;
	case 'B':
	case 'b':
		RETURN_VALUE = READ_BIT(PINB,PIN_NO);
		break;
	case 'C':
	case 'c':
		RETURN_VALUE = READ_BIT(PINC,PIN_NO);
		break;
	case 'D':
	case 'd':
		RETURN_VALUE = READ_BIT(PIND,PIN_NO);
		break;
	default:
		RETURN_VALUE = ERROR;
		break;
	}
	return RETURN_VALUE;
}
//-------------------------------------------------------------------
/*
Controlling on Full Port
 */
// Set All Port 
void DIO_Set_Port_Direction(u8 PORT_NO,u8 PIN_DIRECTION)
{
	switch(PORT_NO)
	{
	case 'A':
	case 'a':
		DDRA = PIN_DIRECTION;
		break;
	case 'B':
	case 'b':
		DDRB = PIN_DIRECTION;
		break;
	case 'C':
	case 'c':
		DDRC = PIN_DIRECTION;
		break;
	case 'D':
	case 'd':
		DDRD = PIN_DIRECTION;
		break;
	default:
		break;
	}
}
// Write on All Port
void DIO_WritePort(u8 PORT_NO,u8 OUTPUT_VALUE)
{
	switch(PORT_NO)
	{
	case 'A':
	case 'a':
		PORTA = OUTPUT_VALUE;
		break;
	case 'B':
	case 'b':
		PORTB = OUTPUT_VALUE;
		break;
	case 'C':
	case 'c':
		PORTC = OUTPUT_VALUE;
		break;
	case 'D':
	case 'd':
		PORTD = OUTPUT_VALUE;
		break;
	default:
		break;
	}
}
// Read Status of The Port
u8 DIO_ReadPort(u8 PORT_NO)
{
	u8 RETURN_VALUE = ZERO;
	switch(PORT_NO){
	case 'A':
	case 'a':
		RETURN_VALUE = PINA;
		break;
	case 'B':
	case 'b':
		RETURN_VALUE = PINB;
		break;
	case 'C':
	case 'c':
		RETURN_VALUE = PINC;
		break;
	case 'D':
	case 'd':
		RETURN_VALUE = PIND;
		break;
	default:
		RETURN_VALUE = ERROR;
		break;
	}
	return RETURN_VALUE;
}
// Toggle Ports 1 to 0 and vice versa
void DIO_TogglePort(u8 PORT_NO)
{
	switch(PORT_NO)
	{
	case 'A':
	case 'a':
		PORTA = TOGGLE_PORT(PORTA);
		break;
	case 'B':
	case 'b':
		PORTB = TOGGLE_PORT(PORTB);
		break;
	case 'C':
	case 'c':
		PORTC = TOGGLE_PORT(PORTC);
		break;
	case 'D':
	case 'd':
		PORTD = TOGGLE_PORT(PORTD);
		break;
	default:
		break;
	}
}
// Active The Pull Up Resistance
void DIO_PullUp_Active(u8 PORT_NO,u8 PIN_NO)
{
	switch (PORT_NO)
	{
	case 'A':
	case 'a':
		SET_BIT(PORTA,PIN_NO); // Set Pin High
		break;
	case 'B':
	case 'b':
		SET_BIT(PORTB,PIN_NO); // Set Pin High
		break;
	case 'C':
	case 'c':
		SET_BIT(PORTC,PIN_NO); // Set Pin High
		break;
	case 'D':
	case 'd':
		SET_BIT(PORTD,PIN_NO); // Set Pin High
		break;
	default:
		break;
	}
}
// DeActive The Pull Up Resistance
void DIO_PullUp_DeActive(u8 PORT_NO,u8 PIN_NO)
{
	switch (PORT_NO){
	case 'A':
	case 'a':
		CLEAR_BIT(PORTA,PIN_NO); // Set Pin Low
		break;
	case 'B':
	case 'b':
		CLEAR_BIT(PORTB,PIN_NO); // Set Pin Low
		break;
	case 'C':
	case 'c':
		CLEAR_BIT(PORTC,PIN_NO); // Set Pin Low
		break;
	case 'D':
	case 'd':
		CLEAR_BIT(PORTD,PIN_NO); // Set Pin Low
		break;
	default:
		break;
	}
}
// Write on Bits from 0 to 3
void DIO_Write_Low_Nibble(u8 PORT_NO,u8 LOW_NIBBLE_VALUE)
{
	LOW_NIBBLE_VALUE&=0x0f;
	switch (PORT_NO)
	{
	case 'A':
	case 'a':
		PORTA&=0xf0;
		PORTA|=LOW_NIBBLE_VALUE;
		break;
	case 'B':
	case 'b':
		PORTB&=0xf0;
		PORTB|=LOW_NIBBLE_VALUE;
		break;
	case 'C':
	case 'c':
		PORTC&=0xf0;
		PORTC|=LOW_NIBBLE_VALUE;
		break;
	case 'D':
	case 'd':
		PORTD&=0xf0;
		PORTD|=LOW_NIBBLE_VALUE;
		break;
	default:
		break;
	}
}
// Write on Bits from 4 to 7
void DIO_Write_High_Nibble(u8 PORT_NO,u8 HIGH_NIBBLE_VALUE)
{
	HIGH_NIBBLE_VALUE<<=FOUR;
	switch (PORT_NO)
	{
	case 'A':
	case 'a':
		PORTA&=0x0f;
		PORTA|=HIGH_NIBBLE_VALUE;
		break;
	case 'B':
	case 'b':
		PORTB&=0x0f;
		PORTB|=HIGH_NIBBLE_VALUE;
		break;
	case 'C':
	case 'c':
		PORTC&=0x0f;
		PORTC|=HIGH_NIBBLE_VALUE;
		break;
	case 'D':
	case 'd':
		PORTD&=0x0f;
		PORTD|=HIGH_NIBBLE_VALUE;
		break;
	default:
		break;
	}
}

void DIO_Set_High_Nibble_Direction(u8 PORT_NO,u8 HIGH_NIBBLE_DIRECTION)
{ // dir = 1 -> output , dir = 0 -> input
	DIO_Set_Pin_Direction(PORT_NO,4,HIGH_NIBBLE_DIRECTION);
	DIO_Set_Pin_Direction(PORT_NO,5,HIGH_NIBBLE_DIRECTION);
	DIO_Set_Pin_Direction(PORT_NO,6,HIGH_NIBBLE_DIRECTION);
	DIO_Set_Pin_Direction(PORT_NO,7,HIGH_NIBBLE_DIRECTION);
}
void DIO_Set_Low_Nibble_Direction(u8 PORT_NO,u8 LOW_NIBBLE_DIRECTION)
{ // dir = 1 -> output , dir = 0 -> input
	DIO_Set_Pin_Direction(PORT_NO,0,LOW_NIBBLE_DIRECTION);
	DIO_Set_Pin_Direction(PORT_NO,1,LOW_NIBBLE_DIRECTION);
	DIO_Set_Pin_Direction(PORT_NO,2,LOW_NIBBLE_DIRECTION);
	DIO_Set_Pin_Direction(PORT_NO,3,LOW_NIBBLE_DIRECTION);
}
//-------------------------------------------------------------------
/* ***** MCAL Driver ***** */
