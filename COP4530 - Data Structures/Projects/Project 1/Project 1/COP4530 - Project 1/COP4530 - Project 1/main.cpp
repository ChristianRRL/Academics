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
   //if (magicSquareDefault.isMagicSquare())
   //{
   //   //ofstream fout("output.txt");
   //   //fout << magicSquareDefault << endl;
   //}

   magicSquareDefault.debug();

   MagicSquare magicSquare7(7);
   magicSquare7.debug();
   MagicSquare magicSquare9(9);
   magicSquare9.debug();
   MagicSquare magicSquare10(10);
   magicSquare10.debug();

   return 0;
}