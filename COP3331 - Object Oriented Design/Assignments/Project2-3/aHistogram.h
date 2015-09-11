//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

using namespace std;
#ifndef AHISTOGRAM_H
#define AHISTOGRAM_H

class aHistogram
{
public:
	aHistogram(void);
	~aHistogram(void);
	void setRange(int low, int high);
	void update(int number);	//potentially const
	int count(int randomNumber) const;
	void display();
	void clear();
private:
	int index;
	int low;
	int high;
	int size;
	int number;
	int randomNumber;
	vector <int> binVector;
};

#endif