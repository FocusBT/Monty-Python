#pragma once
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

class highScore
{
public:
	char name[15];          
	int score;  
	highScore();
	void setData();
	void getData();
	void printData(int);
	void operator=(highScore);
};

#endif	

