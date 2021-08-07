#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<ctime>
#include"global.h"
#include"SnakeHead.h"
#include"Boundary.h"
#include"SFood.h"
#include"BFood.h"
#include"Snake.h"
#include"highScore.h"
#include"highScoreTable.h"
#include "stdafx.h"

using namespace std;

int main()
{
	// Initiating class variables/objects for scoring
	highScore tempScore;
	highScoreTable myTable;
	char choice;
	// Filestream for keeping track of old scores
	ifstream inScorefile("HighScore.txt");
	inScorefile.read((char*)&myTable, sizeof(myTable));
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Boundary b;
	b.welcomeScreen();
	choice = _getch();
	do {
		// Initiating class variables/objects for snake & food & game control variables
		Snake s;
		SFood sfood;
		BFood bfood;
		bool hit, available, esc;
		int count, temp;
		// Option 1 : Start of Game
		if (choice == '1')
		{
			hit = 0, available = 0, esc = 0;
			count = 0, temp = 50;
			system("cls");
			// Setting boundaries, game screen
			b.setLeftBoundary();
			b.setRightBoundary();
			b.setDownBoundary();
			b.setUpBoundary();
			b.gameBoundary();
			SetConsoleTextAttribute(hConsole, 10);
			s.show();
			s.printScore(14, 21);
			SetConsoleTextAttribute(hConsole, 13);
			sfood.generateFood();
			_getch();
			// Catching key press
			while (true)
			{
				switch (s.Direction)
				{
				case Down:
					s.down();
					break;
				case Left:
					s.left();
					break;
				case Right:
					s.right();
					break;
				case Up:
					s.up();
					break;
				}
				SetConsoleTextAttribute(hConsole, 10);
				s.show();
				Sleep(100);
				{
				// Moving the snake in the direction as of pressed key
					if (_kbhit())
					{
						do_key = _getch();
						if (do_key == Up || do_key == Right || do_key == Down || do_key == Left)
						{
							temp_key = do_key;
						}
					}
					if (temp_key == Left && s.Direction == Down)
					{
						s.Direction = Left;
					}
					if (temp_key == Right && s.Direction == Down) {
						s.Direction = Right;
					}
					if (temp_key == Down && s.Direction == Left)
					{
						s.Direction = Down;
					}
					if (temp_key == Up && s.Direction == Left)
					{
						s.Direction = Up;
					}
					if (temp_key == Left && s.Direction == Up)
					{
						s.Direction = Left;
					}
					if (temp_key == Right && s.Direction == Up)
					{
						s.Direction = Right;
					}
					if (temp_key == Up && s.Direction == Right)
					{
						s.Direction = Up;
					}
					if (temp_key == Down && s.Direction == Right)
					{
						s.Direction = Down;
					}
				}
				// Collision Detection for boundaries
				for (int i = 0; i < b.y_distance; i++)
				{
					if (s.snake[0] == b.up_boundary[i])
					{
						hit = 1;
						break;
					}
				}
				if (hit == 1)
				{
					break;
				}
				for (int i = 0; i < b.x_distance; i++)
				{
					if (s.snake[0] == b.right_boundary[i])
					{
						hit = 1;
						break;
					}
				}
				if (hit == 1)
				{
					break;
				}
				for (int i = 0; i < b.y_distance; i++)
				{
					if (s.snake[0] == b.down_boundary[i])
					{
						hit = 1;
						break;
					}
				}
				if (hit == 1)
				{
					break;
				}
				for (int i = 0; i < b.x_distance; i++)
				{
					if (s.snake[0] == b.left_boundary[i])
					{
						hit = 1;
						break;
					}
				}
				// Collision Detection for snake itself
				for (int i = 1; i < s.Length; i++)
				{
					if (s.snake[0] == s.snake[i])
					{
						hit = 1;
						break;
					}
				}
				if (hit == 1)
				{
					break;
				}
				// Detection of food consumption
				if (s.snake[0] == sfood.s_food)
				{
					s++;
					// Winning Condition (score approx. ~ 665,max or less)
					if (s.Length == 99)
					{
						esc = 1;
						break;
					}
					SetConsoleTextAttribute(hConsole, 13);
					sfood.generateFood();
					SetConsoleTextAttribute(hConsole, 268);
					s.printScore(14, 21);
					count++;
					// Condition for bonus food
					if (count == 5)
					{
						bfood.generateBigFood(); available = 1; count = 0;
					}
				}
				// Bonus food timer
				if (available == 1)
				{
					SetConsoleTextAttribute(hConsole, 268);
					b.showTime(temp);
					temp--;
					if (temp == 0)
					{
						bfood.hide();
						b.hideTime();
						available = 0;
						temp = 50;
					}
				}
				// Detection of bonus food consumption
				if (s.snake[0] == bfood.b_food)
				{

					s.Score += 10;
					s.printScore(14, 21);
					b.hideTime();
					available = 0;
					temp = 50;
				}
				// Condition for checking if food is generated on snake body itself
				for (int j = 1; j < s.Length; j++)
				{
					if (sfood.s_food == s.snake[j]) 
					{ 
						sfood.generateFood(); 
					}
				}
			}
			// Game over message/screen
			if (hit == 1)
			{
				Sleep(1200);
				system("cls");
				b.gameOverScreen();
				gotoxy(35, 12);
				SetConsoleTextAttribute(hConsole, 12);
				cout << "Game Over!";
				gotoxy(33, 13);
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Your Score:  " << s.Score;
				SetConsoleTextAttribute(hConsole, 3);
				gotoxy(33, 15);
				tempScore.getData();
				tempScore.score = s.Score;
				myTable.hs[myTable.countScore] = tempScore;
				myTable++;
				for (int i = 0; i < 100; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						swapScore(myTable.hs[i], myTable.hs[j]);
					}
				}
				ofstream scorefile("HighScore.txt", ios::binary);
				if (!scorefile.good()) {
					cout << "File could not be opened";
				}
				scorefile.write((char*)&myTable, sizeof(highScoreTable));
				scorefile.close();
				gotoxy(30, 23);
				Sleep(500);
				_getch();
			}
			// Winning message/screen
			else if (esc == 1)
			{
				esc = 0;
				Sleep(800);
				system("cls");
				b.gameOverScreen();
				gotoxy(31, 9);
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Congratulations!";
				gotoxy(20, 11);
				SetConsoleTextAttribute(hConsole, 13);
				cout << "You Reached to Maximum Length of Snake!";
				gotoxy(33, 13);
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Your Score:  " << s.Score;
				highScore tempScore;
				HANDLE hConsole;
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 3);
				gotoxy(31, 15);
				tempScore.getData();
				tempScore.score = s.Score;
				myTable.hs[myTable.countScore] = tempScore;
				myTable.countScore++;
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						swapScore(myTable.hs[i], myTable.hs[j]);
					}
				}
				ofstream scorefile("HighScore.txt", ios::binary);
				if (!scorefile.good())
				{
					cout << "File could not be opened";
				}
				scorefile.write((char*)&myTable, sizeof(myTable));
				scorefile.close();
				gotoxy(30, 23);
				Sleep(500);
			}
			system("cls");
		}
		// Option 2 : Score sheet
		else if (choice == '2')
		{
			highScore tempScore2;
			if (tempScore.score >= 0) 
			{
				tempScore2.score = tempScore.score;
			}
			inScorefile.read((char*)&myTable, sizeof(myTable));
			system("cls");
			myTable.printTableShape();
			for (int i = 0; i < 15; i++) {
				myTable.hs[i].printData(i);
			}
			gotoxy(44, 24);
			cout << tempScore2.score;
			gotoxy(1, 26);
			cout << "Press Any Key to Continue...";
			_getch();
		}
		// option 3 : Exit game
		else if (choice == '3')
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, 268);
			gotoxy(41, 2);
			cout << "Thankyou for playing...!!! \n\n\n";
			SetConsoleTextAttribute(hConsole, 270);
			gotoxy(25, 4);
			cout << "Made by: Aliasghar (19K-0293) & Abdul Wasee (19K-1357) \n\n\n\n";
			_getch();
			exit(1);
		}
		b.welcomeScreen();
		choice = _getch();
	} while (choice != '3');
}
