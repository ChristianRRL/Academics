/* main.cpp ---------------------------------------------------------
author: Christian A. Rodriguez
Main file to test each of the member functions of the permutations 
class
-------------------------------------------------------------------*/

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <string>
//#include <cassert>
#include "permutations.h"

using namespace std;

//template < class T >

int main()
{
   int n = 0;
   
   cout << "This program finds the factorial of a given input\n" << endl;
   cout << "Enter a non-negative integer number: " << endl;
   cin >> n;
   
   cout << factorial(n) << endl;

   void generateArray();

   int* items2;
   items2 = new(nothrow) int[5];
   items2[0] = 0;
   items2[1] = 1;
   items2[2] = 2;
   items2[3] = 3;
   items2[4] = 4;

   int size2 = 4;
   //ostream out2;
   outputArray(items2, size2, cout);


   //List<int> a;
   //cout << a;
   //generateArray(n);
   cin >> n;

   return 0;
}