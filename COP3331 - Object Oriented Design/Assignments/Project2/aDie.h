//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include "aRandomNumber.h"
#ifndef ADIE_H
#define ADIE_H

class aDie:	public aRandomNumber
{
public:
	aDie(void);
	~aDie(void);
	int roll();
private:

};

#endif