/*
 * fsm_mode.c
 *
 *  Created on: Nov 29, 2022
 *      Author: minhl
 */

#include "fsm_mode.h"

void fsm_mode() {
	switch (mode) {
		case AUTO:
			fsm_automatic_run();
			break;
		case MANNUAL:

			break;
		case TUNNING:

			break;
		case PEDESTRIAN:

			break;
		default:
			break;
	}
}

