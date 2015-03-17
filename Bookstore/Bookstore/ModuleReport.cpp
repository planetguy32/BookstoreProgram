#include "ModuleReport.h"
#include "ModuleInventory.h"
#include <iostream>
#include <vector>

using namespace std;

ModuleReport::ModuleReport(ModuleInventory *inv)
{
	inventory = inv;
}

ModuleReport::~ModuleReport()
{
}

//*****************LIST ALL INVENTORY BOOKS*****************
void ModuleReport::listInv()
{

}

//*****************LIST WHOLESALE VALUES*****************
void ModuleReport::wholeValue()
{
	double sum = 0;

	for (int i = 0; i < inventory->books.size(); i++)
	{
		std::cout << inventory->books[i] << std::endl;
		sum += inventory->books[i];
	}

	std::cout << std::endl << "TOTAL WHOLESALE VALUE: " << sum << std::endl << std::endl;
}

//*****************LIST RETAIL VALUES*****************
void ModuleReport::retailValue()
{
	double sum = 0;

	for (int i = 0; i < inventory->books.size(); i++)
	{
		std::cout << inventory->books[i] << std::endl;
		sum += inventory->books[i];
	}

	std::cout << std::endl << "TOTAL RETAIL VALUE: " << sum << std::endl << std::endl;
}

//*****************SORT BY QUANTITY*****************
void ModuleReport::listByQty()
{
	{
		double temp;

		//SORT THE VECTOR
		for (int wall = 0; wall < inventory->books.size() - 1; wall++)
		{
			for (int i = wall + 1; i < inventory->books.size(); i++)
			{
				//SWAP
				if (inventory->books[i]->getQty() > inventory->books[wall]->getQty())
				{
					temp = inventory->books[i];
					inventory->books[i] = inventory->books[wall];
					inventory->books[wall] = temp;
				}
			}
		}
		//DISPLAY THE VECTOR
		for (int i = 0; i < inventory->books.size(); i++)
			std::cout << inventory->books[i] << endl;
		std::cout << std::endl;
	}
}

//*****************SORT BY WHOLESALE COST*****************
void ModuleReport::listByCost() 
{
	double temp;

	//SORT THE VECTOR
	for (int wall = 0; wall < inventory->books.size() - 1; wall++)
	{
		for (int i = wall + 1; i < inventory->books.size(); i++)
		{
			//SWAP
			if (inventory->books[i] > inventory->books[wall])
			{
				temp = inventory->books[i];
				inventory->books[i] = inventory->books[wall];
				inventory->books[wall] = temp;
			}
		}
	}
	//DISPLAY THE VECTOR
	for (int i = 0; i < inventory->books.size(); i++)
		std::cout << inventory->books[i] << endl;
	std::cout << std::endl;
}

//*****************SORT BY AGE*****************
void ModuleReport::listByAge()
{
	{
		double temp;

		//SORT THE VECTOR
		for (int wall = 0; wall < inventory->books.size() - 1; wall++)
		{
			for (int i = wall + 1; i < inventory->books.size(); i++)
			{
				if (inventory->books[i] > inventory->books[wall])
				{
					//SWAP
					temp = inventory->books[i];
					inventory->books[i] = inventory->books[wall];
					inventory->books[wall] = temp;
				}
			}
		}
		//DISPLAY THE VECTOR
		for (int i = 0; i < inventory->books.size(); i++)
			std::cout << inventory->books[i] << endl;
		std::cout << std::endl;
	}
}





bool ModuleReport::doInteraction() // main calls doInteraction which calls the ModuleReport functions
{
	int menuChoice;

	//REPORT MAIN MENU
	std::cout << "Hello, welcome to the report module." << std::endl
		<< "Choose your destiny:\n"
		<< "1. Inventory List\n2.Inventory Wholesale Value\n3.Inventory Retail Value\n4.List All Books by Quantity\n"
		<< "5.List All Books by Wholesale Cost\n6.List All Books by Age inInventory\n7.Exit\n"
		<< "ENTER CHOICE : ";
		std::cin >> menuChoice;

	switch (menuChoice)
	{
	case 1:
		break;
	case 2:
		wholeValue();
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		listByCost();
		break;
	case 6:
		break;
	case 7:
		cout << endl << "\"See you later.\"";
		return 1;
	}

	return false;
}