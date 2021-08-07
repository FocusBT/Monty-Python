#include <iostream>
#include <windows.h>
#include "highScore.h"
#include "global.h"
#include "stdafx.h"

using namespace std;

// Constructor for incase directly pressed 2 option
highScore :: highScore() {
	score = 0;
}

// For printing data into the high scores table
void highScore ::  printData(int d)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(17, d + 7);
	SetConsoleTextAttribute(hConsole, 15); 
	cout << d + 1;
	gotoxy(26, d + 7);
	SetConsoleTextAttribute(hConsole, 2);  
	cout << name;
	gotoxy(47, d + 7);
	SetConsoleTextAttribute(hConsole, 3);   
	cout << score;
	SetConsoleTextAttribute(hConsole, 7);  
}

// Setter for intial temporary data for file
void highScore ::  setData()
{
	char array[15] = "No Name";
	for (int i = 0; i < 15; i++) {
		name[i] = array[i];
	}
	score = 0;
}

// Getter (for username)
void highScore ::  getData()
{
	cout << "Name: ";
	cin >> name;
}

// For assigning name & score of current user
void highScore::operator =(highScore hh) 
{
	score = hh.score;
	for (int i = 0; i < 15; i++)
	{
		name[i] = hh.name[i];
	}
}