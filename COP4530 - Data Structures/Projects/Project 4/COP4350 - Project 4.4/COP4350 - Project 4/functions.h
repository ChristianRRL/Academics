/* functions.h ------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class functions
-------------------------------------------------------------------*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iterator>

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

int asciiToInt(int&);
/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/

//-- Function/Class Implementations ---------------------------------
string getInfixExpression(const string& input) {

   // Initialize Stack object
   stack <string> stringStack;

   // Initialize postfix input
   string postfix = input;
   string letter;

   // Iterate through the stringInput
   for (int i = 0; i < postfix.length(); i++) {
      string result;
      letter = postfix.at(i);

      if (operatorCheck(letter)) {
         string rightOperand = stringStack.top();
         stringStack.pop();

         string leftOperand = stringStack.top();
         stringStack.pop();

         // Append results into temp
         result = result + "(" + leftOperand + letter + rightOperand + ")";

         stringStack.push(result);
      }

      if (!operatorCheck(letter)) {
         stringStack.push(letter);
      }
   }
   // Initialize infix output
   string infix = stringStack.top();

   return infix;
}

void radixSort(vector<string>& numbers, const int& digitsPerNumber,
   const int& radix) {
   // Initialize a queue for each possible number that can be in a number
   vector<queue<string>> buckets(radix);

   // Debugging
   for (int i = 0; i < numbers.size(); i++) {
      cout << numbers[i] << " ";
   }
   cout << endl;

   // Iterate over the digits of each number, starting with the least sig digit
   for (int i = digitsPerNumber - 1; i >= 0; i--) {
      // Iterate over each of the numbers in the vector and put them in buckets
      for (vector<string>::iterator j = numbers.begin(); j != numbers.end(); j++) {
         string stringI = *j;
         int digitI = stringI[i];
         digitI = asciiToInt(digitI);
         buckets[digitI].push(stringI);
      }
      // Iterate over each of the buckets and pull out the numbers to put them back into numbers
      for (int j = 0, k = 0; j < radix; j++) {
         while (!buckets[j].empty()) {
            numbers[k] = buckets[j].front();
            buckets[j].pop();
            k++;
         }
      }
   }

   // Debugging
   for (int i = 0; i < numbers.size(); i++) {
      cout << numbers[i] << " ";
   }
   cout << endl;

   // In the end, we are modifying the original "numbers" var by
   // setting (numbers = buckets[0]) 
   // i.e. returning the last remaining queue at vector 0

   return;
}

bool operatorCheck(string& letter) {
   return (letter == "*" || letter == "+" || letter == "-" || letter == "/");
}

int asciiToInt(int& character) {
   int integer = -1;
   
   if (character >= 48 && character <= 57) {
      integer = character - 48;
      return integer;
   }
   if (character >= 65 && character <= 90) {
      integer = character - 55;
      return integer;
   }

   return integer;
}


#endif /*FUNCTIONS_H_*/

/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/
