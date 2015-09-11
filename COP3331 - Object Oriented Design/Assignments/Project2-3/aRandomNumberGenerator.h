//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

//#pragma once
using namespace std;
#ifndef ARANDOMNUMBER_H
#define ARANDOMNUMBER_H

class aRandomNumberGenerator
{
public:
	aRandomNumberGenerator(void);
	~aRandomNumberGenerator(void);
	int generate(void);	//potentially const
	void setRange(int low, int high);
	int getLowNumber(void) const;
	int getHighNumber(void) const;
private:
	int low;
	int high;
	int size;
};

#endif