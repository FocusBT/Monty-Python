#include <iostream>
#include <windows.h>
#include "Boundary.h"
#include "global.h"
#include "stdafx.h"

using namespace std;

// Initial values of x & y & variables for each side boundary
Boundary::Boundary()
{
	x_distance = 17;
    y_distance = 76;         
    left_boundary = new SnakeHead[x_distance];
    right_boundary = new SnakeHead[x_distance];    
    up_boundary = new SnakeHead[y_distance];       
    down_boundary = new SnakeHead[y_distance];
}

// Setting left boundary
void Boundary::setLeftBoundary()
{
	for (int i = 0; i < x_distance; i++)
	{
		left_boundary[i].set(2, i + 2);
	}
}

// Setting right boundary
void Boundary::setRightBoundary()
{
	for (int i = 0; i < x_distance; i++)
	{
		right_boundary[i].set(Right, i + 2);
	}
}

// Setting upper boundary
void Boundary :: setUpBoundary()
{
	for (int i = 0; i < y_distance; i++)
	{
		up_boundary[i].set(2 + i, 1);
	}
}

// Setting down boundary
void Boundary :: setDownBoundary()
{
	for (int i = 0; i < y_distance; i++)
	{
		down_boundary[i].set(2 + i, 19);
	}
}

// Displaying game boundary/screen
void Boundary :: gameBoundary()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 8);                         
	cout << "\n  " << '\xC9';
	for (int i = 0; i < 75; i++)
	{
		cout << '\xCD';
	}
	cout << '\xBB' << "\n" << "  " << '\xBA';
	for (int i = 0; i < 75; i++)
	{
		cout << " ";
	}
	cout << '\xBA';
	for (int j = 0; j < 16; j++)
	{
		cout << "\n" << "  " << '\xBA';
		for (int i = 0; i < 75; i++)
		{
			cout << " ";
		}
		cout << '\xBA';
	}
	cout << "\n" << "  " << '\xC8';
	for (int i = 0; i < 75; i++)
	{
		cout << '\xCD';
	}
	cout << '\xBC';
	cout << "\n  " << '\xC9';
	for (int i = 0; i < 75; i++)
	{
		cout << '\xCD';
	}
	cout << '\xBB' << "\n" << "  " << '\xBA';
	SetConsoleTextAttribute(hConsole, 271);                         
	cout << "   Score: " << "\t\t\t\t\t\t\tTime:         ";
	SetConsoleTextAttribute(hConsole, 8);                          
	cout << '\xBA';
	cout << "\n  " << '\xC8';
	for (int i = 0; i < 75; i++)
	{
		cout << '\xCD';
	}
	cout << '\xBC';
}

// Displaying gameover screen
void Boundary :: gameOverScreen()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 8);                          
	cout << "\n  " << '\xC9';
	for (int i = 0; i < 75; i++)
	{
		cout << '\xCD';
	}
	cout << '\xBB' << "\n" << "  " << '\xBA';
	for (int i = 0; i<75; i++)
	{
		cout << " ";
	}
	cout << '\xBA';
	for (int j = 0; j < 19; j++)
	{
		cout << "\n" << "  " << '\xBA';
		for (int i = 0; i < 75; i++)
		{
			cout << " ";
		}
		cout << '\xBA';
	}
	cout << "\n" << "  " << '\xC8';
	for (int i = 0; i < 75; i++)
	{
		cout << '\xCD';
	}
	cout << '\xBC' << "\n  ";
	SetConsoleTextAttribute(hConsole, 480);           
	cout << "Press Any Key To Continue...";
}

// Displaying welcome screen
void Boundary :: welcomeScreen()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(hConsole, 10);             
	gotoxy(30, 5);
	cout << "	 M   O   N   T   Y ";
	SetConsoleTextAttribute(hConsole, 6);           
	gotoxy(30, 7);
	cout << " P   Y   T   H   O   N ";
	SetConsoleTextAttribute(hConsole, 2);            
	gotoxy(37, 9);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << "D";
	SetConsoleTextAttribute(hConsole, 268);             
	gotoxy(35, 13);
	cout << "1) P L A Y";
	SetConsoleTextAttribute(hConsole, 269);
	gotoxy(35, 15);
	cout << "2) S C O R E S";
	SetConsoleTextAttribute(hConsole, 270);
	gotoxy(35, 17);
	cout << "3) E X I T";
	gotoxy(3, 19);
	SetConsoleTextAttribute(hConsole, 7);             
	cout << "Press Any Number to Play: ";
}

// Dsplaying time
void Boundary :: showTime(int a)
{
	if (a < 10)
	{
		gotoxy(74, 21);
		cout << " ";
	}
	gotoxy(73, 21);
	cout << a;
}

// Hiding time
void Boundary :: hideTime()
{
	for (int a = 0; a < 3; a++)
	{
		gotoxy(a + 73, 21);
		cout << " ";
	}
}