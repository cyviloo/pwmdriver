/*
 * spi.h
 *
 *  Created on: 07.02.2017
 *      Author: hcooh
 */

#ifndef INCLUDE_SPI_H_
#define INCLUDE_SPI_H_

#include <avr/io.h>
#include "macros.h"
#include "spi_interrupt.h"

/*
 * SPI inverted mode: 0 on data pin means bit 1
 */
#define SPI_INVERTED_MODE	1

/*
 * SPI data pin letter and number
 */

#define _SPI_DATA_PORT	D
#define _SPI_DATA_NUM	3


/*
 * SPI initialization
 */
inline void SPI_initialization(Int0_level level) {
	DDR(_SPI_DATA_PORT) &= ~(1 << _SPI_DATA_NUM);
#if SPI_INVERTED_MODE == 0
	PORT(_SPI_DATA_PORT) &= ~(1 << _SPI_DATA_NUM);
#else
	PORT(_SPI_DATA_PORT) |= (1 << _SPI_DATA_NUM);
#endif
	int0_irq_init_for_spi(level);
}

/*
 * Get PWM value from a byte received from SPI.
 * Values are returned using pointers.
 */
void get_pwm_from_spi(uint8_t* pwm, uint8_t* output_no);

#endif /* INCLUDE_SPI_H_ */
