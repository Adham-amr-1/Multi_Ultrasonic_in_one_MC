#define F_CPU 8000000UL
#include "DIO.h"
#include "Registers.h"
#include "STD_Macros.h"
#include "STD_Types.h"
#include "External_Interrupt.h"


/* TIMER 0 MACROS */
// For Clk Signal
#define TIMER0_NO_CLK                    0
#define TIMER0_DIVIDE_CLK_BY_1           0
#define TIMER0_DIVIDE_CLK_BY_8           0
#define TIMER0_DIVIDE_CLK_BY_64          0
#define TIMER0_DIVIDE_CLK_BY_256         0
#define TIMER0_DIVIDE_CLK_BY_1024        1
// For Sensing
#define TIMER0_EXTERNAL_FALLING_EDGE     0
#define TIMER0_EXTERNAL_RISING_EDGE      1
// For Fast PWM
#define TIMER0_SET_OCO_ON_BOTTOM         1  // Natural Case
#define TIMER0_SET_OCO_ON_COMPARE_MATCH  0  // Inverting case
// For Phase Correct PWM
#define TIMER0_SET_OCO_ON_DOWN_COUNTING  1  // Natural Case
#define TIMER0_SET_OCO_ON_UP_COUNTING    0  // Inverting case
/******************************/
/* TIMER 1 MACROS*/
// For Clk Signal
#define TIMER1_NO_CLK                    0
#define TIMER1_DIVIDE_CLK_BY_1           0
#define TIMER1_DIVIDE_CLK_BY_8           0
#define TIMER1_DIVIDE_CLK_BY_64          0
#define TIMER1_DIVIDE_CLK_BY_256         0
#define TIMER1_DIVIDE_CLK_BY_1024        1
// For Sensing
#define TIMER1_EXTERNAL_FALLING_EDGE     0
#define TIMER1_EXTERNAL_RISING_EDGE      1
// For Fast PWM Mode
#define TIMER1_SET_OC1A_ON_BOTTOM        1
#define TIMER1_SET_OC1A_ON_COMPARE_MATCH 0

#define TIMER1_SET_OC1B_ON_BOTTOM        1
#define TIMER1_SET_OC1B_ON_COMPARE_MATCH 0

#define TIMER1_SET_ICR1_ON_BOTTOM        1
#define TIMER1_SET_ICR1_ON_COMPARE_MATCH 0
//For Fast PWM in Bits
#define FAST_PWM_8_BIT                   1
#define FAST_PWM_9_BIT                   0
#define FAST_PWM_10_BIT                  0
//For Phase Correct PWM
#define PHASE_CORRECT_PWM_8_BIT          1
#define PHASE_CORRECT_PWM_9_BIT          0
#define PHASE_CORRECT_PWM_10_BIT         0

#define TIMER1_SET_OCRA_ON_DOWNCOUNTING  1  // Natural Case
#define TIMER1_SET_OCRA_ON_UPCOUNTING    0  // Inverting case

#define TIMER1_SET_OCRB_ON_DOWNCOUNTING  1  // Natural Case
#define TIMER1_SET_OCRB_ON_UPCOUNTING    0  // Inverting case
/******************************/
/* TIMER 2 MACROS*/
#define TIMER2_NO_CLK                    0
#define TIMER2_DIVIDE_CLK_BY_1           0
#define TIMER2_DIVIDE_CLK_BY_8           0
#define TIMER2_DIVIDE_CLK_BY_32          0
#define TIMER2_DIVIDE_CLK_BY_64          0
#define TIMER2_DIVIDE_CLK_BY_128         0
#define TIMER2_DIVIDE_CLK_BY_256         0
#define TIMER2_DIVIDE_CLK_BY_1024        1

// For Fast PWM
#define TIMER2_SET_OC2_ON_BOTTOM         1  // Natural Case
#define TIMER2_SET_OC2_ON_COMPARE_MATCH  0  // Inverting case
// For Phase Correct PWM
#define TIMER2_SET_OC2_ON_DOWN_COUNTING  1  // Natural Case
#define TIMER2_SET_OC2_ON_UP_COUNTING    0  // Inverting case
// Clock Select
#define TIMER2_EXTERNAL                  0
#define TIMER2_INTERNAL                  1
/******************************/
/* WATCH DOG TIMER MACROS*/

