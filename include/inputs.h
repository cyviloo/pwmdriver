/*
 * inputs.h
 *
 *  Created on: 04.02.2017
 *      Author: hcooh
 */

#ifndef INCLUDE_INPUTS_H_
#define INCLUDE_INPUTS_H_

#include "../cfg.h"
#include "macros.h"

/*
 * Inputs pins.
 */
#define I0_CH		D
#define I0_NO		0

#define I1_CH		D
#define I1_NO		1

#define I2_CH		D
#define I2_NO		2

#define I3_CH		D
#define I3_NO		3

#define I4_CH		D
#define I4_NO		4

#define I5_CH		D
#define I5_NO		5

#define I6_CH		D
#define I6_NO		6

#define I7_CH		D
#define I7_NO		7

#define I8_CH		B
#define I8_NO		0

#define I9_CH		B
#define I9_NO		1


// macros

#if TRIGGER_MODE > 0

#define I0H		PORT(I0_CH) |= ~(1 << I0_NO)
#define I1H		PORT(I1_CH) |= ~(1 << I1_NO)
#define I2H		PORT(I2_CH) |= ~(1 << I2_NO)
#define I3H		PORT(I3_CH) |= ~(1 << I3_NO)
#define I4H		PORT(I4_CH) |= ~(1 << I4_NO)
#define I5H		PORT(I5_CH) |= ~(1 << I5_NO)
#define I6H		PORT(I6_CH) |= ~(1 << I6_NO)
#define I7H		PORT(I7_CH) |= ~(1 << I7_NO)
#define I8H		PORT(I8_CH) |= ~(1 << I8_NO)
#define I9H		PORT(I9_CH) |= ~(1 << I9_NO)

#define I0A		(  (PIN(I0_CH) & (1 << I0_NO)) )
#define I1A		(  (PIN(I1_CH) & (1 << I1_NO)) )
#define I2A		(  (PIN(I2_CH) & (1 << I2_NO)) )
#define I3A		(  (PIN(I3_CH) & (1 << I3_NO)) )
#define I4A		(  (PIN(I4_CH) & (1 << I4_NO)) )
#define I5A		(  (PIN(I5_CH) & (1 << I5_NO)) )
#define I6A		(  (PIN(I6_CH) & (1 << I6_NO)) )
#define I7A		(  (PIN(I7_CH) & (1 << I7_NO)) )
#define I8A		(  (PIN(I8_CH) & (1 << I8_NO)) )
#define I9A		(  (PIN(I9_CH) & (1 << I9_NO)) )

#else

#define I0H		PORT(I0_CH) |= (1 << I0_NO)
#define I1H		PORT(I1_CH) |= (1 << I1_NO)
#define I2H		PORT(I2_CH) |= (1 << I2_NO)
#define I3H		PORT(I3_CH) |= (1 << I3_NO)
#define I4H		PORT(I4_CH) |= (1 << I4_NO)
#define I5H		PORT(I5_CH) |= (1 << I5_NO)
#define I6H		PORT(I6_CH) |= (1 << I6_NO)
#define I7H		PORT(I7_CH) |= (1 << I7_NO)
#define I8H		PORT(I8_CH) |= (1 << I8_NO)
#define I9H		PORT(I9_CH) |= (1 << I9_NO)

#define I0A		( !(PIN(I0_CH) & (1 << I0_NO)) )
#define I1A		( !(PIN(I1_CH) & (1 << I1_NO)) )
#define I2A		( !(PIN(I2_CH) & (1 << I2_NO)) )
#define I3A		( !(PIN(I3_CH) & (1 << I3_NO)) )
#define I4A		( !(PIN(I4_CH) & (1 << I4_NO)) )
#define I5A		( !(PIN(I5_CH) & (1 << I5_NO)) )
#define I6A		( !(PIN(I6_CH) & (1 << I6_NO)) )
#define I7A		( !(PIN(I7_CH) & (1 << I7_NO)) )
#define I8A		( !(PIN(I8_CH) & (1 << I8_NO)) )
#define I9A		( !(PIN(I9_CH) & (1 << I9_NO)) )

#endif

// functions
void inputs_init();


#endif /* INCLUDE_INPUTS_H_ */
