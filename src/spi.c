/*
 * spi.c
 *
 *  Created on: 07.02.2017
 *      Author: hcooh
 */

#include "../include/spi.h"

void get_pwm_from_spi(uint8_t* pwm, uint8_t* output_no) {
	register uint8_t val = buf;

	*pwm = (val & 0x3F);
	*output_no = (val >> 6);
}
