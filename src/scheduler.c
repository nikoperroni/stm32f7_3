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
}S_TASK_CONF;

typedef struct _S_TASK_
{
	uint8 m_task_id;
	uint16 m_task_period;
	const S_TASK_CONF *m_conf;
}S_TASK;



static const S_TASK_CONF gc_task_conf[TASK_NUM_MAX] =
{
	{10u,  1u, &Scheduler_Task1, }, 	/* Task 1 */
	{20u , 2u, &Scheduler_Task2, },		/* Task 2 */
	{500u , 3u, &Scheduler_Task3, },		/* Task 3 */
};

static int var1;
static int var2;
S_TASK g_task;

void Scheduler_Init(void)
{

/*	int i;
	for(i = 0; i< 2; i++)
	{
		g_task[i].m_task_id = i;
		g_task[i].m_task_period = (i + 1) * 5u;
	}

	g_task[0].m_func_period = Scheduler_Task1;
	g_task[1].m_func_period = Scheduler_Task2;
*/
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

		if( (current_tick % g_task.m_conf->m_task_period) == 0 )
		{
			/* Execute task */
			g_task.m_conf->m_task_function();
		}
		else{}
	}

}

static void Scheduler_Task1(void)
{
	var1++;
}


static void Scheduler_Task2(void)
{
	KeyMng_Periodical();
	var2++;
}

static void Scheduler_Task3(void)
{
	int p_var;
	p_var = var1 + var2;
}
