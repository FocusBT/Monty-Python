#include <iostream>
#include <windows.h>
#include <conio.h>
#include "highScore.h"
#include "global.h"
#include "stdafx.h"

// Definition of standard gotoxy function
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// For sorting of scores
void swapScore(highScore& h1, highScore& h2) {
    if (h1.score > h2.score) {         
        highScore temp;                
        temp = h1;
        h1 = h2;
        h2 = temp;
    }
}
