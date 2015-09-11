/* functions.h ------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class functions
-------------------------------------------------------------------*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;


//-- Function/Class Declarations ------------------------------------
string getInfixExpression(const string&);
/*-------------------------------------------------------------------
Purpose: Convert a postfix expression to the corresponding fully-
parenthesized infix expression. The only characters of the input 
string will be either operators (eg. +, -, *, /) or operands 
(lowercase letters of the English alphabet). The only container that 
you are permitted to use to implement this function is one STL stack 
container.
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/

void radixSort(vector<string>&, const int&, const int&);
/*-------------------------------------------------------------------
Purpose: Implement the Radix Sort Algorithm. The only container(s) 
you are permitted to use is one STL vector container to hold r STL 
queue containters. (To walk over the numbers vector, you must use an 
STL iterator).
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/


//-- Function/Class Implementations ---------------------------------
string getInfixExpression(const string& input) {   // input?

   // Initialize Stack object
   stack <string> stringStack;

   // Initialize String object
   string stringInput = input;
   string temp = 0;

   for (int i = 0; i < stringInput.length(); i++) {
      cout << stringInput.at(i);
   }

   return stringInput;
}

void radixSort(vector<string>& numbers, const int& digitsPerNumber,
   const int& radix) {

}

#endif /*FUNCTIONS_H_*/

/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/
