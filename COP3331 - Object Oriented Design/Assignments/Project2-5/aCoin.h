//file(s): aCoin.cpp & aCoin.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include "aRandomNumberGenerator.h"
using namespace std;
#ifndef ACOIN_H
#define ACOIN_H

class aCoin: public aRandomNumberGenerator
{
public:
	aCoin();				//constructor
	~aCoin();			//destructor
	int flip() const;	//random number of flip
private:

};

#endif