// Aaron Baker
#include "List.h"

List::List()
{
	head = NULL;
}

List::~List()
{
	ClearList();
}

Cell* List::getHead()
{
	return head;
}

void List::ClearList()
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

int List::top_ROW()
{
	Cell *temp, *back;

	int Row;
	temp = head;
	back = NULL;

	while ((temp->next) != NULL)
	{
		back = temp;
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		back->next = temp->next;
		Row = temp->ROW;
			return Row;
	}
	return 0;
}

int List::top_COL()
{
	Cell *temp, *back;

	int Col;
	temp = head;
	back = NULL;

	while ((temp->next) != NULL)
	{
		back = temp;
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		back->next = temp->next;
		Col = temp->ROW;
		return Col;
	}
	return 0;
}

bool List::Insert(int row, int col)
{
	Cell *temp, *newNode;

	newNode = new Cell();

	if (newNode == NULL)
	{
		return false;
	}

	newNode->ROW = row;
	newNode->COL = col;
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

Cell *List::Delete(int row, int col)
{
	Cell *temp, *back;
	if (isEmpty()) return NULL;

	temp = head;
	back = NULL;
	//Combs through linked list looking for value to delete
	while ((temp != NULL) && (row != temp->ROW) && (col != temp->COL))
	{
		back = temp;
		temp = temp->next;
	}
	
	//Checks if item was found
	if (temp == NULL) return NULL; //Return false, not found
	
	else if (back == NULL)         //Checks if cell is first in list
	{
		head = head->next;
		temp = temp->next;
	}
	else
	{
		back->next = temp->next;
		return temp;
	}
	return NULL;
}

int List::ListLength()
{
	Cell *temp;
	int count = 0;

	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

bool List::isEmpty()
{
	return (head == NULL);
}

void List::printList()
{
	Cell *temp;
	cout << "\n\nItems in the List\n";
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