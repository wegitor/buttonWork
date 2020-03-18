/*
 * ButtonTime.h
 *
 *  Created on: Mar 17, 2020
 *      Author: wegitor
 */

#ifndef BUTTONTIME_H_
#define BUTTONTIME_H_

#include "stm32f4xx_hal.h"
int readByDebounce(GPIO_TypeDef *gpioX, int pin);

#endif /* BUTTONTIME_H_ */
