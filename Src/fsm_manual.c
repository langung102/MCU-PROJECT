/*
 * fsm_manual.c
 *
 *  Created on: Dec 6, 2022
 *      Author: HP
 */

#include "fsm_manual.h"

void fsm_manual_run () {
	switch (status) {
	case MANUAL_RED:
		if (timer3_flag == 1) {
			blinkLed1(AUTO_RED);
			blinkLed2(AUTO_GREEN);
			setTimer3(500);
		}
		if (timer2_flag == 1) {
			status = RED_GREEN;
			setColor1(AUTO_RED);
			setColor2(AUTO_GREEN);
			setTimer1(redDuration);
		}
		if (check_button_flag(1)) {
			status = MOD_RED;
		}
		if (check_button_flag(2)) {
			status = MANUAL_YELLOW;
			setColor1(AUTO_YELLOW);
			setColor2(AUTO_RED);
			setTimer2(5000);
			setTimer3(500);
		}
		if (check_button_flag(3)) {
			status = MANUAL_GREEN;
			setColor1(AUTO_GREEN);
			setColor2(AUTO_RED);
			setTimer2(5000);
			setTimer3(500);
		}
		break;
	case MANUAL_YELLOW:
		if (timer3_flag == 1) {
			blinkLed1(AUTO_YELLOW);
			blinkLed2(AUTO_RED);
			setTimer3(500);
		}
		if (timer2_flag == 1) {
			status = YELLOW_RED;
			setColor1(AUTO_YELLOW);
			setColor2(AUTO_RED);
			setTimer1(yellowDuration);
		}
		if (check_button_flag(1)) {
			status = MOD_RED;
		}
		if (check_button_flag(2)) {
			status = MANUAL_GREEN;
			setColor1(AUTO_GREEN);
			setColor2(AUTO_RED);
			setTimer2(5000);
			setTimer3(500);
		}
		if (check_button_flag(3)) {
			status = MANUAL_RED;
			setColor1(AUTO_RED);
			setColor2(AUTO_GREEN);
			setTimer2(5000);
			setTimer3(500);
		}
		break;
	case MANUAL_GREEN:
		if (timer3_flag == 1) {
			blinkLed1(AUTO_GREEN);
			blinkLed2(AUTO_RED);
			setTimer3(500);
		}
		if (timer2_flag == 1) {
			status = GREEN_RED;
			setColor1(AUTO_GREEN);
			setColor2(AUTO_RED);
			setTimer1(greenDuration);
		}
		if (check_button_flag(1)) {
			status = MOD_RED;
		}
		if (check_button_flag(2)) {
			status = MANUAL_RED;
			setColor1(AUTO_RED);
			setColor2(AUTO_GREEN);
			setTimer2(5000);
			setTimer3(500);
		}
		if (check_button_flag(3)) {
			status = MANUAL_YELLOW;
			setColor1(AUTO_YELLOW);
			setColor2(AUTO_RED);
			setTimer2(5000);
			setTimer3(500);
		}
		break;
	}
}

