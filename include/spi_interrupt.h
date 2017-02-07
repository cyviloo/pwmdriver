/*
 * spi_interrupt.h
 *
 *  Created on: 07.02.2017
 *      Author: hcooh
 */

#ifndef INCLUDE_SPI_INTERRUPT_H_
#define INCLUDE_SPI_INTERRUPT_H_


/*
 * Enum for level detection in the int0.
 */
typedef enum {
	low, any, falling, rising
} Int0_level;

/*
 * external interrupt initialization for software SPI purposes
 */
void int0_irq_init_for_spi(Int0_level level);

/*
 * uint8_t value with pwm value buffered:
 * 6 LSBs - pwm value
 * 2 MSBs - output number
 */
extern volatile uint8_t buf;


#endif /* INCLUDE_SPI_INTERRUPT_H_ */
