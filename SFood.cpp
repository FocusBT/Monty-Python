#include <iostream>
#include <ctime>
#include "SnakeHead.h"
#include "SFood.h"
#include "global.h"
#include "stdafx.h"

using namespace std;

// For random food generation
void SFood::generateFood()
{
	time_t t;
	int x, y;
	srand(time(&t));          
	const int MAX_x = 73;
	const int MAX_y = 16;
	x = (rand() % MAX_x) + 3;
	y = (rand() % MAX_y) + 2;
	gotoxy(x, y);
	cout << '\x1';
	s_food.set(x, y);
}