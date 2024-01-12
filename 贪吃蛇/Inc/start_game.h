#pragma once
#include "user_selection.h"
uint16_t RGB(uint8_t r, uint8_t g, uint8_t b);
void snakeinit(Snake* snake);
void foodinit(Snake* snake, Food*food);
void musicinit();
void gamedraw(Snake* snake, Food * food);
void snakemove(Snake* snake);
void keycontrol(Snake* snake);
void eatfood(Snake* snake, Food* food);
void death(Snake* snake);
void startgame(Snake* snake, Food* food);

