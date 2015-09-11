//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "aRandomNumber.h"
using namespace std;

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
