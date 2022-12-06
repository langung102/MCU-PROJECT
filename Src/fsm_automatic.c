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
				setTimer1(1000);
				status = RED_GREEN;
				counter1 = redDuration;
				counter2 = greenDuration;
				setColor1(AUTO_RED);
				setColor2(AUTO_GREEN);
				status = RED_GREEN;
				break;
			case RED_GREEN:
				if (timer1_flag == 1) {
					setColor1(AUTO_RED);
					setColor2(AUTO_YELLOW);
					status = RED_YELLOW;
					setTimer1(yellowDuration*1000);
				}
				if (check_button_flag(1)) {
					status = INIT_MANUAL;
				}
				break;
			case RED_YELLOW:
				if (timer1_flag == 1) {
					setColor1(AUTO_GREEN);
					setColor2(AUTO_RED);
					status = GREEN_RED;
					setTimer1(greenDuration*1000);
				}
				if (check_button_flag(1)) {
					status = INIT_MANUAL;
				}
				break;
			case GREEN_RED:
				if (timer1_flag == 1) {
					setColor1(AUTO_YELLOW);
					setColor2(AUTO_RED);
					status = YELLOW_RED;
					setTimer1(yellowDuration*1000);
				}
				if (check_button_flag(1)) {
					status = INIT_MANUAL;
				}
				break;
			case YELLOW_RED:
				if (timer1_flag == 1) {
					setColor1(AUTO_RED);
					setColor2(AUTO_GREEN);
					status = RED_GREEN;
					setTimer1(redDuration*1000);
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

