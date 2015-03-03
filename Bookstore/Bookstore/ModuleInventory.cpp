#include "ModuleInventory.h"


ModuleInventory::ModuleInventory()
{
}


ModuleInventory::~ModuleInventory()
{
}

bool ModuleInventory::doInteraction()
{
	return false;
}

Book * ModuleInventory::getBook(int isbn)
{
	//TODO implement this
	return reinterpret_cast<Book *>(0);
}

void Book::setISBN(int i)
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

int Book::getISBN()
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
