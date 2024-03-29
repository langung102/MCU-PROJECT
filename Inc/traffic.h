/*
 * traffic.h
 *
 *  Created on: Nov 29, 2022
 *      Author: minhl
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

#include "global.h"
#include "main.h"

void setColor1(int);
void setColor2(int);

void blinkLed1(int);
void blinkLed2(int);
void disable1();
void disable2();

void setPedestrian(int color);

#endif /* INC_TRAFFIC_H_ */
