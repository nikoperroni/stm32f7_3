#include "types.h"
#include "timer.h"


void Tmr_TimInit(void)
{
//	TIM_HandleTypeDef htim;

	/* Init of the tim fields */
//	htim.Channel = ;

//	HAL_TIM_Base_MspInit(&htim);
}


uint8 Tmr_SimInit(void)
{

}

void Tmr_Init(S_TIMER *p_timer, uint16 p_task, S_TIMER_COUNT p_init_val, uint8 p_count_type, uint8 p_auto_rst)
{
	p_timer->m_init_tmr = p_init_val;
	p_timer->m_count_type = p_count_type;
	p_timer->m_auto_reset = p_auto_rst;
	p_timer->m_count_ms = (uint16)(p_init_val / p_task) ;
	p_timer->m_task = p_task;

}

uint8 Tmr_Update(S_TIMER *p_timer)
{
	uint8 is_elapsed;

	p_timer->m_count_ms--;

	if(p_timer->m_count_ms != 0u)
	{
		is_elapsed = 0u;
	}
	else
	{
		is_elapsed = 1u;
	}
	return is_elapsed;
}


void Tmr_Reset(S_TIMER *p_timer)
{
	p_timer->m_count_ms = p_timer->m_init_tmr;
}
