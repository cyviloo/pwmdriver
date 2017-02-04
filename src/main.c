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

#define PWM_STEP_DELAY_MS	2
#define INPUT_ENSURE_MS		1


static uint8_t chk_inp1();
static uint8_t chk_inp2();
static void fast_react_on_input(uint8_t (*f)(), volatile uint8_t * pwm_channel);


int main() {

	// init pwm with prescaler = 8
	pwms_init(8, 2);

	// init inputs
	inputs_init();

	// enable global interrupts
	sei();

	while(1) {
		fast_react_on_input(chk_inp1, &pwms[0]);
		fast_react_on_input(chk_inp2, &pwms[1]);


		_delay_ms(PWM_STEP_DELAY_MS);
	}

	return 0;
}




// additional functions

static uint8_t chk_inp1() {
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

static uint8_t chk_inp2() {
	static uint8_t pressed;
	if(I1A) {
		if(!pressed) {
			pressed = 1;
			_delay_ms(INPUT_ENSURE_MS);
			if(I1A) return pressed;
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

static void fast_react_on_input(uint8_t (*f)(), volatile uint8_t * pwm_channel) {

	if(f()) {
		if(*pwm_channel < 0xFF)
			++(*pwm_channel);
	}
	else {
		if(*pwm_channel > 0)
			--(*pwm_channel);
	}
}
