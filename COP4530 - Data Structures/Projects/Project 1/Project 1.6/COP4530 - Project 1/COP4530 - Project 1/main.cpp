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

   //MagicSquare magicSquareDefault;
   //cout << magicSquareDefault << endl;

   //cout << magicSquareDefault.rotate();

   //cin >> magicSquareDefault;
   //cout << magicSquareDefault;
   //cout << "Is magicSquareDefault still a magic square?\n";
   //verification(magicSquareDefault);

   //MagicSquare ms1;

   //MagicSquare ms3(3);

   //ms1 = ms3;
   //ms3.display();
   //system("pause");

   //cout << ms3.rotate();



   MagicSquare magicSquareDefault;
   cout << "magicSquareDefault(5):\n";
   verification(magicSquareDefault);
   cout << &magicSquareDefault << endl;


   MagicSquare magicSquare2(magicSquareDefault);
   magicSquare2.rotate();
   cout << "is it working now?\n";
   cout << magicSquare2;
   system("pause");
   cout << "is it working again?\n";
   cout << magicSquare2;
   system("pause");
   cout << "is it working a third time?\n";
   magicSquareDefault.rotate();
   cout << magicSquareDefault;
   system("pause");

   cout << "\nOk, let's try to make 2 magic square objects:\n";
   MagicSquare ms1(3);
   MagicSquare ms2(7);

   cout << "Let's make them equal each other:\n";
   ms1 = ms2;

   cout << "ms1:\n";
   cout << ms1;
   cout << "rotate ms1:\n";
   ms1.rotate();
   cout << ms1;
   system("pause");

   ms1.rotate();
   cout << ms1;
   //magicSquareDefault.rotate();
   //cout << "magicSquareDefault.rotate():\n";
   //verification(magicSquareDefault.rotate());

   //MagicSquare magicSquareSame(7);
   //cout << "magicSquareSame(7):\n";
   //verification(magicSquareSame);

   //MagicSquare magicSquare3(3);
   //cout << "magicSquare3(3):\n";
   //verification(magicSquare3);

   //cout << "magicSquare3.rotate():\n";
   //magicSquare3.rotate();
   //system("pause");
   //cout << magicSquare3;
   //system("pause");
   //magicSquare3.rotate().rotate();
   //cout << magicSquare3;
   ////cout << magicSquare3.rotate();
   ////cout << endl;

   cout << "Did this really work???\n";

   system("pause");
   //magicSquareSame = magicSquare3.rotate();
   //cout << "magicSquareSame = magicSquare3.rotate:\n";
   //verification(magicSquareSame);

   //cout << "magicSquareSame = magicSquareDefault.rotate():\n";
   //magicSquareSame = magicSquareDefault.rotate();
   //verification(magicSquareSame);


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