//file(s): aRandomNumberGenerator.cpp & aRandomNumberGenerator.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

//#pragma once
using namespace std;
#ifndef ARANDOMNUMBER_H
#define ARANDOMNUMBER_H

class aRandomNumberGenerator
{
public:
	aRandomNumberGenerator(void);		//constructor
	~aRandomNumberGenerator(void);	//destructor
	int generate(void) const;						//random number generator
	void setRange(int low, int high);			//set the range of the random number generator
	int getLowNumber(void) const;			//get the low number
	int getHighNumber(void) const;			//get the high number
private:
	int low;												//low number
	int high;												//high number
	int size;												//size ((high - low) + 1)
};

#endif