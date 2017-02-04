/*
 * pwms.h
 *
 *  Created on: 02.02.2017
 *      Author: hcooh
 */

#ifndef INCLUDE_PWMS_PWMS_H_
#define INCLUDE_PWMS_PWMS_H_

#include "../cfg.h"

/*
 * Software PWM pins configuration
 */
#define PWM0_CH		C
#define PWM0_NO		5

#define PWM1_CH		C
#define PWM1_NO		4

#define PWM2_CH		C
#define PWM2_NO		3

#define PWM3_CH		C
#define PWM3_NO		2

#define PWM4_CH		C
#define PWM4_NO		1

#define PWM5_CH		C
#define PWM5_NO		0

#define PWM6_CH		B
#define PWM6_NO		5

#define PWM7_CH		B
#define PWM7_NO		4

#define PWM8_CH		B
#define PWM8_NO		3

#define PWM9_CH		B
#define PWM9_NO		2


// global declaration of PWMs' values to write
extern volatile uint8_t pwms[];

// pwms initialization
void pwms_init(uint16_t timer_prescaler, uint8_t divisor);

// macros
#if INVERTING_MODE > 0
#define P0H	PORT(PWM0_CH) |= (1 << PWM0_NO)
#define P1H	PORT(PWM1_CH) |= (1 << PWM1_NO)
#define P2H	PORT(PWM2_CH) |= (1 << PWM2_NO)
#define P3H	PORT(PWM3_CH) |= (1 << PWM3_NO)
#define P4H	PORT(PWM4_CH) |= (1 << PWM4_NO)
#define P5H	PORT(PWM5_CH) |= (1 << PWM5_NO)
#define P6H	PORT(PWM6_CH) |= (1 << PWM6_NO)
#define P7H	PORT(PWM7_CH) |= (1 << PWM7_NO)
#define P8H	PORT(PWM8_CH) |= (1 << PWM8_NO)
#define P9H	PORT(PWM9_CH) |= (1 << PWM9_NO)

#define P0L	PORT(PWM0_CH) &= ~(1 << PWM0_NO)
#define P1L	PORT(PWM1_CH) &= ~(1 << PWM1_NO)
#define P2L	PORT(PWM2_CH) &= ~(1 << PWM2_NO)
#define P3L	PORT(PWM3_CH) &= ~(1 << PWM3_NO)
#define P4L	PORT(PWM4_CH) &= ~(1 << PWM4_NO)
#define P5L	PORT(PWM5_CH) &= ~(1 << PWM5_NO)
#define P6L	PORT(PWM6_CH) &= ~(1 << PWM6_NO)
#define P7L	PORT(PWM7_CH) &= ~(1 << PWM7_NO)
#define P8L	PORT(PWM8_CH) &= ~(1 << PWM8_NO)
#define P9L	PORT(PWM9_CH) &= ~(1 << PWM9_NO)
#else
#define P0L	PORT(PWM0_CH) |= (1 << PWM0_NO)
#define P1L	PORT(PWM1_CH) |= (1 << PWM1_NO)
#define P2L	PORT(PWM2_CH) |= (1 << PWM2_NO)
#define P3L	PORT(PWM3_CH) |= (1 << PWM3_NO)
#define P4L	PORT(PWM4_CH) |= (1 << PWM4_NO)
#define P5L	PORT(PWM5_CH) |= (1 << PWM5_NO)
#define P6L	PORT(PWM6_CH) |= (1 << PWM6_NO)
#define P7L	PORT(PWM7_CH) |= (1 << PWM7_NO)
#define P8L	PORT(PWM8_CH) |= (1 << PWM8_NO)
#define P9L	PORT(PWM9_CH) |= (1 << PWM9_NO)

#define P0H	PORT(PWM0_CH) &= ~(1 << PWM0_NO)
#define P1H	PORT(PWM1_CH) &= ~(1 << PWM1_NO)
#define P2H	PORT(PWM2_CH) &= ~(1 << PWM2_NO)
#define P3H	PORT(PWM3_CH) &= ~(1 << PWM3_NO)
#define P4H	PORT(PWM4_CH) &= ~(1 << PWM4_NO)
#define P5H	PORT(PWM5_CH) &= ~(1 << PWM5_NO)
#define P6H	PORT(PWM6_CH) &= ~(1 << PWM6_NO)
#define P7H	PORT(PWM7_CH) &= ~(1 << PWM7_NO)
#define P8H	PORT(PWM8_CH) &= ~(1 << PWM8_NO)
#define P9H	PORT(PWM9_CH) &= ~(1 << PWM9_NO)
#endif

#endif /* INCLUDE_PWMS_PWMS_H_ */
