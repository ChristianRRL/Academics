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

string radixVector(vector<string>&);
/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/


//-- Function/Class Implementations ---------------------------------
string getInfixExpression(const string& input) {

   // Initialize Stack object
   stack <string> heap;

   // Initialize postfix input
   string postfix = input;
   string infix;
   string character;

   // Check if the input size is less than or equal to 1
   if (postfix.size() <= 1) {
      infix = postfix;
      return infix;
   }

   // Iterate through the input
   for (string::iterator i = postfix.begin(); i != postfix.end(); i++) {
      string result;
      character = *i;

      // Check if the current character is an operator
      if (operatorCheck(character)) {
         // Create right operand
         string rightSide = heap.top();
         heap.pop();
         
         // Create left operand
         string leftSide = heap.top();
         heap.pop();

         // Append results into temp
         result = result + "(" + leftSide + *i + rightSide + ")";

         // Push results into stack
         heap.push(result);
      }

      // Check if the current character is not an operator
      if (!operatorCheck(character)) {
         heap.push(character);
      }
   }
   // Set infix to stack top
   infix = heap.top();
   heap.pop();

   return infix;
}

void radixSort(vector<string>& numbers, const int& digitsPerNumber,
   const int& radix) {
   // Initialize a queue for each possible number that can be in a number
   vector<queue<string>> buckets(radix);

   // Iterate over the digits of each number, starting with the least sig digit
   for (int i = digitsPerNumber - 1; i >= 0; i--) {



      // Iterate over each of the numbers in the vector and put them in buckets
      for (vector<string>::iterator j = numbers.begin(); j != numbers.end(); j++) {
         string stringI = *j;

         while (stringI.size() <= i) {
            stringI.insert(0, "0");
         }

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
   // In the end, we are modifying the original "numbers" var by
   // setting (numbers = buckets[0]) 
   // i.e. returning the last remaining queue at vector 0

   return;
}

bool operatorCheck(string& character) {
   return (character == "*" || character == "+" || character == "-" || character == "/");
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

string radixVector(vector<string>& vectorInput) {
   string result;
   //vector<string>::iterator j = numbers.begin(); j != numbers.end(); j++
   for (vector<string>::iterator i = vectorInput.begin(); i != vectorInput.end(); i++) {
      result = result + *i + " ";
   }

   return result;
}

#endif /*FUNCTIONS_H_*/

/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/
