/*
 * LED.h
 *
 *  Created on: 18-Mar-2026
 *      Author: sunbeam
 */

#ifndef LED_H_
#define LED_H_

#include <stm32f407xx.h>

#define BV(n)	(1 << (n))

//Enabme clock
#define GPIOD_CLK_EN 3

//Macro for Port-D
#define LED_GPIO GPIOD

//All Led address
#define LED_GREEN 		12
#define LED_ORANGE 		13
#define LED_RED 		14
#define LED_BLUE 		15

void led_init(uint8_t);
void led_on(uint8_t);
void led_off(uint8_t);
void led_toggle(uint8_t);


#endif /* LED_H_ */
