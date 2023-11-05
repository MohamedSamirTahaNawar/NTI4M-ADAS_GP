/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  lcd_cfg.h
 *       Module:  lcd
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef LCD_CFG_H
#define LCD_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define LCD_RS_PORT				PORTA
#define LCD_RS_CHANNEL			PIN1

#define LCD_EN_PORT     		PORTA
#define LCD_EN_CHANNEL			PIN2

#define LCD_D4_PORT				PORTA
#define LCD_D4_CHANNEL			PIN3

#define LCD_D5_PORT				PORTA
#define LCD_D5_CHANNEL			PIN4

#define LCD_D6_PORT				PORTA
#define LCD_D6_CHANNEL			PIN5

#define LCD_D7_PORT				PORTA
#define LCD_D7_CHANNEL			PIN6


#define NO_CSTOM_CHAR			8
#define NO_CSTOM_CHAR_BYTES		8

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
  
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* LCD_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: lcd_cfg.h
 *********************************************************************************************************************/