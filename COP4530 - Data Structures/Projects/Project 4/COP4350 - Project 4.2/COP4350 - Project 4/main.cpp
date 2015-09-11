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
   radixVectorVar = { "123", "456", "789" };
   radixSort(radixVectorVar, 3, 10);

   return;
}