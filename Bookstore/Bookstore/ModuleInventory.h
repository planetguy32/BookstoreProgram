#pragma once
#include "Module.h"

/*
ModuelInventory Class
	
	-show menu
		1. Search Book
			a. Search by ISBN
			b. Search by Title
			c. Search by Author
			d. Search by Publisher
			e. Search by Date Added
			f. Search by Quantity
			g. Search by Wholesale Cost
				-input amount
					-less than amount
					-more than amount
					-equal to amount
			h. Search by Retail Price
				-input amount
					-less than amount
					-more than amount
					-equal to amount
			-List book information:
				-ISBN, Title, Author, Publisher, Date Added to Inventory, Quantity-On-Hand, Wholesale Cost, Retail Price
					1. Delete Book
						-Input Admin Password
						-Check for correct Admin Password
						-Confirm deletion
					2. Change Information
						-Input Admin Password
						-Check for correct Admin Password
						a. Change ISBN
						b. Change Title
						c. Change Author
						d. Change Publisher
						e. Change Date Added
						f. Change Quantity
						g. Change Wholesale cost
							-input amount
						h. Change Retail Price
							-input amount
		2. Add Book
			-Input Admin Password
			-Check for correct Admin Password
			-How many?
			-Fill out information:
				-ISBN, Title, Author, Publisher, Date Added to Inventory, Quantity-On-Hand, Wholesale Cost, Retail Price
		3. Delete Book
			-Input Admin Password
			-Check for correct Admin Password
			1. Search Book
			a. Search by ISBN
			b. Search by Title
			c. Search by Author
			d. Search by Publisher
			e. Search by Date Added
			f. Search by Quantity
			g. Search by Wholesale Cost
				-input amount
				-search costs less than amount
				-search costs more than amount
				-search costs equal to amount
			h. Search by Retail Price
				-input amount
				-search prices less than amount
				-search prices more than amount
				-search prices equal to amount
			-List book information:
				-ISBN, Title, Author, Publisher, Date Added to Inventory, Quantity-On-Hand, Wholesale Cost, Retail Price
			-Confirm deletion

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
	int menuChoice;
	int numInput;
	string strInput;
	double costInput;

public:
	ModuleInventory();
	~ModuleInventory();
	int getMenu();
};

class Book {
private:
	int ISBN;
	string title;
	string author;
	string pulisher;
	string date;
	int qty;
	double wholesale;
	double retail;
public:
	Book();
	~Book();
	void setISBN(int i);
	void setTitle(string t);
	void setAuthor(string a);
	void setPub(string p);
	void setQty(int q);
	void setWhole(double w);
	void setRetail(double r);

	int getISBN();
	string getTitle();
	string getAuthor();
	string getPub();
	int getQty();
	double getWhole();
	double getRetail();


};

