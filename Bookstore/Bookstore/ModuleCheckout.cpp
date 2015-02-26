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
	cout << setprecision(2) << fixed;
	while(moreItems)
	{
		string book;
		cout << "Book title: ";
		cin >> book;
		if(book.length  == 0)
		{
			moreItems=false;
			cout << "Subtotal: " << orderPrice;
			cout << "Total: "
			cout << "Thank you for your business." << endl;
		}
		else
		{
			Book * book;
			//TODO lookup from DB
			int qty=book->getQty();
			if(qty <= 1)
			{
				//TODO handle book out of stock
			}
			else
			{
				book->setQty(qty-1);
			}
			double price=book->getRetail();
			cout << book->getTitle() << endl;
			cout << "   $" << price << endl << endl;
			orderPrice += price;
		}
	}
}
