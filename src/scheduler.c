/*
 * scheduler.c
 *
 *  Created on: 21 gen 2017
 *      Author: domenicoperroni
 */
#include "types.h"
#include "key_mng.h"

#define TASK_NUM_MAX 	(uint8)3

static void Scheduler_Task1(void);
static void Scheduler_Task2(void);
static void Scheduler_Task3(void);

typedef void (*funcp_task)(void);

typedef struct _S_TASK_CONF_
{
	uint16	m_task_period;
	uint8 m_task_priority;
	funcp_task m_task_function;
	uint8 m_task_execute;
}S_TASK_CONF;

typedef struct _S_TASK_
{
	uint8 m_task_id;
	uint16 m_task_period;
	S_TASK_CONF *m_conf;
}S_TASK;



static S_TASK_CONF gc_task_conf[TASK_NUM_MAX] =
{
	{10u,  1u, &Scheduler_Task1, FALSE,}, 	/* Task 1 */
	{20u , 2u, &Scheduler_Task2, FALSE,},		/* Task 2 */
	{500u , 3u, &Scheduler_Task3, FALSE,},	/* Task 3 */
};

S_TASK g_task;

void Scheduler_Init(void)
{
	g_task.m_task_id = (uint8) 0;
	g_task.m_task_period = (uint16) 0;
}

void Scheduler_Periodical(void)
{
	int i;
	uint32 current_tick;
	current_tick = HAL_GetTick();
	for(i = 0; i< 2; i++)
	{
		g_task.m_conf = &gc_task_conf[i];

		if(g_task.m_conf->m_task_execute == TRUE)
		{
			/* Execute task */
			g_task.m_conf->m_task_function();
			g_task.m_conf->m_task_execute = FALSE;
		}
		else{}
	}

}

void Scheduler_ExecuteTask(void)
{
	int i;
	uint32 current_tick;
	current_tick = HAL_GetTick();
	for(i = 0; i< 2; i++)
	{
		g_task.m_conf = &gc_task_conf[i];

		if( (current_tick % g_task.m_conf->m_task_period) == 0 )
		{
			/* Execute task */
			g_task.m_conf->m_task_execute = TRUE;
		}
		else{}
	}
}

static void Scheduler_Task1(void)
{
	KeyMng_Periodical();
}


static void Scheduler_Task2(void)
{

}

static void Scheduler_Task3(void)
{
}

