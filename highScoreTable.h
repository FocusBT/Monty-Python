#pragma once
#ifndef HIGHSCORETABLE_H
#define HIGHSCORETABLE_H
#include"highScore.h"

class highScoreTable : public highScore
{
public:

	highScore hs[100];        
	int countScore;            
	highScoreTable();
	highScoreTable(int);
	void printTableShape();
	highScoreTable operator++(int);
};

#endif

