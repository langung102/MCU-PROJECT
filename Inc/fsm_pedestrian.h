/*
 * fsm_pedestrian.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Acer
 */

#ifndef INC_FSM_PEDESTRIAN_H_
#define INC_FSM_PEDESTRIAN_H_

#include "global.h"
#include "input_reading.h"
#include "main.h"
#include "math.h"
#include "software_timer.h"
#include "traffic.h"
#include "stm32_hal_legacy.h"
#include "stm32f1xx_hal_tim.h"

void fsm_pedestrian_run(TIM_HandleTypeDef);

#endif /* INC_FSM_PEDESTRIAN_H_ */
