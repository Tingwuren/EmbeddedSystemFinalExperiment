#include "start_game.h"

// RGB����
uint16_t RGB(uint8_t r, uint8_t g, uint8_t b)
{
	uint16_t color = 0;
	color |= (r >> 3) << 11;
	color |= (g >> 2) << 5;
	color |= (b >> 3);
	return color;
}
// ��ʼ����
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

// ��ʼ��ʳ��
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

// ʵ����Ϸ�е�һ�λ���
void gamedraw(Snake* snake, Food * food)
{
	// ���ñ���ɫΪ��ɫ
	// LCD_Fill(0, 0, 480, 272, RGB(56, 113, 19));
	// ����
	if(snake->coord[0].x < 0 || snake->coord[0].y < 0) return;
	for(int i = 0; i < snake->num; i++)
	{
		LCD_Fill(snake->coord[i].x, snake->coord[i].y, 
			snake->coord[i].x + snake->size, snake->coord[i].y + snake->size, Yellow);
	}
	
	// �����β��
	LCD_Fill(snake->toclear.x, snake->toclear.y, 
		snake->toclear.x + snake->size, snake->toclear.y + snake->size, 
		RGB(56, 113, 19));
	snake->toclear.x = snake->coord[snake->num-1].x;
	snake->toclear.y = snake->coord[snake->num-1].y;
	
	// ��ʳ��
	if(food->existence == 1)
	{
		Fill_Circle(food->x, food->y, snake->size/2, food->color);
	}
}

// ʵ���ߵ�һ���ƶ�
void snakemove(Snake* snake)
{
	// ʵ���߸���ͷ��
	for (int i = snake->num-1; i > 0; i --)
	{
		snake->coord[i].x = snake->coord[i-1].x;
		snake->coord[i].y = snake->coord[i-1].y;
	}
	// ʵ���ߵ�ǰ������ı�
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

// �Ӱ����������ƶ�����
void keycontrol(Snake* snake)
{
	uint8_t select_key;
	select_key = KEY_Scan(0);
	// ����K6�������Ϊ����
	if(select_key == 6 && snake->dir != RIGHT)
	{
		snake->dir = LEFT;
	}
	// ����K5�������Ϊ����
	if(select_key == 5 && snake->dir != UP)
	{
		snake->dir = DOWN;
	}
	// ����K4�������Ϊ����
	if(select_key == 4 && snake->dir != DOWN)
	{
		snake->dir = UP;
	}
	// ����K3�������Ϊ����
	if(select_key == 3 && snake->dir != LEFT)
	{
		snake->dir = RIGHT;
	}
}

// ʵ���߳�ʳ����߼�
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

// ��Ϸ�����ж�
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
	// ��ʼ���ߺ�ʳ��
	gameinit(snake, food);
	// ����߻����
	while(snake->alive)
	{
		HAL_Delay(100);
		// �߸�������ı�
		snakemove(snake);
		// ��һ���ߺ�ʳ��
		gamedraw(snake, food);
		// ��һ��ʳ��
		eatfood(snake, food);
		// ��ȡ������Ӧ
		keycontrol(snake);
		// �ж����Ƿ�����
		death(snake);
		// ������Ѿ�����
		if(!snake->alive)
		{
			LCD_ShowString(180, 110, "GameOver!", Red, Transparent);
			// ��ʾ����
			char temp[20] = "";
			sprintf(temp, "����:%d", snake->score);
			LCD_ShowString(180, 135, (uint8_t *)temp, Red, Transparent);
			LCD_ShowString(180, 160, "��K6�˳���Ϸ", Black, Transparent);
			LCD_ShowString(180, 185, "��K5���¿�ʼ��Ϸ", Black, Transparent);
		}
	}
	uint8_t select_key;
	while(1)
	{
		select_key = KEY_Scan(0);
		if(select_key == 6)
		{
			snake->alive = 0;
			// ���������˳���������ѭ��
			break;
		}
		else if(select_key == 5)
		{
			snake->alive = 1;
			// �ߴ���ʼ��һ����Ϸ
			break;
		}
	}
}
