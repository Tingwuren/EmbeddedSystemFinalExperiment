#include "lcd.h"
#include "initialize.h"


void initialize()
{
	lcd_clear(Blue);
	extern uint8_t gImage_bk[];
	LCD_DrawPicture(0,0,480,270, gImage_bk); // 将背景图片加载出来
	
	// K6按键对应的控制块
	LCD_Fill(130, 135, 230, 185, White);
	LCD_ShowString(150, 150, "简单模式", Red, White);
	
	// K5按键对应的控制块
	LCD_Fill(250, 135, 350, 185, White);
	LCD_ShowString(270, 150, "困难模式", Red, White);
	
	// K4按键对应的控制块
	LCD_Fill(130, 205, 230, 255, White);
	LCD_ShowString(150, 220, "地狱模式", Red, White);
	
	// K3按键对应的控制块
	LCD_Fill(250, 205, 350, 255, White);
	LCD_ShowString(270, 220, "游戏说明", Red, White);
	
}