/******************************/



#ifndef TIMER_H_
#define TIMER_H_
/*====================================================================================*/
/*   TIMER0 Functions */
/*====================================================================================*/
/*
	Function Name        : Timer0_Set_Clk
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the clk that timer use.
 */
void Timer0_Set_Clk(void);

/*
	Function Name        : Timer0_Stop_Count
	Function Returns     : void
	Function Arguments   : void
	Function Description : Stop timer0 from counting.
 */
void Timer0_Stop_Count(void);

/*
	Function Name        : Timer0_Start_Count
	Function Returns     : void
	Function Arguments   : void
	Function Description : Timer0 Start Counts .
 */
void Timer0_Start_Count(void);


/*
	Function Name        : Timer0_Pin_T0_Sense
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the PB0 Pin to count events by set the sense method.
 */
void Timer0_Pin_T0_Sense(void);

/*
	Function Name        : Timer0_Set_OverFlow_Mode
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the Timer to make interrupt on overflow mode.
 */
void Timer0_Set_OverFlow_Mode(void);

/*
	Function Name        : Timer0_Set_CTC_Mode
	Function Returns     : void
	Function Arguments   : u8 OCRO_VALUE
	Function Description : Set the Timer to make interrupt on Compare match mode.
 */
void Timer0_Set_CTC_Mode(u8 OCRO_VALUE);

/*
	Function Name        : Timer0_CTC_Generate_Signal
	Function Returns     : void
	Function Arguments   : u8 OCRO_VALUE
	Function Description : Generate Signal at compare match.
 */
void Timer0_CTC_Generate_Signal(u8 OCRO_VALUE);

/*
	Function Name        : Timer0_Set_FastPWM_Mode
	Function Returns     : void
	Function Arguments   : u8 OCRO_VALUE
	Function Description : Generate PWM Signal on OCO Pin using Fast PWM .
 */
void Timer0_Set_FastPWM_Mode(u8 OCRO_VALUE);

/*
	Function Name        : PWM_Timer0_Generate
	Function Returns     : void
	Function Arguments   : u8 SPEED_PERCENT
	Function Description : Generate PWM Signal on OCO Pin Using Percentage of Time on.
 */
void PWM_Timer0_Generate(u8 SPEED_PERCENT);

/*
	Function Name        : Timer0_Set_PhaseCorrect_PWM_Mode
	Function Returns     : void
	Function Arguments   : u8 OCRO_VALUE
	Function Description : Generate PWM Signal on OCO Pin Using Phase Correct PWM.
 */
void Timer0_Set_PhaseCorrect_PWM_Mode(u8 OCRO_VALUE);

/*
	Function Name        : Timer0_Clear_TCNT10
	Function Returns     : void
	Function Arguments   : void
	Function Description : Clear TCNT0 Counter.
 */
void Timer0_Clear_TCNT0();

/*====================================================================================*/
/* TIMER1 Decleration*/
/*====================================================================================*/

/*
	Function Name        : Timer1_Set_Clk
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the clk that timer use.
 */
void Timer1_Set_Clk(void);

/*
	Function Name        : Timer1_Stop_Count
	Function Returns     : void
	Function Arguments   : void
	Function Description : Stop timer1 from counting.
 */
void Timer1_Stop_Count(void);

/*
	Function Name        : Timer1_Start_Count
	Function Returns     : void
	Function Arguments   : void
	Function Description : Timer1 Start Counts .
 */
void Timer1_Start_Count(void);

/*
	Function Name        : Timer1_Pin_T1_Sense
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the PB0 Pin to count events by set the sense method.
 */
void Timer1_Pin_T1_Sense(void);

/*
	Function Name        : Timer1_Set_OverFlow_Mode
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the Timer to make interrupt on overflow mode.
 */
void Timer1_Set_OverFlow_Mode(void);

/*
	Function Name        : Timer1_Set_OCRA_CTC_Mode
	Function Returns     : void
	Function Arguments   : u16 OCR1A_VALUE
	Function Description : Set the Timer to make interrupt on Compare match mode.
 */
void Timer1_Set_OCRA_CTC_Mode(u16 OCR1A_VALUE);

/*
	Function Name        : Timer1_Set_ICR_CTC_Mode
	Function Returns     : void
	Function Arguments   : u16 ICR1_VALUE
	Function Description : Set the Timer to make interrupt on Compare match mode.
 */
