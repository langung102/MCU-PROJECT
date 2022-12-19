/*
 * fsm_automatic.c
 *
 *  Created on: Nov 29, 2022
 *      Author: minhl
 */

#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch (status) {
			case INIT:
				fixLedDuration();
				setTimer1(greenDuration*1000);
				setTimer2(1000);//***
				counter1 = redDuration;
				counter2 = greenDuration;
				setColor1(AUTO_RED);
				setColor2(AUTO_GREEN);
				status = RED_GREEN;
				break;
			case RED_GREEN:
				// these line is used for pedestrian
				if(timer2_flag == 1){//***
					if (counter2 == 1) {
						counter1--;
						counter2 = yellowDuration;

						setColor1(AUTO_RED);
						setColor2(AUTO_YELLOW);
						status = RED_YELLOW;
					}
					else {
						counter1--;
						counter2--;
					}
					setTimer2(1000);
				}
				if (check_button_flag(1)) {
					status = INIT_MANUAL;
				}
				break;
			case RED_YELLOW:
				// these line is used for pedestrian
				if(timer2_flag == 1){//***
					if (counter1 == 1) {
						counter1 = greenDuration;
						counter2 = redDuration;

						setColor1(AUTO_GREEN);
						setColor2(AUTO_RED);
						status = GREEN_RED;
					} else {
						counter1--;
						counter2--;
					}
					setTimer2(1000);
				}
				if (check_button_flag(1)) {
					status = INIT_MANUAL;
				}
				break;
			case GREEN_RED:
				// these line is used for pedestrian
				if(timer2_flag == 1){//***
					if (counter1 == 1) {
						counter1 = yellowDuration;
						counter2--;

						setColor1(AUTO_YELLOW);
						setColor2(AUTO_RED);
						status = YELLOW_RED;
					} else {
						counter1--;
						counter2--;
					}
					setTimer2(1000);
				}
				if (check_button_flag(1)) {
					status = INIT_MANUAL;
				}
				break;
			case YELLOW_RED:
				// these line is used for pedestrian
				if(timer2_flag == 1){//***
					if (counter1 == 1) {
						counter1 = redDuration;
						counter2 = greenDuration;

						setColor1(AUTO_RED);
						setColor2(AUTO_GREEN);
						status = RED_GREEN;
					} else {
						counter1--;
						counter2--;
					}
					setTimer2(1000);
				}
				if (check_button_flag(1)) {
					status = INIT_MANUAL;
				}
				break;
			default:
				break;
		}
}

//void fsm_automatic_run() {
//	switch (status) {
//		case INIT:
//			fixLedDuration();
//			setTimer1(1000);
//			status = RED_GREEN;
//			counter1 = redDuration;
//			counter2 = greenDuration;
//			setColor1(AUTO_RED);
//			setColor2(AUTO_GREEN);
//			status = RED_GREEN;
//			break;
//		case RED_GREEN:
//			if (timer1_flag == 1) {
//				if (counter2 == 1) {
//					status = RED_YELLOW;
//					counter1--;
//					counter2 = yellowDuration;
//					setColor2(AUTO_YELLOW);
//					timer1_flag = 0;
//					setTimer1(1000);
//				} else {
//					counter1--;
//					counter2--;
//					setTimer1(1000);
//				}
//			}
//			if (check_button_flag(1)) {
//				status = INIT_MANUAL;
//			}
//			break;
//		case RED_YELLOW:
//			if (timer1_flag == 1) {
//				if (counter1 == 1) {
//					status = GREEN_RED;
//					counter1 = greenDuration;
//					counter2 = redDuration;
//					setColor1(AUTO_GREEN);
//					setColor2(AUTO_RED);
//					timer1_flag = 0;
//					setTimer1(1000);
//				} else {
//					counter1--;
//					counter2--;
//					setTimer1(1000);
//				}
//			}
//			if (check_button_flag(1)) {
//				status = INIT_MANUAL;
//			}
//			break;
//		case GREEN_RED:
//			if (timer1_flag == 1) {
//				if (counter1 == 1) {
//					status = YELLOW_RED;
//					counter1 = yellowDuration;
//					counter2--;
//					setColor1(AUTO_YELLOW);
//					timer1_flag = 0;
//					setTimer1(1000);
//				} else {
//					counter1--;
//					counter2--;
//					setTimer1(1000);
//				}
//			}
//			if (check_button_flag(1)) {
//				status = INIT_MANUAL;
//			}
//			break;
//		case YELLOW_RED:
//			if (timer1_flag == 1) {
//				if (counter1 == 1) {
//					status = RED_GREEN;
//					counter1 = redDuration;
//					counter2 = greenDuration;
//					setColor1(AUTO_RED);
//					setColor2(AUTO_GREEN);
//					timer1_flag = 0;
//					setTimer1(1000);
//				} else {
//					counter1--;
//					counter2--;
//					setTimer1(1000);
//				}
//			}
//			if (check_button_flag(1)) {
//				status = INIT_MANUAL;
//			}
//			break;
//		default:
//			break;
//	}
//}

