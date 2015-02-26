#include "ModuleCheckout.h"
#include "ModuleInventory.h"

#include <iostream>
#include <iomanip>


ModuleCheckout::ModuleCheckout()
{
}


ModuleCheckout::~ModuleCheckout()
{
}

bool ModuleCheckout::doInteraction()
{
	bool moreItems=true;
	double orderPrice=0;
	std::cout << std::setprecision(2) << std::fixed;
	while(moreItems)
	{
		std::string book;
		std::cout << "Book title: ";
		std::cin >> book;
		if(book.length  == 0)
		{
			moreItems=false;
			std::cout << "Subtotal: " << orderPrice;
			std::cout << "Total: "
			std::cout << "Thank you for your business." << endl;
		}
		else
		{
			Book * book;
			//TODO lookup from DB
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
