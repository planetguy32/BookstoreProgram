#include "Book.h"

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