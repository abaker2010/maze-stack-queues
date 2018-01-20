// Aaron Baker
#include<stdio.h>
#include<conio.h>

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;


struct Cell {

	int ROW;
	int COL;
	int VIT;
	Cell *next;

};
class Queue
{
public:
	Queue();
	~Queue();
	void ClearQueue();
	Cell *Queue::Dequeue();
	bool Enqueue(int x, int y);



	void display();
	bool isEmpty();


private:
	Cell *head;
};

#endif












