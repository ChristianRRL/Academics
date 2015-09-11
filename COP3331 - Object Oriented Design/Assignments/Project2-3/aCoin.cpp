//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <cstdlib>
#include <vector>
//#include "aRandomNumberGenerator.h"
#include "aHistogram.h"
#include "aCoin.h"
#include "aDie.h"
using namespace std;


aCoin::aCoin(void)
{
	this->setRange(0,1);
	string name[2]={"Heads","Tails"};
}


aCoin::~aCoin(void)
{
}

int aCoin::flip()
{
	return generate();
}
