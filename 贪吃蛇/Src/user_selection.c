#include "user_selection.h"

void user_selection(Snake* snake)
{
	uint8_t select_key;
	int flag = 0;
	extern uint8_t gImage_info[];
	int action = 0;
	
	while(!action)
	{
		
		if(flag == 0) // 响应第一次用户按键
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					LCD_Fill(130, 135, 230, 185, Yellow);
					LCD_ShowString(150, 150, "简单模式", Red, Yellow);
					flag = 6;
					break;
				case 5:
					LCD_Fill(250, 135, 350, 185, Yellow);
					LCD_ShowString(270, 150, "困难模式", Red, Yellow);
					flag = 5;
					break;
				case 4:
					LCD_Fill(130, 205, 230, 255, Yellow);
					LCD_ShowString(150, 220, "地狱模式", Red, Yellow);
					flag = 4;
					break;
				case 3:
					LCD_Fill(250, 205, 350, 255, Yellow);
					LCD_ShowString(270, 220, "游戏说明", Red, Yellow);
					flag = 3;
					break;
				case 0:
					break;
			}
		}
		if(flag == 6) // 当用户上一次按下K6
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					flag = 0;
					action = 6;
					break;
				case 5:
					LCD_Fill(130, 135, 230, 185, White);
					LCD_ShowString(150, 150, "简单模式", Red, White);
					LCD_Fill(250, 135, 350, 185, Yellow);
					LCD_ShowString(270, 150, "困难模式", Red, Yellow);
					flag = 5;
					break;
				case 4:
					LCD_Fill(130, 135, 230, 185, White);
					LCD_ShowString(150, 150, "简单模式", Red, White);
					LCD_Fill(130, 205, 230, 255, Yellow);
					LCD_ShowString(150, 220, "地狱模式", Red, Yellow);
					flag = 4;
					break;
				case 3:
					LCD_Fill(130, 135, 230, 185, White);
					LCD_ShowString(150, 150, "简单模式", Red, White);
					LCD_Fill(250, 205, 350, 255, Yellow);
					LCD_ShowString(270, 220, "游戏说明", Red, Yellow);
					flag = 3;
					break;
				case 0:
					break;
			}
		}
		if(flag == 5) // 当用户上一次按下K5
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					LCD_Fill(250, 135, 350, 185, White);
					LCD_ShowString(270, 150, "困难模式", Red, White);
					LCD_Fill(130, 135, 230, 185, Yellow);
					LCD_ShowString(150, 150, "简单模式", Red, Yellow);
					flag = 6;
					break;
				case 5:
					flag = 0;
					action = 5;
					break;
				case 4:
					LCD_Fill(250, 135, 350, 185, White);
					LCD_ShowString(270, 150, "困难模式", Red, White);
					LCD_Fill(130, 205, 230, 255, Yellow);
					LCD_ShowString(150, 220, "地狱模式", Red, Yellow);
					flag = 4;
					break;
				case 3:
					LCD_Fill(250, 135, 350, 185, White);
					LCD_ShowString(270, 150, "困难模式", Red, White);
					LCD_Fill(250, 205, 350, 255, Yellow);
					LCD_ShowString(270, 220, "游戏说明", Red, Yellow);
					flag = 3;
					break;
				case 0:
					break;
			}
		}
		if(flag == 4) // 当用户上一次按下K4
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					LCD_Fill(130, 205, 230, 255, White);
					LCD_ShowString(150, 220, "地狱模式", Red, White);
					LCD_Fill(130, 135, 230, 185, Yellow);
					LCD_ShowString(150, 150, "简单模式", Red, Yellow);
					flag = 6;
					break;
				case 5:
					LCD_Fill(130, 205, 230, 255, White);
					LCD_ShowString(150, 220, "地狱模式", Red, White);
					LCD_Fill(250, 135, 350, 185, Yellow);
					LCD_ShowString(270, 150, "困难模式", Red, Yellow);
					flag = 5;
					break;
				case 4:
					flag = 0;
					action = 4;
					break;
				case 3:
					LCD_Fill(130, 205, 230, 255, White);
					LCD_ShowString(150, 220, "地狱模式", Red, White);
					LCD_Fill(250, 205, 350, 255, Yellow);
					LCD_ShowString(270, 220, "游戏说明", Red, Yellow);
					flag = 3;
					break;
				case 0:
					break;
			}
		}
		if(flag == 3) // 当用户上一次按下K3
		{
			select_key = KEY_Scan(0);
			switch(select_key)
			{
				case 6:
					LCD_Fill(250, 205, 350, 255, White);
					LCD_ShowString(270, 220, "游戏说明", Red, White);
					LCD_Fill(130, 135, 230, 185, Yellow);
					LCD_ShowString(150, 150, "简单模式", Red, Yellow);
					flag = 6;
					break;
				case 5:
					LCD_Fill(250, 205, 350, 255, White);
					LCD_ShowString(270, 220, "游戏说明", Red, White);
					LCD_Fill(250, 135, 350, 185, Yellow);
					LCD_ShowString(270, 150, "困难模式", Red, Yellow);
					flag = 5;
					break;
				case 4:
					LCD_Fill(250, 205, 350, 255, White);
					LCD_ShowString(270, 220, "游戏说明", Red, White);
					LCD_Fill(130, 205, 230, 255, Yellow);
					LCD_ShowString(150, 220, "地狱模式", Red, Yellow);
					flag = 4;
					break;
				case 3:
					// action = 3;
					LCD_Fill(0, 0, 480, 272, White);
					LCD_DrawPicture(99,0,381,282, gImage_info); // 将游戏说明图片加载出来
					LCD_ShowString(15, 15, "游戏规则：", Black, Transparent);
					LCD_ShowString(15, 40, "1. 在主菜单页按下K6选择简单模式，再按一次开始游戏。", Blue, Transparent);
					LCD_ShowString(15, 65, "2. 在主菜单页按下K5选择困难模式，再按一次开始游戏。", Blue, Transparent);
					LCD_ShowString(15, 90, "3. 在主菜单页按下K4选择地狱模式，再按一次开始游戏。", Blue, Transparent);
					LCD_ShowString(15, 115, "4. 在主菜单页按下K3选择游戏说明，再按一次打开规则说明界面。", Blue, Transparent);
					LCD_ShowString(15, 140, "5. 开始游戏后K6控制蛇向左移动，K3控制蛇向右移动。", Blue, Transparent);
					// Todo:存在bug，数字3不显示
					LCD_ShowString(15, 165, "6. 开始游戏后K5控制蛇向下移动，K4控制蛇向上移动。", Blue, Transparent);
					// Todo:存在bug，数字4不显示
					LCD_ShowString(15, 190, "7. 开始游戏后蛇每吃一个食物就得一分。", Blue, Transparent);
					LCD_ShowString(15, 215, "8. 开始游戏后蛇头运动出屏幕时会碰死，蛇咬到自身时也会死。", Blue, Transparent);
					LCD_ShowString(350, 15, "按K3返回主菜单", Red, Transparent);
					// Todo: 存在bug，K3不显示
					
					while(1)
					{
						select_key = KEY_Scan(0);
						if(select_key == 3)
						{
							break;
						}
					}
					initialize();
					flag = 0;
					break;
				case 0:
					break;
			}
		}
	}
	snake->speed = 0;
	snake->alive = 0;
	
	switch(action)
	{
		case 6:
			// 简单模式
			snake->speed = 10;
			snake->alive = 1;
			break;
		case 5:
			// 困难模式
			snake->speed = 20;
			snake->alive = 1;
			break;
		case 4:
			// 地狱模式
			snake->speed = 30;
			snake->alive = 1;
			break;
		case 3:
			break;
	}
	
}
