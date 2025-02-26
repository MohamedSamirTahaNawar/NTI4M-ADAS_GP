/*
 * TIMERx_program.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Ziad Hamdy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMERx_config.h"
#include "TIMERx_private.h"
#include "TIMERx_interface.h"







void MTIMERx_voidInit(void)
{
#if TIMER_2_ENABLE == TIMER_ENABLE
	TIM2->PSC = TIMWER_2_PRESCALER;
	TIM2->ARR = TIMER_2_MAX_VALUE;
	TIM2->CR1 |= (TIMER_2_DIRECTION << 4);
	TIM2->CR1 |= TIM_CR1_CEN;
#endif

#if TIMER_3_ENABLE == TIMER_ENABLE
	TIM3->PSC = TIMWER_3_PRESCALER;
	TIM3->ARR = TIMER_3_MAX_VALUE;
	TIM3->CR1 |= (TIMER_3_DIRECTION << 4);
	TIM3->CR1 |= TIM_CR1_CEN;
#endif
#if TIMER_4_ENABLE == TIMER_ENABLE
	TIM4->PSC = TIMWER_4_PRESCALER;
	TIM4->ARR = TIMER_4_MAX_VALUE;
	TIM4->CR1 |= (TIMER_4_DIRECTION << 4);
	TIM4->CR1 |= TIM_CR1_CEN;
#endif
#if TIMER_5_ENABLE == TIMER_ENABLE
	TIM5->PSC = TIMWER_5_PRESCALER;
	TIM5->ARR = TIMER_5_MAX_VALUE;
	TIM5->CR1 |= (TIMER_5_DIRECTION << 4);
	TIM5->CR1 |= TIM_CR1_CEN;
#endif
}




void MTIMERx_voidUpdatePSC(u8 copy_u8TimerID, u32 copy_u32Psc, u32 copy_u32MaxValue)
{
	volatile GPTM_t *TIMER = MTIMERx_GetTimerID(copy_u8TimerID);

	TIMER->PSC = copy_u32Psc;
	TIMER->ARR = copy_u32MaxValue;
}

void MTIMERx_voidPWMSetup(u8 copy_u8TimerID, u8 copy_u8ChannelID)
{

	volatile GPTM_t *TIMER = MTIMERx_GetTimerID(copy_u8TimerID);

	TIMER->CR1 &= ~(TIM_CR1_CEN);
	TIMER->CR1 |=  TIM_CR1_ARPE;
	switch (copy_u8ChannelID)
	{
	case CH1:
		TIMER->CCMR1 &= ~(TIM_CCMR1_CC1S);
		TIMER->CCMR1 &= ~(TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE);
		TIMER->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE;
		TIMER->CCER |= TIM_CCER_CC1E;
		TIMER->CCR1 = 0;
		break;
	case CH2:
		TIMER->CCMR1 &= ~(TIM_CCMR1_CC2S);
		TIMER->CCMR1 &= ~(TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE);
		TIMER->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE;
		TIMER->CCER |= TIM_CCER_CC2E;
		TIMER->CCR2 = 0;
		break;
	case CH3:
		TIMER->CCMR2 &= ~(TIM_CCMR2_CC3S);
		TIMER->CCMR2 &= ~(TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE);
		TIMER->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE;
		TIMER->CCER |= TIM_CCER_CC3E;
		TIMER->CCR3 = 0;
		break;
	case CH4:
		TIMER->CCMR2 &= ~(TIM_CCMR2_CC4S);
		TIMER->CCMR2 &= ~(TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE);
		TIMER->CCMR2 |= TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE;
		TIMER->CCER |= TIM_CCER_CC4E;
		TIMER->CCR4 = 0;
		break;
	default:
		break;
	}
	/* Enable timer */
	TIMER->EGR |= TIM_EGR_UG;
	TIMER->CR1 |= TIM_CR1_CEN;
}

void MTIMERx_voidSetPWMDuty(u8 copy_u8TimerID, u8 copy_u8ChannelID, u32 copy_u32Duty)
{
	volatile GPTM_t *TIMER = MTIMERx_GetTimerID(copy_u8TimerID);

	switch (copy_u8ChannelID)
	{
	case CH1: TIMER->CCR1 = copy_u32Duty; break;
	case CH2: TIMER->CCR2 = copy_u32Duty; break;
	case CH3: TIMER->CCR3 = copy_u32Duty; break;
	case CH4: TIMER->CCR4 = copy_u32Duty; break;
	default: break;
	}
}

void MTIMERx_voidStopTimer(u8 copy_u8TimerID)
{
	switch (copy_u8TimerID)
	{
	case TIMER2:TIM2->CR1 &= ~(TIM_CR1_CEN); break;
	case TIMER3:TIM3->CR1 &= ~(TIM_CR1_CEN); break;
	case TIMER4:TIM4->CR1 &= ~(TIM_CR1_CEN); break;
	case TIMER5:TIM5->CR1 &= ~(TIM_CR1_CEN); break;
	default: break;
	}

}

