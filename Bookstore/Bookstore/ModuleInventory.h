
/*
ModuelInventory Class



	Book Class (SUBCLASS?)
		-declare variables: ISBN, title, author, publisher, addDate, qty, wholesale, retail
		-constructor
		-destructor
		-set functions
		-get functions
	Set Functions
		-initialize variables to get data
	Get Functions
		-ofstream open file
		-pull from BookList file into appropriate variables
		-ofstream close file
*/
#pragma once
#include "Module.h"
#include <string>
#include <vector>

class Book;

class ModuleInventory :
	public Module
{
private:
	std::vector<Book> books;
	std::string * split(const std::istream& in, char splitChar);
public:
	ModuleInventory();
	~ModuleInventory();
	bool doInteraction();
	Book * getBook(long long int isbn);
};

class Book {
private:
	long long int ISBN;
	std::string title;
	std::string author;
	std::string publisher;
	std::string date;
	int qty;
	double wholesale;
	double retail;
public:
	Book();
	~Book();
	void setISBN(long long int i);
	void setTitle(std::string t);
	void setAuthor(std::string a);
	void setPub(std::string p);
	void setDate(std::string date);
	void setQty(int q);
	void setWhole(double w);
	void setRetail(double r);

	long long int getISBN();
	std::string getTitle();
	std::string getAuthor();
	std::string getPub();
	std::string getDate();
	int getQty();
	double getWhole();
	double getRetail();


};
