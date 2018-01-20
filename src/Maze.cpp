// Aaron Baker
#include<iostream>
#include<cstdlib>
#include<stack>
#include<ctime>
#include <fstream>
#include "maze.h"
#include "Stack.h"
#include "List.h"

using namespace std;

int Not_Good = 0;
int CUR_ROW = 1, CUR_COL = 1;

int moveEW(int DIR, int x) {
	if (DIR == EAST)
		return x + 1;
	else if (DIR == WEST)
		return x - 1;
	else
		return x;
}

int moveNS(int DIR, int y) {
	if (DIR == NORTH)
		return y - 1;
	else if (DIR == SOUTH)
		return y + 1;
	else
		return y;
}

bool Is_Move(int x, int y, int DIR, char maze[COL_SIZE][ROW_SIZE]) {
	
	x = moveEW(DIR, x);
	y = moveNS(DIR, y);

	if (maze[y][x] == '.' || x >= (ROW_SIZE - 1) || x <= 0 || y <= 0 || y >= (COL_SIZE - 1)) {
		return false;
	}

	// Check which directions are available
	if (DIR == NORTH) {
		if (maze[y][x - 1] != '.' &&  maze[y - 1][x] != '.' && maze[y][x + 1] != '.' &&  maze[y - 1][x - 1] != '.' && maze[y - 1][x + 1] != '.') {
			return true;
		}
	}
	if (DIR == SOUTH) {
		if (maze[y][x - 1] != '.' &&  maze[y + 1][x] != '.' && maze[y][x + 1] != '.' && maze[y + 1][x - 1] != '.' && maze[y + 1][x + 1] != '.') {
			return true;
		}
	}
	if (DIR == EAST) {
		if (maze[y][x + 1] != '.' &&  maze[y - 1][x] != '.' && maze[y + 1][x] != '.' && maze[y - 1][x + 1] != '.' && maze[y + 1][x + 1] != '.') {
			return true;
		}
	}
	if (DIR == WEST) {
		if (maze[y][x - 1] != '.' &&  maze[y - 1][x] != '.' && maze[y + 1][x] != '.' && maze[y - 1][x - 1] != '.' && maze[y + 1][x - 1] != '.') {
			return true;
		}
	}
	return false;
}

bool isGoodSolve(int x, int y, int DIR, char maze[COL_SIZE][ROW_SIZE]) {
	
	x = moveEW(DIR, x);
	y = moveNS(DIR, y);

	if (maze[y][x] == '0' || x >= (ROW_SIZE - 1) || x <= 0 || y <= 0 || y >= (COL_SIZE - 1) || maze[y][x] == '#') {
		return false;
	}

	// Check which directions are available
	if (DIR == NORTH) {
		if (maze[y][x - 1] != '0' &&  maze[y - 1][x] != '0' && maze[y][x + 1] != '0' &&  maze[y - 1][x - 1] != '0' && maze[y - 1][x + 1] != '0') {
			return true;
		}
	}
	if (DIR == SOUTH) {
		if (maze[y][x - 1] != '0' &&  maze[y + 1][x] != '0' && maze[y][x + 1] != '0' && maze[y + 1][x - 1] != '0' && maze[y + 1][x + 1] != '0') {
			return true;
		}
	}
	if (DIR == EAST) {
		if (maze[y][x + 1] != '0' &&  maze[y - 1][x] != '0' && maze[y + 1][x] != '0' && maze[y - 1][x + 1] != '0' && maze[y + 1][x + 1] != '0') {
			return true;
		}
	}
	if (DIR == WEST) {
		if (maze[y][x - 1] != '0' &&  maze[y - 1][x] != '0' && maze[y + 1][x] != '0' && maze[y - 1][x - 1] != '0' && maze[y + 1][x - 1] != '0') {
			return true;
		}
	}
	return false;
}

