/*
 * interrupt.h
 *
 *  Created on: 02.02.2017
 *      Author: hcooh
 */

#ifndef INCLUDE_PWMS_INTERRUPT_H_
#define INCLUDE_PWMS_INTERRUPT_H_

/*
 * Do we read "ocr" values instantly from flash within the ISR?
 * This operation is slower (since LPM is 3 cycles and LDS is 2 cycles)
 * but consumes much less static RAM bytes.
 */
#define	OCR_FROM_FLASH	1

/*
 * timer initialization for PWM purposes
 *
 * prescaler - value of the hardware prescaler for timer
 * divisor   - value of division of the TCNT0 to go
 * divisor is calculated like this: TCNT0 = -(0xFF / divisor)
 */
void timer0_init_for_pwms(uint16_t prescaler, uint8_t divisor);


#endif /* INCLUDE_PWMS_INTERRUPT_H_ */
