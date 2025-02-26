/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         @Author	:  Hassan Abdelazim Abdelsalam
 *         @File	:  APP_prog.c
 *         @Module	:  APP
 *
 *  Description:  This file provide Module APIs code Implementation
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "MAFIO_int.h"
#include "MSYSTICK_int.h"
#include "MADC_int.h"
#include "MUSART_int.h"
#include "HLCD_int.h"
#include "HRAIN_int.h"
#include "HLM35_int.h"
#include "TIMERx_interface.h"
#include "APP_int.h"
#include "APP_config.h"
#include "APP_priv.h"



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void App_voidstartApp(void)
 *
 * \Description     : This Services for start the Application
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 *
 * \Return value:   : None
 *******************************************************************************/
void App_voidstartApp(void)
{

	/**********************************************************************************************************************/
#if (APPLICATION == ADAS_SYSTEM)
	/**********************************************************************************************************************/

	while (1)
	{

	}
	/**********************************************************************************************************************/
#elif (APPLICATION == ANALOG_SENORS_APP)
	/**********************************************************************************************************************/

	u8 Local_u8TemperatureDegree, Local_u8WaterLevel;
	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MRCC_enEnablePeripheralCLK(MRCC_ADC1);

	/* LCD */
	lcd_vidInit();

	/* SYSTICK */
	MSYSTICK_enInit();

	/* LM35 */
	MADC_GROUP_t LM35_TEMP =  {MADC_channel0, MADC_SAMPLE_71_5CYCLE, MADC_INDEX_0};
	LM35_u8TemperatureInit(&LM35_TEMP);

	/* Rain Sensor */
	MADC_GROUP_t RAIN_SEN  =  {MADC_channel7, MADC_SAMPLE_71_5CYCLE, MADC_INDEX_1};
	RainSensor_u8Init(&RAIN_SEN);

	MADC_INIT_t Sensors = {MADC_CONTINUES_CONV, MADC_ENABLE,MADC_RIGHT_ALLIGN,MADC_channel1,MADC_SWSTART, MADC_channel0,MADC_JSWSTART};
	MADC_enInit(&Sensors);

	while (1)
	{
		LM35_u16GetTemperature(&Local_u8TemperatureDegree);
		MSYSTICK_enDelayMS(1);
		RainSensor_u8GetWaterLevel(&Local_u8WaterLevel);

		// TODO TEMP Action
		lcd_vidGotoRowColumn(0, 0);
		lcd_vidDisplyStr("temp =");
		lcd_vidDisplayNum(Local_u8TemperatureDegree);

		//// TODO RAIN Action
		lcd_vidGotoRowColumn(1, 0);
		lcd_vidDisplyStr("rain =");
		lcd_vidDisplayNum(Local_u8WaterLevel);
		MSYSTICK_enDelayMS(500);
		lcd_vidClrDislay();
	}
	/**********************************************************************************************************************/
#elif(APPLICATION == COLLESION_AVOIDENCE)
	/**********************************************************************************************************************/


	while (1)
	{


	}

	/**********************************************************************************************************************/
#elif(APPLICATION == LANE_KEEPING)
	/**********************************************************************************************************************/


	while (1)
	{


	}
	/**********************************************************************************************************************/
#elif(APPLICATION == LANE_CHANGE)
	/**********************************************************************************************************************/


	while (1)
	{


	}
	/**********************************************************************************************************************/
#elif(APPLICATION == EMERGENCY_BREAK)
	/**********************************************************************************************************************/


	while (1)
	{


	}
	/**********************************************************************************************************************/
#elif(APPLICATION == ADAPTIVE_CURISE_CONTROL)
	/**********************************************************************************************************************/

	MRCC_enSysClkINIT();
	MRCC_enEnablePeripheralCLK(MRCC_IOPA);
	MRCC_enEnablePeripheralCLK(MRCC_TIM3);
	MGPIO_enSetPinDirection(PORTA, PIN2, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(PORTA, PIN3, OUT_2MHZ_PUSH_PULL);
	MGPIO_enSetPinDirection(PORTA, PIN6, OUT_2MHZ_AF_PUSH_PULL);
	MGPIO_enSetPinDirection(PORTA, PIN7, OUT_2MHZ_AF_PUSH_PULL);
	TIM3_PWM_Init();
	TIM3_PWM_CH1_Generate(60);

	while (1)
	{


	}

	/**********************************************************************************************************************/
#elif(APPLICATION == BLIND_SPOT)
	/**********************************************************************************************************************/
	// step 1

	while (1)
	{


	}

	/**********************************************************************************************************************/
#elif (APPLICATION == SLEEP_MODE)
	/**********************************************************************************************************************/

	while (1)
	{

	}
#endif
}
/**********************************************************************************************************************
 *  END OF FILE: APP_prog.c
 *********************************************************************************************************************/
