//file(s): aDie.cpp & aDie.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include "aRandomNumberGenerator.h"
using namespace std;
#ifndef ADIE_H
#define ADIE_H

class aDie:	public aRandomNumberGenerator
{
public:
	aDie(void);			//constructor
	~aDie(void);		//destructor
	int roll() const;	//random number of roll
private:

};

#endif