/*
 * UART_communication.h
 *
 *  Created on: Jan 2, 2023
 *      Author: minhl
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

#include "main.h"
#include "global.h"
#include "string.h"
#include "software_timer.h"
#include "stdio.h"

void send_data(UART_HandleTypeDef huart2);


#endif /* INC_UART_COMMUNICATION_H_ */
