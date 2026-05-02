#include "Main_Storage.h"
#include<iostream>
#include <iomanip>
#include<string>
using namespace std;
Main_Storage::Node::Node(Order o)
{
	Data = o;
	Next = NULL;
}
Main_Storage::Main_Storage()
{
	size = 0;
	left = right = NULL;
}
bool Main_Storage::Add_Order(Order o)
{
	if (Search_Order(o.GetID(), true) != NULL)
	{
		cout << "\n╔══════════════════════════════╗\n";
		cout << "║   Error: ID Already Exists!  ║\n";
		cout << "╚══════════════════════════════╝\n";
		return false;
	}
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
	isSorted = false;
	cout << "\n╔══════════════════════════════╗\n";
	cout << "║   The Order Has Been Added   ║\n";
	cout << "╚══════════════════════════════╝\n";
	return true;
}
bool Main_Storage::Sort_By_ID(bool silent)
{
	if (isSorted)return true;
	if (size == 1)
	{
		return true;
	}
	else if (size == 0)
	{
		if (!silent)
		{
			Print_Empty_Message();
		}
		return false;
	}
	Node* sorted = NULL;
	Node* current = left;
	while (current != NULL)
	{
		Node* next = current->Next;
		if (sorted == NULL || sorted->Data.GetID() >= current->Data.GetID())
		{
			current->Next = sorted;
			sorted = current;
		}
		else
		{
			Node* temp = sorted;
			while (temp->Next != NULL && temp->Next->Data.GetID() < current->Data.GetID())
				temp = temp->Next;
			current->Next = temp->Next;
			temp->Next = current;
		}
		current = next;
	}
	left = sorted;
	Node* temp = left;
	while (temp->Next != NULL) temp = temp->Next;
	right = temp;
	if (!silent)
	{
		cout << "\n╔══════════════════════════════╗\n";
		cout << "║  Orders Have Been Arranged ! ║\n";
		cout << "╚══════════════════════════════╝\n";
	}
	isSorted = true;
	return true;
}
void Main_Storage::Sort_By_Name()
{
	if (size == 1)return;
	else if (size == 0)
	{
		Print_Empty_Message();
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		Node* ptr1 = left, * ptr2 = ptr1->Next;
		for (int j = 0; j < size - i - 1; j++)
		{
			string str1 = ptr1->Data.GetCustomer_Name();
			string str2 = ptr2->Data.GetCustomer_Name();
			if (str1 > str2)
			{
				swap(ptr1->Data, ptr2->Data);
			}
			ptr1 = ptr2;
			ptr2 = ptr1->Next;
		}
	}
	cout << "\n╔══════════════════════════════╗\n";
	cout << "║  Orders Have Been Arranged ! ║\n";
	cout << "╚══════════════════════════════╝\n";
}
void Main_Storage::Sort_By_Price()
{
	if (size == 1)return;
	else if (size == 0)
	{
		Print_Empty_Message();
		return;
	}
	Node* ptr1 = left;
	for (int i = 0; i < size - 1; i++)
	{
		Node* ptr2 = ptr1->Next, * ptr3 = ptr1;
		float minIdx1 = ptr1->Data.GetPrice();
		for (int j = i + 1; j < size; j++)
		{
			float minIdx2 = ptr2->Data.GetPrice();
			if (minIdx1 > minIdx2)
			{
				minIdx1 = minIdx2;
				ptr3 = ptr2;
			}
			ptr2 = ptr2->Next;
		}
		swap(ptr1->Data, ptr3->Data);
		ptr1 = ptr1->Next;
	}
	cout << "\n╔══════════════════════════════╗\n";
	cout << "║  Orders Have Been Arranged ! ║\n";
	cout << "╚══════════════════════════════╝\n";
}
Main_Storage::Node* Main_Storage::getMiddle(int idx)
{
	Node* cur = left;
	for (int i = 0;i < idx && cur != NULL;i++)
	{
		cur = cur->Next;
	}
	return cur;
}
Order* Main_Storage::Search_Order(int ID, bool silent)
{
	if (!isSorted)
	{
		if (!Sort_By_ID(true))
		{
			Print_Empty_Message();
			return NULL;
		}
	}
	int low = 0, high = size - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		Node* midNode = getMiddle(mid);
		if (midNode->Data.GetID() == ID)
		{
			if (!silent)
			{
				cout << "\n╔══════════════════════════════╗" << endl;
				cout << "║         Order Found !        ║" << endl;
				cout << "╠══════════════════════════════╣" << endl;
				cout << midNode->Data;
				cout << "╚══════════════════════════════╝\n" << endl;
			}
			return &midNode->Data;
		}
		else if (midNode->Data.GetID() > ID)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	if (!silent)
	{
		cout << "\n╔════════════════════════╗" << endl;
		cout << "║    Order Not Found !   ║" << endl;
		cout << "╚════════════════════════╝\n" << endl;
	}
	return NULL;
}
void Main_Storage::Remove_Order(int ID)
{
	if (!isSorted)
	{
		if (!Sort_By_ID(true))
		{
			Print_Empty_Message();
			return;
		}
	}
	Order* found = Search_Order(ID, true);
	if (found == NULL)
	{
		cout << "\n╔════════════════════════╗\n";
		cout << "║    Order not found !   ║\n";
		cout << "╚════════════════════════╝\n";
		return;
	}
	Node* current = left, * prev = NULL;
	while (current != NULL)
	{
		if (current->Data.GetID() == ID)
		{
			if (prev == NULL)
			{
				left = current->Next;
				if (left == NULL)
				{
					right = NULL;
				}
			}
			else
			{
				prev->Next = current->Next;
				if (current == right)
				{
					right = prev;
				}
			}
			delete current;
			size--;
			cout << "\n╔═════════════════════════╗\n";
			cout << "║      Order removed !    ║\n";
			cout << "╚═════════════════════════╝\n";
			return;
		}
		prev = current;
		current = current->Next;
	}
}
void Main_Storage::Display()
{
	if (size == 0)
	{
		Print_Empty_Message();
		return;
	}
	Node* current = left;
	int idx = 1;
	cout << "\n=========== Orders List ===========" << endl;
	cout << "\n======= Total Orders : " << size << " =======" << endl;
	while (current != NULL)
	{
		int width = 13;
		cout << "\n╔══════════════════════════════╗\n";
		cout << "║       Order No. " << std::left << setw(width) << idx << "║\n";
		cout << "╠══════════════════════════════╣\n";
		cout << current->Data;
		cout << "╚══════════════════════════════╝\n";
		current = current->Next;
		idx++;
	}
}
void Main_Storage::Print_Empty_Message()
{
	cout << "\n=============================================\n";
	cout << "\n[!] SYSTEM ALERT : OPERATION FAILED ! \n";
	cout << "-----------------------------------------------" << endl;
	cout << ">> Status: Database is Empty." << endl;
	cout << ">> Reason: No orders found to process." << endl;
	cout << ">> Action: Please add at least one order first." << endl;
	cout << "===============================================" << endl;
}
void Main_Storage::Show_Statistics()
{
	if (size == 0)
	{
		Print_Empty_Message();
		return;
	}
	double total = 0, maxP = 0, minP = 1e9;
	long long pending = 0, processing = 0, delivered = 0;
	Node* cur = left;
	while (cur != NULL)
	{
		float p = cur->Data.GetPrice();
		total += p;
		if (p > maxP) maxP = p;
		if (p < minP) minP = p;
		if (cur->Data.GetStatus() == PENDING)    pending++;
		if (cur->Data.GetStatus() == PROCESSING) processing++;
		if (cur->Data.GetStatus() == DELIVERED)  delivered++;
		cur = cur->Next;
	}
	cout << fixed << setprecision(2);
	cout << "\n╔═══════════════════════════════════╗" << endl;
	cout << "║         ORDER STATISTICS          ║" << endl;
	cout << "╠═══════════════════════════════════╣" << endl;
	cout << "║ Total Orders  : " << std::left << setw(18) << size << "║" << endl;
	cout << "║ Total Revenue : " << std::left << setw(10) << total << "EGP     ║" << endl;
	cout << "║ Average Price : " << std::left << setw(10) << total / size << "EGP     ║" << endl;
	cout << "║ Highest Order : " << std::left << setw(10) << maxP << "EGP     ║" << endl;
	cout << "║ Lowest Order  : " << std::left << setw(10) << minP << "EGP     ║" << endl;
	cout << "╠═══════════════════════════════════╣" << endl;
	cout << "║ Pending       : " << std::left << setw(18) << pending << "║" << endl;
	cout << "║ Processing    : " << std::left << setw(18) << processing << "║" << endl;
	cout << "║ Delivered     : " << std::left << setw(18) << delivered << "║" << endl;
	cout << "╚═══════════════════════════════════╝" << endl;
}
void Main_Storage::Add_Order_Silent(Order o)
{
	isSorted = false;
	Node* new_node = new Node(o);
	if (size == 0)
		left = right = new_node;
	else
	{
		right->Next = new_node;
		right = new_node;
	}
	size++;
}
void Main_Storage::Save_To_File(const string& filename)
{
	ofstream file(filename);
	if (!file.is_open())
	{
		cout << "Error Opening File ! " << endl;
		return;
	}
	Node* current = left;
	while (current != NULL)
	{
		file << current->Data.GetID() << ","
			<< current->Data.GetCustomer_Name() << ","
			<< current->Data.GetPrice() << ","
			<< current->Data.GetStatusString() << "\n";
		current = current->Next;
	}
	file.close();
	cout << "Order Saved Successfully ! " << endl;
}
void Main_Storage::Load_From_File(const string& filename, Order_Processing& OP)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "No Saved Data Found ! \n";
		return;
	}
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string id_str, name, price_str, status_str, undo_str;
		getline(ss, id_str, ',');
		getline(ss, name, ',');
		getline(ss, price_str, ',');
		getline(ss, status_str, ',');
		getline(ss, undo_str, ',');
		if (!id_str.empty())
		{
			if (undo_str == "Undo_Add") continue;
			Order o;
			o.SetID(stoi(id_str));
			o.SetCustomer_Name(name);
			o.SetPrice(stof(price_str));
			if (status_str == "Processing")
			{
				o.SetStatus(PROCESSING);
				OP.Add_Order(o);
			}
			else if (status_str == "Delivered")
			{
				o.SetStatus(DELIVERED);
			}
			else
			{
				o.SetStatus(PENDING);
			}
			Add_Order_Silent(o);
		}
	}
	file.close();
	cout << "Orders Loaded Successfully !" << endl;
}
Main_Storage::~Main_Storage()
{
	Save_To_File("order.txt");
	Node* current = left;
	while (current != NULL)
	{
		Node* temp = current->Next;
		delete current;
		current = temp;
	}
}