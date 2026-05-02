#pragma once
#include "Order.h"
#include"Order_Processing.h"
#include"Undo_Feature.h"
#include<iostream>
#include <fstream>
#include <sstream>
class Main_Storage
{
private:
	bool isSorted = false;
	struct Node
	{
		Order Data;
		Node* Next;
		Node(Order O);
	};
	Node* getMiddle(int idx);
	Node* left, *right;
	int size;
public:
	Main_Storage();
	Order* Search_Order(int ID,bool silent = false);
	bool Sort_By_ID(bool silent=false);
	void Print_Empty_Message();
	void Remove_Order(int ID);
	void Add_Order_Silent(Order o);
	bool Add_Order(Order od);
	void Show_Statistics();
	void Sort_By_Price();
	void Sort_By_Name();
	void Display();
	void Save_To_File(const string& filename);
	void Load_From_File(const string& filename,Order_Processing &OP);
	~Main_Storage();
};

