#include "types.h"



typedef uint16 S_TIMER_COUNT;

typedef struct _S_TIMER_
{
	uint16 m_task;					/* Task of the timer in ms */
	S_TIMER_COUNT m_init_tmr;		/* Init val in ms */
	uint16 m_count_ms;				/* Count in ms(actual value) */
	uint8 m_count_type;				/* Count type */
	uint8 m_auto_reset;				/* Timer auto reset */
}S_TIMER;

void Tmr_Init(S_TIMER *p_timer, uint16 p_task, S_TIMER_COUNT p_init_val, uint8 p_count_type, uint8 p_auto_rst);
uint8 Tmr_Update(S_TIMER *p_timer);

