#pragma once
#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

class SnakeHead
{
public:
	  int x;
	  int y;
	  void show(int);
	  void hide();
	  void set(int, int);
	  bool operator == (SnakeHead &);
};

#endif	
