/*
 * display_screen.c
 *
 *  Created on: 29 gen 2017
 *      Author: domenicoperroni
 */

#include "types.h"
#include "stm32746g_discovery_ts.h"
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "display_screen.h"

static void DisplayScreen_initPeripheralClock(void);
static void DisplayScreen_LCDConfig(void);



static void DisplayScreen_initPeripheralClock(void)
{
  	RCC_PeriphCLKInitTypeDef  PeriphClkInitStruct;
	/* LCD clock configuration */
	/* PLLSAI_VCO Input = HSE_VALUE/PLL_M = 1 Mhz */
	/* PLLSAI_VCO Output = PLLSAI_VCO Input * PLLSAIN = 192 Mhz */
	/* PLLLCDCLK = PLLSAI_VCO Output/PLLSAIR = 192/5 = 38.4 Mhz */
	/* LTDC clock frequency = PLLLCDCLK / LTDC_PLLSAI_DIVR_4 = 38.4/4 = 9.6Mhz */
	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
	PeriphClkInitStruct.PLLSAI.PLLSAIN = 192;
 	PeriphClkInitStruct.PLLSAI.PLLSAIR = 5;
	PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_4;
	HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

}

/**
  * @brief LCD Configuration.
  * @note  This function Configure tha LTDC peripheral :
  *        1) Configure the Pixel Clock for the LCD
  *        2) Configure the LTDC Timing and Polarity
  *        3) Configure the LTDC Layer 1 :
  *           - The frame buffer is located at FLASH memory
  *           - The Layer size configuration : 480x272                      
  * @retval
  *  None
  */
static void DisplayScreen_LCDConfig(void)
{ 
	  /* LCD Initialization */
	  BSP_LCD_Init();

	  /* LCD Initialization */
	  BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);

	  /* Enable the LCD */
	  BSP_LCD_DisplayOn();

	  /* Select the LCD Background Layer  */
	  BSP_LCD_SelectLayer(0);

	  /* Clear the Background Layer */
	  BSP_LCD_Clear(LCD_COLOR_BLACK);

	  /* Configure the transparency for background */
	  BSP_LCD_SetTransparency(0, 100);
}



void DisplayScreen_init(void)
{

	DisplayScreen_initPeripheralClock();
	  
	/* Configure LED1 */
//	BSP_LED_Init(LED1);   
	
	/* Configure LCD : Only one layer is used */
	DisplayScreen_LCDConfig();

	/* init the touchscreen */
	BSP_TS_Init( (uint16_t)480, (uint16_t)272);
	
	/* Our main starts here */
	uint16_t ypos = 0, ymax = 0;
	int8_t yincr = 1;

/*
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_YELLOW);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
		
	BSP_LCD_DrawCircle( (uint16_t)230u, (uint16_t)150u, (uint16_t)50u);
	BSP_LCD_FillCircle((uint16_t)230u, (uint16_t)150u, (uint16_t)50u);
	BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW); */

  /* Clear the LCD */ 
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  
  /* Set LCD Demo description */
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  BSP_LCD_FillRect(0, 40, 70, 70);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
/*  BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
  BSP_LCD_SetFont(&Font24);
  BSP_LCD_DisplayStringAt(0, 0, (uint8_t *)"LCD", CENTER_MODE);
  BSP_LCD_SetFont(&Font12);
  BSP_LCD_DisplayStringAt(0, 30, (uint8_t *)"This example shows the different", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 45, (uint8_t *)"LCD Features, use BUTTON to display", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 60, (uint8_t *)"next page", CENTER_MODE);
*/
   /* Set the LCD Text Color */
/*  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_DrawRect(10, 90, BSP_LCD_GetXSize() - 20, BSP_LCD_GetYSize()- 100);
  BSP_LCD_DrawRect(11, 91, BSP_LCD_GetXSize() - 22, BSP_LCD_GetYSize()- 102);
*/
  BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
  BSP_LCD_FillRect(100, 40, 70, 70);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

  BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
  BSP_LCD_FillRect(200, 40, 70, 70);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

  BSP_LCD_SetTextColor(LCD_COLOR_GREEN );
  BSP_LCD_FillRect(310, 40, 70, 70);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);


}


