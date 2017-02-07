/*
 * interrupt.c
 *
 *  Created on: 02.02.2017
 *      Author: hcooh
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "../include/macros.h"
#include "../include/pwm_interrupt.h"
#include "../include/pwms.h"


volatile uint16_t pwms[PWM_CNT];

// GAMMA SECTION

#if OCR_FROM_FLASH > 0
#define GAMMA(a)  (pgm_read_word(&gamma_correction[a]))	 // macro
#else
static uint16_t gamma_correction_ram[PWM_STEPS];
#define GAMMAP(a) (pgm_read_word(&gamma_correction[a]))  // macro
#define GAMMA(a)  (gamma_correction_ram[a])  			 // macro
#endif


// ------ gamma    = 2,8
const uint16_t gamma_correction[PWM_STEPS] PROGMEM = {
		  0,  1,  1,  1,  1,  1,  1,  1,  1,  2,  3,  3,  5,  6,  7,  9, 10, 12,
		 15, 17, 20, 23, 26, 29, 33, 37, 41, 46, 51, 56, 62, 68, 74, 81, 88, 96,
		104,112,121,130,140,150,161,172,183,196,208,221,235,249,264,279,295,312,
		329,346,365,384,403,423,444,466,488,511
};



// divisor value
static uint8_t tcnt0_divisor;

void timer0_init_for_pwms(uint16_t prescaler, uint8_t divisor) {

	tcnt0_divisor = divisor;

#if !OCR_FROM_FLASH
	/*
	 * by the way we fill the array in RAM,
	 * maybe it's not a pretty solution, so it may be worth considering
	 * to move it to another function
	 */
	for(uint16_t i = 0; i < PWM_STEPS; ++i)
		GAMMA(i) = GAMMAP(i);
#endif

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
