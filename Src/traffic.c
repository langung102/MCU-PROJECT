/*
 * traffic.c
 *
 *  Created on: Nov 29, 2022
 *      Author: minhl
 */

#include "traffic.h"

uint8_t red1_flag = 0, green1_flag = 0, yellow1_flag,
		red2_flag = 0, green2_flag = 0, yellow2_flag;

void setColor1(int color) {
	switch (color) {
		case INIT:
			HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_RESET);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_RESET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}

void setColor2(int color) {
	switch (color) {
		case INIT:
			HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_RESET);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_RESET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}

void blinkLed1(int color) {
	switch (color) {
		case AUTO_RED:
			if (red1_flag) {
				HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_RESET);
				red1_flag = 0;
			} else {
				HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_RESET);
				red1_flag = 1;
			}
			break;
		case AUTO_GREEN:
			if (green1_flag) {
				HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_RESET);
				green1_flag = 0;
			} else {
				HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_SET);
				green1_flag = 1;
			}
			break;
		case AUTO_YELLOW:
			if (yellow1_flag) {
				HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_RESET);
				yellow1_flag = 0;
			} else {
				HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_SET);
				yellow1_flag = 1;
			}
			break;
		default:
			break;
	}
}

void blinkLed2(int color) {
	switch (color) {
		case AUTO_RED:
			if (red2_flag) {
				HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_RESET);
				red2_flag = 0;
			} else {
				HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_RESET);
				red2_flag = 1;
			}
			break;
		case AUTO_GREEN:
			if (green2_flag) {
				HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_RESET);
				green2_flag = 0;
			} else {
				HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_SET);
				green2_flag = 1;
			}
			break;
		case AUTO_YELLOW:
			if (yellow2_flag) {
				HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_RESET);
				yellow2_flag = 0;
			} else {
				HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_SET);
				yellow2_flag = 1;
			}
			break;
		default:
			break;
	}
}

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
