/*
 * cfg.h
 *
 *  Created on: 04.02.2017
 *      Author: hcooh
 */

#ifndef CFG_H_
#define CFG_H_

/*
 * PWM channels number. Set as few as possible.
 * This implies the performance.
 */
#define PWM_CNT			5

/*
 * Do use use inverting mode for pwm?
 * (BOTTOM_VALUE->...LOW->...OCR_VALUE->...HIGH->...TOP_VALUE)
 */
#define INVERTING_MODE	0

/*
 * What states trigger what?
 * 0 - low state on input triggers output up to high state along PWM
 *     high state stubs out the output
 *
 * 1 - high state on input triggers output up to high state along PWM
 *     low state stubs out the output
 */
#define TRIGGER_MODE	0

/*
 * The time resolution of the main loop.
 */
#define PWM_STEP_DELAY_MS	3

/*
 * Time of stabilizing inputs.
 */
#define INPUT_ENSURE_MS		1

/*
 * Do we use slowened reaction function?
 */
#define USE_SLOW_REACT_INP	0

#endif /* CFG_H_ */
