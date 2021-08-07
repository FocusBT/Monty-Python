#pragma once
#ifndef SFOOD_H
#define SFOOD_H
#include "SnakeHead.h"

class SFood : public SnakeHead
{
public:
	SnakeHead s_food;
	void generateFood();
};

#endif

