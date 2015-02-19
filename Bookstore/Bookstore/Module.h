#pragma once
class Module
{
public:
	Module(){}
	virtual ~Module(){};

	virtual bool doInteraction()=0;
};

