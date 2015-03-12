#include "ModuleInventory.h"
#include <fstream>
#include <iostream>
#include <algorithm>

ModuleInventory::ModuleInventory()
{
	std::ifstream in("booklist.txt", std::ifstream::in);
	bool valid = true;
	while (in.good() && valid)
	{	
		Book * book=new Book;
		std::string * subParts=split(in, '~');
		if (subParts)
		{
			book->setISBN(stoll(subParts[0]));
			book->setTitle(subParts[1]);
			book->setAuthor(subParts[2]);
			book->setPub(subParts[3]);
			book->setDate(subParts[4]);
			book->setQty(stoi(subParts[5]));
			book->setWhole(stod(subParts[6]));
			book->setRetail(stod(subParts[7]));

			books.push_back(book);
			
			delete[]  subParts;
		}
		else
		{
			valid = false;
		}
	}
	std::sort(books.begin(), books.end());
}

std::string * ModuleInventory::split(std::istream& instream, char splitChar)
{
	std::string * readLines = new std::string [8];
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
	return false;
}

Book * ModuleInventory::getBook(long long int isbn)
{
	return findBook(isbn, 0, books.size());
}

Book * ModuleInventory::findBook(long long int isbn, int start, int end)
{
	int midpt = start+(end - start) / 2;
	long long int otherISBN = books[midpt]->getISBN();
	if (end == start && otherISBN != isbn)
		return 0;
	else if (isbn == otherISBN)
		return books[midpt];
	else if (isbn > otherISBN)
		return findBook(isbn, midpt, end);
	else
		return findBook(isbn, start, midpt);
}