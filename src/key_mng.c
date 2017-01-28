#include "stm32f7xx_hal.h"
#include "stm32746g_discovery_ts.h"
#include "types.h"
#include "timer.h"
#include "key_mng.h"



typedef struct _S_KEY_DEB_{
	uint8 m_key_id;
	uint16 m_key_x_dim;
	uint16 m_key_y_dim;
	uint16 m_key_size;
	S_TIMER_COUNT m_key_deb_cnt;
	uint8 m_key_sts;
}S_KEY_DEB;

typedef struct _S_KEY_MNG_STS_
{
	uint8 m_key_fsm_state;
	S_TIMER m_key_deb_tmr;
}S_KEY_MNG_STS;

typedef struct _S_KEY_MNG_
{
	uint16 m_task_period;
	S_KEY_MNG_STS  m_key_status[KEY_BUTTON_MAX_NUM];
	const S_KEY_DEB *m_conf;
}S_KEY_MNG;


static const  S_KEY_DEB gc_key_deb_conf[KEY_BUTTON_MAX_NUM] =
{
	{0, 40u,  40u,100u, (S_TIMER_COUNT)100, 0},
	{0, 80u,  40u,100u, (S_TIMER_COUNT)100, 0},
	{0, 140u, 40u,100u, (S_TIMER_COUNT)100, 0},
	{0, 240u, 40u,100u, (S_TIMER_COUNT)100, 0},
};

static void KeyMng_GeyKeyStatus(S_KEY_DEB *p_key);
static uint8 KeyMng_HandleSts(S_KEY_DEB *p_key);

S_KEY_MNG g_key_mng;

/* Private Routines */
static void KeyMng_GeyKeyStatus(S_KEY_DEB *p_key)
{
	uint8_t ts_state;
	uint16_t ypos = 0, ymax = 0, xpos = 0, size = 0;
	TS_StateTypeDef TS_State;

	ypos = p_key->m_key_y_dim;
	xpos = p_key->m_key_x_dim;
	size = p_key->m_key_size;

	ts_state = BSP_TS_GetState(&TS_State);
	for(int x1= 0; x1<5; x1++)
	{
		if( (TS_State.touchY[x1] > ypos) && (TS_State.touchY[x1] < (ypos + size)) )
		{
			if( (TS_State.touchX[x1] > xpos) && (TS_State.touchX[x1] < (xpos + size)) )
			//BSP_LCD_DisplayStringAt(0, 120, string1, CENTER_MODE);
			sendUart();
		}else{}
	}


}

static uint8 KeyMng_HandleSts(S_KEY_DEB *p_key)
{

}


/* Globabl routine definition */

void KeyMng_Init(int p_task)
{
	g_key_mng.m_task_period = p_task;
}

void KeyMng_Periodical(void)
{
	int i;
	for(i = 0; i< KEY_BUTTON_MAX_NUM; i++)
	{
		g_key_mng.m_conf = &(gc_key_deb_conf[i]);
		KeyMng_GeyKeyStatus(g_key_mng.m_conf);
	}
}



