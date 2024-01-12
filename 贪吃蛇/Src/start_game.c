#include "start_game.h"

// RGB函数
uint16_t RGB(uint8_t r, uint8_t g, uint8_t b)
{
	uint16_t color = 0;
	color |= (r >> 3) << 11;
	color |= (g >> 2) << 5;
	color |= (b >> 3);
	return color;
}
// 初始化蛇
void snakeinit(Snake* snake)
{
	snake->num = 3;
	snake->score = 0;
	snake->dir = RIGHT;
	snake->size = snake->speed;
	snake->coord[0].x = 2 *	snake->size;
	snake->coord[0].y = 0;
	snake->coord[1].x = snake->size;
	snake->coord[1].y = 0;
	snake->coord[2].x = 0;
	snake->coord[2].y = 0;
	snake->toclear.x = 0;
	snake->toclear.y = 0;
}

// 初始化食物
void foodinit(Snake* snake, Food*food)
{
	food->existence = 1;
	food->x = rand() % (WIN_WIDTH / snake->size) * snake->size + snake->size/2;
	food->y = rand() % (WIN_HEIGHT / snake->size) * snake->size + snake->size/2;
	if(food->x <= snake->size)
	{
		food->x += snake->size;
	}
	if(food->y <=snake->size)
	{
		food->y += snake->size;
	}
	if(food->x >= WIN_WIDTH - snake->size)
	{
		food->x -= snake->size;
	}
	if(food->y >= WIN_HEIGHT - snake->size)
	{
		food->y -= snake->size;
	}
	food -> color = RGB(rand() % 256, rand() % 256, rand() % 256);
}

void musicinit()
{
}
void gameinit(Snake* snake, Food* food)
{
	snakeinit(snake);
	foodinit(snake, food);
	musicinit();
}

// 实现游戏中的一次绘制
void gamedraw(Snake* snake, Food * food)
{
	// 设置背景色为绿色
	// LCD_Fill(0, 0, 480, 272, RGB(56, 113, 19));
	// 画蛇
	if(snake->coord[0].x < 0 || snake->coord[0].y < 0) return;
	for(int i = 0; i < snake->num; i++)
	{
		LCD_Fill(snake->coord[i].x, snake->coord[i].y, 
			snake->coord[i].x + snake->size, snake->coord[i].y + snake->size, Yellow);
	}
	
	// 清除蛇尾巴
	LCD_Fill(snake->toclear.x, snake->toclear.y, 
		snake->toclear.x + snake->size, snake->toclear.y + snake->size, 
		RGB(56, 113, 19));
	snake->toclear.x = snake->coord[snake->num-1].x;
	snake->toclear.y = snake->coord[snake->num-1].y;
	
	// 画食物
	if(food->existence == 1)
	{
		Fill_Circle(food->x, food->y, snake->size/2, food->color);
	}
}

// 实现蛇的一次移动
void snakemove(Snake* snake)
{
	// 实现蛇跟着头走
	for (int i = snake->num-1; i > 0; i --)
	{
		snake->coord[i].x = snake->coord[i-1].x;
		snake->coord[i].y = snake->coord[i-1].y;
	}
	// 实现蛇的前进方向改变
	if (snake->dir == UP)
	{
		snake->coord[0].y -= snake->speed;
	}
	if (snake->dir == DOWN)
	{
		snake->coord[0].y += snake->speed;
	}
	if (snake->dir == LEFT)
	{
		snake->coord[0].x -= snake->speed;
	}
	if (snake->dir == RIGHT)
	{
		snake->coord[0].x += snake->speed;
	}
}

// 从按键控制蛇移动方向
void keycontrol(Snake* snake)
{
	uint8_t select_key;
	select_key = KEY_Scan(0);
	// 按下K6，方向变为向左
	if(select_key == 6 && snake->dir != RIGHT)
	{
		snake->dir = LEFT;
	}
	// 按下K5，方向变为向下
	if(select_key == 5 && snake->dir != UP)
	{
		snake->dir = DOWN;
	}
	// 按下K4，方向变为向上
	if(select_key == 4 && snake->dir != DOWN)
	{
		snake->dir = UP;
	}
	// 按下K3，方向变为向右
	if(select_key == 3 && snake->dir != LEFT)
	{
		snake->dir = RIGHT;
	}
}

// 实现蛇吃食物的逻辑
void eatfood(Snake* snake, Food* food)
{
	int p = snake->coord[0].x + snake->size / 2, q = snake->coord[0].y + snake->size / 2;
	if (p==food->x&&q==food->y&& food->existence == 1)
	{
		snake->num++;
		snake->score++;
		food->existence = 0;
		snake->coord[snake->num - 1].x = snake->coord[snake->num - 2].x;
		snake->coord[snake->num - 1].y = snake->coord[snake->num - 2].y;
	}
	if(food->existence == 0)
	{
		foodinit(snake, food);
	}
	while(food->existence)
	{
		for(int j = 1; j < snake->num; j++)
		{
			if(snake->coord[j].x + snake->size/2 == food->x && snake->coord[j].y + snake->size/2 == food->y)
			{
				food->existence = 0;
				break;
			}
			else
			{
				food->flag = j;
			}
		}
		if(food->existence == 0)
		{
			foodinit(snake, food);
		}
		if (food->flag == snake->num - 1)
		{
			break;
		}
	}
}

// 游戏结束判断
void death(Snake* snake)
{
	if(snake->coord[0].x < 0 || snake->coord[0].x > WIN_WIDTH - snake->size || 
		snake->coord[0].y < 0 || snake->coord[0].y >WIN_HEIGHT - snake->size)
	{
		snake->alive = 0;
	}
	for(int i = 1; i < snake->num; i++)
	{
		if(snake->coord[0].x == snake->coord[i].x && snake->coord[0].y == snake->coord[i].y)
		{
			snake->alive = 0;
			break;
		}
	}
}

void startgame(Snake* snake, Food* food)
{
	LCD_Fill(0, 0, 480, 272, RGB(56, 113, 19));
	// 初始化蛇和食物
	gameinit(snake, food);
	// 如果蛇还存活
	while(snake->alive)
	{
		HAL_Delay(100);
		// 蛇各节坐标改变
		snakemove(snake);
		// 画一次蛇和食物
		gamedraw(snake, food);
		// 吃一次食物
		eatfood(snake, food);
		// 获取按键响应
		keycontrol(snake);
		// 判断蛇是否死亡
		death(snake);
		// 如果蛇已经死亡
		if(!snake->alive)
		{
			LCD_ShowString(180, 110, "GameOver!", Red, Transparent);
			// 显示分数
			char temp[20] = "";
			sprintf(temp, "分数:%d", snake->score);
			LCD_ShowString(180, 135, (uint8_t *)temp, Red, Transparent);
			LCD_ShowString(180, 160, "按K6退出游戏", Black, Transparent);
			LCD_ShowString(180, 185, "按K5重新开始游戏", Black, Transparent);
		}
	}
	uint8_t select_key;
	while(1)
	{
		select_key = KEY_Scan(0);
		if(select_key == 6)
		{
			snake->alive = 0;
			// 蛇死亡，退出主函数的循环
			break;
		}
		else if(select_key == 5)
		{
			snake->alive = 1;
			// 蛇存活，开始下一次游戏
			break;
		}
	}
}
