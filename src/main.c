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




int main() {

	// init pwm with prescaler = 8
	pwms_init(8, 2);

	// init inputs
	inputs_init();

	// enable global interrupts
	sei();

	while(1) {


	}

	return 0;
}
