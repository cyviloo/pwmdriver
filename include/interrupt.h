/*
 * interrupt.h
 *
 *  Created on: 02.02.2017
 *      Author: hcooh
 */

#ifndef INCLUDE_PWMS_INTERRUPT_H_
#define INCLUDE_PWMS_INTERRUPT_H_

/*
 * timer initialization for PWM purposes
 *
 * prescaler - value of the hardware prescaler for timer
 * divisor   - value of division of the TCNT0 to go
 * divisor is calculated like this: TCNT0 = -(0xFF / divisor)
 */
void timer0_init_for_pwms(uint16_t prescaler, uint8_t divisor);

#endif /* INCLUDE_PWMS_INTERRUPT_H_ */
