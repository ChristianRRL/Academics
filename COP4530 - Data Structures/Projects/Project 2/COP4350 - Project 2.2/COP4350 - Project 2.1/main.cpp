/* main.cpp ---------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class permutations
-------------------------------------------------------------------*/

#include <iostream>
#include <cstdlib>
#include "permutations.h"
using namespace std;

int main() {
   int size = 5;
   int* intArray = new int[size];

   for (int i = 0; i < size; ++i) {
      cin >> intArray[i];
   }

   cout << factorial(size) << endl;

   ostream& yolo = cout;

   outputArray(intArray, size, yolo);

   system("pause");

   size = 10;
   intArray = new int[size];

   for (int i = 0; i < size; ++i) {
      intArray[i] = i;
   }

   outputArray(intArray, size, yolo);

   system("pause");

   size = 2;
   intArray = new int[size];

   for (int i = 0; i < size; ++i) {
      intArray[i] = i;
   }

   outputArray(intArray, size, yolo);

   system("pause");

   return 0;
}