//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

//#pragma once
class aRandomNumber
{
public:
	aRandomNumber(void);
	~aRandomNumber(void);
	int generate();
	void setRange(int low, int high);
	//int aVector();
	void aHistogram();
private:
	int low;
	int high;
	int size;
};

