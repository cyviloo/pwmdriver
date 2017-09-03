/*
 * main.c
 *
 *  Created on: 04.02.2017
 *      Author: hcooh
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include "../cfg.h"
#include "../include/inputs.h"
#include "../include/pwms.h"
#include "../include/spi.h"

static void fast_react_on_input(volatile uint16_t * pwm_channel, uint8_t input_number);
#if USE_SLOW_REACT_INP > 0
static void slow_react_on_input(volatile uint16_t * pwm_channel, uint8_t input_number,
		uint8_t every_which_step);
#endif
static uint8_t (*input_activation_function)(uint8_t);


int main() {

	// initial delay so another devices can init their SPI
	_delay_ms(200);

	// init pwm with prescaler = 8
	pwms_init(8, 4);

	// init inputs
	inputs_init();

	// register inputs activation function
	input_activation_function = isActivated;

	// init software SPI
	SPI_initialization(falling);
	PORTD |= (1 << 2) | (1 << 3);

	// needed variables
	uint8_t pwm_val, pwm_out;

	// enable global interrupts
	sei();

	while(1) {
		fast_react_on_input(&pwms[0], 0);
		fast_react_on_input(&pwms[1], 1);

		get_pwm_from_spi(&pwm_val, &pwm_out);
			pwms[pwm_out + 2] = pwm_val;

		_delay_ms(PWM_STEP_DELAY_MS);
	}

	return 0;
}




// additional functions

static uint8_t chk_inp(uint8_t input_number) {
	static uint8_t pressed;
	if(input_activation_function(input_number)) {
		if(!pressed) {
			pressed = 1;
			_delay_ms(INPUT_ENSURE_MS);
			if(input_activation_function(input_number)) return pressed;
		}
	}
	else {
		pressed = 0;
	}
	return pressed;
}

static void fast_react_on_input(volatile uint16_t * pwm_channel, uint8_t input_number) {
	uint16_t buf = *pwm_channel;

	if(chk_inp(input_number)) {
		if(buf < PWM_STEPS - 1) {
			++buf;
		}
	}
	else {
		if(buf > 0)
			--buf;
	}

	*pwm_channel = buf;
}

#if USE_SLOW_REACT_INP > 0
static void slow_react_on_input(volatile uint16_t * pwm_channel,
		uint8_t input_number, uint8_t every_which_step) {
	static uint8_t step;

	if( !(step % every_which_step) )
		fast_react_on_input(pwm_channel, input_number);

	++step;
}
#endif
