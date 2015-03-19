#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book()
{

}

Book::~Book()
{

}


//Lots of getters and setters

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

void Book::setDate(std::string d)
{
	date = d;
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

std::string Book::getDate()
{
	return date;
}


//Annotates and prints all of the book's data. Uses quite a bit of screen space
void Book::print()
{
	std::cout << std::endl;
	std::cout << " ISBN : " << getISBN() << std::endl;
	std::cout << " Title : " << getTitle() << std::endl;
	std::cout << " Author : " << getAuthor() << std::endl;
	std::cout << " Publisher : " << getPub() << std::endl;
	std::cout << " Date Added to Inventory : " << getDate() << std::endl;
	std::cout << " Quantity On Hand : " << getQty() << std::endl;
	std::cout << " Wholesale Cost : $" << getWhole() << std::endl;
	std::cout << " Retail Price : $" << getRetail() << std::endl;
	std::cout << std::endl;
}

//Comparison operators work on ISBNs
bool operator> (Book &b1, Book &b2)
{
	return b1.ISBN > b2.ISBN;
}

bool operator< (Book &b1, Book &b2)
{
	return b1.ISBN < b2.ISBN;
}

bool operator>= (Book &b1, Book &b2)
{
	return b1.ISBN >= b2.ISBN;
}

bool operator<= (Book &b1, Book &b2)
{
	return b1.ISBN <= b2.ISBN;
}

bool operator== (Book &b1, Book &b2)
{
	return b1.ISBN == b2.ISBN;
}

bool operator!= (Book &b1, Book &b2)
{
	return b1.ISBN != b2.ISBN;
}

//See also the print function. This goes on only one line but is not nearly as complete.
std::ostream& operator<< (std::ostream& o, Book &b)
{
	o << std::setw(55) << b.getTitle() << " (" << b.getISBN() << ")";
	return o;
}