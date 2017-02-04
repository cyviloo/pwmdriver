/*
 * interrupt.c
 *
 *  Created on: 02.02.2017
 *      Author: hcooh
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "../include/interrupt.h"
#include "../include/macros.h"
#include "../include/pwms.h"

volatile uint8_t pwms[PWM_CNT];


// pwm resolution (size of the array of gamma coefficients)
#define PWM_RES		256

// GAMMA SECTION
static uint8_t gamma_correction_ram[PWM_RES];

#define GAMMAP(a) (pgm_read_byte(&gamma_correction[a]))  // macro
#define GAMMA(a)  (gamma_correction_ram[a])  			 // macro

// ------ gamma    = 2,8
const uint8_t gamma_correction[PWM_RES] PROGMEM = {
	0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  3,  3,
	3,  3,  3,  3,  4,  4,  4,  4,  5,  5,  5,  5,  5,  6,  6,  6,  7,  7,
	7,  7,  8,  8,  8,  9,  9,  9, 10, 10, 10, 11, 11, 12, 12, 12, 13, 13,
	14, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 21, 21, 22, 22,
	23, 23, 24, 25, 25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35,
	35, 36, 37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 48, 49, 50,
	51, 52, 53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68, 69, 70,
	72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89, 90, 92, 93, 95,
	96, 98, 99,101,102,104,105,107,109,110,112,113,115,117,119,120,122,124,
	125,127,129,131,133,135,136,138,140,142,144,146,148,150,152,154,156,158,
	160,162,164,166,168,171,173,175,177,179,182,184,186,188,191,193,195,198,
	200,203,205,207,210,212,215,217,220,222,225,228,230,233,235,238,241,243,
	246,249,252,255
};



// divisor value
static uint8_t tcnt0_divisor;

void timer0_init_for_pwms(uint16_t prescaler, uint8_t divisor) {

	tcnt0_divisor = divisor;

	/*
	 * by the way we fill the array in RAM,
	 * maybe it's not a pretty solution, so it may be worth considering
	 * to move it to another function
	 */
	for(uint16_t i = 0; i < PWM_RES; ++i)
		GAMMA(i) = GAMMAP(i);

	switch(prescaler) {
	case 0:
		TCCR0 |= (1 << CS00);									// prescaler = 0
		break;
	case 8:
		TCCR0 |= (1 << CS01);									// prescaler = 8
		break;
	case 64:
		TCCR0 |= ((1 << CS01) | (1 << CS00));					// prescaler = 64
		break;
	case 256:
		TCCR0 |= (1 << CS02);									// prescaler = 256
		break;
	case 1024:
		TCCR0 |= ((1 << CS02) | (1 << CS00));					// prescaler = 1024
		break;
	default:
		TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));	// counter stopped
		break;
	}

	TIMSK |= (1 << TOIE0);		// enable irq
}


ISR(TIMER0_OVF_vect) {
	static uint8_t ocr;

	TCNT0 = -(0xFF / tcnt0_divisor);

	// not done with a loop because must be very fast
	if(ocr < GAMMA(pwms[0]))
		P0H;
	else
		P0L;

#if PWM_CNT > 1
	if(ocr < GAMMA(pwms[1]))
		P1H;
	else
		P1L;
#endif

#if PWM_CNT > 2
	if(ocr < GAMMA(pwms[2]))
		P2H;
	else
		P2L;
#endif

#if PWM_CNT > 3
	if(ocr < GAMMA(pwms[3]))
		P3H;
	else
		P3L;
#endif

#if PWM_CNT > 4
	if(ocr < GAMMA(pwms[4]))
		P4H;
	else
		P4L;
#endif

#if PWM_CNT > 5
	if(ocr < GAMMA(pwms[5]))
		P5H;
	else
		P5L;
#endif

#if PWM_CNT > 6
	if(ocr < GAMMA(pwms[6]))
		P6H;
	else
		P6L;
#endif

#if PWM_CNT > 7
	if(ocr < GAMMA(pwms[7]))
		P7H;
	else
		P7L;
#endif

#if PWM_CNT > 8
	if(ocr < GAMMA(pwms[8]))
		P8H;
	else
		P8L;
#endif

#if PWM_CNT > 9
	if(ocr < GAMMA(pwms[9]))
		P9H;
	else
		P9L;
#endif

	++ocr;
}
