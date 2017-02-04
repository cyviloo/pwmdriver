/*
 * inputs.c
 *
 *  Created on: 04.02.2017
 *      Author: hcooh
 */

#include <avr/io.h>

#include "../include/inputs.h"

void inputs_init() {
	DDR(I0_CH) &= ~(1 << I0_NO);
	I0H;

#if PWM_CNT > 1
	DDR(I1_CH) &= ~(1 << I1_NO);
	I1H;
#endif

#if PWM_CNT > 2
	DDR(I2_CH) &= ~(1 << I2_NO);
	I2H;
#endif

#if PWM_CNT > 3
	DDR(I3_CH) &= ~(1 << I3_NO);
	I3H;
#endif

#if PWM_CNT > 4
	DDR(I4_CH) &= ~(1 << I4_NO);
	I4H;
#endif

#if PWM_CNT > 5
	DDR(I5_CH) &= ~(1 << I5_NO);
	I5H;
#endif

#if PWM_CNT > 6
	DDR(I6_CH) &= ~(1 << I6_NO);
	I6H;
#endif

#if PWM_CNT > 7
	DDR(I7_CH) &= ~(1 << I7_NO);
	I7H;
#endif

#if PWM_CNT > 8
	DDR(I8_CH) &= ~(1 << I8_NO);
	I8H;
#endif

#if PWM_CNT > 9
	DDR(I9_CH) &= ~(1 << I9_NO);
	I9H;
#endif
}


