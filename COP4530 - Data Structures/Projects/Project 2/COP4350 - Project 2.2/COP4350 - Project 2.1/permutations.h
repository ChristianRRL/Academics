/* permutations.h ---------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class permutations
-------------------------------------------------------------------*/

#ifndef PERMUTATIONS_H_
#define PERMUTATIONS_H_

#include <iostream>
#include <cassert>
using namespace std;

//-- Function/Class Declarations

template <class T>
void outputArray(T* items, const int& size, ostream& out);
/*-------------------------------------------------------------------
Purpose: A generic function to output an array

Preconditions: items is a non-empty array, size is a non-zero number,
out is an ostream type.
Postconditions: Array items is output on a single line with one space
between each element.

Big O:
-------------------------------------------------------------------*/

long factorial(const int& n);
/*-------------------------------------------------------------------
Purpose: A recursive function to compute n!

Preconditions: n is a non-negative integer.
Postconditions: n! is returned.

Big O:
-------------------------------------------------------------------*/


template <class T>
void outputPermutations(T* items, const int& size, ostream& out);
/*-------------------------------------------------------------------
Purpose: A generic recursive solution to output all permutations of 
an array.

Preconditions: There are n! permutations of an array
Postconditions: outputArray function used to output all permutations.

Big O:
-------------------------------------------------------------------*/


//-- Function/Class Declarations
template <class T>
void outputArray(T* items, const int& size, ostream& out) {
   for (int i = 0; i < size; ++i) {
      out << items[i] << " ";
   }
   out << "\n";

   return;
}

long factorial(const int& n) {
   assert(n >= 0);
   if (n == 0) {
      return 1;
   }
   else {
      return n*factorial(n - 1);
   }
}

template <class T>
void outputPermutations(T* items, const int& size, ostream& out) {


   return;
}

#endif