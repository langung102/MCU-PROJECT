/*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Acer
 */


#include "fsm_pedestrian.h"

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
			setPedestrian(GREEN_PED);
			counterPedtrian = 3;
		}
		// status1 == 1, pedestrian led have a red color
		if(status1 == PED_RED){
			setPedestrian(RED_PED);
			counterPedtrian = 2;
		}
		break;
	case PED_GREEN:
		//the sound generate bip which grow bigger until  led pds is red.
		//setcompare 1 - (((double) counter)/ Maxcounter)*999
		if(counter1 > 3){
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1,  1 - (((double) counter1)/ MAX_COUNTER)*999);
		}
		//counter = counter1
		// if counter1 < 3s, it generate bip bip to warn people not to cross.
		if(counter1 < 3){
			if(timer4_flag == 1){
				// set compare (0.8)*999
				__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, (0.8)*999);
				setTimer4(1000);
			}
		}
		// if counterPedestrian != 1, status1= PED_RED
		if(counterPedtrian != 1){
			setPedestrian(RED_PED);
			counterPedtrian--;
			status1 = PED_RED;
		}
		if(counterPedtrian == 1){
			setPedestrian(INIT);
			status1 = INIT_PEDESTRIAN;
		}
		break;
	case PED_RED:
		//the sound generate bip bip each 1s
		if(timer4_flag == 1){
			// set compare (0.5)*999
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, (0.5)*999);
		}
		// if counterPedestrian != 1, status1= PED_RED
		if(counterPedtrian != 1){
			setPedestrian(GREEN_PED);
			counterPedtrian--;
			status1 = PED_GREEN;
		}
		if(counterPedtrian == 1){
			setPedestrian(INIT);
			status1 = INIT_PEDESTRIAN;
		}
		break;
	default:
		break;
	}
}
