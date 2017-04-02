#include "stm32f7xx_hal.h"
#include "stm32746g_discovery_ts.h"
#include "types.h"
#include "usart.h"
#include "timer.h"
#include "display_screen.h"
#include "key_mng.h"

#define KEY_BUTTON_OFF 	(uint8) 0
#define KEY_BUTTON_ON 	(uint8) 1

typedef struct _S_KEY_DEB_{
	uint8 	m_key_id;
	uint16	m_key_x_dim;
	uint16	m_key_y_dim;
	uint16 	m_key_size;
	S_TIMER_COUNT m_key_deb_cnt;
	uint8 m_key_sts;
}S_KEY_DEB;

typedef struct _S_KEY_MNG_STS_
{
	uint8 		m_key_fsm_state;
	S_TIMER 	m_key_deb_tmr;
}S_KEY_MNG_STS;

typedef struct _S_KEY_TOUCH_POS_
{
	uint16 x_pos;
	uint16 y_pos;
	uint8  new_pos;
}S_KEY_TOUCH_POS;

typedef struct _S_KEY_MNG_
{
	uint16	 	 	m_task_period;
	S_KEY_MNG_STS  	m_key_status[KEY_BUTTON_MAX_NUM];
	const S_KEY_DEB *m_conf;
	uint8	 		m_switch_touch;
	S_KEY_TOUCH_POS m_touch_pos;
}S_KEY_MNG;


static const  S_KEY_DEB gc_key_deb_conf[KEY_BUTTON_MAX_NUM] =
{
	{0, 0u,  40u, 70u, (S_TIMER_COUNT)20, KEY_BUTTON_ON},
	{1, 100u,  40u, 70u, (S_TIMER_COUNT)20, KEY_BUTTON_ON},
	{2, 200u, 40u, 70u, (S_TIMER_COUNT)20, KEY_BUTTON_ON},
	{3, 310u,  40u,  70u, (S_TIMER_COUNT)20, KEY_BUTTON_ON},
};

static void KeyMng_GetKeyStatus(S_KEY_DEB *p_key);
static uint8 KeyMng_HandleSts(S_KEY_DEB *p_key);
static uint8_t KeyMng_HandleNewTouch(uint16 x_pos, uint16 y_pos);

S_KEY_MNG g_key_mng;

/* Private Routines */

static void KeyMng_GetKeyStatus(S_KEY_DEB *p_key)
{
	uint8_t ts_state;
	uint8_t is_newpos = 0u;
	uint16_t ypos = 0, ymax = 0, xpos = 0, size = 0;
	TS_StateTypeDef TS_State;
	/* Get position from configuration */
	ypos = p_key->m_key_y_dim;
	xpos = p_key->m_key_x_dim;
	size = p_key->m_key_size;
	/* Get the touch screen state */
	ts_state = BSP_TS_GetState(&TS_State);
	/* No multitouch */
	for(int x1= 0; x1<1; x1++)
	{
		/* Y axis validation */
		if( (TS_State.touchY[x1] > ypos)  && (TS_State.touchY[x1] < (ypos + size ) ) )
		{
			/* X axis validation */
			if( (TS_State.touchX[x1] > xpos  ) && (TS_State.touchX[x1] < (xpos + size) ) )
			{
				/* Check new position */
				is_newpos = KeyMng_HandleNewTouch(TS_State.touchX[x1], TS_State.touchY[x1]);
				if(is_newpos == 1u)
				{
					KeyMng_HandleSts(p_key);
				}
				else{}
			}
			else{}

		}
		else{}
	}


}

static uint8_t KeyMng_HandleNewTouch(uint16 x_pos, uint16 y_pos)
{

	if( (x_pos == g_key_mng.m_touch_pos.x_pos) && (y_pos == g_key_mng.m_touch_pos.y_pos) )
	{}
	else
	{
		g_key_mng.m_touch_pos.x_pos = x_pos;
		g_key_mng.m_touch_pos.y_pos = y_pos;
		g_key_mng.m_touch_pos.new_pos = TRUE;
	}

	return g_key_mng.m_touch_pos.new_pos;
}

static uint8 KeyMng_HandleSts(S_KEY_DEB *p_key)
{
	uint8 is_elapsed;
	uint8_t id_converted;

	is_elapsed = Tmr_Update(&(g_key_mng.m_key_status[p_key->m_key_id].m_key_deb_tmr));

	if(is_elapsed == TRUE)
	{
		/* If the previous state is on switch to off */
/*		if(p_key->m_key_sts == KEY_BUTTON_ON)
		{
			p_key->m_key_sts = KEY_BUTTON_OFF;	
			g_key_mng.m_touch_pos.new_pos = FALSE;
		}
		else if(p_key->m_key_sts == KEY_BUTTON_OFF)
		{ 
			p_key->m_key_sts = KEY_BUTTON_ON;*/
			id_converted = (p_key->m_key_id + 48); 
			sendUartMex( &id_converted, 1u);
			g_key_mng.m_touch_pos.new_pos = FALSE;
			DisplayScreen_ActionOnEvent(DISPLAY_MOVE_RECT, 0u);
		//} 
		Tmr_Reset(&(g_key_mng.m_key_status[p_key->m_key_id].m_key_deb_tmr));
	}
	else{}
	
	return 0;

}


/* Globabl routine definition */

void KeyMng_Init(int p_task)
{
	int i;
	g_key_mng.m_task_period = p_task;
	for(i = 0; i<KEY_BUTTON_MAX_NUM; i++)
	{
		Tmr_Init(&(g_key_mng.m_key_status[i].m_key_deb_tmr), p_task, gc_key_deb_conf[i].m_key_deb_cnt, 0, 0);
	}
}

void KeyMng_Periodical(void)
{
	int i;
	for(i = 0; i< KEY_BUTTON_MAX_NUM; i++)
	{
		g_key_mng.m_conf = &(gc_key_deb_conf[i]);
		KeyMng_GetKeyStatus(g_key_mng.m_conf);
	}
}



