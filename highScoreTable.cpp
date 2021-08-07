#include <iostream>
#include <windows.h>
#include "highScore.h"
#include "highScoreTable.h"
#include "global.h"
#include "stdafx.h"

using namespace std;

// For setting initial data into the score table
highScoreTable :: highScoreTable()
{
	for (int i = 0; i < 100; i++)
	{
		hs[i].setData();
	}
	countScore = 0;
}

// Constructor for sorting
highScoreTable :: highScoreTable(int hst)
{
	countScore = hst;
}

// Printing high scores table
void highScoreTable :: printTableShape() {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(hConsole, 480);
	gotoxy(32, 1);
	cout << " High Scores ";
	SetConsoleTextAttribute(hConsole, 8);             
	gotoxy(15, 4);
	cout << '\xDA';
	for (int i = 16; i < 57; i++) {                
		gotoxy(i, 4);                          
		cout << '\xC4';                          
	}                                         
	cout << '\xBF';
	gotoxy(20, 4); 
	cout << '\xC2';
	gotoxy(39, 4); cout << '\xC2';
	gotoxy(15, 5); cout << '\xB3';
	gotoxy(20, 5); cout << '\xB3';
	gotoxy(39, 5); cout << '\xB3';
	gotoxy(57, 5); cout << '\xB3';
	gotoxy(15, 6); cout << '\xC3';
	for (int i = 16; i < 57; i++) {
		gotoxy(i, 6);
		cout << '\xC4';
	}
	gotoxy(39, 6); cout << '\xC5';
	gotoxy(20, 6); cout << '\xC5';
	gotoxy(57, 6); cout << '\xB4';
	for (int i = 7; i < 23; i++) {
		gotoxy(15, i); cout << '\xB3';
		gotoxy(20, i); cout << '\xB3';
		gotoxy(39, i); cout << '\xB3';
		gotoxy(57, i); cout << '\xB3';
	}
	gotoxy(15, 22); cout << '\xC0';
	for (int i = 16; i < 57; i++) {
		gotoxy(i, 22);
		cout << '\xC4';
	}
	gotoxy(39, 22); cout << '\xC1';
	gotoxy(20, 22); cout << '\xC1';
	gotoxy(57, 22); cout << '\xD9';
	SetConsoleTextAttribute(hConsole, 14);    
	gotoxy(28, 5); cout << "Name";
	gotoxy(46, 5); cout << "Score";
	gotoxy(17, 5); cout << "S#";
	SetConsoleTextAttribute(hConsole, 480);
	gotoxy(31, 24); cout << "Your Score: ";
}

// For ranking/serial no. 
highScoreTable highScoreTable::operator++(int) {
	highScoreTable temp(countScore);
	countScore++;
	return temp;
}