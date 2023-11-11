/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  BIT_MATH.h
 *         @Module	:  LIB
 *
 *  Description:  This file provide Global BIT MINIPULATION MACROS FUN
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * HEADER GUARD
 *********************************************************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define SET_BIT(REG,BIT)	(REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)   	(REG &= ~(1<<BIT))
#define TOG_BIT(REG,BIT)   	(REG ^= (1<<BIT))
#define GET_BIT(REG,BIT)   	((REG >> (BIT))&1)


#endif /* BIT_MATH_H_ */

/**********************************************************************************************************************
 *  END OF FILE:  BIT_MATH.h
 *********************************************************************************************************************/
