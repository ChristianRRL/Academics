/* magicSquare.h -----------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class magicSquare.
--------------------------------------------------------------*/

#ifndef MAGICSQUARE_H_
#define MAGICSQUARE_H_

#include <iostream>
using namespace std;

class MagicSquare
{

public:

   //-- Constructors
   MagicSquare();
   /*-----------------------------------------------------------
   Default constructor
   Precondition: None.
   Postcondition: MagicSquare object has been constructed
   with a 5 x 5 matrix.
   -----------------------------------------------------------*/

   MagicSquare(const int&);
   /*-----------------------------------------------------------
   Explicit value constructor
   Precondition: Takes an odd integer n as a parameter.
   Postcondition: MagicSquare object has been constructed
   with a n x n matrix. (You should assume that n will
   always be an odd integer).
   -----------------------------------------------------------*/

   MagicSquare(const MagicSquare&);
   // ex1. MyClass (const MyClass& other);
   // ex2. MyClass (MyClass& other);
   /*-----------------------------------------------------------
   Copy constructor
   Precondition: There exists a current magic square object.
   Postcondition: A new copy of the existing magic square
   object is created.
   -----------------------------------------------------------*/

   //-- Overloading Operators
   friend ostream& operator<<(ostream&, const MagicSquare);
   /*-----------------------------------------------------------
   Overload the << to output the magic square to an ostream
   Precondition: MagicSquare object should exist.
   Postcondition: Magic Squares are output on n + 1 lines.
   The first list should indicate n, the size of the magic
   square.
   -----------------------------------------------------------*/

   friend istream& operator>>(istream&, MagicSquare);
   /*-----------------------------------------------------------
   Overload the >> to input a magic square from istream
   Precondition: None.
   Postcondition: Magic Square is input in the same format as
   it was output.
   -----------------------------------------------------------*/

   //const MagicSquare& operator=(const MagicSquare&);
   /*-----------------------------------------------------------
   Overload the = to assign existing magic squares to new
   magic squares. (Alternative to copy constructor)
   Precondition: None.
   Postcondition: Magic Square is input in the same format as
   it was output.
   -----------------------------------------------------------*/


   //-- Verification Function
   bool isMagicSquare();
   /*-----------------------------------------------------------
   Tests whether the object is a magic square
   Precondition: None.
   Postcondition: Function returns true if the object meets
   the criteria for a magic square and false otherwise.
   (This is useful to verify that a magic square that was
   input is using the overloaded >> is valid).
   -----------------------------------------------------------*/

   //-- Rotation Function
   MagicSquare rotate();
   /*-----------------------------------------------------------
   Creates new MagicSquare object that rotates and rotates it
   90 degrees clockwise
   Precondition: n x n matrix is a magic square.
   Postcondition: Create a new magic square object that
   rotates the calling magic square object
   -----------------------------------------------------------*/
   void display();
   /*-----------------------------------------------------------
   Displays current magic square object
   Precondition: None.
   Postcondition: Displays magic square.
   -----------------------------------------------------------*/
   
   void debug();
   /*-----------------------------------------------------------
   Helps debug the program.
   Precondition: None.
   Postcondition: This function has no specific purpose
   other than to help debug the program.
   -----------------------------------------------------------*/

private:

   //-- Generator Function
   void generateMagicSquare();
   /*-----------------------------------------------------------
   Create a magic square
   Precondition: None.
   Postcondition: Generate an n x n matrix in which each of
   the integers 1,2,3,...,n^2 appears exactly once on all
   column sums, row sums, and diagonal sums are equal.
   -----------------------------------------------------------*/

   //-- Data Members
   int size;
   int **matrix;
   int *array;
}; // end of class declaration

#endif