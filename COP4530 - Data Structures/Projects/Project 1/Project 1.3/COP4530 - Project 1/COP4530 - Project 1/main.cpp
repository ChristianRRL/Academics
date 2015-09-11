/* main.cpp ----------------------------------------------------
author: Christian A. Rodriguez
Main function to test each of the member functions of
MagicSquare class
--------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include "magicSquare.h"

using namespace std;

void verify(MagicSquare);

int main()
{

   //-- Question 2a: Create default magic square object
   MagicSquare magicSquareDefault;
   verify(magicSquareDefault);

   //cin >> magicSquareDefault;
   //verify(magicSquareDefault);

   //-- Question 2b: Create magic squares of sizes
   //-- 7,9,11,13,15,17,19,21,23,25
   MagicSquare magicSquare7(7);
   verify(magicSquare7);

   MagicSquare magicSquare9(9);
   verify(magicSquare9);

   MagicSquare magicSquare11(11);
   verify(magicSquare11);

   MagicSquare magicSquare13(13);
   verify(magicSquare13);

   MagicSquare magicSquare15(15);
   verify(magicSquare15);

   MagicSquare magicSquare17(17);
   verify(magicSquare17);

   MagicSquare magicSquare19(19);
   verify(magicSquare19);

   MagicSquare magicSquare21(21);
   verify(magicSquare21);

   MagicSquare magicSquare23(23);
   verify(magicSquare23);

   MagicSquare magicSquare25(25);
   verify(magicSquare25);

   // Testing isMagicSquare now

   system("pause");
   return 0;
}

void verify(MagicSquare ms)
{
   //static int count = 0;

   if (ms.isMagicSquare())
   {
      ofstream outputFile;
      //outputFile.open("output.txt", ofstream::out, ofstream::trunc);
      outputFile.open("output.txt",fstream::app);
      outputFile << ms << endl;
      outputFile.close();
      //ofstream fout("output.txt");
      //fout << magicSquareDefault.display() << endl;
      cout << ms << endl;
   }

   system("pause");

   return;
}