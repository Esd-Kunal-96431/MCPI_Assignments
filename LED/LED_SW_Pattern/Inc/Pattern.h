/*
 * Pattern.h
 *
 *  Created on: 18-Mar-2026
 *      Author: sunbeam
 */

#ifndef PATTERN_H_
#define PATTERN_H_

#include "LED.h"

#define PATTERN_OFF        0
#define PATTERN_SINGLE     1
#define PATTERN_ALL_BLINK  2
#define PATTERN_RUNNING    3
#define PATTERN_ALTERNATE  4
#define PATTERN_INOUT      5

void set_pattern(uint8_t);
void run_pattern(uint8_t p);

#endif /* PATTERN_H_ */
