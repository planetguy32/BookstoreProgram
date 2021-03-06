/*
Which information of book are you going to work on it ?
1. ISBN
2. Title
3. Author
4. Publisher

if find it
a - show book information : (Search)
-ISBN, Title, Author, Publisher, Date Added to Inventory, Quantity - On - Hand, Wholesale Cost, Retail Price
b - then ask for "What are you going to do?"
1 - just take a look
2 - Change information
a.Change ISBN
b.Change Title
c.Change Author
d.Change Publisher
e.Change Date Added
f.Change Quantity
g.Change Wholesale cost
h.Change Retail Price
3 - Delete

else if don't find it
"There isn't any information about this book"
"Are you going to add this book to database?"
Add Book
- Fill out information :
-ISBN, Title, Author, Publisher, Date Added to Inventory, Quantity - On - Hand, Wholesale Cost, Retail Price

*/

#pragma once

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>

#include "Module.h" 
#include "ModuleInventory.h"

bool compare(Book* b1, Book* b2)
{
	return *b1 < *b2;
}

ModuleInventory::ModuleInventory()
{
	bool go = true;

	std::ifstream in("booklist.txt", std::ifstream::in);
	bool valid = true;
	while (in.good() && valid)
	{
		std::string * subParts = split(in, '~');
		if (subParts)
		{
			Book * book = parseBook(subParts);

			books.push_back(book);

			delete[]  subParts;
		}
		else
		{
			valid = false;
		}
	}

	std::sort(books.begin(), books.end(), compare);
}

Book * ModuleInventory::parseBook(std::string * subParts)
{
	Book * book = 0;
	if (subParts)
	{
		try
		{
			book = new Book;

			book->setISBN(stoll(subParts[0]));
			book->setTitle(subParts[1]);
			book->setAuthor(subParts[2]);
			book->setPub(subParts[3]);
			book->setDate(subParts[4]);
			book->setQty(stoi(subParts[5]));
			book->setWhole(stod(subParts[6]));
			book->setRetail(stod(subParts[7]));
		}
		catch (std::invalid_argument a)
		{
			for (int i = 0; i < 8; i++)
				std::cout << subParts[i]<< " ";
			std::cout << std::endl;

		}
	}
	return book;
}

std::string * ModuleInventory::split(std::istream& instream, char splitChar)
{
	std::string * readLines = new std::string[8];
	char readSpot[2048];
	instream.getline(readSpot, 2048);
	int indexIntoLine = 0;
	int indexIntoReadLines = 0;
	std::string inProgress;
	//exits on \0 or finished readSpot or found all 8 parts
	if (readSpot[0] == '\0')
	{
		delete[] readLines;
		return 0;
	}
	else
	{
		while (readSpot[indexIntoLine]
			&& indexIntoLine < 2048
			&& indexIntoReadLines < 8)
		{
			if (readSpot[indexIntoLine] == splitChar)
			{
				readLines[indexIntoReadLines] = inProgress;
				indexIntoReadLines++;
				inProgress = "";
			}
			else
			{
				inProgress += readSpot[indexIntoLine];
			}
			indexIntoLine++;
		}
		if (inProgress != "")
			readLines[indexIntoReadLines] = inProgress;
		return readLines;
	}
}


ModuleInventory::~ModuleInventory()
{
	std::ofstream bookList("booklist.txt", std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < books.size(); i++)
	{
		Book * book = books[i];
		bookList << book->getISBN() << "~"
			<< book->getTitle() << "~"
			<< book->getAuthor() << "~"
			<< book->getPub() << "~"
			<< book->getDate() << "~"
			<< book->getQty() << "~"
			<< book->getWhole() << "~"
			<< book->getRetail() << "~" << std::endl;
		delete book;
	}
}

bool ModuleInventory::doInteraction()
{
	bool moreItems = true;
	char AddBook;

	std::cout << "===Inventory module===" << std::endl;
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

	if (choice == 5)
		return false;

	std::string bookQuery;
	std::cout << "Search for: ";
	std::cin.ignore();
	Book * book;
	if (!(std::getline(std::cin, bookQuery)) || choice == 5)
	{
		return false;
	}
	else
	{
		long long int bookISBN;
		switch (choice)
		{
		case 1:
			bookISBN = stoll(bookQuery);
			book = findBook(bookISBN, &Book::getISBN, 0, books.size());
			break;
		case 2:
			book = findBook(bookQuery, &Book::getTitle, 0, books.size());
			break;
		case 3:
			book = findBook(bookQuery, &Book::getAuthor, 0, books.size());
			break;
		case 4:
			book = findBook(bookQuery, &Book::getPub, 0, books.size());
			break;
		default:
			break;
		}

		if (book != 0)
		{
			book = Action(book);

		}
		else //null book
		{
			std::cout << "There isn't any information about this book!" << std::endl;
			std::cout << "Are you going to add this book to database? " << std::endl;
			std::cin >> AddBook;
			std::cout << std::endl;

			if (AddBook == 'y' || AddBook == 'Y')
			{
				std::string * NewBook = new std::string[8];
				Book * book = new Book;
				NewBook[0] = std::to_string(bookISBN);
				std::cin.ignore();
				std::cout << std::endl << " Title : ";
				std::getline(std::cin, NewBook[1]);
				std::cout << std::endl << " Author : ";
				std::getline(std::cin, NewBook[2]);
				std::cout << std::endl << " Publisher : ";
				std::getline(std::cin, NewBook[3]);
				std::cout << std::endl << " Date Added to Inventory : ";
				std::getline(std::cin, NewBook[4]);
				std::cout << std::endl << " Quantity On Hand : ";
				std::getline(std::cin, NewBook[5]);
				std::cout << std::endl << " Wholesale Cost : $";
				std::getline(std::cin, NewBook[6]);
				std::cout << std::endl << " Retail Price : $";
				std::getline(std::cin, NewBook[7]);
				std::cout << std::endl;

				book = parseBook(NewBook);

				books.push_back(book);

				std::sort(books.begin(), books.end(), compare);
			}

		}
	}
	return false;
}

