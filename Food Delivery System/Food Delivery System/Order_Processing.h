#pragma once
#include "Order.h"
class Order_Processing
{
private:
	struct  Node
	{
		Order Data;
		Node* Next;
		Node(Order o);
	};
	Node* left,*right;
	int size;
public:
	Order_Processing();
	void Add_Order(Order o);
	void Remove_Order();
	void Remove_By_ID(int ID);
	Node *Top();
	~Order_Processing();
};

