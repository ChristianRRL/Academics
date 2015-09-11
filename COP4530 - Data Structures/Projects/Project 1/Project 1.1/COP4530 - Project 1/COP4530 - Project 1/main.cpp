/* main.cpp ----------------------------------------------------
author: Christian A. Rodriguez
Main function to test each of the member functions of
MagicSquare class
--------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include "magicSquare.h"

using namespace std;

int main()
{

   //-- Question 2a: Create default magic square object
   MagicSquare magicSquareDefault;
   magicSquareDefault.debug();
   cout << "Is magicSquareDefault a magic square?\n";
   cout << magicSquareDefault.isMagicSquare() << endl;

   MagicSquare magicSquare7(7);
   magicSquare7.debug();
   cout << "Is magicSquareDefault a magic square?\n";
   cout << magicSquareDefault.isMagicSquare() << endl;
   cout << endl;

   MagicSquare magicSquare9(9);
   magicSquare9.debug();
   cout << "Is magicSquareDefault a magic square?\n";
   cout << magicSquareDefault.isMagicSquare() << endl;
   cout << endl;

   //MagicSquare magicSquare10(10);
   //magicSquare10.debug();

   // Testing isMagicSquare now
   return 0;
}