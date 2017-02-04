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



static uint8_t chkI0() {
	return I0A;
}

#if PWM_CNT > 1
static uint8_t chkI1() {
	return I1A;
}
#endif

#if PWM_CNT > 2
static uint8_t chkI2() {
	return I2A;
}
#endif

#if PWM_CNT > 3
static uint8_t chkI3() {
	return I3A;
}
#endif

#if PWM_CNT > 4
static uint8_t chkI4() {
	return I4A;
}
#endif

#if PWM_CNT > 5
static uint8_t chkI5() {
	return I5A;
}
#endif

#if PWM_CNT > 6
static uint8_t chkI6() {
	return I6A;
}
#endif

#if PWM_CNT > 7
static uint8_t chkI7() {
	return I7A;
}
#endif

#if PWM_CNT > 8
static uint8_t chkI8() {
	return I8A;
}
#endif

#if PWM_CNT > 9
static uint8_t chkI9() {
	return I9A;
}
#endif


uint8_t isActivated(uint8_t number) {
	static uint8_t (*funcs[PWM_CNT])() = {
			chkI0,
#if PWM_CNT > 1
			chkI1,
#endif
#if PWM_CNT > 2
			chkI2,
#endif
#if PWM_CNT > 3
			chkI3,
#endif
#if PWM_CNT > 4
			chkI4,
#endif
#if PWM_CNT > 5
			chkI5,
#endif
#if PWM_CNT > 6
			chkI6,
#endif
#if PWM_CNT > 7
			chkI7,
#endif
#if PWM_CNT > 8
			chkI8,
#endif
#if PWM_CNT > 9
			chkI9
#endif
	};

	return funcs[number]();
}
