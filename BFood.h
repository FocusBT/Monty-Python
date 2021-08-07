#pragma once
#ifndef BFOOD_H
#define BFOOD_H
#include "SnakeHead.h"

class BFood : public SnakeHead
{
public:
	SnakeHead b_food;
	void generateBigFood();
};

#endif

