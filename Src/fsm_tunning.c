/*
 * fsm_tunning.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Acer
 */


#include "fsm_mode.h"

void fsm_tunning_run(){
	switch(status){
	case MOD_RED:
		if(timer2_flag == 1 || check_button_flag(0)){
			/*
			 * come back to INIT status if
			 * don't nothing for 10s or
			 * button1 is pressed
			 * */
			status  =  INIT;
		}
		//assign redDuration to tmp
		tmp = redDuration;
		//button2 is pressed
		if(check_button_flag(1)){
			tmp++;
			if(tmp > 99) tmp = 1;
			setTimer2(10000);
		}
		//button3 is pressed
		if(check_button_flag(2)){
			//confirm red duration
			redDuration = tmp;
			setTimer2(10000);
			//move to MOD_YELLOW status
			status = MOD_YELLOW;
		}
		break;
	case MOD_YELLOW:
		if(timer2_flag == 1 || check_button_flag(0)){
			/*
			 * come back to INIT status if
			 * don't nothing for 10s or
			 * button1 is pressed
			 * */
			status  =  INIT;
		}
		//assign yellowDuration to tmp
		tmp = yellowDuration;
		//button2 is pressed
		if(check_button_flag(1)){
			tmp++;
			if(tmp > 99) tmp = 1;
			setTimer2(10000);
		}
		//button3 is pressed
		if(check_button_flag(2)){
			//confirm yellow duration
			yellowDuration = tmp;
			setTimer2(10000);
			//move to MOD_GREEN status
			status = MOD_GREEN;
		}
		break;
	case MOD_GREEN:
		if(timer2_flag == 1 || check_button_flag(0)){
			/*
			 * come back to INIT status if
			 * don't nothing for 10s or
			 * button1 is pressed
			 * */
			status  =  INIT;
		}
		//assign greenDuration to tmp
		tmp = greenDuration;
		//button2 is pressed
		if(check_button_flag(1)){
			tmp++;
			if(tmp > 99) tmp = 1;
			setTimer2(10000);
		}
		//button3 is pressed
		if(check_button_flag(2)){
			//confirm green duration
			greenDuration = tmp;
			setTimer2(10000);
			//move to MOD_RED status
			status = MOD_RED;
		}
		break;
	}
}