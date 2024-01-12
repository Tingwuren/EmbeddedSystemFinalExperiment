#ifndef STRUCT_H
#define STRUCT_H

#include "coord.h"
#include <stdlib.h>
#include <stdio.h>
#include "gpio.h"
#include "lcd.h"

#define MAX_LENGTH 200 // �ߵ���������200
#define WIN_WIDTH 480 // ���ڿ��Ϊ480
#define WIN_HEIGHT 282 // ���ڿ��Ϊ282


static struct Snake // �ߵĽṹ��
{
	int num; // �ߵĽ���
	int dir; // ��ͷ�����з���
	int score; // ����
	int size; // ÿ���ߵĿ�Ⱥ͸߶�
	Coord coord[MAX_LENGTH]; // ÿ���ߵ�����
	int speed; // �ߵ������ٶ�
	int alive; // �ߵĴ��״̬
	Coord toclear; // ����һ��Ҫ����ķ���
	// int flag[3];
}snake;

enum DIR // �ߵ����з���
{
	LEFT,
	DOWN,
	UP,
	RIGHT,
};

static struct Food // ʳ��Ľṹ��
{
	int x; // ʳ��ĺ�����
	int y; // ʳ���������
	int existence;
	uint16_t color; // ʳ�����ɫ
	int flag;
}food;

typedef struct Snake Snake;
typedef struct Food Food;
#endif
