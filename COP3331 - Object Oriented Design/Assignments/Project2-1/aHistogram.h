//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include "aRandomNumberGenerator.h"
#ifndef AHISTOGRAM_H
#define AHISTOGRAM_H

class aHistogram
{
public:
	aHistogram(void);
	~aHistogram(void);
	void setRange(int low, int high);
	void update(int number);
	void display();
	void clear();
	int count(int randomNumber) const;
private:
	int low;
	int high;
	int size;
	int number;
	int randomNumber;
};

#endif