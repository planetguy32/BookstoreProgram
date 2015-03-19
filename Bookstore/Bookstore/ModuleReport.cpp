#include "ModuleReport.h"
#include "ModuleInventory.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

ModuleReport::ModuleReport(ModuleInventory *inv)
{
	inventory = inv;
}

ModuleReport::~ModuleReport()
{
}

template<class T>
void ModuleReport::accumulate(T (Book::* f)())
{
	T sum = 0;

	for (int i = 0; i < inventory->books.size(); i++)
	{
		T subtotal = (inventory->books[i]->*f)();
		std::cout << *(inventory->books[i]) << "  " << subtotal << std::endl;
		sum += subtotal;
	}

	std::cout << std::endl << "TOTAL WHOLESALE VALUE: " << sum << std::endl << std::endl;
}

template<class T>
void ModuleReport::listBy(T(Book::* f)())
{
	sortBy(f);
	dumpBookList();
}

template<class T>
void ModuleReport::sortBy(T(Book::* f)())
{
	for (int wall = 0; wall < inventory->books.size() - 1; wall++)
	{
		for (int i = wall + 1; i < inventory->books.size(); i++)
		{
			if ((inventory->books[i]->*f)() > (inventory->books[wall]->*f)())
			{
				Book * temp = inventory->books[i];
				inventory->books[i] = inventory->books[wall];
				inventory->books[wall] = temp;
			}
		}
	}
}

template<class T>
void ModuleReport::dumpBookList(T(Book::* f)())
{
	for (int i = 0; i < inventory->books.size(); i++)
		std::cout << *inventory->books[i] << "   " << (inventory->books[i]->*f)() << endl;
	std::cout << std::endl;
}

void ModuleReport::dumpBookList()
{
	for (int i = 0; i < inventory->books.size(); i++)
		std::cout << *inventory->books[i] << endl;
	std::cout << std::endl;
}

bool ModuleReport::doInteraction() // main calls doInteraction which calls the ModuleReport functions
{
	int menuChoice;
	std::cout << "===Inventory Module===" << std::endl;
	//REPORT MAIN MENU
	std::cout << "Hello, welcome to the report module." << std::endl
		<< "Choose your destiny:\n"
		<< "1. Inventory List\n2.Inventory Wholesale Value\n3.Inventory Retail Value\n4.List All Books by Quantity\n"
		<< "5.List All Books by Wholesale Cost\n6.List All Books by Age inInventory\n7.Exit\n"
		<< "ENTER CHOICE : "
		<< setprecision(2) << fixed;
		std::cin >> menuChoice;

	switch (menuChoice)
	{
	case 1:
		dumpBookList();
		break;
	case 2:
		accumulate(&(Book::getWhole));
		break;
	case 3:
		accumulate(&Book::getRetail);
		break;
	case 4:
		listBy(&Book::getQty);
		break;
	case 5:
		listBy(&Book::getWhole);
		break;
	case 6:
		listBy(&Book::getDate);
		break;
	case 7:
		cout << endl << "\"See you later.\"";
		return 1;
	}

	return false;
}