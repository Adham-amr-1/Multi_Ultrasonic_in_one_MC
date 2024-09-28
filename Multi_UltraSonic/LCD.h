/*
 * LCD.h
 *
 * Created: 6 / 28 / 2024 10:36:16 AM
 *  Author: Adham Amr
 */ 
#include "LCD_CONFIG.h"
#include "DIO.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#include "Registers.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define CLR_SCREEN 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define DISPLAYON_CURSORON 0x0E
#define DISPLAYON_CURSOROFF 0x0C
#define DISPLAYON_CURSORBLINK 0x0F
#define CURSOR_TO_LEFT 0x14
#define CURSOR_TO_RIGHT 0x10
#define WRITING_TO_LEFT 0X04
#define SHIFT_DISPLAY_TO_RIGHT 0x1C 
#define SHIFT_DISPLAY_TO_LEFT 0x18

#ifndef status
#define status
#define HIGH_NIBBLE 
#endif

#define CONTROL_PORT 'A'
#define DATA_PORT 'A'
#define EN 0
#define RS 1
#define RW 2

#if defined FOUR_BIT_MODE
#define FOUR_BITS_1 0x02
#define FOUR_BITS_2 0x28
#elif defined EIGHT_BIT_MODE
#define EIGHT_BITS 0x38
#endif
#define LCD_ROWS    2
#define LCD_COLUMNS 16




#ifndef LCD_H_
#define	LCD_H_


/*
Function Name        : enable
Function Returns     : void
Function Arguments   : void
Function Description : Sending Pulse with 2 m sec Width to Tell The LCD to take the data from data pins as input
 */
void enable();

/*
Function Name        : Data_Register_Select
Function Returns     : static void
Function Arguments   : No Arguments
Function Description : Select The place where The data that came from MC as Data to be stored in Data Register to display it
 */
void Data_Register_Select();

/*
Function Name        : Cmd_Register_Select
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Select The place where The data that came from MC as Command to be stored in Instruction Register to do it 
 */
void Cmd_Register_Select();

/*
Function Name        : LCD_Data_Direction
Function Returns     : void
Function Arguments   : u8 DIRECTION
Function Description : Set The data Direction ( Reading from LCD or Writing on LCD ) 
 */
void LCD_Data_Direction(u8 DIRECTION);

/*
Function Name        : LCD_Send_Cmd
Function Returns     : void
Function Arguments   : u8 COMMAND
Function Description : Send Command To LCD To do it 
 */
void LCD_Send_Cmd(u8 COMMAND);

/*
Function Name        : LCD_Clear_Screen
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Clear LCD Screen
 */
void LCD_Clear_Screen();

/*
Function Name        : LCD_Return_Home
Function Returns     : void
Function Arguments   : No Argument
Function Description : Return the cursor at the beginning of LCD
 */
void LCD_Return_Home();

/*
Function Name        : EntryMode
Function Returns     : static void
Function Arguments   : No Argument
Function Description : Used In Initialization
 */
void EntryMode();

/*
Function Name        : LCD_DiplayON_CursorOn
Function Returns     : void
Function Arguments   : No Argument
Function Description : Set The Display ON and Cursor ON
 */
void LCD_DiplayON_CursorON();
/*

Some CMDS Will Be Defined Here

 */

/*
Function Name        : LCD_Move_Cursor
Function Returns     : void
Function Arguments   : u8 ROW, u8 COLUMN
Function Description : Used In Initialization
 */
void LCD_Move_Cursor(u8 ROW, u8 COLUMN);

/*
Function Name        : LCD_vSendChar
Function Returns     : void
Function Arguments   : u8 DATA
Function Description : Send a character to LCD To display it
 */
void LCD_vSendChar(u8 DATA);

/*
Function Name        : LCD_vSendString
Function Returns     : void
Function Arguments   : u8 *DATA
Function Description : Send a String to LCD To display it
 */
void LCD_vSendString(u8 *DATA);

/*
Function Name        : LCD_vInit
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Initialize the LCD To Be Ready For Use
 */
void LCD_vInit();


/*
Function Name        : LCD_DiplayON_CursorOff
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Display the Character , Hide the Cursor
 */
void LCD_DiplayON_CursorOff();

/*
Function Name        : LCD_DiplayON_CursorBlink
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Display the Character , Blinking the Cursor
 */
void LCD_DiplayON_CursorBlink();

/*
Function Name        : LCD_Shift_Display_Right
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Move The Whole Display to Right ( 2 Rows )
 */
void LCD_Shift_Display_Right();

/*
Function Name        : LCD_Shift_Display_Left
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Move The Whole Display to Left ( 2 Rows )
 */
void LCD_Shift_Display_Left();

/*
Function Name        : LCD_Cursor_To_Right
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Move Cursor To Right Without Typing
 */
void LCD_Cursor_To_Right();

/*
Function Name        : LCD_Cursor_To_Left
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Move Cursor To Left Without Typing
 */
void LCD_Cursor_To_Left();

/*
Function Name        : LCD_Writing_To_Left
Function Returns     : void
Function Arguments   : No Arguments
Function Description : Set Cursor To Move Left When typing A char
 */
void LCD_Writing_To_Left();

/*
Function Name        : LCD_Integer_To_String
Function Returns     : void
Function Arguments   : uint16 DATA
Function Description : Take Integer Number And Turn it Into String and Display it
 */
void LCD_Integer_To_String(uint16 DATA);


#endif /* LCD_H_ */
