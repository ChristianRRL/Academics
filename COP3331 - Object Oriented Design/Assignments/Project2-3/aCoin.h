//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include "aRandomNumberGenerator.h"
using namespace std;
#ifndef ACOIN_H
#define ACOIN_H

class aCoin: public aRandomNumberGenerator
{
public:
	aCoin();
	~aCoin();
	int flip();	//potentially const
private:

};

#endif