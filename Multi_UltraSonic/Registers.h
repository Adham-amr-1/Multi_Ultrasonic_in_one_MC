/*
 * Registers.h
 *
 * Created: 5/12/2024 1:03:58 PM
 *  Author: Adham Amr
 */ 

#include "STD_Types.h"
#ifndef REGISTERS_H_
#define REGISTERS_H_
// DIO Registers
// PORT A
#define PORTA *((volatile  u8*)0x3B)
#define DDRA  *((volatile  u8*)0x3A)
#define PINA  *((volatile  u8*)0x39)
// PORT B
#define PORTB *((volatile  u8*)0x38)
#define DDRB  *((volatile  u8*)0x37)
#define PINB  *((volatile  u8*)0x36)
// PORT C
#define PORTC *((volatile  u8*)0x35)
#define DDRC  *((volatile  u8*)0x34)
#define PINC  *((volatile  u8*)0x33)
// PORT D
#define PORTD *((volatile  u8*)0x32)
#define DDRD  *((volatile  u8*)0x31)
#define PIND  *((volatile  u8*)0x30)

//**********************************************


// INTERRUPT Register

//MCUCR  MCU Control Register
#define MCUCR *((volatile u8*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
//MCUCSR MCU Control and Status Register
#define MCUCSR *((volatile u8*)0x54)
#define ISC2 6
//General Interrupt Control Register � GICR
#define GICR *((volatile u8*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5
//General Interrupt Flag Register � GIFR
#define GIFR *((volatile u8*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5
// Global Interrupt Register SREG
//we deal with I-Bit to enable or disable global interrupt enable
#define SREG *((volatile u8*)0x5F)
#define I_BIT 7
//*******************************

//TIMERS
//*******************************
#define  TIFR *((volatile u8*)0x58)
// TIFR BITS
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0
//*******************************
#define  TIMSK *((volatile u8*)0x59)
// TIMSK BITS
#define OCIE2    7
#define TOIE2    6
#define TICIE1   5
#define OCIE1A   4
#define OCIE1B   3
#define TOIE1    2
#define OCIE0    1
#define TOIE0    0

//*******************************
// TIMER0
// Register
#define TCNT0 *((volatile u8*)0x52)
#define OCR0  *((volatile u8*)0x5C)
//*******************************
#define TCCR0 *((volatile u8*)0x53)
// TCCRO BITS 
#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0

//*******************************
//TIMER1

//Timer/Counter1 Control Register A � TCCR1A
#define	TCCR1A	*((volatile u8*)0x4F)
//Timer/Counter1 Control Register B � TCCR1B
#define	TCCR1B	*((volatile u8*)0x4E)

//Timer/Counter1 � TCNT1H and TCNT1L
#define	TCNT1L	*((volatile u8*)0x4C)
#define	TCNT1H  *((volatile u8*)0x4D)
#define	TCNT1   *((volatile u16*)0x4C)

//Output Compare Register 1 A � OCR1AH and OCR1AL
#define	OCR1AL *((volatile u8*)0x4A)
#define	OCR1AH *((volatile u8*)0x4B)
#define	OCR1A  *((volatile u16*)0x4A)

//Output Compare Register 1 B � OCR1BH and OCR1BL
#define	OCR1BL *((volatile u8*)0x48)
#define	OCR1BH *((volatile u8*)0x49)
#define	OCR1B  *((volatile u16*)0x48)

//Input Capture Register 1 � ICR1H and ICR1L
#define	ICR1L *((volatile u8*)0x46)
#define	ICR1H *((volatile u8*)0x47)
#define	ICR1  *((volatile u16*)0x46)