Maze::~Maze()
{
	cout << "Finish" << endl;
}
void Maze::solveMaze()
{
	cout << "Solve maze called." << endl;
	List *someList;
	someList = new List();
	Not_Good = 0;
	int direction = 0;

	maze[1][1] = '0';

	Stack *someStack = new Stack(10000);

	std::stack<int> Row_Values;
	std::stack<int> Col_Values;
	
	do {
		
		//Find how many directons are available
		for (int i = 0; i < 4; i++) {
			if (isGoodSolve(CUR_ROW, CUR_COL, i, maze))
				Not_Good++;
		}

		// If there is only one direction to move then move there
		if (Not_Good == 1) {
			
			if (isGoodSolve(CUR_ROW, CUR_COL, NORTH, maze))
				CUR_COL = moveNS(NORTH, CUR_COL);
			else if (isGoodSolve(CUR_ROW, CUR_COL, SOUTH, maze))
				CUR_COL = moveNS(SOUTH, CUR_COL);
			else if (isGoodSolve(CUR_ROW, CUR_COL, EAST, maze))
				CUR_ROW = moveEW(EAST, CUR_ROW);
			else if (isGoodSolve(CUR_ROW, CUR_COL, WEST, maze))
				CUR_ROW = moveEW(WEST, CUR_ROW);
		}

		// If there is no where, move back in stack
		else if (Not_Good == 0) 
		{
			CUR_ROW = someStack->topX();
			CUR_COL = someStack->topY();
			someStack->pop();
		}

		//If there is more than one way to move,
		else if (Not_Good > 1)
		{
			someStack->push(CUR_ROW, CUR_COL);

			//Pick a random direction 
			do 
			{
				direction = rand() % 4;
			} while (!isGoodSolve(CUR_ROW, CUR_COL, direction, maze));

			CUR_ROW = moveEW(direction, CUR_ROW);
			CUR_COL = moveNS(direction, CUR_COL);
		}

		// set maze
		maze[CUR_COL][CUR_ROW] = '0';

		//Reset number of good moves
		Not_Good = 0;

		for (int i = 0; i < COL_SIZE; i++)
		{
			for (int j = 0; j < ROW_SIZE; j++) {
				cout << maze[i][j];
			}
			cout << endl;
		}
		cout << endl;

		system("CLS");

	} while (CUR_ROW!=18 || CUR_COL!=18);
}

void Maze::genMaze()
{
	this->maze[COL_SIZE][ROW_SIZE];

	for (int i = 0; i < COL_SIZE; i++) {
		for (int j = 0; j < ROW_SIZE; j++) {
			maze[i][j] = '#';
		}
	}

	//init random 
	srand((unsigned int)time(0));

	//Create stack for row and col coordinates
	std::stack<int> Row_Values;
	std::stack<int> Col_Values;

	Not_Good = 0;
	int direction = 0;
	
	do {
		//Find how many directons available
		for (int i = 0; i < 4; i++) {
			if (Is_Move(CUR_ROW, CUR_COL, i, maze))
				Not_Good++;
		}

		// If there is only one direction to move then move there
		if (Not_Good == 1) {
			if (Is_Move(CUR_ROW, CUR_COL, NORTH, maze))
				CUR_COL = moveNS(NORTH, CUR_COL);
			else if (Is_Move(CUR_ROW, CUR_COL, SOUTH, maze))
				CUR_COL = moveNS(SOUTH, CUR_COL);
			else if (Is_Move(CUR_ROW, CUR_COL, EAST, maze))
				CUR_ROW = moveEW(EAST, CUR_ROW);
			else if (Is_Move(CUR_ROW, CUR_COL, WEST, maze))
				CUR_ROW = moveEW(WEST, CUR_ROW);
		}

		// If there is no where, move back in stack
		else if (Not_Good == 0) {
			CUR_ROW = Row_Values.top();
			CUR_COL = Col_Values.top();
			Row_Values.pop();
			Col_Values.pop();
		}

		//If there is more than one way to move,
		else if (Not_Good > 1) {
			Row_Values.push(CUR_ROW);
			Col_Values.push(CUR_COL);

			//Pick a random direction 
			do {
				direction = rand() % 4;
			} while (!Is_Move(CUR_ROW, CUR_COL, direction, maze));

			CUR_ROW = moveEW(direction, CUR_ROW);
			CUR_COL = moveNS(direction, CUR_COL);
		}

		// set maze
		maze[CUR_COL][CUR_ROW] = '.';
		//output grid to show creation

		//Reset number of good moves
		Not_Good = 0;

	} while (!Row_Values.empty());

	if (maze[COL_SIZE - 1][ROW_SIZE - 1] = '#')
	{
		maze[COL_SIZE - 2][ROW_SIZE - 2] = '.';
	}
	if (maze[COL_SIZE - 2][ROW_SIZE - 3] = '#')
	{
		maze[COL_SIZE - 2][ROW_SIZE - 3] = '.';
	}
	if (maze[COL_SIZE - 3][ROW_SIZE - 2] = '#')
	{
		maze[COL_SIZE - 3][ROW_SIZE - 2] = '.';
	}
}

void Maze::printMaze()
{
	for (int i = 0; i < COL_SIZE; i++)
	{
		for (int j = 0; j < ROW_SIZE; j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
}

void Maze::saveMaze()
{
	ofstream output;
	char file[20];
	char input;

	cout << endl << "Save Maze? (Y)/(N): ";
	cin >> input;

	if ((input == 'y') || (input == 'Y')) {
		cout << endl << "Save as: ";
		cin >> file;

		output.open(file);

		for (int i = 0; i < COL_SIZE; i++) {
			output << endl;
			for (int j = 0; j < ROW_SIZE; j++) {
				output << " " << maze[i][j] << " ";
			}
			output << endl;
		}
		cout << "Maze has been saved to" << "/" << file << "/" << endl;
		output.close();
	}
}