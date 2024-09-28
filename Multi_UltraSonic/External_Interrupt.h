/*
 * External_Interrupt.h 
 *
 * Created: 6 / 18 / 2024 6:36:16 PM
 *  Author: Adham Amr
 */ 
#include "Registers.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#include <avr/interrupt.h>
#define RISE_EDGE 0x03
#define FALLING_EDGE 0x02
#define LOW_VOLT 0x00
#define ANY_CHANGE 0x01

#ifndef EXTERN_INTERRUPT_H_
#define EXTERN_INTERRUPT_H_

/*
	Function Name        : Set_Global_Interrupt
	Function Returns     : void
	Function Arguments   : No Argument
	Function Description : Enable Interrupt
*/

void Set_Global_Interrupt();
/*
	Function Name        : Clear_Global_Interrupt
	Function Returns     : void
	Function Arguments   : No Arguments
	Function Description : Disable Interrupt
*/
void Clear_Global_Interrupt();


/*
	Function Name        : INT0_INIT
	Function Returns     : void
	Function Arguments   : u8 SENSING_MODE
	Function Description : Initialize the Interrupt if INT0 and it's sensing for interrupt
*/
void INT0_INIT(u8 SENSING_MODE);

/*
	Function Name        : INT1_INIT
	Function Returns     : void
	Function Arguments   : u8 SENSING_MODE
	Function Description : Initialize the Interrupt if INT1 and it's sensing for interrupt
*/
void INT1_INIT(u8 SENSING_MODE);

/*
	Function Name        : INT2_INIT
	Function Returns     : void
	Function Arguments   : u8 SENSING_MODE
	Function Description : Initialize the Interrupt if INT2 and it's sensing for interrupt
*/
void INT2_INIT(u8 SENSING_MODE);

/* Extra Function */
/*
	Function Name        : CheckIRQ0
	Function Returns     : unsigned char
	Function Arguments   : No Argument
	Function Description : Check if there's interrupt happen or not
*/
u8 CheckIRQ0();

/*
	Function Name        : CheckIRQ1
	Function Returns     : unsigned char
	Function Arguments   : No Argument
	Function Description : Check if there's interrupt happen or not
*/
u8 CheckIRQ1();

/*
	Function Name        : CheckIRQ2
	Function Returns     : unsigned char
	Function Arguments   : No Argument
	Function Description : Check if there's interrupt happen or not
*/
u8 CheckIRQ2();

/* Needed Functions For Applying the Nested Interrupt */

/*
	Function Name        : SET_ENABLE_INT0
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Set Enable bit of INT0 
*/
void SET_ENABLE_INT0();

/*
	Function Name        : SET_ENABLE_INT1
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Set Enable bit of INT1
*/
void SET_ENABLE_INT1();

/*
	Function Name        : SET_ENABLE_INT2
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Set Enable bit of INT2
*/
void SET_ENABLE_INT2();

/*
	Function Name        : Clear_ENABLE_INT0
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Clear Enable bit of INT0
*/
void Clear_ENABLE_INT0();

/*
	Function Name        : Clear_ENABLE_INT1
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Clear Enable bit of INT1
*/
void Clear_ENABLE_INT1();

/*
	Function Name        : Clear_ENABLE_INT2
	Function Returns     : Void
	Function Arguments   : No Argument
	Function Description : Clear Enable bit of INT2
*/
void Clear_ENABLE_INT2();

/*
To Apply Nested Interrupt Back To IVT In Data Sheet
ISR Code Steps
1- Enable Interrupt
2- Disable Low Priority Interrupts ( to make the interrupt comes from the High Priority Interrupts Only )
3- Write Interrupt code 
4- Enable Low Priority Interrupts
*/

/****************** pointer to function to use callback functions ***********************/
void (*INT0_ISR)(void) ;
void (*INT1_ISR)(void) ;
void (*INT2_ISR)(void) ;
/****************************************************************************************/


#endif /* EXTERN_INTERRUPT_H_ */
