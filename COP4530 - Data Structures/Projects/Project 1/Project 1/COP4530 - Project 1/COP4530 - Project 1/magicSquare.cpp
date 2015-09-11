/* magicSquare.cpp --------------------------------------------
   author: Christian A. Rodriguez
   Implementation file of the class library for the class 
   magicSquare.
--------------------------------------------------------------*/

#include <iostream>
//#include <string>    // string
#include <cassert>
using namespace std;

#include "magicSquare.h"

//-- Default Constructor
MagicSquare::MagicSquare()
: size(5)
{
   generateMagicSquare();
}

//-- Explicit-value Constructor
MagicSquare::MagicSquare(const int& n)
{
   assert((n % 2) != 0);   // Check preconditions
   size = n;
   generateMagicSquare();
}

//-- Copy Constructor
MagicSquare::MagicSquare(const MagicSquare&)
{

}

//-- Generator Function
void MagicSquare::generateMagicSquare()
{
   int i = 0;
   int j = 0;
   int k = 0;
   int rows = size + 2;    // Used for borders/padding
   int columns = size + 2; // Used for borders/padding
   int midpoint = (size + 1) / 2;

   // Initialize matrix of size rows x columns
   matrix = new int*[rows];
   for (i = 0; i < rows; i++)
      matrix[i] = new int[columns];

   debug();

   // Initialize borders/padding with 0
   for (i = 0; i < rows; i++)
   {
      for (j = 0; j < columns; j++)
      {
         matrix[i][j] = 0;
      }
   }

   // Initialize the usable matrix with -1
   for (i = 1; i <= rows - 2; i++)
   {
      for (j = 1; j <= columns - 2; j++)
      {
         matrix[i][j] = -1;
      }
   }
   
   debug();

   // Fill in matrix with integer elements
   for (i = 1, j = midpoint, k = 1; k <= (size * size); k++)
   {
      matrix[i][j] = k;

      if (matrix[(i - 1)][(j + 1)] >= 1 || (i == 1 && j == (columns - 2)))
         i++;
      else
      {
         i--;
         j++;

         if (i < 1 || i > (rows - 2))
            i = rows - 2;
         if (j < 1 || j > (columns - 2))
            j = 1;
      }
   }
   
   debug();

   ////Delete Matrix
   //for (i = 0; i < rows; i++)
   //{
   //   delete[] matrix[i];
   //}
   //delete matrix;
}

//-- Overloading Function
ostream& operator<<(ostream& output, MagicSquare ms)
{
   return output;
}

//-- Overloading Function
istream& operator>>(istream& input,MagicSquare ms)
{
   return input;
}

//-- Overloading Function
//const MagicSquare& MagicSquare::operator=(const MagicSquare& right)
//{
//
//}

//-- Verification Function
bool MagicSquare::isMagicSquare()
{
   return false;
}

//-- Rotation Function
MagicSquare MagicSquare::rotate()
{
   return *this;
}

void MagicSquare::debug()
{
   int i = 1;
   int j = 1;
   int rows = size + 2;
   int columns = size + 2;

   // Display each matrix element
   for (i = 0; i < rows; i++)
   {
      for (j = 0; j < columns; j++)
      {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }
   system("pause");

   return;
}