#include <iostream>
#include <ctime>
#include"SnakeHead.h"
#include "BFood.h"
#include "global.h"
#include "stdafx.h"

using namespace std;

// For random bonus food generation
void BFood :: generateBigFood()
{
	time_t t1;
	srand(time(&t1));           
	const int max_x = 73;
	const int max_y = 15;
	x = (rand() % max_x) + 4;
	y = (rand() % max_y) + 3;
	gotoxy(x, y);
	cout << '\x5';
	b_food.set(x, y);
}
