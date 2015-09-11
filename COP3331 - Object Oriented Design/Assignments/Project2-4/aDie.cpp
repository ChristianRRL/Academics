//file(s): aDie.cpp & aDie.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <cstdlib>
#include <vector>
#include "aHistogram.h"
#include "aCoin.h"
#include "aDie.h"
using namespace std;


aDie::aDie(void)			//constructor
{
	this->setRange(0,5);
}


aDie::~aDie(void)		//destructor
{
}

int aDie::roll() const	//random number of roll
{
	return generate(); 
}
