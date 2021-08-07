#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include "highScore.h"

char temp_key, do_key;

enum EDir { Down = 80, Left = 75, Right = 77, Up = 72, Esc = 27 };   

void gotoxy(int, int);

void swapScore(highScore &, highScore &);

#endif