// Register Bits
// TCCR1A
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0
// TCCR1B
#define ICNC1  7
#define ICES1  6
#define WGM13  4
#define WGM12  3
#define CS12   2
#define CS11   1
#define CS10   0
//*******************************
//TIMER2
//*******************************
// Register
#define	TCCR2 *((volatile u8*)0x45)
// TCCR2 BITS 
#define FOC2  7
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22  2
#define CS21  1
#define CS20  0
//*******************************
//Timer/Counter Register TCNT2
#define	TCNT2 *((volatile u8*)0x44)
//Output Compare Register OCR2
#define	OCR2  *((volatile u8*)0x43)
//*******************************
//Register
#define	ASSR  *((volatile u8*)0x42)
// ASSR BITS
#define AS2 3
#define TCN2UB 2
#define OCR2UB 1
#define TCR2UB 0
//*********************************

//ADC REGISTERS
//ADC Multiplexer Selection Register - ADMUX

//REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0

#define ADMUX *((volatile u8*)0x27)

//ADC Control and Status Register A � ADCSRA

#define ADCSRA *((volatile u8*)0x26)

//The ADC Data Register � ADCL and ADCH

#define ADCL *((volatile u8*)0x24)

#define ADCH *((volatile u8*)0x25)

#define ADC  *((volatile u16*)0x24)

// ADCSRA Bits
#define ADEN   7
#define ADSC   6
#define ADATE  5
#define ADIF   4
#define ADIE   3
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0
// ADMUX Bits
#define REFS1   7
#define REFS0   6
#define ADLAR  5
#define MUX4   4
#define MUX3   3
#define MUX2  2
#define MUX1  1
#define MUX0  0

//Special FunctionIO Register � SFIOR

#define SFIOR *((volatile u8*)0x50)

// EEPROM Registers

#define EEARH *((volatile u8*)0x3F)
#define EEARL *((volatile u8*)0x3E)
#define EEDR  *((volatile u8*)0x3D)
#define EECR  *((volatile u8*)0x3C)

// EECR Bits

#define EERE  0
#define EEWE  1
#define EEMWE 2
#define EERIE 3

// Communication Registers
// USART Registers
#define UCSRA  *((volatile u8*)0x2B)
// UCSRA Bits
#define RXC   7
#define TXC   6
#define UDRE  5
#define FE    4
#define DOR   3
#define PE    2
#define U2X   1
#define MPCM  0
//*********************************
#define UCSRB  *((volatile u8*)0x2A)
// UCSRB Bits
#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN  4
#define TXEN  3
#define UCSZ2 2
#define RXB8  1
#define TXB8  0
//*********************************
#define UCSRC  *((volatile u8*)0x40)
// UCSRC Bits
#define URSEL 7
#define UMSEL 6
#define UPM1  5
#define UPM0  4
#define USBS  3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0
//*********************************
#define UBRRL  *((volatile u8*)0x29)
#define UBRRH  *((volatile u8*)0x40)
#define UDR    *((volatile u8*)0x2C)
//*********************************
//*********************************
// SPI Registers
#define SPCR    *((volatile u8*)0x2D)
// SPCR Bits
#define SPIE  7
#define SPE   6
#define DORD  5
#define MSTR  4
#define CPOL  3
#define CPHA  2
#define SPR1  1
#define SPR0  0
//*********************************
#define SPSR    *((volatile u8*)0x2E)
// SPSR Bits
#define SPIF   7
#define WCOL   6
#define SPI2X  0
//*********************************
#define SPDR    *((volatile u8*)0x2F)

// I2C Registers
#define TWDR    *((volatile u8*)0x23)
#define TWAR    *((volatile u8*)0x22)
//*********************************
// TWAR Bits
#define TWGCE  0
//*********************************
#define TWSR    *((volatile u8*)0x21)
//*********************************
// TWSR Bits
#define TWPS1  1
#define TWPS0  0
//*********************************
#define TWBR    *((volatile u8*)0x20)
#define TWCR    *((volatile u8*)0x56)
//*********************************
// TWSR Bits
#define TWINT  7
#define TWEA   6
#define TWSTA  5
#define TWSTO  4
#define TWWC   3
#define TWEN   2
#define TWIE   0
//*********************************













#endif /* REGISTERS_H_ */
