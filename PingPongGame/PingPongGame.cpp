#include "stdafx.h"
#include<iostream>
#include<conio.h>

using namespace std;

bool quit = false, restart = false, Gameover = false;
int Height = 25, Width = 30;
int Virpos, Horpos;
int flag = 10;
int newXA = (Width / 2) - 2, newXB = (Width / 2) - 2; // btw 1 to 18(new 20)
int Ballx = (Width / 2) - 2, Bally = Height / 2;
enum enumdir { LEFT = 0, RIGHT }; enum Balldirenum { BUP = 0, BDOWN, BLEFTUP, BRIGHTUP, BLEFTDOWN, BRIGHTDOWN };
int Balldir = 100;
int dir = 100; int temp; int t1, t2;

void Draw()
{
	for (int i = 1; i <= Width; i++)
	{
		cout << "#";
	}
	cout << "\n";
	/*********************************/

	for (int Virpos = 1; Virpos <= Height; Virpos++)
	{
		cout << "#";
		//postion checking for ===
		for (int Horpos = 1; Horpos <= Width - 2; Horpos++)
		{
			if (flag<5)
			{
				flag++;
				continue;
			}
			if ((Virpos == 1 && Horpos == newXA) || (Virpos == Height && Horpos == newXB))
			{
				cout << "===";
				flag = 3;
				continue;
			}
			//postion cheking for Ball
			if (Virpos == Bally && Horpos == Ballx)
			{
				cout << "0";
			}
			else
			{
				cout << " ";
			}
		}

		cout << "#\n";
	}
	/*******************************/
	for (int i = 0; i<Width; i++)
	{
		cout << "#";
	}
	cout << "\n";

}

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			quit = true;
			break;
		case 'r':
			restart = true;
		defualt:
			break;
		}
	}
}

void Controls()
{
	switch (dir)
	{
	case LEFT:
		if (newXB > 1)
			newXB--;
		break;
	case RIGHT:
		if (newXB < Width - 4)
			newXB++;
		break;
	default:
		break;
	}
}

void GameOver()
{
	quit = true;
	system("cls");
	printf("%s", "Game Over");
	getchar();
}

void Ballpos()
{
	if (Bally == Height)
	{
		Balldir = BUP;
	}
	if (Bally == 1)
	{
		Balldir = BDOWN;
	}
	//Collision Controls
	//x=left right and y=up down
	//Collison with Players
	t1 = newXB + 1, t2 = newXB + 2;
	if ((Ballx == newXB || Ballx + 1 == t1 || Ballx == t2) && Bally == Height)
	{
		temp = dir;
		if (temp = RIGHT)
			Balldir = BRIGHTUP;
	}
	if ((Ballx == newXB || Ballx + 1 == t1 || Ballx == t2) == newXB && Bally == Height)
	{
		temp = dir;
		if (temp = LEFT)
			Balldir = BLEFTUP;
	}
	//Right wall collison with ball
	if (Ballx == Width)
	{
		temp = Balldir;
		if (temp == BRIGHTUP)
		{
			Balldir = BLEFTUP;
		}
		else if (temp == BRIGHTDOWN)
		{
			Balldir = BLEFTDOWN;
		}
	}
	//Left wall collison with ball
	if (Ballx == 1)
	{
		temp = Balldir;
		if (temp = BLEFTUP)
		{
			Balldir = BRIGHTUP;
		}
		else if (temp = BLEFTDOWN)
		{
			Balldir = BRIGHTDOWN;
		}
	}
}

void BallMove()
{
	switch (Balldir)
	{
	case BUP:
		Bally--;
		break;
	case BDOWN:
		Bally++;
		break;
	case BLEFTUP:
		Bally--;
		Ballx--;
		break;
	case BRIGHTUP:
		Bally--;
		Ballx++;
		break;
	case BLEFTDOWN:
		Bally++;
		Ballx--;
		break;
	case BRIGHTDOWN:
		Bally++;
		Ballx++;
		break;
	default:
		Bally++;
		break;
	}
}

int  main()
{
	system("cls");
	cout << "PingPong\n";
	cout << "\n";
	cout << "Start Game: s\n";
	cout << "End Game: e \n";
	cout << "Restart meanwhile playing: r\n";

	switch (_getch())
	{
	case 's':
		break;
	case 'e':
		quit = true;
		break;
	}
	//loop
	while (!quit)
	{
		Draw();
		Ballpos();
		BallMove();
		system("cls");
		input();
		Controls();
	}
	/*system("cls");
	printf("%s","Game Over");
	getchar();*/

	return 0;
}


