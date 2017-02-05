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

volatile uint16_t pwms[PWM_CNT];


// pwm resolution
#define PWM_RES		512

// pwm steps
#define PWM_STEPS	64

// GAMMA SECTION
static uint16_t gamma_correction_ram[PWM_STEPS];

#define GAMMAP(a) (pgm_read_word(&gamma_correction[a]))  // macro
#define GAMMA(a)  (gamma_correction_ram[a])  			 // macro

// ------ gamma    = 2,8
const uint16_t gamma_correction[PWM_STEPS] PROGMEM = {
		  0,  1,  1,  1,  1,  1,  2,  2,  3,  4,  6,  7,  9, 11, 13, 15, 18, 21,
		 24, 27, 31, 35, 39, 44, 48, 53, 59, 64, 70, 76, 83, 90, 97,105,113,121,
		129,138,148,157,167,178,189,200,211,223,236,248,262,275,289,304,318,334,
		349,365,382,399,416,434,453,472,491,511
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
	for(uint16_t i = 0; i < PWM_STEPS; ++i)
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
	static uint16_t ocr;

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

	ocr = (ocr + 1) & (PWM_RES - 1);
}
