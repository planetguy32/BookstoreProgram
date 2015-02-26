#include "ModuleInventory.h"


ModuleInventory::ModuleInventory()
{
}


ModuleInventory::~ModuleInventory()
{
}

void Book::setISBN(int i)
{
	ISBN = i;
}

void Book::setTitle(string t)
{
	title = t;
}

void Book::setAuthor(string a)
{
	author = a;
}

void Book::setPub(string p)
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

int Book::getISBN()
{
	return ISBN;
}

string Book::getTitle()
{
	return title;
}

string Book::getAuthor()
{
	return author;
}

string Book::getPub()
{
	return publisher;
}

int setQty()
{
	return qty;
}

double setWhole()
{
	return wholesale;
}

double setRetail()
{
	return retail;
}