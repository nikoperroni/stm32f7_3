/*
 * display_screen.h
 *
 *  Created on: 29 gen 2017
 *      Author: domenicoperroni
 */

#ifndef DISPLAY_SCREEN_H_
#define DISPLAY_SCREEN_H_

#include "types.h"

#define DISPLAY_MOVE_RECT 	(uint16)0

void DisplayScreen_init(void);
void DisplayScreen_ActionOnEvent(uint16 p_event, uint16 p_action);

#endif /* DISPLAY_SCREEN_H_ */
