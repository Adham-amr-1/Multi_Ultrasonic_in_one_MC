/*
 * STD_Macros.h
 *
 * Created 3/10/2024 10:17:05
 * Author: Adham Amr
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_
/********************************************/
// Bit Manipulation
// Dealing With BIT
#define REGISTER_SIZE 8
#define SET_BIT(REG,BIT_NO)      ( REG|=(1<<BIT_NO) )
#define CLEAR_BIT(REG,BIT_NO)       ( REG&=(~(1<<BIT_NO)) )
#define TOGGLE_BIT(REG,BIT_NO)      ( REG^=(1<<BIT_NO) )
#define READ_BIT(REG,BIT_NO)        ((REG&(1<<BIT_NO))>>BIT_NO)
// Returns 1 if the Bit is Set
#define IS_BIT_SET(REG,BIT_NO)      ((REG&(1<<BIT_NO))>>BIT_NO)
// Returns 1 if the Bit is Clear
#define IS_BIT_CLR(REG,BIT_NO)     !((REG&(1<<BIT_NO))>>BIT_NO)
#define ROR(REG,ROTATE_NUM)             ( REG = (REG<<(REGISTER_SIZE-ROTATE_NUM)) | (REG>>ROTATE_NUM) )
#define ROL(REG,ROTATE_NUM)             ( REG = (REG>>(REGISTER_SIZE-ROTATE_NUM)) | (REG<<ROTATE_NUM) )
/*********************************/
// Dealing With Whole Register
#define TOGGLE_PORT(REG) (REG ^= 0xff)
#define WRITE_PORT(REG,REG_VALUE) (REG = REG_VALUE)
#define READ_WHOLE_PORT(REG) REG
/*********************************/
// Dealing With Nibbles
// Set Nibbles 
#define SET_HIGH_NIBBLE(REG) ( REG |= 0xf0 )
#define SET_LOW_NIBBLE(REG)  ( REG |= 0x0f )
// Clear Nibbles
#define CLEAR_HIGH_NIBBLE(REG) ( REG &= 0x0f )
#define CLEAR_LOW_NIBBLE(REG)  ( REG &= 0xf0 )
/*********************************/
#define SET_2_BITS(REG, BIT1, BIT2) ( REG |= ((1<<BIT1) | (1<<BIT2)) )
#define SET_3_BITS(REG, BIT1, BIT2, BIT3) ( REG |= ((1<<BIT1) | (1<<BIT2) | (1<<BIT3)) )
/*********************************/
// MACROS FOR ELIMINATING THE MAGIC NUMBERS FOR THE DIRECTION PORTS >> INPUT | OUTPUT
#define INPUT 0
#define OUTPUT 1
/*********************************/
// MACROS FOR PORT
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
/*********************************/
//MACROS FOR PIN NUMBER TO ELIMINATE MAGIC NUMBERS FOR USAGE WITH PORTS AND DDRS REGISTERS INSTEAD OF WRITING 0 >> 7
#define PIN_NO_0 0
#define PIN_NO_1 1
#define PIN_NO_2 2
#define PIN_NO_3 3
#define PIN_NO_4 4
#define PIN_NO_5 5
#define PIN_NO_6 6
#define PIN_NO_7 7
/*********************************/
//FOR LEDS ON/OFF
#define LED__ON       1
#define LED__OFF      0
//FOR Buzzer ON/OFF
#define BUZZER_ON    1
#define BUZZER_OFF   0
/*********************************/
//For Push Buttons
//CONSIDERING PULLUP ACTIVATION
//#define NOT_PRESSED 1
//#define PRESSED 0
/*********************************/
//MACROS FOR NUMBERS
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
/*********************************/
//MACROS FOR SEVEN SEGMENTS OPERATION 
/* ORDER OF SGEMENTS LETTERS
	   			     0b(hgfedcba)
 */
//for Common cathode
#define ZERO_SEG_K  0x3f
#define ONE_SEG_K   0x06
#define TWO_SEG_K   0x5b
#define THREE_SEG_K 0x4f
#define FOUR_SEG_K  0x66
#define FIVE_SEG_K  0x6d
#define SIX_SEG_K   0x7d
#define SEVEN_SEG_K 0x47
#define EIGHT_SEG_K 0x7f
#define NINE_SEG_K  0x6f

/*********************************/

//for Common anode
//ORDER OF SGEMENTS LETTERS
//				     hgfedcba

#define ZERO_SEG_A  ~0x3f
#define ONE_SEG_A   ~0x06
#define TWO_SEG_A   ~0x5b
#define THREE_SEG_A ~0x4f
#define FOUR_SEG_A  ~0x66
#define FIVE_SEG_A  ~0x6d
#define SIX_SEG_A   ~0x7d
#define SEVEN_SEG_A ~0x47
#define EIGHT_SEG_A ~0x7f
#define NINE_SEG_A  ~0x6f

/*********************************/
#define HIGH_NIBBLE      1
#define LOW_NIBBLE       0
#define HIGH             1
#define LOW              0
#define FULL_PORT_OUTPUT 0xff
#define FULL_PORT_INPUT  0x00
//#define LOW_PORT_OUTPUT 
#define ERROR -1

/* FOR KEYPAD */ 

#define NOT_PRESSED 0xff

#endif /* STD_MACROS_H_ */