void MTIMERx_voidStartTimer(u8 copy_u8TimerID)
{
	switch (copy_u8TimerID)
	{
	case TIMER2:TIM2->CR1 |= (TIM_CR1_CEN); break;
	case TIMER3:TIM3->CR1 |= (TIM_CR1_CEN); break;
	case TIMER4:TIM4->CR1 |= (TIM_CR1_CEN); break;
	case TIMER5:TIM5->CR1 |= (TIM_CR1_CEN); break;
	default: break;
	}

}
void MTIMERx_voidInputCaptureSetup(u8 copy_u8TimerID, u8 copy_u8ChannelID)
{
	volatile GPTM_t *TIMER = MTIMERx_GetTimerID(copy_u8TimerID);

	/* Disable timer */
	TIMER->CR1 &= ~(TIM_CR1_CEN);
	switch (copy_u8ChannelID)
	{
	case CH1:
		/* set timer pin input */
		TIMER->CCMR1 |= TIM_CCMR1_CC1S_0;
		/* Enable Capture*/
		TIMER->CCER |= TIM_CCER_CC1E;
		/* Enable Interrupt */
		TIMER->DIER |= TIM_DIER_CC1IE;
		break;
	case CH2:
		/* set timer pin input */
		TIMER->CCMR1 |= TIM_CCMR1_CC2S_0;
		/* Enable Capture*/
		TIMER->CCER |= TIM_CCER_CC2E;
		/* Enable Interrupt */
		TIMER->DIER |= TIM_DIER_CC2IE;
		break;
	case CH3:
		/* set timer pin input */
		TIMER->CCMR2 |= TIM_CCMR2_CC3S_0;
		/* Enable Capture*/
		TIMER->CCER |= TIM_CCER_CC3E;
		/* Enable Interrupt */
		TIMER->DIER |= TIM_DIER_CC3IE;
		break;
	case CH4:
		/* set timer pin input */
		TIMER->CCMR2 |= TIM_CCMR2_CC4S_0;
		/* Enable Capture*/
		TIMER->CCER |= TIM_CCER_CC4E;
		/* Enable Interrupt */
		TIMER->DIER |= TIM_DIER_CC4IE;
		break;
	default:
		break;
	}
	/* Enable timer */
	TIMER->CR1 |= TIM_CR1_CEN;
}


void MTIMERx_voidGetInputCaptureCounter(u8 copy_u8TimerID, u8 copy_u8ChannelID, u32 *ptr_Counts)
{

	volatile GPTM_t *TIMER = MTIMERx_GetTimerID(copy_u8TimerID);

	switch (copy_u8ChannelID)
	{
	case CH1: *ptr_Counts = TIMER->CCR1; break;
	case CH2: *ptr_Counts = TIMER->CCR2; break;
	case CH3: *ptr_Counts = TIMER->CCR3; break;
	case CH4: *ptr_Counts = TIMER->CCR4; break;
	default: break;
	}
}

void MTIMERx_voidSetInputCaptureTrigger(u8 copy_u8TimerID, u8 copy_u8ChannelID, Trigger_Type copy_u8ICTrigger)
{
	volatile GPTM_t *TIMER = MTIMERx_GetTimerID(copy_u8TimerID);
	switch (copy_u8ChannelID)
	{
	case CH1:
		TIMER->CCER &= ~(TIM_CCER_CC1P);
		TIMER->CCER |= (copy_u8ICTrigger << TIM_CCER_CC1P_Pos);
		break;
	case CH2:
		TIMER->CCER &= ~(TIM_CCER_CC2P);
		TIMER->CCER |= (copy_u8ICTrigger << TIM_CCER_CC2P_Pos);
		break;
	case CH3:
		TIMER->CCER &= ~(TIM_CCER_CC3P);
		TIMER->CCER |= (copy_u8ICTrigger << TIM_CCER_CC3P_Pos);
		break;
	case CH4:
		TIMER->CCER &= ~(TIM_CCER_CC4P);
		TIMER->CCER |= (copy_u8ICTrigger << TIM_CCER_CC4P_Pos);
		break;
	default: break;
	}

}

volatile GPTM_t* MTIMERx_GetTimerID(u8 copy_u8TimerID)
{
	volatile GPTM_t* timer_ptr = NULL;

	switch (copy_u8TimerID)
	{
	case TIMER2: timer_ptr = TIM2; break;
	case TIMER3: timer_ptr = TIM3; break;
	case TIMER4: timer_ptr = TIM4; break;
	case TIMER5: timer_ptr = TIM5; break;
	default: break;
	}
	return timer_ptr;
}

static timer_callback_t input_capture_callback[4][4] = { NULL };

