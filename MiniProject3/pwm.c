/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: source.h
 *
 * Description: source file for PWM for AVR microcontroller
 *
 * Author: Hazem Hisham
 *
 *******************************************************************************/
#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"
/*
 * Description :
 * Function responsible To Configure and Initialize PWM according to Passed Duty Cycle
 */
void PWM_TIMER0_Start(uint8 duty_cycle){
		TCNT0 = 0; //Set Timer Initial value
		uint8 value=(PWM_TOP_VALUE*duty_cycle/100); /*convert duty cycle from percentage to counter value*/
		OCR0  = value; // Set Compare Value
		GPIO_setupPinDirection(PWM_SIGNAL_PORT, PWM_SIGNAL_PIN, PIN_OUTPUT); /*set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.*/

		/* Configure timer control register
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
		 */
		TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
