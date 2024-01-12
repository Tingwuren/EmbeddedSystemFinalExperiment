#include "lcd.h"
#include "initialize.h"


void initialize()
{
	lcd_clear(Blue);
	extern uint8_t gImage_bk[];
	LCD_DrawPicture(0,0,480,270, gImage_bk); // ������ͼƬ���س���
	
	// K6������Ӧ�Ŀ��ƿ�
	LCD_Fill(130, 135, 230, 185, White);
	LCD_ShowString(150, 150, "��ģʽ", Red, White);
	
	// K5������Ӧ�Ŀ��ƿ�
	LCD_Fill(250, 135, 350, 185, White);
	LCD_ShowString(270, 150, "����ģʽ", Red, White);
	
	// K4������Ӧ�Ŀ��ƿ�
	LCD_Fill(130, 205, 230, 255, White);
	LCD_ShowString(150, 220, "����ģʽ", Red, White);
	
	// K3������Ӧ�Ŀ��ƿ�
	LCD_Fill(250, 205, 350, 255, White);
	LCD_ShowString(270, 220, "��Ϸ˵��", Red, White);
	
}

