 /******************************************************************************
 *
 * Main function
 *
 * File Name: project.c
 *
 * Description: Main Application
 *
 * Author: Hazem Hisham
 *
 *******************************************************************************/
#include "adc.h"
#include "lm35_sensor.h"
#include "motor.h"
#include "pwm.h"
#include "lcd.h"
#include "adc.h"
#include "common_macros.h"
int main(void){
	ADC_ConfigType Config_ptr={INTERNAL,F_CPU_8}; /*Initializing The Config Structure  */
	/* Initializing Modules*/
	ADC_init(&Config_ptr);
	LCD_init();
	DcMotor_init();
	/*             */
	uint8 temperature;
	LCD_displayStringRowColumn(0, 0, "FAN is");
	LCD_displayStringRowColumn(1,0,"Temp =     C");
	while(1){
		temperature=LM35_getTemperature(); /*Reading Temperature From Sensor and Storing in a variable to process*/
		/*First Case For temperature less than 30 */
		if(temperature<30){
			DcMotor_Rotate(STOP, 0); /* Stop The motor*/
			LCD_displayStringRowColumn(0, 7, "OFF");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}
		/*Second Case For temperature less than 60 and greater than 30 */
		else if(temperature>=30&&temperature<60){
			DcMotor_Rotate(CW, 25); /*Fan ON with 25% of Max Speed*/
			LCD_displayStringRowColumn(0, 7, "ON ");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}
		/*Second Case For temperature less than 90 and greater than 60 */
		else if(temperature>=60&&temperature<90){
			DcMotor_Rotate(CW, 50); /*Fan ON with 50% of Max Speed*/
			LCD_displayStringRowColumn(0, 7, "ON");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}
		/*Third Case For temperature less than 120 and greater than 90 */
		else if(temperature>=90&&temperature<120){
			DcMotor_Rotate(CW, 75);	/*Fan ON with 75% of Max Speed*/
			LCD_displayStringRowColumn(0, 7, "ON");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}
		/*For OTHER CASES*/
		else if(temperature>=120){
			DcMotor_Rotate(CW, 100); /*Fan ON with 100% of Motor MAX SPEED*/
			LCD_displayStringRowColumn(0, 7, "ON");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temperature);
		}
	}
}
