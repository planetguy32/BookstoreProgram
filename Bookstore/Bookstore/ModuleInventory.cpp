#include "ModuleInventory.h"
#include <fstream>


ModuleInventory::ModuleInventory()
{
	/*
	std::ifstream in("booklist.txt", std::ifstream::in);
	char *line = new char[4096];
	while (in.good())
	{	
		Book book;
		int indexIntoLine = 0;
		in.getline(line, 4096);
		std::string name="";
		while (line[indexIntoLine] != '~')
		{
			name = name + line[indexIntoLine];
		}
	}
	delete line;
	*/
}

/*
std::string [] split(const std::istream& in, char splitChar)
{
	
}
*/

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

Book::Book()
{

}

Book::~Book()
{

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
