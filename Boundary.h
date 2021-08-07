#pragma once
#ifndef BOUNDARY_H
#define BOUNDARY_H
#include "SnakeHead.h"

class Boundary : public SnakeHead
{
public:
	int x_distance;
	int y_distance;
	SnakeHead *left_boundary;
	SnakeHead *right_boundary;
	SnakeHead *up_boundary;
	SnakeHead *down_boundary;
	Boundary();
	void setLeftBoundary();
	void setRightBoundary();
	void setUpBoundary();
	void setDownBoundary();
	void gameBoundary();
	void gameOverScreen();
	void welcomeScreen();
	void showTime(int);
	void hideTime();
};

#endif