void Timer1_Set_ICR_CTC_Mode(u16 ICR1_VALUE);

/*
	Function Name        : Timer1_Set_OCRB_CTC_Mode
	Function Returns     : void
	Function Arguments   : u16 OCR1B_VALUE
	Function Description : Set the Timer to make interrupt on Compare match mode.
 */
void Timer1_Set_OCRB_CTC_Mode(u16 OCR1B_VALUE);

/*
	Function Name        : Timer1_CTC_OCRA_Generate_Signal
	Function Returns     : void
	Function Arguments   : u8 OCR1A_VALUE
	Function Description : Generate Signal at compare match.
 */
void Timer1_CTC_OCRA_Generate_Signal(u16 OCR1A_VALUE);

/*
	Function Name        : Timer1_CTC_OCRB_Generate_Signal
	Function Returns     : void
	Function Arguments   : u8 OCR1B_VALUE
	Function Description : Generate Signal at compare match.
 */
void Timer1_CTC_OCRB_Generate_Signal(u16 OCR1B_VALUE);

/*
	Function Name        : Timer1_Set_OCA_FastPWM_Mode
	Function Returns     : void
	Function Arguments   : u16 OCR1A_VALUE
	Function Description : Generate PWM Signal on OC1A Pin using Fast PWM .
 */
void Timer1_Set_OCA_FastPWM_Mode(u16 OCR1A_VALUE);

/*
	Function Name        : Timer1_Set_OCA_FastPWM_Mode
	Function Returns     : void
	Function Arguments   : u16 OCR1B_VALUE
	Function Description : Generate PWM Signal on OC1B Pin using Fast PWM .
 */
void Timer1_Set_OCB_FastPWM_Mode(u16 OCR1B_VALUE);

/*
	Function Name        : Timer1_Set_OCA_FastPWM_Mode_Using_Bits
	Function Returns     : void
	Function Arguments   : void
	Function Description : Generate PWM Signal on OC1A Pin using Fast PWM .
 */
void Timer1_Set_OCA_FastPWM_Mode_Using_Bits();

/*
	Function Name        : Timer1_Set_OCB_FastPWM_Mode_Using_Bits
	Function Returns     : void
	Function Arguments   : void
	Function Description : Generate PWM Signal on OC1B Pin using Fast PWM .
 */
void Timer1_Set_OCB_FastPWM_Mode_Using_Bits();

/*
	Function Name        : PWM_Timer1A_Generate
	Function Returns     : void
	Function Arguments   : u8 SPEED_PERCENT
	Function Description :  Generate PWM Signal on OC1A Pin Using Percentage of Time on. .
 */
void PWM_Timer1A_Generate(u8 SPEED_PERCENT);

/*
	Function Name        : PWM_Timer1B_Generate
	Function Returns     : void
	Function Arguments   : u8 SPEED_PERCENT
	Function Description :  Generate PWM Signal on OC1B Pin Using Percentage of Time on. .
 */
void PWM_Timer1B_Generate(u8 SPEED_PERCENT);

/*
	Function Name        : Timer1_Set_ICU_Rising_Edge
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set ICU To Capture TCNT1 Count at Rising Edge.
 */
void Timer1_Set_ICU_Rising_Edge();

/*
	Function Name        : Timer1_Set_ICU_Falling_Edge
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set ICU To Capture TCNT1 Count at Falling Edge.
 */
void Timer1_Set_ICU_Falling_Edge();

/*
	Function Name        : Clear_ICF1_BIT
	Function Returns     : void
	Function Arguments   : void
	Function Description : Clear Input Capture Unit Flag Bit.
 */
void Timer1_Clear_ICF1_BIT();

/*
	Function Name        : Timer1_Set_OCA_PhaseCorrect_PWM_Mode_Using_Bits
	Function Returns     : void
	Function Arguments   : void
	Function Description : Generate PWM Signal on OC1A Pin using Fast PWM.
 */
void Timer1_Set_OCA_PhaseCorrect_PWM_Mode_Using_Bits();

/*
	Function Name        : Timer1_Set_OCB_PhaseCorrect_PWM_Mode_Using_Bits
	Function Returns     : void
	Function Arguments   : void
	Function Description : Generate PWM Signal on OC1B Pin using Fast PWM.
 */
