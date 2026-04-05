/*
 * LED.c
 *
 *  Created on: 18-Mar-2026
 *      Author: sunbeam
 */

#include "LED.h"

void led_init(uint8_t pin)
{
	// Enable Clock
	RCC->AHB1ENR |= BV(GPIOD_CLK_EN);

	// Set Pins for i/p
	LED_GPIO->MODER &= ~BV(pin * 2 + 1);
	LED_GPIO->MODER |= BV(pin * 2);

	//o/p configuration push pull?
	LED_GPIO->OTYPER &= ~BV(pin);

	//select speed
	LED_GPIO->OSPEEDR &= ~(BV(pin *2 + 1) | BV(pin * 2));

	//disable pull up/down
	LED_GPIO->PUPDR &= ~(BV (pin * 2 + 1) | BV(pin * 2));
}

void led_on(uint8_t pin)
{
	LED_GPIO->ODR |= BV(pin);
}

void led_off(uint8_t pin)
{
	LED_GPIO->ODR &= ~BV(pin);
}

void led_toggle(uint8_t pin)
{
	LED_GPIO->ODR ^= BV(pin);
}
