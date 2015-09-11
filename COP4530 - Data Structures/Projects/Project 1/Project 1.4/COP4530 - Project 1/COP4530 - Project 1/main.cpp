/* main.cpp ----------------------------------------------------
author: Christian A. Rodriguez
Main function to test each of the member functions of
MagicSquare class
--------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include "magicSquare.h"

using namespace std;

void verification(MagicSquare);
void rotatation(MagicSquare&, MagicSquare);

int main()
{

   //-- Question 2a: Create default magic square object
   MagicSquare magicSquareDefault;
   cout << "magicSquareDefault(5):\n";
   verification(magicSquareDefault);

   MagicSquare magicSquareSame(7);
   cout << "magicSquareSame(7):\n";
   verification(magicSquareSame);

   magicSquareSame = magicSquareDefault.rotate();
   verification(magicSquareSame);


   ////magicSquareSame.operator=(magicSquareDefault);
   ////cout << "magicSquareDefault.operator=(magicSquareSame):\n";
   //magicSquareSame = magicSquareDefault;
   //cout << "magicSquareSame = magicSquareDefault:\n";
   //verification(magicSquareSame);

   //MagicSquare magicSquare9(9);
   //cout << "magicSquare9(9):\n";
   //verification(magicSquare9);

   //magicSquareDefault = magicSquare9;
   //cout << "magicSquareDefault = magicSquare9:\n";
   //verification(magicSquareDefault);

   ////magicSquareDefault.operator=(magicSquare9);
   ////magicSquareDefault = magicSquare9;
   ////cout << "magicSquareDefault.operator=(magicSquare9):\n";
   ////verification(magicSquareDefault);
   ////cin >> magicSquareDefault;
   ////verification(magicSquareDefault);

   ////-- Question 2b: Create magic squares of sizes
   ////-- 7,9,11,13,15,17,19,21,23,25
   //MagicSquare magicSquare7(7);
   //verification(magicSquare7);

   //MagicSquare magicSquare9(9);
   //verification(magicSquare9);

   //MagicSquare magicSquare11(11);
   //verification(magicSquare11);

   //MagicSquare magicSquare13(13);
   //verification(magicSquare13);

   //MagicSquare magicSquare15(15);
   //verification(magicSquare15);

   //MagicSquare magicSquare17(17);
   //verification(magicSquare17);

   //MagicSquare magicSquare19(19);
   //verification(magicSquare19);

   //MagicSquare magicSquare21(21);
   //verification(magicSquare21);

   //MagicSquare magicSquare23(23);
   //verification(magicSquare23);

   //MagicSquare magicSquare25(25);
   //verification(magicSquare25);

   // Testing isMagicSquare now

   system("pause");
   return 0;
}

void verification(MagicSquare ms)
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

void rotation(MagicSquare ms1, MagicSquare ms2)
{
   // Fill in Code
   // eg. ms2 = ms1.rotate();
}