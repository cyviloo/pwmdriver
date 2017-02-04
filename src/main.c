/*
 * main.c
 *
 *  Created on: 04.02.2017
 *      Author: hcooh
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include "../include/inputs.h"
#include "../include/pwms.h"

#define PWM_STEP_DELAY_MS	1
#define INPUT_ENSURE_MS		1

static uint8_t chk_inp0() {
	static uint8_t pressed;
	if(I0A) {
		if(!pressed) {
			pressed = 1;
			_delay_ms(INPUT_ENSURE_MS);
			if(I0A) return pressed;
		}
		else {
			return pressed;
		}
	}
	else {
		pressed = 0;
	}
	return pressed;
}


int main() {

	// init pwm with prescaler = 8
	pwms_init(8, 2);

	// init inputs
	inputs_init();

	// enable global interrupts
	sei();

	while(1) {

		if(chk_inp0()) {
			if(pwms[0] < 0xFF)
				pwms[0]++;
		}
		else {
			if(pwms[0] > 0)
				pwms[0]--;
		}

		_delay_ms(PWM_STEP_DELAY_MS);
	}

	return 0;
}
