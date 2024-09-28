#include "DIO.h"
#include "Timers.h"
#include "Registers.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

/*
Function Name        : Trigger
Function Returns     : void
Function Arguments   : u8 TRIGGER_PORT, u8 TRIGGER_PIN
Function Description : Sending Pulse with 2 micro sec Width to send pulses
*/
void Trigger(u8 TRIGGER_PORT, u8 TRIGGER_PIN);

/*
Function Name        : UltraSonic_vint
Function Returns     : void
Function Arguments   : u8 TRIGGER_PORT, u8 TRIGGER_PIN
Function Description : Set trigger pin
*/
void UltraSonic_vint(u8 TRIGGER_PORT, u8 TRIGGER_PIN);

/*
Function Name        : UltraSonic_ICR_Read
Function Returns     : void
Function Arguments   : u8 TRIGGER_PORT, u8 TRIGGER_PIN
Function Description : Read From UltraSonic Sensor
*/
u16 UltraSonic_ICR_Read(u8 TRIGGER_PORT, u8 TRIGGER_PIN);
