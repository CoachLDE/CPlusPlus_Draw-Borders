/************************************************************************************************
	Name: CoachLDE
	Date: 10.20.2023
	Purpose: In this program I will create a function that will draw a border to make a game 
			 playing field.  We will use GoToXY function to place the cursor where needed and then
			 use a for loop to draw the walls and we will use the windowSize function to adjust
			 the size of the console window to make sure the game playing field that will be 
			 surrounded by the border fits
*************************************************************************************************/

#include <iostream>
#include <Windows.h>	//In this library is the function that will allow is to control cursor position
//#include <conio.h>		//In this library is a function to detect keypresses

using namespace std;

void windowSize(int x, int y)
{
	HWND console = GetConsoleWindow();		//Get the Console Window and put it in a variable of the Window Handle type
	RECT ConsoleRect;						//Rect Structure defines a Rectangle (The Window)
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);
}

void GoToXY(int x, int y)
{
	HANDLE hCon;		//Console Handle
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);		//Get the ID of the console window

	COORD coord;								//Variable of type COORD that holds the X and Y position
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hCon, coord);
}

void drawBorders()
{
	//Border Dimensions (Playing Field Size)
	int width = 65;
	int height = 41;

	char tAndB = 205;
	char lAndR = 186;
	char topLeft = 201;
	char botLeft = 200;
	char topRight = 187;
	char botRight = 188;

	//Top & Bottom Borders
	for (int i = 2; i < width - 3; i++)
	{
		GoToXY(i, 3);
		cout << tAndB;

		GoToXY(i, height - 2);
		cout << tAndB;
	}

	//Left & Right Borders
	for (int j = 4; j < height - 2; j++)
	{
		GoToXY(2, j);
		cout << lAndR;

		GoToXY(61, j);
		cout << lAndR;
	}

	//Corners
	//Top Left
	GoToXY(2, 3);
	cout << topLeft;

	//Bottom Left
	GoToXY(2, height - 2);
	cout << botLeft;

	//Top Right
	GoToXY(61, 3);
	cout << topRight;

	//Bottom Right
	GoToXY(61, height - 2);
	cout << botRight;
}

int main()
{
	windowSize(500, 700);
	drawBorders();

	while (true)
	{
		
		
	}

	return 0;
}