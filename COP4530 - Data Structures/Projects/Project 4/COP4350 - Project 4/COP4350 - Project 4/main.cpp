/* main.h -----------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class circularLinkedList
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
   getInfixExpression("YOLO+MOFO");

   return;
}