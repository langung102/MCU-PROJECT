/*
 * fix_led_duration.c
 *
 *  Created on: Dec 6, 2022
 *      Author: Acer
 */


#include "fix_led_duration.h"

// if a structure red time = green time + yellow time
// is broken, this function is used to balance it again
void fixLedDuration(){
	if (tempGreen != redDuration && tempGreen == greenDuration && tempYellow == yellowDuration) {
		if (redDuration > (yellowDuration + greenDuration)) {
				greenDuration = redDuration - yellowDuration;
			} else if (redDuration < (yellowDuration + greenDuration)) {
				yellowDuration = redDuration/2;
				greenDuration = redDuration/2;
					if (redDuration%2 != 0)
					greenDuration++;
		}
	} else if (tempGreen == redDuration && tempGreen != greenDuration && tempYellow == yellowDuration) {
		if (redDuration != yellowDuration + greenDuration) {
			redDuration = yellowDuration + greenDuration;
			if (redDuration > 99) {
				redDuration = 99;
				greenDuration = redDuration - yellowDuration;
			}
		}
	} else if (tempGreen == redDuration && tempGreen != greenDuration && tempYellow == yellowDuration) {
		if (redDuration != yellowDuration + greenDuration) {
			redDuration = yellowDuration + greenDuration;
			if (redDuration > 99) {
				redDuration = 99;
				yellowDuration = redDuration - greenDuration;
			}
		}
	}
}
