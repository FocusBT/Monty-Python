#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include "SnakeHead.h"

class Snake : public SnakeHead
{
public:
	int Score;
	int Length;
	char Direction;
	SnakeHead snake[100];
	Snake();
	Snake(int);
	void show();
	void left();
	void right();
	void up();
	void down();
	void printScore(int, int);
	Snake operator++(int);
};

#endif


