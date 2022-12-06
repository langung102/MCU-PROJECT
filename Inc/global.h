/*
 * global.h
 *
 *  Created on: Nov 29, 2022
 *      Author: minhl
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "input_reading.h"
#include "fsm_automatic.h"
#include "fsm_tunning.h"

#define INIT			1
#define AUTO_RED		2
#define AUTO_GREEN		3
#define AUTO_YELLOW		4
#define RED_GREEN		5
#define RED_YELLOW		6
#define GREEN_RED		7
#define YELLOW_RED		8
#define AUTO			10
#define MANNUAL			11
#define TUNNING			12
#define PEDESTRIAN		13

#define INIT_MANUAL		14
#define MANUAL_RED		15
#define MANUAL_YELLOW	16
#define MANUAL_GREEN	17

#define INIT_TUNING		19
#define MOD_RED			20
#define MOD_YELLOW		21
#define MOD_GREEN		22

extern int status;
extern int mode;
extern int CYCLE;
extern int redDuration;
extern int yellowDuration;
extern int greenDuration;
extern int counter1;
extern int counter2;
extern int tmp;

extern int tempRed;
extern int tempYellow;
extern int tempGreen;

#endif /* INC_GLOBAL_H_ */
