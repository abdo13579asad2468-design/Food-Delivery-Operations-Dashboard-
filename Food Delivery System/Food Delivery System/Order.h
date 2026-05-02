#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
enum Status { PENDING, PROCESSING, DELIVERED };
class Order
{
private:
	string customer_name;
	Status status;
	float price;
	int ID;
public:
	Order();
	friend ostream& operator<<(ostream& os, const Order& od);
	void SetCustomer_Name(string cuistomer_name);
	void SetPrice(float price);
	void SetStatus(Status s);
	void SetID(int ID);
	int GetID()const;
	string GetCustomer_Name()const;
	string GetStatusString() const; 
	Status GetStatus() const;        
	float GetPrice()const;
	~Order();
};