void MTIMERx_voidInputCaptureCallback(u8 copy_u8TimerID, u8 copy_u8ChannelID, timer_callback_t ptr)
{
	if(ptr != NULL && (copy_u8TimerID < 6))
	{
		input_capture_callback[copy_u8TimerID-2][copy_u8ChannelID-1] = ptr;
	}

}



void TIM2_IRQHandler(void) {

	/* CH1 ISR */
	if ((TIM2->SR & TIM_SR_CC1IF) != 0)
	{
		// CC1IF bit (clear interrupt flag)
		TIM2->SR &= ~(TIM_SR_CC1IF);

		if (input_capture_callback[0][0] != NULL)
		{
			input_capture_callback[0][0]();
		}
	}

	/* CH2 ISR */
	if ((TIM2->SR & TIM_SR_CC2IF) != 0) {
		// CC2IF bit (clear interrupt flag)
		TIM2->SR &= ~(TIM_SR_CC2IF);

		if (input_capture_callback[0][1] != NULL) {
			input_capture_callback[0][1]();
		}
	}

	/* CH3 ISR */
	if ((TIM2->SR & TIM_SR_CC3IF) != 0) {
		// CC3IF bit (clear interrupt flag)
		TIM2->SR &= ~(TIM_SR_CC3IF);

		if (input_capture_callback[0][2] != NULL) {
			input_capture_callback[0][2]();
		}
	}

	/* CH4 ISR */
	if ((TIM2->SR & TIM_SR_CC4IF) != 0) {
		// CC4IF bit (clear interrupt flag)
		TIM2->SR &= ~(TIM_SR_CC4IF);

		if (input_capture_callback[0][3] != NULL) {
			input_capture_callback[0][3]();
		}
	}
}




void TIM3_PWM_Init(void)
{
	// Configure the PWM mode for TIM3
	TIM3->CR1 &= ~TIM_CR1_DIR; // Count up mode
	TIM3->CR1 &= ~TIM_CR1_CMS; // Edge-aligned mode
	TIM3->CR1 |= TIM_CR1_CEN;  // Enable the timer
}




/*the used tim 3 PWM generation func */
void TIM3_PWM_CH1_Generate(u8 copy_u8Duty)
{
	// Configure PWM mode for Channel 1
	TIM3->CCMR1 |= TIM_CCMR1_OC1M; // PWM mode 1
	TIM3->CCMR1 |= TIM_CCMR1_OC1PE; // Preload enable
	TIM3->CCER |= TIM_CCER_CC1E;   // Enable the output for Channel 1
	// Set the PWM period and duty cycle


	TIM3->PSC = 0 ;             						 // No prescaler
	TIM3->ARR = TIM3_MAX_NUM_OF_TICKS_CH1;           // Period (1 kHz PWM frequency)
	copy_u8Duty = 100-copy_u8Duty;
	TIM3->CCR1 = (u16)(((copy_u8Duty/100.0)*(TIM3_MAX_NUM_OF_TICKS_CH1-1))+1);        		 // Duty cycle (50%)
	// Enable the timer
	TIM3->CR1 |= TIM_CR1_CEN;
}

void TIM3_PWM_CH2_Generate(u8 copy_u8Duty)
{
	TIM3->CCMR1 |= TIM_CCMR1_OC2M; // PWM mode 1
	TIM3->CCMR1 |= TIM_CCMR1_OC2PE; // Preload enable
	TIM3->CCER  |= TIM_CCER_CC2E;   // Enable the output for Channel 2


	// Set the PWM period and duty cycle

	TIM3->PSC = 0;             // No prescaler
	TIM3->ARR = TIM3_MAX_NUM_OF_TICKS_CH2;           // Period (1 kHz PWM frequency)
	copy_u8Duty = 100-copy_u8Duty;
	TIM3->CCR2 = (u16)(((copy_u8Duty/100.0)*(TIM3_MAX_NUM_OF_TICKS_CH1-1))+1);
	// Enable the timer
	TIM3->CR1 |= TIM_CR1_CEN;
}


/*this function takes the percentage of duty cycle in (%) to change from default
 * Ex:1-10
 * 	  2-20
 * 	  3-30
 * ETC...
 **/
//void TIM3_PWM_CH1_Change_Duty(u16 copy_u16DutyPercentege)
//{
//	TIM3->CCR1 = 0;
//	TIM3->CCR1 = copy_u16DutyPercentege;//(u16)(((f32)(copy_u16DutyPercentege/100.0)*(TIM3_MAX_NUM_OF_TICKS_CH1+1))-1);
//}
//
///*this function takes the percentage of duty cycle in (%) to change from default
// * Ex:1-10
// * 	  2-20
// * 	  3-30
// * ETC...
// **/
//void TIM3_PWM_CH2_Change_Duty(u16 copy_u16DutyPercentege)
//{
//	TIM3->CCR2 = (((u16)(copy_u16DutyPercentege/100.0)*(TIM3_MAX_NUM_OF_TICKS_CH2+1))-1);
//}



