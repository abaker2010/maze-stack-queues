// Aaron Baker
#pragma once

#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct Cell {

	int ROW;
	int COL;
	int VIT;
	Cell *next;

};

class List
{
public:
	List();
	~List();
	void ClearList();
	bool Insert(int x, int y);
	Cell *Delete(int x, int y);

	int ListLength();
	bool isEmpty();

	Cell* getHead();

	int top_ROW();
	int top_COL();
	
	void printList();

private:
	Cell *head;
};

#endif


