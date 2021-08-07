#include <iostream>
#include "global.h"
#include "Snake.h"
#include "stdafx.h"

using namespace std;

// Initially setting up snake
Snake :: Snake()
{
	Length = 5;
	Score = 0;
	Direction = Right;
	snake[0].set(15, 10);
	snake[1].set(14, 10);
	snake[2].set(13, 10);
	snake[3].set(12, 10);
	snake[4].set(11, 10);
	snake[5].set(10, 10);
}

// For operator overload ++
Snake :: Snake(int l)
{
	Length = l;
}

// For displaying snake
void Snake:: show()
{
	for (int a = 0; a < Length; a++)
		snake[a].show(a);
	snake[Length].hide();
}

// For moving left
void Snake:: left()
{
	// Logic for body to follow head
	for (int b = Length; b > 0; b--)
	{
		
		snake[b].x = snake[b - 1].x;
		snake[b].y = snake[b - 1].y;
	}
	// Left
	snake[0].x--;
}

// For moving right
void Snake::right()
{
	// Logic for body to follow head
	for (int b = Length; b > 0; b--)
	{
		snake[b].x = snake[b - 1].x;
		snake[b].y = snake[b - 1].y;
	}
	// Right
	snake[0].x++;
}

// For moving down
void Snake::down()
{
	// Logic for body to follow head
	for (int c = Length; c > 0; c--)
	{
		snake[c].x = snake[c - 1].x;
		snake[c].y = snake[c - 1].y;
	}
	// Down
	snake[0].y++;
}

// For moving up
void Snake::up()
{
	// Logic for body to follow head
	for (int c = Length; c > 0; c--)
	{
		snake[c].y = snake[c - 1].y;
		snake[c].x = snake[c - 1].x;
	}
	// Up
	snake[0].y--;
}

// For displaying current score
void Snake::printScore(int x0, int y0)
{
	gotoxy(x0, y0);
	cout << Score;
}

// Operator overload ++ for increment of score & length
Snake Snake::operator++(int)
{
	Snake temp(Length);
	Length++;
	Score += 5;
	return temp;
}
