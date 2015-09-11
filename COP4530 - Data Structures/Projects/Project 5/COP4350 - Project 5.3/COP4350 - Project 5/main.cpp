/* main.h -----------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class bst
-------------------------------------------------------------------*/

#include "bst.h"

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
   //bst1.insert(77);
   //bst1.insert(77);
   //bst1.insert(99);
   //bst1.insert(44);
   bst1.insert(22);
   //bst1.insert(66);
   bst1.insert(11);

}