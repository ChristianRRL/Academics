/*authors:
**Christian Rodriguez
**Gabriel Sotolongo
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "aRandomNumber.h"
using namespace std;

int main()
{
	aRandomNumber number;

	number.setRange(1,9);

	number.generate();

	return 0;
}