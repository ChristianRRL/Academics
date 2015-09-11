/* main.h -----------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class functions
-------------------------------------------------------------------*/

#include "functions.h"


void testFunctionsClass();

int main() {
   testFunctionsClass();

   cout << "\nfinished" << endl;

   cin.ignore();

   return 0;
}

void testFunctionsClass() {
   //string infixVar = "ab+cd-*";
   //cout << getInfixExpression(infixVar);

   vector<string> radixVectorVar(3);
   int digitsPerNumber = 3;
   int radix = 36;
   radixVectorVar = { "ABC", "123", "XYZ" };
   radixSort(radixVectorVar, digitsPerNumber, radix);

   return;
}