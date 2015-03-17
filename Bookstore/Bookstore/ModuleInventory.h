#pragma once
#include "Module.h"
#include "Book.h"
#include <string>
#include <vector>


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

class ModuleInventory :
	public Module
{
private:
	std::vector<Book *> books;
	std::string * split(std::istream& in, char splitChar);
	
	template<class T>
	Book * findBook(T, T(Book::* f)(), int start, int end);
	Book * parseBook(std::string * inputArrayOf8);
public:
	ModuleInventory();
	~ModuleInventory();
	bool doInteraction();

	Book * Action(Book *);

	template<class T>
	Book * getBook(T isbn, T(Book::* f)());
	Book * getBook(long long int isbn);

	template<class T>
	int getBookIndex(T isbn, T(Book::* f)(), int start, int end);

};
