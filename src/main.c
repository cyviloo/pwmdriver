/*
 * main.c
 *
 *  Created on: 04.02.2017
 *      Author: hcooh
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include "../include/pwms.h"


int main() {

	// init pwm with prescaler = 8
	pwms_init(8, 2);

	// enable global interrupts
	sei();

	while(1) {
		uint8_t j = 0;
		for(; j < 0xFF; ++j) {
			_delay_ms(7);
			pwms[0] = j;
		}
		for(; j > 0x00; --j) {
			_delay_ms(7);
			pwms[0] = j;
		}
	}

	return 0;
}
