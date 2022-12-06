/*
 * fsm_tunning.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Acer
 */


#include "fsm_tunning.h"

void fsm_tunning_run(){
	switch(status){
	case INIT_TUNING:
		setColor1(AUTO_RED);
		setColor2(INIT);
		setTimer2(10000);
		setTimer3(500);
		tempRed = redDuration;
		tempGreen = greenDuration;
		tempYellow = yellowDuration;
		status = MOD_RED;
		break;
	case MOD_RED:
		if(timer2_flag == 1 || check_button_flag(1)){
			/*
			 * come back to INIT status if
			 * don't nothing for 10s or
			 * button1 is pressed
			 * */
			status  =  INIT;
		}
		//button2 is pressed
		if(check_button_flag(2)){
			tempRed++;
			if(tempRed > 99) tempRed = 1;
			setTimer2(10000);
		}
		//button3 is pressed
		if(check_button_flag(3)){
			setColor1(AUTO_YELLOW);
			setColor2(INIT);
			//confirm red duration
			redDuration = tempRed;
			setTimer2(10000);
			//move to MOD_YELLOW status
			status = MOD_YELLOW;
		}
		break;
	case MOD_YELLOW:
		if(timer2_flag == 1 || check_button_flag(1)){
			/*
			 * come back to INIT status if
			 * don't nothing for 10s or
			 * button1 is pressed
			 * */
			status  =  INIT;
		}
		//button2 is pressed
		if(check_button_flag(2)){
			tempYellow++;
			if(tempYellow > 99) tempYellow = 1;
			setTimer2(10000);
		}
		//button3 is pressed
		if(check_button_flag(3)){
			setColor1(AUTO_GREEN);
			setColor2(INIT);
			//confirm yellow duration
			yellowDuration = tempYellow;
			setTimer2(10000);
			//move to MOD_GREEN status
			status = MOD_GREEN;
		}
		break;
	case MOD_GREEN:
		if(timer2_flag == 1 || check_button_flag(1)){
			/*
			 * come back to INIT status if
			 * don't nothing for 10s or
			 * button1 is pressed
			 * */
			status  =  INIT;
		}
		//button2 is pressed
		if(check_button_flag(2)){
			tempGreen++;
			if(tempGreen > 99) tempGreen = 1;
			setTimer2(10000);
		}
		//button3 is pressed
		if(check_button_flag(3)){
			setColor1(AUTO_RED);
			setColor2(INIT);
			//confirm green duration
			greenDuration = tempGreen;
			setTimer2(10000);
			//move to MOD_RED status
			status = MOD_RED;
		}
		break;
	}
}
