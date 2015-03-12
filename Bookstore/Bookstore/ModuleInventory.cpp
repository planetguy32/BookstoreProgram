/*
Which information of book are you going to work on it ?
	1. ISBN
	2. Title
	3. Author
	4. Publisher

if find it
	a - show book information : (Search)
		-ISBN, Title, Author, Publisher, Date Added to Inventory, Quantity - On - Hand, Wholesale Cost, Retail Price
	b - then ask for
		1 - Change information
			- Input Admin Password
			- Check for correct Admin Password
			a.Change ISBN
			b.Change Title
			c.Change Author
			d.Change Publisher
			e.Change Date Added
			f.Change Quantity
			g.Change Wholesale cost
			h.Change Retail Price

		2 - Delete
			- Input Admin Password
			- Check for correct Admin Password
			- Confirm deletion
		3 - just take a look

else if don't find it
	"There isn't any information about this book"
	"Are you going to add this book to database?"
	Add Book
		- Input Admin Password
		- Check for correct Admin Password
		- Fill out information :
		-ISBN, Title, Author, Publisher, Date Added to Inventory, Quantity - On - Hand, Wholesale Cost, Retail Price

*/

#pragma once

#include <fstream>
#include <iostream>

#include "Module.h" 
#include "ModuleInventory.h"


ModuleInventory::ModuleInventory()
{
	bool go = true;

	std::ifstream in("booklist.txt", std::ifstream::in);
	while (in.good())
	{
		Book * book = new Book;
		std::string * subParts = split(in, '~');
		book->setISBN(stoll(subParts[0]));
		book->setTitle(subParts[1]);
		book->setAuthor(subParts[2]);
		book->setPub(subParts[3]);
		book->setDate(subParts[4]);

		books.push_back(*book);
		delete[]  subParts;
	}

}

std::string * ModuleInventory::split(const std::istream& in, char splitChar)
{
	std::string * readLines = new std::string[8];
	char readSpot[2048];
//	in.getline(readSpot, 2048);
	int indexIntoLine = 0;
	int indexIntoReadLines = 0;
	std::string inProgress;
	//exits on \0 or finished readSpot or found all 8 parts
	while (readSpot[indexIntoLine]
		&& indexIntoLine < 2048
		&& indexIntoReadLines < 8)
	{
		if (readSpot[indexIntoLine] == splitChar)
		{
			readLines[indexIntoReadLines] = inProgress;
			indexIntoReadLines++;
		}
		else
		{
			inProgress += readSpot[indexIntoLine];
		}
		indexIntoLine++;
	}
	return readLines;
}


ModuleInventory::~ModuleInventory()
{
}

bool ModuleInventory::doInteraction()
{
	std::string * NewBook = new std::string[8];
	bool moreItems = true;
	char AddBook;

	std::cout << "Bookstore program" << std::endl;
	std::cout << "Which information of book are you going to work on it ?" << std::endl;
	std::cout << "    1. ISBN" << std::endl;
	std::cout << "    2. Title" << std::endl;
	std::cout << "    3. Author" << std::endl;
	std::cout << "    4. Publisher" << std::endl;
	std::cout << "    5. Return to main Menu" << std::endl;

	std::cout << std::endl;
	std::cout << ":";
	int choice = -1;
	while (!(std::cin >> choice) || choice > 5 || choice < 0)
	{
		std::cout << "Invalid choice - only 1-5 are allowed" << std::endl;
	}

	while (moreItems)
	{
		long long int bookISBN;
		std::cout << "ISBN: ";
		if (!(std::cin >> bookISBN))
		{
			moreItems = false;
		}
		else
		{

//			Book * book = inventory->getBook(bookISBN);
			Book * book = getBook(bookISBN);
			if (book != 0)
			{
				std::cout << " ISBN : " << book->getISBN << std::endl;
				std::cout << " Title : " << book->getTitle << std::endl;
				std::cout << " Author : " << book->getAuthor << std::endl;
				std::cout << " Publisher : " << book->getPub << std::endl;
				std::cout << " Date Added to Inventory : " << book->getDate << std::endl;
				std::cout << " Quantity On Hand : " << book->getQty << std::endl;
				std::cout << " Wholesale Cost $: " << book->getWhole << std::endl;
				std::cout << " Retail Price $: " << book->getRetail << std::endl;
			}
			else //null book
			{
				std::cout << "There isn't any information about this book!" << std::endl;
				std::cout << "Are you going to add this book to database? " << std::endl;
				std::cin >> AddBook;
				std::cout << std::endl;

				if (AddBook == 'y' || AddBook == 'Y')
				{
					Book * book = new Book;
					NewBook[0] = bookISBN;
					std::cout << std::endl << " Title : ";
					std::cin >> NewBook[1];
					std::cout << std::endl << " Author : ";
					std::cin >> NewBook[2];
					std::cout << std::endl << " Publisher : ";
					std::cin >> NewBook[3];
					std::cout << std::endl << " Date Added to Inventory : ";
					std::cin >> NewBook[4];
					std::cout << std::endl << " Quantity On Hand : ";
					std::cin >> NewBook[5];
					std::cout << std::endl << " Wholesale Cost $: ";
					std::cin >> NewBook[6];
					std::cout << std::endl << " Retail Price $: ";
					std::cin >> NewBook[7];

					book->setISBN(bookISBN);
					book->setTitle(NewBook[1]);
					book->setAuthor(NewBook[2]);
					book->setPub(NewBook[3]);
					book->setDate(NewBook[4]);
					book->setQty(stoi(NewBook[5]));
					book->setWhole(stoi(NewBook[6]));
					book->setRetail(stoi(NewBook[7]));


				}

			}
		}
	}
	return false;
}

Book * ModuleInventory::getBook(long long int isbn)
{
	bool FindIt = true;
	/*
	while (FindIt)
	{
		if (book->getISBN)
		{
			book->getTitle;
			book->getAuthor;
			book->getPub;
			book->getQty;
			book->getWhole;
			book->getRetail;
		}
	}
*/
	return reinterpret_cast<Book *>(0);
}

Book::Book()
{

}

Book::~Book()
{

}

void Book::setISBN(long long int i)
{
	ISBN = i;
}

void Book::setTitle(std::string t)
{
	title = t;
}

void Book::setAuthor(std::string a)
{
	author = a;
}

void Book::setPub(std::string p)
{
	publisher = p;
}

void Book::setDate(std::string d)
{
	date = d;
}


void Book::setQty(int q)
{
	qty = q;
}

void Book::setWhole(double w)
{
	wholesale = w;
}

void Book::setRetail(double r)
{
	retail = r;
}

long long int Book::getISBN()
{
	return ISBN;
}

std::string Book::getTitle()
{
	return title;
}

std::string Book::getAuthor()
{
	return author;
}

std::string Book::getPub()
{
	return publisher;
}
std::string Book::getDate()
{
	return date;
}

int Book::getQty()
{
	return qty;
}

double Book::getWhole()
{
	return wholesale;
}

double Book::getRetail()
{
	return retail;
}
