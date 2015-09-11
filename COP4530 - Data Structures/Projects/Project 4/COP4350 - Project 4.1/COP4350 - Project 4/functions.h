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
#include <cctype>

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

bool operatorCheck(string&);
/*-------------------------------------------------------------------
Purpose: 
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/

//-- Function/Class Implementations ---------------------------------
string getInfixExpression(const string& input) {   // input?

   // Initialize Stack object
   stack <string> stringStack;

   // Initialize String variables
   string postfix = input;
   string letter;

   // Iterate through the stringInput
   for (int i = 0; i < postfix.length(); i++) {
      string temp;
      letter = postfix.at(i);

      if (postfix.at(i) == '+' || postfix.at(i) == '-' || postfix.at(i) == '*' || postfix.at(i) == '/') {
      //if (operatorCheck(letter)) {
         string rightOperand = stringStack.top();
         stringStack.pop();

         string leftOperand = stringStack.top();
         stringStack.pop();

         temp.append("(");
         temp.append(leftOperand);
         temp.append(letter);
         temp.append(rightOperand);
         temp.append(")");

         stringStack.push(temp);
      }

      if (isalpha(postfix.at(i))) {
         stringStack.push(letter);
      }

      //letter = stringInput.at(i);
      //stringStack.push(letter);

      //if (operatorCheck(letter)) {
      //   letter = stringInput.at(i + 1);
      //   if (operatorCheck(letter)) {

      //   }
      //}

      //if (letter != "-" || letter != "+" || letter != "*" || letter != "/") {
      //   stringStack.push(letter);
      //}
      //else
      //{
      //   temp2 = stringStack.top();
      //   stringStack.pop();
      //   temp1 = stringStack.top();
      //   stringStack.pop();
      //   result = temp1 + letter + temp2;
      //   stringStack.push(result);
      //}
   }
   string infix = stringStack.top();

   return infix;
}

void radixSort(vector<string>& numbers, const int& digitsPerNumber,
   const int& radix) {

}

bool operatorCheck(string& letter) {
   return (letter == "*" || letter == "+" || letter == "-" || letter == "/");
}


#endif /*FUNCTIONS_H_*/

/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/
