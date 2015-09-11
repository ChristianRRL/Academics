/* main.h -----------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class bst
-------------------------------------------------------------------*/

#include "bst.h"

using namespace std;

void testBST();

int main() {
   testBST();

   cout << "\nfinished" << endl;

   cin.ignore();

   return 0;
}

void testBST() {
   cout << "Testing BinarySearchTree: " << endl;
   BinarySearchTree<int> bst1;
   bst1.insert(55);
   bst1.insert(55);
   bst1.insert(33);
   bst1.insert(33);
   bst1.insert(77);
   bst1.insert(77);
   bst1.insert(99);
   bst1.insert(44);
   bst1.insert(22);
   bst1.insert(66);
   bst1.insert(11);
   bst1.insert(5);
   bst1.insert(16);
   bst1.insert(27);
   bst1.insert(38);
   bst1.insert(49);
   bst1.insert(50);
   bst1.insert(61);
   bst1.insert(72);
   bst1.insert(83);
   bst1.insert(94);
   bst1.insert(105);
   bst1.insert(1);

   cout << "The minimum location is: " << bst1.getMinimum() << endl;
   cout << "The maximum location is: " << bst1.getMaximum() << endl;
   cout << endl;

   bst1.displayGraphic(cout);
}