void Timer1_Set_OCB_PhaseCorrect_PWM_Mode_Using_Bits();

/*
	Function Name        : Timer1_Set_OCA_PhaseCorrect_PWM_Mode
	Function Returns     : void
	Function Arguments   : void
	Function Description : Generate PWM Signal on OC1A Pin using Fast PWM.
 */
void Timer1_Set_OCA_PhaseCorrect_PWM_Mode(u16 OCR1A_VALUE);

/*
	Function Name        : Timer1_Set_OCB_PhaseCorrect_PWM_Mode
	Function Returns     : void
	Function Arguments   : void
	Function Description : Generate PWM Signal on OC1B Pin using Fast PWM.
 */
void Timer1_Set_OCB_PhaseCorrect_PWM_Mode(u16 OCR1B_VALUE);

/*
	Function Name        : Timer1_Check_ICF1_BIT
	Function Returns     : u8
	Function Arguments   : void
	Function Description : Check ICF1 Flag Bit.
 */
u8 Timer1_Check_ICF1_BIT();

/*
	Function Name        : Timer1_Clear_TCNT1
	Function Returns     : void
	Function Arguments   : void
	Function Description : Clear TCNT1 Counter.
 */
void Timer1_Clear_TCNT1();

/*====================================================================================*/
/* TIMER2 Decleration*/
/*====================================================================================*/

/*
	Function Name        : Timer2_Stop_Count
	Function Returns     : void
	Function Arguments   : u8 OCRO_VALUE
	Function Description : Stop timer0 from counting.
 */
void Timer2_Stop_Count(void);

/*
	Function Name        : Timer2_Start_Count
	Function Returns     : void
	Function Arguments   : void
	Function Description : Timer2 Start Counts .
 */
void Timer2_Start_Count(void);

/*
	Function Name        : Timer2_Clk_Select
	Function Returns     : void
	Function Arguments   : void
	Function Description : Select the clk source ( External or internal ).
 */
void Timer2_Clk_Select();
/*
	Function Name        : Timer2_Set_Clk
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the clk that timer use.
 */
void Timer2_Set_Clk(void);

/*
	Function Name        : Timer2_Set_OverFlow_Mode
	Function Returns     : void
	Function Arguments   : void
	Function Description : Set the Timer to make interrupt on overflow mode.
 */
void Timer2_Set_OverFlow_Mode(void);

/*
	Function Name        : Timer2_Set_CTC_Mode
	Function Returns     : void
	Function Arguments   : u8 OCRO_VALUE
	Function Description : Set the Timer to make interrupt on Compare match mode.
 */
void Timer2_Set_CTC_Mode(u8 OCRO_VALUE);

/*
	Function Name        : Timer2_CTC_Generate_Signal
	Function Returns     : void
	Function Arguments   : u8 OCRO_VALUE
	Function Description : Generate Signal at compare match.
 */
void Timer2_CTC_Generate_Signal(u8 OCRO_VALUE);

/*
	Function Name        : Timer2_Set_FastPWM_Mode
	Function Returns     : void
	Function Arguments   : u8 OCRO_VALUE
	Function Description : Generate PWM Signal on OCO Pin using Fast PWM .
 */
void Timer2_Set_FastPWM_Mode(u8 OCRO_VALUE);

/*
	Function Name        : PWM_Timer2_Generate
	Function Returns     : void
	Function Arguments   : u8 SPEED_PERCENT
	Function Description : Generate PWM Signal on OCO Pin Using Percentage of Time on.
 */
void PWM_Timer2_Generate(u8 SPEED_PERCENT);

/*
	Function Name        : Timer2_Set_PhaseCorrect_PWM_Mode
	Function Returns     : void
	Function Arguments   : u8 OCRO_VALUE
	Function Description : Generate PWM Signal on OC2 Pin Using Phase Correct PWM.
 */
void Timer2_Set_PhaseCorrect_PWM_Mode(u8 OCRO_VALUE);

/*
	Function Name        : Timer2_Clear_TCNT2
	Function Returns     : void
	Function Arguments   : void
	Function Description : Clear TCNT2 Counter.
 */
void Timer2_Clear_TCNT2();

#endif /* TIMER_H_ */



