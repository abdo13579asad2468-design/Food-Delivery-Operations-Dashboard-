#include "Undo_Feature.h"
#include "Order.h"
Undo_Feature::Node::Node(Order o, ActionType a)
{
	Data = o;
	Action = a;
	Next = NULL;
}
Undo_Feature::Undo_Feature()
{
	top = NULL;
	size = 0;
}
void Undo_Feature::Push(Order o, ActionType a)
{
	Node* new_node = new Node(o,a);
	new_node->Next = top;
	top = new_node;
	size++;
}
void Undo_Feature::Pop()
{
	if (size == 0)return;
	Node* current = top;
	top = top->Next;
	delete current;
	size--;
}
ActionType Undo_Feature::TopAction()
{
	return top->Action;
}
Order* Undo_Feature::Top()
{
	if (top == NULL) return NULL;
	return &top->Data;
}
Undo_Feature::~Undo_Feature()
{
	Node* current = top;
	while (current != NULL)
	{
		Node* temp = current->Next;
		delete current;
		current = temp;
	}
}
