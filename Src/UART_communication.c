/*
 * UART_communication.c
 *
 *  Created on: Jan 2, 2023
 *      Author: minhl
 */
#include "UART_communication.h"

void send_data(UART_HandleTypeDef huart2) {
	  if (timer0_flag == 1) {
		  if (status == INIT_TUNING || status == MOD_RED || status == MOD_YELLOW || status == MOD_GREEN) {
			  switch (status) {
			  case MOD_RED:
					strcpy(str2, "T_R: ");
					sprintf(str1, "%d\r\n", tempRed);
					break;
			  case MOD_YELLOW:
					strcpy(str2, "T_Y: ");
					sprintf(str1, "%d\r\n", tempYellow);
					break;
			  case MOD_GREEN:
					strcpy(str2, "T_G: ");
					sprintf(str1, "%d\r\n", tempGreen);
					break;
			  default:
					break;
			  }
			  strncat(output, str2, 50);
			  strncat(output, str1, 50);
			  HAL_UART_Transmit(&huart2, (void*) output, 50, 500);
		  } else if (status == INIT_MANUAL || status == MANUAL_RED || status == MANUAL_YELLOW || status == MANUAL_GREEN) {
			  switch (status) {
			  case MANUAL_RED:
					strcpy(str2, "M_R\r\n");
					break;
			  case MANUAL_YELLOW:
					strcpy(str2, "M_Y\r\n");
					break;
			  case MANUAL_GREEN:
					strcpy(str2, "M_G\r\n");
					break;
			  default:
					break;
			  }
			  strncat(output, str2, 50);
			  HAL_UART_Transmit(&huart2, (void*) output, 50, 500);
		  } else {
			  sprintf(str2, "%d  ", redDuration);
			  strncat(output, red, 50);
			  strncat(output, str2, 50);

			  memset(str2,0,strlen(str2));

			  sprintf(str2, "%d  ", greenDuration);
			  strncat(output, green, 50);
			  strncat(output, str2, 50);

			  memset(str2,0,strlen(str2));

			  sprintf(str2, "%d\r\n", yellowDuration);
			  strncat(output, yellow, 50);
			  strncat(output, str2, 50);

			  memset(str2,0,strlen(str2));

			  switch (status) {
			  case RED_GREEN:
					strcpy(str2, "R_G: ");
					break;
			  case RED_YELLOW:
					strcpy(str2, "R_Y: ");
					break;
			  case GREEN_RED:
					strcpy(str2, "G_R: ");
					break;
			  case YELLOW_RED:
					strcpy(str2, "Y_R: ");
					break;
			  default:
					break;
			  }
			  strncat(output, str2, 50);
			  sprintf(str1, "%d\r\n\r\n", counter1);
			  strncat(output, str1, 50);
			  HAL_UART_Transmit(&huart2, (void*) output, 50, 500);
		  }
		  memset(str1,0,strlen(str1));
		  memset(str2,0,strlen(str2));
		  memset(output,0,strlen(output));
		  setTimer0(1000);
	  }
}


