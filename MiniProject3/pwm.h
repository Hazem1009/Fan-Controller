 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: header file for PWM for AVR microcontroller
 *
 * Author: Hazem Hisham
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_SIGNAL_PIN 		PIN3_ID
#define PWM_SIGNAL_PORT		PORTB_ID
#define PWM_TOP_VALUE		255
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible To Configure and Initialize PWM according to Passed Duty Cycle
 */

void PWM_TIMER0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
