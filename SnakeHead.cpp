#include <iostream>
#include "SnakeHead.h"
#include<iostream>
#include "global.h"
#include "stdafx.h"

using namespace std;

// Function to display head & body of snake
void SnakeHead::show(int head)
{
	// Snake head
	if (head == 0)
	{
		gotoxy(x, y);
		cout << "D";
	}
	// Snake body
	else
	{
		gotoxy(x, y);
		cout << "\xDB";
	}
}

// for snake body & removing bonus food after timer 
void SnakeHead::hide()
{
	gotoxy(x, y);
	cout << " ";
}
// x,y setter for food,snake,boundary
void SnakeHead::set(int x0, int y0)
{
	x = x0;
	y = y0;
}
// For collision detection
bool SnakeHead::operator == (SnakeHead & temp)
{
	if (x == temp.x && y == temp.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

