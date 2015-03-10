#include "ModuleInventory.h"
#include <fstream>


ModuleInventory::ModuleInventory()
{
	std::ifstream in("booklist.txt", std::ifstream::in);
	while (in.good())
	{	
		Book * book = new Book;
		std::string * subParts=split(in, '~');
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
	std::string * readLines = new std::string [8];
	char readSpot[2048];
	in.getline(readSpot, 2048);
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
			inProgress+=readSpot[indexIntoLine];
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