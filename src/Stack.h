//Aaron Baker
#include<stdio.h>
#include<conio.h>

#ifndef STACKHW_H
#define STACKHW_H
#include <iostream>
using namespace std;

struct S_Cell
{
	int ROW;
	int COL;
	int VIT;
	S_Cell* next;
};

class Stack
{
public:
	Stack(int max) : top(NULL), maxnum(max), count(0)
	{}
	
	void display();

	~Stack();

	void push(int x_coor, int y_coor);

	void pop();

	int topX() const;
	int topY() const;

private:
	S_Cell *top;
	int count; //head
	int maxnum;
	int stackInfo;
};

#endif












