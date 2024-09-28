/*
 * DIO.h
 *
 * Created: 4 / 6 / 2024 11:36:16 PM
 *  Author: Adham Amr
 */ 

#include "Registers.h"
#include "STD_Types.h"
#include "STD_Macros.h"

#ifndef DIO_H_
#define DIO_H_
/*
	Function Name        : DIO_Set_Pin_Direction
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 PIN_NO,u8 PIN_DIRECTION
	Function Description : Set the direction of the given pin in the given port (dir 0 = input : 1 = output)
*/
void DIO_Set_Pin_Direction(u8 PORT_NO,u8 PIN_NO,u8 PIN_DIRECTION);

/*
	Function Name        : DIO_Write_Pin
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 PIN_NO,u8 OUTPUT_VALUE
	Function Description : Set the value of the given pin in the given port (output 0 = low : 1 = high) 
*/
void DIO_Write_Pin(u8 PORT_NO,u8 PIN_NO,u8 OUTPUT_VALUE);

/*
	Function Name        : DIO_u8ReadPin
	Function Returns     : unsigned char
	Function Arguments   : u8 PORT_NO,u8 PIN_NO
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
u8 DIO_u8ReadPin(u8 PORT_NO,u8 PIN_NO);

/*
	Function Name        : DIO_TogglePin
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 PIN_NO
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_TogglePin(u8 PORT_NO,u8 PIN_NO);

/*
	Function Name        : DIO_Set_Port_Direction
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 PIN_DIRECTION
	Function Description : set the direction of whole port .
*/

void DIO_Set_Port_Direction(u8 PORT_NO,u8 PIN_DIRECTION);

/*
	Function Name        : DIO_WritePort
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 OUTPUT_VALUE
	Function Description : Write the value to all port pins.
*/

void DIO_WritePort(u8 PORT_NO,u8 OUTPUT_VALUE);

/*
	Function Name        : DIO_ReadPort
	Function Returns     : unsigned char
	Function Arguments   : u8 PORT_NO
	Function Description : read the value of the port .
*/
u8 DIO_ReadPort(u8 PORT_NO);

/*
	Function Name        : DIO_TogglePort
	Function Returns     : void
	Function Arguments   : u8 PORT_NO
	Function Description : toggle the value of the port .
*/
void DIO_TogglePort(u8 PORT_NO);

/*
	Function Name        : DIO_PullUp_Active
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 PIN_NO
	Function Description : Active the Internal Pull Up Resistance .
*/
void DIO_PullUp_Active(u8 PORT_NO,u8 PIN_NO);

/*
	Function Name        : DIO_PullUp_DeActive
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 PIN_NO
	Function Description : DisActive the Internal Pull Up Resistance .
*/
void DIO_PullUp_DeActive(u8 PORT_NO,u8 PIN_NO);

/*
	Function Name        : DIO_WriteLowNibble
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 LOW_NIBBLE_VALUE
	Function Description :  Write on the Pins from 0 to 3
*/
void DIO_Write_Low_Nibble(u8 PORT_NO,u8 LOW_NIBBLE_VALUE);

/*
	Function Name        : DIO_Write_High_Nibble
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 HIGH_NIBBLE_VALUE
	Function Description : Write on the Pins from 4 to 7
*/
void DIO_Write_High_Nibble(u8 PORT_NO,u8 HIGH_NIBBLE_VALUE);


/*
	Function Name        : DIO_Set_High_Nibble_Direction
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 HIGH_NIBBLE_DIRECTION
	Function Description : Set Direction of the Pins from 4 to 7
*/
void DIO_Set_High_Nibble_Direction(u8 PORT_NO,u8 HIGH_NIBBLE_DIRECTION);

/*
	Function Name        : DIO_Set_Low_Nibble_Direction
	Function Returns     : void
	Function Arguments   : u8 PORT_NO,u8 LOW_NIBBLE_DIRECTION
	Function Description : Set Direction of the Pins from 0 to 3
*/
void DIO_Set_Low_Nibble_Direction(u8 PORT_NO,u8 LOW_NIBBLE_DIRECTION);
#endif /* DIO_H_ */
