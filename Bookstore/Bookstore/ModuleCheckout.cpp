#include "ModuleCheckout.h"
#include "ModuleInventory.h"
#include "SystemPrograms.h"

#include <iostream>
#include <iomanip>


ModuleCheckout::ModuleCheckout(ModuleInventory *inv)
{
	inventory = inv;
}


ModuleCheckout::~ModuleCheckout()
{
}

bool ModuleCheckout::doInteraction()
{
	std::cout << "===Checkout Module===" << std::endl;
	std::cout << std::setprecision(2) << std::fixed;
	while(1)
	{
		std::cout << "Ready for business - enter employee username (or \"logout\" or \"quit\")" << std::endl;
		std::string employeeID;
		std::cin.ignore();
		std::getline(std::cin,employeeID);
		if(strcmp( employeeID.c_str(), "logout") == 0)
		{
			return true;
		}
		else
		{
			system_clear();
			std::cout << "Welcome to the bookstore."  << std::endl;
		}
		bool moreItems = true;
		double orderPrice = 0;
		while (moreItems)
		{
			std::string strBookISBN;
			long long int bookISBN;
			std::cout << "ISBN: ";
			std::getline(std::cin, strBookISBN);
			try{
				bookISBN = std::stoll(strBookISBN);
				Book * book = inventory->getBook(bookISBN);
				if (book != 0)
				{
					int qty = book->getQty();
					book->setQty(qty - 1);
					double price = book->getRetail();
					std::cout << book->getTitle() << std::endl;
					std::cout << "   $" << price << std::endl << std::endl;
					orderPrice += price;
				}
				else //null book
				{
					std::cout << "Book not recognized!" << std::endl;
				}
			}
			catch (std::invalid_argument)
			{
				moreItems = false;
				std::cout << "Subtotal: " << orderPrice << std::endl;
				std::cout << "Total: " << orderPrice * 1.10 <<std::endl; 
				std::cout << "Thank you for your business." << std::endl;
				std::cout << "Your cashier was " << employeeID << std::endl;
			}
		}


	}
	int i = 0;
	std::cout << std::setw(6) << inventory->books[i]->getQty() << inventory->books[i]->getTitle();
	return 0;
}
