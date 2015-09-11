//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
//#include "aRandomNumberGenerator.h"
#include "aHistogram.h"
#include "aCoin.h"
#include "aDie.h"
using namespace std;

int main()
{
	int seed=0;
	cout << "Enter an integer to seed the random number generator: ";
	cin >> seed;
	srand(seed);

	aCoin coinObject;
	aDie dieObject;
	aHistogram coinHistogram;
	aHistogram dieHistogram;
	int flips;
	int rolls;
	string heads;
	string tails;
	int index=0;
	int number=0;

	coinHistogram.setRange(coinObject.getLowNumber(), coinObject.getHighNumber());
	dieHistogram.setRange(dieObject.getLowNumber(), dieObject.getHighNumber());

	cout << "How many times would you like to flip the coin?" << endl;
	cin >> flips;

	for (index=0; index<flips; ++index)
	{
		coinHistogram.update(number);
	}
	coinHistogram.display();
	coinHistogram.clear();


	cout << "How many times would you like to roll the die?" << endl;
	cin >> rolls;

	for (index=0; index<rolls; ++index)
	{
		dieHistogram.update(number);
	}
	dieHistogram.display();
	dieHistogram.clear();
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