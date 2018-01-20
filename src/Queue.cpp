// Aaron Baker
#include "Queue.h"


Queue::Queue()
{

	head = NULL;
}

Queue::~Queue()
{
	ClearQueue();

}

void Queue::ClearQueue()
{
	Cell *temp;
	if (!isEmpty())
	{
		temp = head;

		// Scan list and free all nodes
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
}

bool Queue::isEmpty()
{
	return (head == NULL);
}



bool Queue::Enqueue(int x, int y)
{
	Cell *temp, *newNode;

	newNode = new Cell();

	if (newNode == NULL)
	{
		return false;
	}

	newNode->ROW = x;
	newNode->COL = y;
	newNode->VIT = 1;
	newNode->next = NULL;


	if (isEmpty())
	{
		head = newNode;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	return true;
}




Cell *Queue::Dequeue()
{
	Cell *temp;


	temp = head;
	
	head = head->next;
	delete(temp);

	return NULL;

}

void Queue::display()
{
	Cell *temp;
	cout << "\n\nItems in the Stack\n";
	cout << "-----------------------------------------------------------\n";
	cout << "X_coor\t\tY_coor\n";
	cout << "-----------------------------------------------------------\n";
	if (head == NULL)
	{
		cout << "List is empty";
	}
	else
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->ROW << "\t\t" << temp->COL << "\n";
			temp = temp->next;
		}

	}
	cout << "-----------------------------------------------------------\n\n";
}
