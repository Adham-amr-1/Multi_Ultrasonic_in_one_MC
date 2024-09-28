#include "External_Interrupt.h"

/* Enable Global Interrupt */

void Set_Global_Interrupt()
{
	SET_BIT(SREG,I_BIT); // Enable Interrupt
}

/* Disable Global Interrupt */

void Clear_Global_Interrupt()
{
	CLEAR_BIT(SREG,I_BIT); // Disable Interrupt
}

/* Initialize External INT0 */

void INT0_INIT(u8 SENSING_MODE)
{
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_2,INPUT);
	MCUCR |= SENSING_MODE; // Set the pin to sense the interrupt as there's 4 ways to sense
	SET_BIT(GICR,INT0); // Enable the INT0 To Interrupt the MC  ( 6 Is the location of it in GICR ) ( Open The Data Sheet )
}

/* Initialize External INT1 */

void INT1_INIT(u8 SENSING_MODE)
{
	DIO_Set_Pin_Direction(PORT_D,PIN_NO_3,INPUT); // Set Pin As Input to sense the interrupt
	MCUCR |= (SENSING_MODE<<TWO); // Set the pin to sense the interrupt as there's 4 ways to sense
	SET_BIT(GICR,INT1); // Enable the INT1 To Interrupt the MC ( 7 Is the location of it in GICR ) ( Open The Data Sheet )
}

/* Initialize External INT2 */

void INT2_INIT(u8 SENSING_MODE)
{
	DIO_Set_Pin_Direction(PORT_B,PIN_NO_2,INPUT); // Set Pin As Input to sense the interrupt
	if(SENSING_MODE == RISE_EDGE){
		SET_BIT(MCUCSR,SIX); // Set The Sense of interrupt as Rising edge
	}
	if(SENSING_MODE == FALLING_EDGE){
		CLEAR_BIT(MCUCSR,SIX); // Set The Sense of interrupt as Falling edge
	}
	SET_BIT(GICR,INT2); // Enable the INT2 To Interrupt the MC ( 5 Is the location of it in GICR ) ( Open The Data Sheet )
}

/* Extra Function */
/* Check Interrupt Request of INT0 */ /* I Can Read It from Watching Window In Proteus */ 

u8 CheckIRQ0()
{
	return READ_BIT(GIFR,INTF0);
}

/* Check Interrupt Request of INT1 */

u8 CheckIRQ1()
{
	return READ_BIT(GIFR,INTF1);
}

/* Check Interrupt Request of INT2 */

u8 CheckIRQ2()
{
	return READ_BIT(GIFR,INTF2);
}

/* Needed Functions For Applying the Nested Interrupt */

/* Set the INT0 Enable bit */

void SET_ENINT0()
{
	SET_BIT(GICR,INT0);
}

/* Set the INT1 Enable bit */

void SET_ENINT1()
{
	SET_BIT(GICR,INT1);
}

/* Set the INT2 Enable bit */

void SET_ENABLE_INT2()
{
	SET_BIT(GICR,INT2);
}

/* Clear the INT0 Enable bit */

void Clear_ENABLE_INT0()
{
	CLEAR_BIT(GICR,INT0);
}

/* Clear the INT1 Enable bit */

void Clear_ENABLE_INT1()
{
	CLEAR_BIT(GICR,INT1);
}

/* Clear the INT2 Enable bit */

void Clear_ENABLE_INT2()
{
	CLEAR_BIT(GICR,INT2);
}
/***************************************/
ISR(INT0_vect)
{
	INT0_ISR();
}
/***************************************/




/***************************************/
ISR(INT1_vect)
{
	INT1_ISR();
}
/***************************************/




/***************************************/
ISR(INT2_vect)
{
	INT2_ISR();
}
/***************************************/
