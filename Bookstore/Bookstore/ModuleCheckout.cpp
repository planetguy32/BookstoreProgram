#include "ModuleCheckout.h"
#include "ModuleInventory.h"

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
	bool moreItems=true;
	bool moreCustomers=true;
	double orderPrice=0;
	std::cout << std::setprecision(2) << std::fixed;
	while(moreCustomers)
	{
		std::cout << "Ready for business - enter employee username" << std::endl;
		std::string employeeID;
		std::cin >> employeeID;
		if(employeeID == "logout" || employeeID == "quit")
		{
			moreItems=false;
			moreCustomers=false;
			return employeeID == "quit";
		}
		else
		{
			system("clear");
			std::cout << "Welcome to the bookstore."  << std::endl;
		}
		while(moreItems)
		{
			int bookISBN;
			std::cout << "ISBN: ";
			if (!(std::cin >> bookISBN))
			{
				moreItems=false;
				std::cout << "Subtotal: " << orderPrice;
				std::cout << "Total: " << orderPrice * 1.10; //TODO variable tax rate?
				std::cout << "Thank you for your business." << std::endl;
				std::cout << "Your cashier was " << employeeID << std::endl;
			}
			else
 			{
				Book * book = inventory->getBook(bookISBN);
				int qty=book->getQty();
				if(qty <= 1)
				{
					//Book is now out of stock. What to do?
				}
				book->setQty(qty-1);
				double price=book->getRetail();
				std::cout << book->getTitle() << std::endl;
				std::cout << "   $" << price << std::endl << std::endl;
				orderPrice += price;
			}
		}
	}
}
