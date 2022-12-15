/*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Acer
 */


#include "fsm_pedestrian.h"

int buzzer_flag = 0;

// create a var to loop finite status.
void fsm_pedestrian_run(TIM_HandleTypeDef htim3){
	switch(status1){
	case INIT_PEDESTRIAN:
		// button_0(pedestrian) is pressed
		if(check_button_flag(0)){
			if(status == RED_GREEN || status == RED_YELLOW){
				status1 = PED_GREEN;
			}
			if(status == GREEN_RED || status == YELLOW_RED){
				status1 = PED_RED;
			}
			MAX_COUNTER = redDuration;
		}
		// status1 == 1, pedestrian led have a green color
		if(status1 == PED_GREEN){
			setPedestrian(PED_GREEN);
			counterPedtrian = 3;
			setTimer4(500);
		}
		// status1 == 1, pedestrian led have a red color
		if(status1 == PED_RED){
			setPedestrian(PED_RED);
			counterPedtrian = 2;
			setTimer4(1000);
		}
		buzzer_flag = 1;
		break;
	case PED_GREEN:
		//	the sound generate bip which grow bigger until  led pds is red.
		//	setcompare (1 - ((double) counter1/MAX_COUNTER))*800 - (((double) counter1)/ Maxcounter)*999
		if(counter1 > 5){
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, ((double)(log(counter1)-log(MAX_COUNTER))/(log(6)-log(MAX_COUNTER)))*(700-250)+250);
		}
		// if counter1 <= 3s, it generate bip bip to warn people not to cross.
		if(counter1 <= 5 && timer4_flag == 1){
			// set compare (0.8)*999
			if (buzzer_flag) {
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 800);
				buzzer_flag = 0;;
			} else {
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
				buzzer_flag = 1;
			}
			setTimer4(300 - (5-counter1)*90);
		}
		// if counterPedestrian != 1, status1= PED_RED
		if(counterPedtrian == 0){
			setPedestrian(INIT);
			status1 = INIT_PEDESTRIAN;
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
			setTimer4(1000);
		}
		if(counterPedtrian != 0  && status == GREEN_RED){
			setPedestrian(PED_RED);
			counterPedtrian--;
			status1 = PED_RED;
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
			buzzer_flag = 1;
			setTimer4(1000);
		}
		break;
	case PED_RED:
		//	the sound generate bip bip each 1s
		if(timer4_flag == 1 && counter2 > 2){
			// set compare 500
			if (buzzer_flag) {
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 500);
				buzzer_flag = 0;
			} else {
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
				buzzer_flag = 1;
			}
			setTimer4(1000);
		}
		if(timer4_flag == 1 && counter2 <= 1){
			// set compare 500
			if (buzzer_flag) {
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 500);
				buzzer_flag = 0;
			} else {
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
				buzzer_flag = 1;
			}
			setTimer4(100);
		}
		//	if counterPedestrian != 1 & counter2 = 1, status1=
		if(counterPedtrian == 0){
			setPedestrian(INIT);
			status1 = INIT_PEDESTRIAN;
		}
		if(counterPedtrian != 0  && status == RED_GREEN){
			setPedestrian(PED_GREEN);
			counterPedtrian--;
			status1 = PED_GREEN;
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
			buzzer_flag = 1;
			setTimer4(500);
		}

		break;
	default:
		break;
	}
}
