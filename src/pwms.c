/*
 * pwms.c
 *
 *  Created on: 03.02.2017
 *      Author: hcooh
 */

#include <avr/io.h>
#include "../include/interrupt.h"
#include "../include/macros.h"
#include "../include/pwms.h"

void pwms_init(uint16_t timer_prescaler, uint8_t divisor) {

	DDR(PWM0_CH) |= (1 << PWM0_NO);
	P0L;

#if PWM_CNT > 1
	DDR(PWM1_CH) |= (1 << PWM1_NO);
	P1L;
#endif

#if PWM_CNT > 2
	DDR(PWM2_CH) |= (1 << PWM2_NO);
	P2L;
#endif

#if PWM_CNT > 3
	DDR(PWM3_CH) |= (1 << PWM3_NO);
	P3L;
#endif

#if PWM_CNT > 4
	DDR(PWM4_CH) |= (1 << PWM4_NO);
	P4L;
#endif

#if PWM_CNT > 5
	DDR(PWM5_CH) |= (1 << PWM5_NO);
	P5L;
#endif

#if PWM_CNT > 6
	DDR(PWM6_CH) |= (1 << PWM6_NO);
	P6L;
#endif

#if PWM_CNT > 7
	DDR(PWM7_CH) |= (1 << PWM7_NO);
	P7L;
#endif

#if PWM_CNT > 8
	DDR(PWM8_CH) |= (1 << PWM8_NO);
	P8L;
#endif

#if PWM_CNT > 9
	DDR(PWM9_CH) |= (1 << PWM9_NO);
	P9L;
#endif

	timer0_init_for_pwms(timer_prescaler, divisor);
}
