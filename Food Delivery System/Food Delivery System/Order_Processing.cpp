#include "Order_Processing.h"
Order_Processing::Node::Node(Order o)
{
	Data = o;
	Next = NULL;
}
Order_Processing::Order_Processing()
{
	left = right = NULL;
	size = 0;
}
void Order_Processing::Add_Order(Order o)
{
	Node* new_node = new Node(o);
	if (size == 0)
	{
		left = right = new_node;
	}
	else
	{
		right->Next = new_node;
		right = new_node;
	}
	size++;
} 
Order_Processing::Node*Order_Processing::Top()
{
	return left;
}
void Order_Processing::Remove_Order()
{
	if (size == 0)return;
	Node* current = left;
	left = left->Next;
	delete current;
	size--;
}
void Order_Processing::Remove_By_ID(int ID)
{
	Node* current = left, * prev = NULL;
	while (current != NULL)
	{
		if (current->Data.GetID() == ID)
		{
			if (prev == NULL) left = current->Next;
			else prev->Next = current->Next;
			if (current == right) right = prev;
			delete current;
			size--;
			return;
		}
		prev = current;
		current = current->Next;
	}
}
Order_Processing::~Order_Processing()
{
	Node* current = left;
	while (current != NULL)
	{
		Node* temp = current->Next;
		delete current;
		current = temp;
	}
}
