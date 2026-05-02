#include "Order.h"
constexpr char el = '\n';
Order::Order()
{
	ID = 0;
	customer_name = "unknown";
	price = 0;
	status = PENDING;
}
void Order::SetID(int ID)
{
	this->ID = ID;
}
void Order::SetCustomer_Name(string cuistomer_name)
{
	this->customer_name = cuistomer_name;
}
void Order::SetPrice(float price)
{
	this->price = price;
}
void Order::SetStatus(Status s)
{
	this->status = s;
}
int  Order::GetID()const
{
	return ID;
}
string Order::GetCustomer_Name()const
{
	return customer_name;
}
float Order::GetPrice()const
{
	return price;
}
Status Order::GetStatus()const
{
	return status;
}
string Order::GetStatusString() const
{
	if (status == PENDING)    return "Pending";
	if (status == PROCESSING) return "Processing";
	return "Delivered";
}
ostream& operator<<(ostream& os, const Order& od)
{
	int width = 16;
	os << "║ The Name   : " <<left<<setw(width)<< od.customer_name << "║\n";
	os << "║ The ID     : " <<left<<setw(width)<< od.ID << "║\n";
	os << "║ The Price  : " <<left<<fixed<< setprecision(2)<<setw(10)<< od.price << "EGP   ║\n";
	os << "║ The Status : " <<left<<setw(width)<< od.GetStatusString() << "║\n";
	return os;
}
Order::~Order()
{

}
