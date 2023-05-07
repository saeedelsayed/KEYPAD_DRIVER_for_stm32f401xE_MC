/*
 * common_macros.h
 *
 *  Created on: Apr 18, 2023
 *      Author: EGYPT
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define SET_BIT_MODE(REG,BIT,MODE)         ( REG |= (MODE << (BIT*2) ) )
#define CLEAR_BIT_MODE(REG,BIT)            ( REG &= ~(0x03 << (BIT*2) ) )
#define SET_BIT(REG,PIN_ID)                ( REG |= (1 << PIN_ID) )
#define CLEAR_BIT(REG,PIN_ID)              ( REG &= ~(1 << PIN_ID) )
#define GET_BIT(REG,BIT)                   ( ( REG & (1 << BIT) ) >> BIT )
#define GET_MODE_BITS(REG,PIN_ID)          ( ( REG & (3 << ( PIN_ID * 2 ) ) ) >> ( PIN_ID * 2 ) )
#define BIT_IS_SET(REG,PIN_ID)             ( REG & ( 1 << PIN_ID ) )

#endif /* COMMON_MACROS_H_ */
