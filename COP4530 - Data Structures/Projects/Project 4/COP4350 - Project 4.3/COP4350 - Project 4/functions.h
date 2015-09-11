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
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>
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
      string temp;
      letter = postfix.at(i);

      if (operatorCheck(letter)) {
         string rightOperand = stringStack.top();
         stringStack.pop();

         string leftOperand = stringStack.top();
         stringStack.pop();

         // Append results into temp
         temp = temp + "(" + leftOperand + letter + rightOperand + ")";

         //temp.append("(");
         //temp.append(leftOperand);
         //temp.append(letter);
         //temp.append(rightOperand);
         //temp.append(")");

         stringStack.push(temp);
      }

      if (!operatorCheck(letter)) {
         stringStack.push(letter);
      }
      //if (isalpha(postfix.at(i))) {
      //   stringStack.push(letter);
      //}

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
   // Initialize infix output
   string infix = stringStack.top();

   return infix;
}

void radixSort(vector<string>& numbers, const int& digitsPerNumber,
   const int& radix) {
   // Initialize a queue for each possible number that can be in a number
   vector<queue<string>> buckets(radix);

   //buckets[0].push("ABC");
   //buckets[1].push("123");
   //buckets[2].push("Move Bitch");
   //buckets[2].push("Get out the way");
   //buckets[2].push("Get out the way bitch");
   //buckets[2].push("Get out the way");
   //buckets[8].push("ABC");
   //buckets[9].push("123");
   //buckets[10].push("asdf");
   //buckets[12].push("wtf");
   //buckets[20].push("is this working");
   //buckets[35].push("THIS IS THE END");

   //for (int i = 0; i < radix; i++) {
   //   if (!buckets[i].empty()) {
   //      cout << buckets[i].front() << endl;
   //      while (buckets[i].size() > 1) {
   //         buckets[i].pop();
   //         cout << buckets[i].front() << endl;
   //      }

   //   }
   //}

   //for (vector<queue<string>>::iterator j = buckets.begin(); j != buckets.end(); j++) {
   //   buckets[j] = 0;
   //}


   // Iterate over the digits of each number, starting with the least sig digit
   for (int i = digitsPerNumber - 1; i >= 0; i--) {
      // Iterate over each of the numbers in the vector and put them in buckets
      for (vector<string>::iterator j = numbers.begin(); j != numbers.end(); j++) {
         string stringI = *j;
         //cout << stringI[i] << " ";
         int digitI = stringI[i];
         digitI = asciiToInt(digitI);
         //cout << digitI << endl;

         buckets[digitI].push(stringI);
         cout << buckets[digitI].front();
      }
      cout << endl;
      // Iterate over each of the buckets and pull out the numbers to put them back into numbers
      for (int j = 0; j < radix; j++) {
         cout << numbers[j] << endl;
         for (int l = 0; !buckets[j].empty(); l++) {
               numbers[l] = buckets[j].front();
               buckets[j].pop();
         }
      }
         
         //numbers = buckets[i].pop();
      cout << endl;
   }

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
