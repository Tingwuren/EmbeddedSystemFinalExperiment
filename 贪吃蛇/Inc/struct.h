#ifndef STRUCT_H
#define STRUCT_H

#include "coord.h"
#include <stdlib.h>
#include <stdio.h>
#include "gpio.h"
#include "lcd.h"

#define MAX_LENGTH 200 // 蛇的最大节数是200
#define WIN_WIDTH 480 // 窗口宽度为480
#define WIN_HEIGHT 282 // 窗口宽度为282


static struct Snake // 蛇的结构体
{
	int num; // 蛇的节数
	int dir; // 蛇头的运行方向
	int score; // 分数
	int size; // 每节蛇的宽度和高度
	Coord coord[MAX_LENGTH]; // 每节蛇的坐标
	int speed; // 蛇的运行速度
	int alive; // 蛇的存活状态
	Coord toclear; // 蛇下一次要清除的方块
	// int flag[3];
}snake;

enum DIR // 蛇的运行方向
{
	LEFT,
	DOWN,
	UP,
	RIGHT,
};

static struct Food // 食物的结构体
{
	int x; // 食物的横坐标
	int y; // 食物的纵坐标
	int existence;
	uint16_t color; // 食物的颜色
	int flag;
}food;

typedef struct Snake Snake;
typedef struct Food Food;
#endif
