/*
 * spi_interrupt.c
 *
 *  Created on: 07.02.2017
 *      Author: hcooh
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../include/spi.h"
#include "../include/spi_interrupt.h"

volatile uint8_t buf;

#if SPI_INVERTED_MODE > 0
#define _SPI_DATA_1	(! (PIN(_SPI_DATA_PORT) & (1 << _SPI_DATA_NUM)) )
#else
#define _SPI_DATA_1	( (PIN(_SPI_DATA_PORT) & (1 << _SPI_DATA_NUM)) )
#endif

void int0_irq_init_for_spi(Int0_level level) {
	GICR |= (1 << INT0);

	switch(level) {
	case low:
		MCUCR &= ~((1 << ISC01) | (1 << ISC00));
		break;
	case any:
		MCUCR |= (1 << ISC00);
		break;
	case falling:
		MCUCR |= (1 << ISC01);
		break;
	case rising:
		MCUCR |= ((1 << ISC01) | (1 << ISC00));
		break;
	default:
		GICR &= ~(1 << INT0);
	}
}

ISR(INT0_vect) {
	static uint8_t rec_byte;
	static uint8_t counter;

	if(_SPI_DATA_1)
		rec_byte |= 0x01;
	else
		rec_byte &= ~0x01;

	counter++;
	counter &= 0x07;

	if(!counter)
		buf = rec_byte;

	rec_byte <<= 1;
}
