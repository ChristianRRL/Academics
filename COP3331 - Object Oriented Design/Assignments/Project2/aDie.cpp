//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
//#include "aRandomNumber.h"
#include "aHistogram.h"
#include "aCoin.h"
#include "aDie.h"
using namespace std;


aDie::aDie(void)
{
	this->setRange(1,6);
}


aDie::~aDie(void)
{
}

int aDie::roll()
{
	return (rand() % (getHighNumber() - getHighNumber() + 1) ) + getLowNumber(); 
}
