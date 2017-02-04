/*
 * macros.h
 *
 *  Created on: 04.02.2017
 *      Author: hcooh
 */

#ifndef INCLUDE_MACROS_H_
#define INCLUDE_MACROS_H_


#define SPORT(x) (PORT ## x)
#define PORT(x) SPORT(x)

#define SDDR(x) (DDR ## x)
#define DDR(x) SDDR(x)

#define SPIN(x) (PIN ## x)
#define PIN(x) SPIN(x)




#endif /* INCLUDE_MACROS_H_ */
