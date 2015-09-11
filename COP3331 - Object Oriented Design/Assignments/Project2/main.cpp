//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
//#include "aRandomNumber.h"
#include "aHistogram.h"
#include "aCoin.h"
#include "aDie.h"
using namespace std;

int main()
{
	srand(time(NULL));

	aCoin coinObject;
	aDie dieObject;
	aHistogram myHistogram;
	int flips;
	int rolls;
	int index=0;
	int number=0;

	cout << "How many times would you like to flip the coin?" << endl;
	cin >> flips;

	myHistogram.count(flips);
	for (index=0; index<flips; ++index)
	{
		myHistogram.update(number);//array
			
	}
	myHistogram.display();
	myHistogram.clear();


	cout << "How many times would you like to roll the die?" << endl;
	cin >> rolls;

	myHistogram.count(rolls);
	for (index=0; index<rolls; ++index)
	{
		myHistogram.update(number);//array
			
	}
	myHistogram.display();
	myHistogram.clear();
}


/*
int main()
{
	srand(time(NULL));


	aRandomNumber numberObject1;
	aRandomNumber numberObject2;
	aRandomNumber numberObject3;


	int x=0;
	int y=0;

	cout << "Enter a low number: ";
	cin >> x;
	cout << "Enter a high number: ";
	cin >> y;

	numberObject2.setRange(5,15);
	numberObject3.setRange(x,y);

	cout << "The first set of randomly generated numbers is: " << endl;
	numberObject1.aHistogram();
	cout << "The second set of randomly generated numbers is: " << endl;
	numberObject2.aHistogram();
	cout << "The third set of randomly generated numbers is: " << endl;
	numberObject3.aHistogram();


	system("pause");
	return 0;
}
*/