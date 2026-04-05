/*
 * Pattern.c
 *
 *  Created on: 18-Mar-2026
 *      Author: sunbeam
 */

#include "Pattern.h"

void run_pattern(uint8_t p)
{
    static uint8_t step = 0;

    switch(p)
    {
        // 0: All OFF
        case PATTERN_OFF:
            GPIOD->ODR &= ~(BV(12)|BV(13)|BV(14)|BV(15));
            break;

        // 1: One LED ON (static)
        case PATTERN_SINGLE:
            GPIOD->ODR = BV(12);
            break;

        // 2: All blink
        case PATTERN_ALL_BLINK:
            GPIOD->ODR ^= (BV(12)|BV(13)|BV(14)|BV(15));
            DelayMs(500);
            break;

        // 3: Circular running
        case PATTERN_RUNNING:
            GPIOD->ODR &= ~(BV(12)|BV(13)|BV(14)|BV(15));

            switch(step)
            {
                case 0: GPIOD->ODR |= BV(12); break;
                case 1: GPIOD->ODR |= BV(13); break;
                case 2: GPIOD->ODR |= BV(14); break;
                case 3: GPIOD->ODR |= BV(15); break;
            }

            step = (step + 1) % 4;
            DelayMs(200);
            break;

        // 4: Alternate LEDs
        case PATTERN_ALTERNATE:
            if(step == 0)
                GPIOD->ODR = BV(12)|BV(14);
            else
                GPIOD->ODR = BV(13)|BV(15);

            step ^= 1;
            DelayMs(400);
            break;

        // 5: In-out pattern
        case PATTERN_INOUT:
            switch(step)
            {
                case 0: GPIOD->ODR = BV(12); break;
                case 1: GPIOD->ODR = BV(12)|BV(13); break;
                case 2: GPIOD->ODR = BV(12)|BV(13)|BV(14); break;
                case 3: GPIOD->ODR = BV(12)|BV(13)|BV(14)|BV(15); break;
                case 4: GPIOD->ODR = BV(13)|BV(14)|BV(15); break;
                case 5: GPIOD->ODR = BV(14)|BV(15); break;
                case 6: GPIOD->ODR = BV(15); break;
            }

            step = (step + 1) % 7;
            DelayMs(200);
            break;
    }
}

//void set_pattern(uint8_t p)
//{
//    // Clear all LEDs first
//    GPIOD->ODR &= ~(BV(12) | BV(13) | BV(14) | BV(15));
//
//    switch(p)
//    {
//        case 0:
//            break;
//
//        case 1:
//            GPIOD->ODR |= BV(12);
//            break;
//
//        case 2:
//            GPIOD->ODR |= BV(13);
//            break;
//
//        case 3:
//            GPIOD->ODR |= BV(14);
//            break;
//
//        case 4:
//            GPIOD->ODR |= BV(15);
//            break;
//
//        case 5:
//            GPIOD->ODR |= BV(12)|BV(13)|BV(14)|BV(15);
//            break;
//    }
//}
