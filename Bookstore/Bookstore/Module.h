#pragma once
class Module
{
public:
	Module(){}
	virtual ~Module(){};

	//Passes control to the module. Return value is unimportant.
	virtual bool doInteraction()=0;
};

