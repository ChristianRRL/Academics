//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include "aRandomNumber.h"
#ifndef AHISTOGRAM_H
#define AHISTOGRAM_H

class aHistogram: public aRandomNumber 
{
public:
	aHistogram(void);
	~aHistogram(void);
	void update(int number);
	void display();
	void clear();
	int count(int randomNumber);
private:
	int number;
	int randomNumber;
};

#endif