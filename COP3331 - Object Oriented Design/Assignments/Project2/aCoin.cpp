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


aCoin::aCoin(void)
{
	this->setRange(1,2);
}


aCoin::~aCoin(void)
{
}

int aCoin::flip()
{
	return (rand() % (getHighNumber() - getHighNumber() + 1) ) + getLowNumber();
}
