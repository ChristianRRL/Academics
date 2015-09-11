//file(s): aCoin.cpp & aCoin.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <cstdlib>
#include <vector>
#include "aHistogram.h"
#include "aCoin.h"
#include "aDie.h"
using namespace std;


aCoin::aCoin(void)			//constructor
{
	this->setRange(0,1);
	//string name[2]={"Heads","Tails"};
}


aCoin::~aCoin(void)			//destructor
{
}

int aCoin::flip() const		//random number of flip
{
	return generate();
}
