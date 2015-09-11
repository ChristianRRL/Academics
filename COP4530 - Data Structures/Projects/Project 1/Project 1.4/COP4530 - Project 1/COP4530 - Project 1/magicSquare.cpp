/* magicSquare.cpp --------------------------------------------
author: Christian A. Rodriguez
Implementation file of the class library for the class
magicSquare.
--------------------------------------------------------------*/

#include <iostream>
#include <cassert>
#include "magicSquare.h"

using namespace std;

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
MagicSquare::MagicSquare(const MagicSquare& original)
   : size(original.size)
{
   generateMagicSquare();
}

//-- Destructor
MagicSquare::~MagicSquare()
{
   ////Delete Matrix
   //for (i = 0; i < rows; i++)
   //{
   //   delete[] matrix[i];
   //}
   //delete matrix;
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

         if (i < 1 || i >(rows - 2))
            i = rows - 2;
         if (j < 1 || j >(columns - 2))
            j = 1;
      }
   }

   // Initialize array of size rows x columns with 0
   array = new int[size*size];
   for (k = 0; k < size*size; k++)
   {
      array[k] = 0;
   }

   // Fill in array elements with matrix elements
   k = 0;
   while (k < (size*size))
   {
      for (i = 1; i <= size; i++)
      {
         for (j = 1; j <= size; j++)
         {
            array[k] = matrix[i][j];
            k++;
         }
      }
   }
}

//-- Overloading Function
ostream& operator<<(ostream& output, const MagicSquare& ms)
{
   int i = 1;
   int j = 1;

   // Output magic square matrix size
   output << ms.size << endl;

   // Output magic square matrix elements
   for (i = 1; i <= ms.size; i++)
   {
      for (j = 1; j <= ms.size; j++)
      {
         output << ms.matrix[i][j] << " ";
      }
      output << endl;
   }

   return output;
}

//-- Overloading Function
istream& operator>>(istream& input, MagicSquare& ms)
{
   //int i = 1;
   //int j = 1;

   //// Input magic square size
   //input >> ms.size;

   //// Create magic square object ???


   //// Input magic square matrix elements
   //for (i = 1; i <= ms.size; i++)
   //{
   //   for (j = 1; j <= ms.size; j++)
   //   {
   //      input >> ms.matrix[i][j] >> " ";
   //   }
   //   input >> "\n";
   //}
   //input >> "\n";

   return input;
}

//-- Overloading Function
const MagicSquare& MagicSquare::operator=(const MagicSquare& right)
{
   //cout << "size: " << size << endl;
   //system("pause");
   //cout << "right.size: "<< right.size << endl;
   //system("pause");
   //cout << "*this: " << *this << endl;
   //system("pause");
   //cout << "&right: " << &right << endl;
   //system("pause");
   //cout << "right: " << right << endl;
   //system("pause");
   //cout << "this: " << this << endl;
   //system("pause");


   int i = 0;
   int j = 0;
   int rows = size + 2;
   int columns = size + 2;

   if (&right != this)
   {
      if (size != right.size)
      {
         //delete[] matrix;
         // Release space
         for (i = 0; i < rows; i++)
         {
            delete[] matrix[i];
         }
         delete[] matrix;

         // Resize this object
         size = right.size;
         rows = right.size + 2;
         columns = right.size + 2;

         // Initialize matrix of size rows x columns
         matrix = new int*[rows];
         for (i = 0; i < rows; i++)
            matrix[i] = new int[columns];

         // Initialize borders/padding with 0
         for (i = 0; i < rows; i++)
         {
            for (j = 0; j < columns; j++)
            {
               matrix[i][j] = 0;
            }
         }
      }
      // Copy array into object
      for (i = 1; i <= size; i++)
      {
         for (j = 1; j <= size; j++)
         {
            matrix[i][j] = right.matrix[i][j];
         }
      }
   }

   return *this;
}


//-- Verification Function
bool MagicSquare::isMagicSquare()
{
   int i = 1;
   int j = 1;
   int k = 1;
   //int counts = 0;
   //int rows = size;
   //int columns = size;
   int magicSquareSum = size*(size*size + 1) / 2;
   int temp = 0;
   int count = 0;
   int sumRow = 0;
   int sumCol = 0;
   int sumDiag1 = 0;
   int sumDiag2 = 0;

   // First Check all row/column sums equal magicSquareSum
   for (i = 1; i <= size; i++)
   {
      sumRow = 0;
      sumCol = 0;

      for (j = 1; j <= size; j++)
      {
         sumRow += matrix[i][j];
         //cout << "\nsumRow += matrix[" << i << "][" << j << "]: " << sumRow << endl;
         //system("pause");
         sumCol += matrix[j][i];
         //cout << "\nsumCol += matrix[" << j << "][" << i << "]: " << sumCol << endl;
         //system("pause");
      }
      
      if (sumRow != magicSquareSum || sumCol != magicSquareSum)
         return false;
   }

   // Then check that both diagonals also equal magicSquareSum
   for (k = 1; k <= size; k++)
   {
      sumDiag1 += matrix[k][k];
      //cout << "\nsumDiag1 += matrix[" << k << "][" << k << "]: " << sumDiag1 << endl;
      //system("pause");
      sumDiag2 += matrix[(size + 1) - k][k];
      //cout << "\nsumDiag2 += matrix[" << (size + 1) - k << "][" << k << "]: " << sumDiag2 << endl;
      //system("pause");
   }

   if (sumDiag1 != magicSquareSum || sumDiag2 != magicSquareSum)
      return false;
   

   // Lastly make sure that no number is used more than once
   for (k = 0; k < (size*size); k++)
   {
      temp = array[k];

      for (i = 1; i <= size; i++)
      {
         for (j = 1; j <= size; j++)
         {
            if (temp == matrix[i][j])
               count++;
         }
      }

      if (count != 1)
         return false;
      else
         count = 0;
   }

   return true;

   //return false;
}


//-- Rotation Function
MagicSquare MagicSquare::rotate()
{
   int i = 1;
   int j = 1;

   for (i = 1; i <= size; i++)
   {
      for (j = 1; j <= size; j++)
      {

      }
   }

   return *this;
}


void MagicSquare::display()
{
   //cout << isMagicSquare();
   int i = 1;
   int j = 1;

   // Display size of magic square matrix
   cout << size << endl;

   // Display each magic square matrix element
   for (i = 1; i <= size; i++)
   {
      for (j = 1; j <= size; j++)
      {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;

   system("pause");

   return;
}


void MagicSquare::debug()
{
   int k = 0;

   // Display each array element
   for (k = 0; k < (size*size); k++)
      cout << array[k] << " ";
   cout << endl;

   ////cout << isMagicSquare();
   //int i = 1;
   //int j = 1;
   //int rows = size + 2;
   //int columns = size + 2;

   //// Display each matrix element
   //for (i = 0; i < rows; i++)
   //{
   //   for (j = 0; j < columns; j++)
   //   {
   //      cout << matrix[i][j] << " ";
   //   }
   //   cout << endl;
   //}
   system("pause");

   return;
}