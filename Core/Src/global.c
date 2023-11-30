/*
 * global.c
 *
 *  Created on: Nov 30, 2023
 *      Author: tuankiet
 */

#include "global.h"
#include "main.h"

void toggle_led1(void)
{
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
}

void toggle_led2(void){
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}

void toggle_led3(void)
{
	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
}

void toggle_led4(void)
{
	HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
}

void toggle_led5(void)
{
	HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
}
