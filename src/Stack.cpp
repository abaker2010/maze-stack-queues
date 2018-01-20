// Aaron Baker
#include "Stack.h"

Stack::~Stack()
{
	S_Cell* current = top;
	S_Cell *temp = new S_Cell;
	
	while (temp != NULL)
	{
		S_Cell* next = current->next;
		delete current;
		current = next;
	}
	top = NULL;
}

int Stack::topX() const
{
	return top->ROW;
}
int Stack::topY() const
{
	return top->COL;
}

void Stack::push(int x, int y)
{
	if (count == maxnum)
		cout << "stack is full";
	else
	{
		S_Cell *newTop = new S_Cell;
		if (top == NULL)
		{
			newTop->ROW = x;
			newTop->COL = y;
			newTop->next = NULL;
			top = newTop;
			count++;
		}
		else
		{
			newTop->ROW = x;
			newTop->COL = y;
			newTop->next = top;
			top = newTop;
			count++;
		}
	}
}

void Stack::pop()
{
	if (top == NULL)
		cout << "nothing to pop";
	else
	{
		S_Cell * old = top;
		top = top->next;
		count--;
		delete(old);
	}
}

void Stack::display()
{
	S_Cell *temp;
	cout << "\n\nItems in the Stack\n";
	cout << "-----------------------------------------------------------\n";
	cout << "X_coor\t\tY_coor\n";
	cout << "-----------------------------------------------------------\n";
	if (top == NULL)
	{
		cout << "List is empty";
	}
	else
	{
		temp = top;
		while (temp != NULL)
		{
			cout << temp->ROW << "\t\t" << temp->COL << "\n";
			temp = temp->next;
		}
	}
	cout << "-----------------------------------------------------------\n\n";
}