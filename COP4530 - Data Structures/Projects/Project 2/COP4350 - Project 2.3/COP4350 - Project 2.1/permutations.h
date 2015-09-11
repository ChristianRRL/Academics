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

template <class T>
void recursivePermutations(T* items, const int size, int begin, int end, ostream& out);


template <class T>
void swap(T* items, T& a, T& b);


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
   int begin = 0;
   int end = size;
   recursivePermutations(items, size, begin, end, out);
   //static int index = 0;
   //static long iterations = factorial(size - 1);
   //static int count = 0;
   //static int i;

   //if (index == (size)) {
   //   //assert(count == iterations);
   //   cout << "Success!\n";
   //   //return;
   //}
   //else {
   //   for (i = 0; i < size; ++i) {
   //      if (count != iterations) {

   //      }
         
         //outputArray(items, size, out);
         //swap(items, &items[index], &items[i]);
         //index++;
         //count++;
         //outputPermutations(items, size, out);
         //outputArray(items, size, out);
         //swap(items, &items[i], &items[index]);
   //   }
   //}
   return;
   //for (int i = 0; i < size; ++i) {

   //}

   //++index;



   //static long iterations = factorial(size);
   ////static int count = 0;
   //T index;

   //if (iterations == 0) {
   //   return;
   //}
   //else {
   //   //outputArray(items, size, out);
   //   --iterations;
   //   //outputPermutations(items, size, out);
   //   for (int i = 0; i < size; ++i) {
   //      index = items[size-1];
   //      items[size - 1] = items[i];
   //      items[i] = items[size - 1];
   //      outputPermutations(items, size, out);
   //   }
   //   outputArray(items, size, out);
   //}

   return;
}

template <class T>
void recursivePermutations(T* items, const int size, int begin, int end, ostream& out) {
   int i;
   int range = size;
   if (range == 0) {
      outputArray(items, size, out);
   }
   else {
      for (i = 0; i < range; ++i) {
         swap(items[begin], items[begin + i]);
         recursivePermutations(items, size, begin + 1, end, out);
         swap(items[begin], items[begin + i]);
      }
   }

   return;
   ////if (end != 0) {
   //   for (int i = 0; i < size; ++i) {
   //      if (end != 0) {
   //         outputArray(items, size, out);
   //         swap(i, index);
   //         recursivePermutations(items, size, --end, out);
   //      }
   //   }
   //   end = size;
   ////}
}

template <class T>
void swap(T* items, T& a, T& b) {
   T temp;

   temp = items[a];
   items[a] = items[b];
   items[b] = temp;
}

//int recursiveFunction() {
//   static int statVar = 0;
//   if (statVar > 5) {
//      return statVar;
//   }
//   else {
//      statVar++;
//      recursiveFunction();
//   }
//}

#endif