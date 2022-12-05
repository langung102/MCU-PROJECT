/*
 * traffic.c
 *
 *  Created on: Nov 29, 2022
 *      Author: minhl
 */

#include "traffic.h"

//void setColor1(int color) {
//	switch (color) {
//		case INIT:
//			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin | LED_YELLOW1_Pin, GPIO_PIN_SET);
//			break;
//		case AUTO_RED:
//			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin | LED_YELLOW1_Pin, GPIO_PIN_SET);
//			break;
//		case AUTO_GREEN:
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin | LED_YELLOW1_Pin, GPIO_PIN_SET);
//			break;
//		case AUTO_YELLOW:
//			HAL_GPIO_WritePin(GPIOA, LED_YELLOW1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin | LED_RED1_Pin, GPIO_PIN_SET);
//			break;
//		default:
//			break;
//	}
//}
//
//void setColor2(int color) {
//	switch (color) {
//		case INIT:
//			HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin | LED_YELLOW2_Pin, GPIO_PIN_SET);
//			break;
//		case AUTO_RED:
//			HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin | LED_YELLOW2_Pin, GPIO_PIN_SET);
//			break;
//		case AUTO_GREEN:
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin | LED_YELLOW2_Pin, GPIO_PIN_SET);
//			break;
//		case AUTO_YELLOW:
//			HAL_GPIO_WritePin(GPIOA, LED_YELLOW2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin | LED_RED2_Pin, GPIO_PIN_SET);
//			break;
//		default:
//			break;
//	}
//}

void setColor1(int color) {
	switch (color) {
		case INIT:
			HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}

void setColor2(int color) {
	switch (color) {
		case INIT:
			HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}
//void blinkLed1(int color) {
//	switch (color) {
//		case AUTO_RED:
//			HAL_GPIO_WritePin(GPIOA, LED_YELLOW0_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_SET);
//			HAL_GPIO_TogglePin(GPIOA, LED_RED0_Pin);
//			break;
//		case AUTO_YELLOW:
//			HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_SET);
//			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW0_Pin);
//			break;
//		case AUTO_GREEN:
//			HAL_GPIO_WritePin(GPIOA, LED_YELLOW0_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_SET);
//			HAL_GPIO_TogglePin(GPIOA, LED_GREEN0_Pin);
//			break;
//		default:
//			break;
//	}
//}

//void disable1() {
//	HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA, LED_YELLOW0_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_SET);
//}
//
//void disable2() {
//	HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA, LED_YELLOW1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_SET);
//}
