//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include "aRandomNumberGenerator.h"
#ifndef ADIE_H
#define ADIE_H

class aDie:	public aRandomNumberGenerator
{
public:
	aDie(void);
	~aDie(void);
	int roll();
private:

};

#endif