Book * ModuleInventory::getBook(long long int isbn)
{
	return getBook(isbn, &Book::getISBN);
}

template<class T>
Book * ModuleInventory::getBook(T isbn, T(Book::* f)())
{
	return findBook(isbn, f, 0, books.size());
}

template<class T>
Book * ModuleInventory::findBook(T isbn, T(Book::* f)(), int start, int end)
{
	int bookIdx = getBookIndex(isbn, f, start, end);

	if (bookIdx == -1)
		return reinterpret_cast<Book *>(0);
	else
		return books[bookIdx];

}

/*
Binary search of books. The problem is that most modules re-order bookList in their normal operation, so we have no guarantee that bookList is sorted.
We could sort bookList by whatever f returns, but running a O(n*log(n)) sort so we can do O(log(n)) search once is worse than just using O(n) search.

template<class T>
int ModuleInventory::getBookIndex(T isbn, T(Book::* f)(), int start, int end)
{
if (end <= start)
return -1;

int midpt = start + (end - start) / 2;
T otherISBN = (books[midpt]->*f)();
if (isbn == otherISBN)
return midpt;
if (isbn > otherISBN)
return getBookIndex(isbn, f, midpt + 1, end);
else
return getBookIndex(isbn, f, start, midpt - 1);
}
*/

template<class T>

int ModuleInventory::getBookIndex(T search_field, T(Book::* f)(), int start, int end)
{
	if (end <= start)
		return -1;

	T otherISBN = (books[start]->*f)();
	if (search_field == otherISBN)
		return start;
	else
		return getBookIndex(search_field, f, start + 1, end);

}


Book * ModuleInventory::Action(Book* book)
{
	char AddBook;

	std::string * NewBook = new std::string[8];

	NewBook[0] = std::to_string(book->getISBN());
	NewBook[1] = book->getTitle();
	NewBook[2] = book->getAuthor();
	NewBook[3] = book->getPub();
	NewBook[4] = book->getDate();
	NewBook[5] = std::to_string(book->getQty());
	NewBook[6] = std::to_string(book->getWhole());
	NewBook[7] = std::to_string(book->getRetail());

	// Print all fileds
	book->print();

	std::cout << "What will you do with this information?" << std::endl;
	std::cout << "    1. Just take a look?" << std::endl;
	std::cout << "    2. Edit" << std::endl;
	std::cout << "    3. Delete" << std::endl;

	std::cout << std::endl;
	std::cout << ":";
	int choice = -1;
	while (!(std::cin >> choice) || choice > 3 || choice < 0)
	{
		std::cout << "Invalid choice - only 1-3 are allowed" << std::endl;
	}
	if (choice == 2)
	{
		std::cout << std::endl;
		std::cout << "Which information of book are you going to Edit?" << std::endl;
		std::cout << "    1. Title" << std::endl;
		std::cout << "    2. Author" << std::endl;
		std::cout << "    3. Publisher" << std::endl;
		std::cout << "    4. Date Added to Inventory" << std::endl;
		std::cout << "    5. Quantity On Hand" << std::endl;
		std::cout << "    6. Wholesale Cost" << std::endl;
		std::cout << "    7. Retail Price" << std::endl;
		std::cout << "    8. Return to main Menu" << std::endl;

		std::cout << std::endl;
		std::cout << ":";
		int choice = -1;
		while (!(std::cin >> choice) || choice > 8 || choice < 0)
		{
			std::cout << "Invalid choice - only 1-8 are allowed" << std::endl;
		}

		switch (choice)
		{
		case 1:
			std::cout << " Title : ";
			std::cin.ignore();
			std::getline(std::cin, NewBook[1]);
			break;
		case 2:
			std::cout << " Author : ";
			std::cin.ignore();
			std::getline(std::cin, NewBook[2]);
			break;
		case 3:
			std::cout << " Publisher : ";
			std::cin.ignore();
			std::getline(std::cin, NewBook[3]);
			break;
		case 4:
			std::cout << " Date Added to Inventory : ";
			std::cin.ignore();
			std::getline(std::cin, NewBook[4]);
			break;
		case 5:
			std::cout << " Quantity On Hand : ";
			std::cin.ignore();
			std::getline(std::cin, NewBook[5]);
			break;
		case 6:
			std::cout << " Wholesale Cost : $";
			std::cin.ignore();
			std::getline(std::cin, NewBook[6]);
			break;
		case 7:
			std::cout << " Retail Price : $";
			std::cin.ignore();
			std::getline(std::cin, NewBook[7]);
			break;
		case 8:
			break;
		default:
			break;
		}
		int index = getBookIndex(book->getISBN(), &Book::getISBN, 0, books.size());
		books.erase(books.begin() + index);

		book = parseBook(NewBook);
		books.push_back(book);
		std::sort(books.begin(), books.end(), compare);

	}
	else if (choice == 3)
	{
		int index = getBookIndex(book->getISBN(), &Book::getISBN, 0, books.size());
		books.erase(books.begin() + index);
	}
	return 0;
}
