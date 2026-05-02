#include <iostream> 
#include"Order.h"
#include"Main_Storage.h"
#include"Order_Processing.h"
#include "Undo_Feature.h"
using namespace std;
constexpr char el = '\n';
void Safe_Int_Input(int& value)
{
	while (!(cin >> value))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n Invalid Input ! Enter a Number : ";
	}
}
void Safe_Float_Input(float& value)
{
	while (!(cin >> value))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nInvalid Input! Enter a Number : ";
	}
}
void Check_Choice(int& choice)
{
	int Attempt = 2;
	while (choice <= 0 || choice > 12)
	{

		cout << "Invalid Choice ! Re-Enter Your Choice  " << el << el;
		cout << "You Only Have " << Attempt << " Attempt Left ! " << el;
		cout << "****************************************" << el;
		cout << "\nEnter The Choice : ";
		Attempt--;
		Safe_Int_Input(choice);
		if (Attempt <= 0 && (choice <= 0 || choice > 12))
		{
			cout << "\n╔══════════════════════════════╗\n";
			cout << "║    Your Attempt Are Over !   ║\n";
			cout << "╚══════════════════════════════╝\n";
			throw runtime_error("Attempts Over");
		}
	}
}
void Check_ID(int& ID)
{
	int Attempt = 2;
	string str_ID = to_string(ID);
	while (str_ID.size() != 5)
	{
		cout << el << "****************************************" << el;
		cout << "Invalid ID ! Re-Enter The ID : " << el << el;
		cout << "You Only Have " << Attempt << " Attempt Left ! " << el;
		cout << "****************************************" << el << el;

		cout << "Enter The ID : ";
		Attempt--;
		Safe_Int_Input(ID);
		str_ID = to_string(ID);
		if (Attempt <= 0 && str_ID.size() != 5)
		{
			cout << "\n╔══════════════════════════════╗\n";
			cout << "║    Your Attempt Are Over !   ║\n";
			cout << "╚══════════════════════════════╝\n";
			throw runtime_error("Attempts Over");

		}
	}
}
void Check_Price(float& price)
{
	int Attempt = 2;
	while (price <= 0)
	{
		cout << el << "****************************************" << el;
		cout << "Invalid Price ! Re-Enter The Price : " << el;
		cout << "You Only Have " << Attempt << " Attempt Left ! " << el << el;
		cout << "****************************************" << el << el;
		cout << "Enter The Price : ";
		Attempt--;
		Safe_Float_Input(price);
		if (Attempt <= 0 && price <= 0)
		{
			cout << "\n╔══════════════════════════════╗\n";
			cout << "║    Your Attempt Are Over !   ║\n";
			cout << "╚══════════════════════════════╝\n";
			throw runtime_error("Attempts Over");

		}
	}
}
void ShowExitMessage()
{
	cout << "\n====================================================" << endl;
	cout << "||                                                ||" << endl;
	cout << "||      SYSTEM SHUTDOWN COMPLETED SUCCESSFULLY    ||" << endl;
	cout << "||          -- Thank you for using our Hub --     ||" << endl;
	cout << "||                                                ||" << endl;
	cout << "====================================================" << endl;
	cout << ">> Saving session data and logs... [Done]" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Have a great day, Administrator! Goodbye." << endl;
	cout << "====================================================" << endl;
}
void displayWelcome()
{
	cout << "====================================================" << el;
	cout << "||                                                ||" << endl;
	cout << "||       FOOD DELIVERY OPERATIONS DASHBOARD       ||" << el;
	cout << "||         -- Internal Management v1.0 --         ||" << el;
	cout << "||                                                ||" << endl;
	cout << "====================================================" << el;
	cout << "====================================================" << el;
	cout << "||      Administrator Access Granted... [OK]      ||" << el;
	cout << "----------------------------------------------------" << el;
	cout << "||         Logged in as: System Dispatcher        ||" << endl;
	cout << "|| Ready to process, sort, and manage daily orders||" << endl;
	cout << "====================================================" << endl;
}
void displaymenu(Main_Storage& MS, Undo_Feature& UF, Order_Processing& OP)
{
	cout << el;
	cout << "==========================================================" << el;
	cout << "||System ready..Choose the task to execute from (1 - 12)||" << el;
	cout << "==========================================================" << el;
	cout << "|| 1. Add Order..........||" << el;
	cout << "|| 2. Remove Order.......||" << el;
	cout << "|| 3. Display Orders.....||" << el;
	cout << "|| 4. Sort By Price......||" << el;
	cout << "|| 5. Sort By Name.......||" << el;
	cout << "|| 6. Sort By ID.........||" << el;
	cout << "|| 7. Search Order.......||" << el;
	cout << "|| 8. Add To Queue.......||" << el;
	cout << "|| 9. Process Order......||" << el;
	cout << "|| 10. Undo Last Action..||" << el;
	cout << "|| 11. Show Statistics...||" << el;
	cout << "|| 12. Exit..............||" << el;
	cout << "==========================================================" << el;
	int choice;
	cout << "\nEnter The Choice : ";
	Safe_Int_Input(choice);
	cout << el;
	Check_Choice(choice);
	switch (choice)
	{
	case 1:
	{
		Order OD;
		cout << "=== Enter Customer Data ===\n\n";
		string Customer_Name;
		float Price;
		int ID;
		cin.ignore();
		cout << "Enter Customer Name : ";
		getline(cin, Customer_Name);
		cout << "Enter a 5-Digit ID : ";
		Safe_Int_Input(ID);
		Check_ID(ID);
		cout << "Enter The Price : ";
		Safe_Float_Input(Price);
		Check_Price(Price);
		OD.SetCustomer_Name(Customer_Name);
		OD.SetID(ID);
		OD.SetPrice(Price);
		if (MS.Add_Order(OD))
		{
			UF.Push(OD, ADD);
		}
		break;
	}
	case 2:
	{
		int ID;
		cout << "Enter a 5-Digit ID : ";
		Safe_Int_Input(ID);
		Check_ID(ID);
		Order* found = MS.Search_Order(ID);
		if (found != NULL)
		{
			UF.Push(*found, REMOVE);
			MS.Remove_Order(ID);
		}
		break;
	}
	case 3:
	{
		MS.Display();
		break;
	}
	case 4:
	{
		MS.Sort_By_Price();
		break;
	}
	case 5:
	{
		MS.Sort_By_Name();
		break;
	}
	case 6:
	{
		MS.Sort_By_ID();
		break;
	}
	case 7:
	{
		int ID;
		cout << "Enter a 5-Digit ID : ";
		Safe_Int_Input(ID);
		Check_ID(ID);
		MS.Search_Order(ID);
		break;
	}
	case 8:
	{
		int ID;
		cout << "Enter a 5-Digit ID : ";
		Safe_Int_Input(ID);
		Check_ID(ID);
		Order* found = MS.Search_Order(ID);
		if (found == NULL)
		{
			break;
		}
		if (found->GetStatus() == DELIVERED)
		{
			cout << "\n╔══════════════════════════════╗\n";
			cout << "║  Order Already Delivered!    ║\n";
			cout << "╚══════════════════════════════╝\n";
			break;
		}
		if (found->GetStatus() == PROCESSING)
		{
			cout << "\n╔══════════════════════════════╗\n";
			cout << "║  Order Already In Queue  !   ║\n";
			cout << "╚══════════════════════════════╝\n";
			break;
		}
		found->SetStatus(PROCESSING);
		OP.Add_Order(*found);
		cout << "\n╔══════════════════════════════╗\n";
		cout << "║    Order Added To Queue !    ║\n";
		cout << "╠══════════════════════════════╣\n";
		cout << *found;
		cout << "╚══════════════════════════════╝\n";
		break;
	}
	case 9:
	{
		if (OP.Top() == NULL)
		{
			cout << "\n╔══════════════════════════════╗\n";
			cout << "║      Queue Is Empty !        ║\n";
			cout << "╚══════════════════════════════╝\n";
			break;
		}
		cout << "\n╔══════════════════════════════╗\n";
		cout << "║   Processing Next Order...   ║\n";
		cout << "╠══════════════════════════════╣\n";
		cout << OP.Top()->Data;
		cout << "╚══════════════════════════════╝\n";


		Order* inStorage = MS.Search_Order(OP.Top()->Data.GetID(), true);
		if (inStorage != NULL)
			inStorage->SetStatus(DELIVERED);

		OP.Remove_Order();

		cout << "\n╔════════════════════════════════════════════╗\n";
		cout << "║   Order Has Been Processed Successfully !  ║\n";
		cout << "╚════════════════════════════════════════════╝\n";
		break;
	}
	case 10:
	{
		Order* last = UF.Top();
		if (last != NULL)
		{
			cout << "\n╔══════════════════════════════╗\n";
			cout << "║     Undoing Last Action      ║" << el;
			cout << "╠══════════════════════════════╣\n";
			cout << *last;
			cout << "╚══════════════════════════════╝\n";
			if (UF.TopAction() == ADD)
			{
				MS.Remove_Order(last->GetID());
				OP.Remove_By_ID(last->GetID());
				cout << "\n╔════════════════════════════════╗\n";
				cout << "║  Undo:Order Addition Canceled  ║\n";
				cout << "╚════════════════════════════════╝\n";
			}
			else
			{
				MS.Add_Order(*last);
				cout << "\n╔═════════════════════════════════╗\n";
				cout << "║  Undo: Order Has been Restored  ║" << el;
				cout << "╚═════════════════════════════════╝\n";
			}
			UF.Pop();
		}
		else
		{
			cout << "\n╔══════════════════════╗\n";
			cout << "║   Nothing To Undo !  ║\n";
			cout << "╚══════════════════════╝\n";
		}
		break;
	}
	case 11:
	{
		MS.Show_Statistics();
		break;
	}
	case 12:
	{
		ShowExitMessage();
		throw runtime_error("Attempts Over");
		break;
	}
	}
}
int main()
{
	system("chcp 65001");
	Main_Storage MS;
	Undo_Feature UF;
	Order_Processing OP;
	MS.Load_From_File("order.txt", OP);
	char userResponse;
	displayWelcome();
	try
	{
		do
		{
			displaymenu(MS, UF, OP);
			cout << "\n------------------------------------------" << endl;
			cout << ">> Operation completed successfully." << endl;
			cout << ">> Do you want to perform another task? (y/n): ";
			cin >> userResponse;
		} while (userResponse == 'y' || userResponse == 'Y');
	}
	catch (runtime_error& e)
	{
		return 0;
	}

}