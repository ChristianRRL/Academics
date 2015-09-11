/* main.h -----------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class circularLinkedList
-------------------------------------------------------------------*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "circularLinkedList.h"

using namespace std;

const int LARGE_LIST_SIZE = 1024;

void testListClass();

using namespace std;

int main() {
   srand(time(NULL));

   testListClass();

   cout << "finished" << endl;
   cin.ignore();

   return 0;
}

void testListClass() {
   int testSize = 5;

   // test the constructor
   cout << "Constructing an integer list." << endl;
   List<int> intList;
   cout << endl;

   // test the isEmpty function. Output an empty list, if applicable
   if (intList.isEmpty()) {
      cout << "Empty List: " << intList << endl;
   }
   cout << intList << endl;

   // test the copy constructor
   cout << "Constructing an integer list." << endl;
   List<int> copyList(intList);
   cout << endl;

   // test the isEmpty function on the copied list
   if (copyList.isEmpty()) {
      cout << "Empty List: " << copyList << endl;
   }
   cout << copyList << endl;

   // insert item into original list
   cout << "Inserting " << 0 << " at position " << 1 << ": ";
   if (intList.insert(0, 1)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Inserting " << 5 << " at position " << 10 << ": ";
   if (intList.insert(5, 10)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Inserting " << 5 << " at position " << 0 << ": ";
   if (intList.insert(5, 0)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Inserting " << 7 << " at position " << 0 << ": ";
   if (intList.insert(7, 0)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }
   
   cout << "Inserting " << 9 << " at position " << 2 << ": ";
   if (intList.insert(9, 2)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Inserting " << 13 << " at position " << 3 << ": ";
   if (intList.insert(13, 3)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Removing item at position " << 0 << ": ";
   if (intList.remove(0)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }
   cout << "Removing item at position " << 0 << ": ";
   if (intList.remove(0)) {
      cout << intList << endl;
   }
   else {
      cout << "removal failed!" << endl;
   }
   cout << "Removing item at position " << 1 << ": ";
   if (intList.remove(1)) {
      cout << intList << endl;
   }
   else {
      cout << "removal failed!" << endl;
   }
   cout << "Removing item at position " << -1 << ": ";
   if (intList.remove(-1)) {
      cout << intList << endl;
   }
   else {
      cout << "removal failed!" << endl;
   }
   cout << "Removing item at position " << 0 << ": ";
   if (intList.remove(0)) {
      cout << intList << endl;
   }
   else {
      cout << "removal failed!" << endl;
   }
   cout << "Removing item at position " << 0 << ": ";
   if (intList.remove(0)) {
      cout << intList << endl;
   }
   else {
      cout << "removal failed!" << endl;
   }
   cout << "Removing item at position " << -1 << ": ";
   if (intList.remove(-1)) {
      cout << intList << endl;
   }
   else {
      cout << "removal failed!" << endl;
   }
   cout << "Removing item at position " << 1 << ": ";
   if (intList.remove(1)) {
      cout << intList << endl;
   }
   else {
      cout << "removal failed!" << endl;
   }

   cout << "Inserting " << 13 << " at position " << 3 << ": ";
   if (intList.insert(13, 0)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Removing item at position " << 1 << ": ";
   if (intList.remove(1)) {
      cout << intList << endl;
   }
   else {
      cout << "removal failed!" << endl;
   }
   cout << "Removing item at position " << 2 << ": ";
   if (intList.remove(2)) {
      cout << intList << endl;
   }
   else {
      cout << "removal failed!" << endl;
   }
   cout << "Inserting " << 49 << " at position " << 3 << ": ";
   if (intList.insert(49, 3)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   // test the copy constructor
   cout << "Making a copy of the integer list via copy constructor" << endl;
   List<int> copiedList(intList);

   cout << "Original List: " << intList << endl;
   cout << "Copied List: " << copiedList << endl;

   cout << "Inserting " << 27 << " at position " << 1 << ": ";
   if (intList.insert(27, 1)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Original List: " << intList << endl;
   cout << "Copied List: " << copiedList << endl;


   cout << "Inserting " << 10101 << " at position " << 0 << ": ";
   if (intList.insert(10101, 0)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Original List: " << intList << endl;
   cout << "Copied List: " << copiedList << endl;


   cout << "Inserting " << 7 << " at position " << 3 << ": ";
   if (intList.insert(7, 3)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Original List: " << intList << endl;
   cout << "Copied List: " << copiedList << endl;

   cout << "Inserting " << 010110 << " at position " << 5 << ": ";
   if (intList.insert(010110, 5)) {
      cout << intList << endl;
   }
   else {
      cout << "insertion failed!" << endl;
   }

   cout << "Original List: " << intList << endl;
   cout << "Original Size: " << intList.getSize() << endl;
   cout << "Copied List: " << copiedList << endl;
   cout << "Copied Size: " << copiedList.getSize() << endl;

   cout << "JosephusAlgorithm Result: " << copiedList.runJosephusAlgorithm();
   cout << endl;

   List<int> newList;
   cout << "JosephusAlgorithm Result: " << newList.runJosephusAlgorithm();
   cout << endl;

   //cout << "JosephusAlgorithm Result: " << intList.runJosephusAlgorithm();
   //cout << endl;


   //int testSize = 5;

   //// test the constructor
   //cout << "Constructing an integer list." << endl;
   //List<int> intList;
   //cout << endl;

   //// test the isEmpty function. Output an empty list, if applicable
   //if (intList.isEmpty()) {
   //   cout << "Empty List: " << intList << endl;
   //}
   //cout << endl;

   //// test the insert function
   //for (int i = 0; i<testSize; ++i) {
   //   cout << "Inserting " << i << " at position " << (i / 2) << ": ";
   //   if (intList.insert(i, i / 2)) {
   //      cout << intList << endl;
   //   }
   //   else {
   //      cout << "insertion failed!" << endl;
   //   }
   //}
   //cout << endl;

   ////cin.ignore();

   ////List <int> intList2;

   ////for (int i = testSize; i > 0; --i) {
   ////   cout << "Inserting " << i << " at position " << i << ": ";
   ////   if (intList2.insert(i, i)) {
   ////      intList2.display(cout);
   ////      cout << endl;
   ////   }
   ////   else {
   ////      cout << "insertion failed!" << endl;
   ////   }
   ////}
   ////cin.ignore();

   ////// test the constructor
   ////cout << "Constructing an integer list." << endl;
   ////List<int> intList3;
   ////cout << endl;

   ////// test the insert function
   ////for (int i = 0; i < testSize; ++i) {
   ////   cout << "Inserting " << i << " at position " << (i) << ": ";
   ////   if (intList3.insert(i, i)) {
   ////      intList3.display(cout);
   ////      cout << endl;
   ////   }
   ////   else {
   ////      cout << "insertion failed!" << endl;
   ////   }
   ////}
   ////cout << endl;
   ////cin.ignore();

   ////List<int> intList4;
   ////cout << endl;
   ////intList4.insert(1, 1);
   ////intList4.display(cout);
   ////cout << endl;
   ////intList4.insert(2, 2);
   ////intList4.display(cout);
   ////cout << endl;
   ////intList4.insert(1, 1);
   ////intList4.display(cout);
   ////cout << endl;
   ////intList4.insert(1, 1);
   ////intList4.display(cout);
   ////cout << endl;
   ////intList4.insert(1, 1);
   ////intList4.display(cout);
   ////cout << endl;
   ////intList4.insert(1, 1);
   ////intList4.display(cout);
   ////cout << endl;
   ////intList4.insert(2, 1);
   ////intList4.display(cout);
   ////cout << endl;


   ////cin.ignore();

   //////intList4 = intList;
   //////cout << intList4 << endl;

   //////cin.ignore();

   ////List<int> intList5(intList);
   ////cout << intList5;

   ////cin.ignore();

   ////List<int> intList6;
   ////intList6 = intList2;
   ////cout << intList6;

   //cin.ignore();
   //// test the = operator
   //cout << "Making a copy of the integer list." << endl;
   //List<int> copyList = intList;
   //cout << "original list: " << intList << endl;
   //cout << "copied list: " << copyList << endl;
   //for (int i = 0; i<testSize; ++i) {
   //   cout << "Inserting " << i << " at position " << (i / 2) << " into ";
   //   int index = rand() % 2;
   //   if (index) {
   //      cout << "original list: ";
   //      if (intList.insert(i, i / 2)) {
   //         cout << endl;
   //      }
   //      else {
   //         cout << "insertion failed!" << endl;
   //      }
   //   }
   //   else {
   //      cout << "copied list: ";
   //      if (copyList.insert(i, i / 2)) {
   //         cout << endl;
   //      }
   //      else {
   //         cout << "insertion failed!" << endl;
   //      }
   //   }
   //   cout << "\toriginal list: " << intList << endl;
   //   cout << "\tcopied list: " << copyList << endl;
   //}
   //cout << endl;

   //// test the isEmpty function. Output yes/no as applicable
   //cout << "List empty? " << (intList.isEmpty() ? "Yes" : "No") << endl << endl;

   //// continue testing the insert function
   //cout << "Try to insert at position -1: ";
   //if (intList.insert(0, -1)) {
   //   cout << intList << endl;
   //}
   //else {
   //   cout << "insertion failed!" << endl;
   //}

   //cin.ignore();

   //int size = intList.getSize();
   //cout << "Try to insert at position " << (size + 1) << ": ";
   //if (intList.insert(-1, size + 1)) {
   //   cout << intList << endl;
   //}
   //else {
   //   cout << "insertion failed!" << endl;
   //}

   //// test the remove function
   //while (!intList.isEmpty()) {
   //   int index = rand() % intList.getSize();

   //   cout << "Removing the element at position: " << index << ": ";
   //   intList.remove(index);
   //   cout << intList << endl;
   //}
   //cout << "Original List is empty!" << endl;
   //cout << "Copied List: " << copyList << endl;

   //// test the insert function, up to the CAPACITY of the list
   //int capacity = intList.getCapacity();
   //if (capacity<0) {
   //   capacity = LARGE_LIST_SIZE;
   //}
   //cout << "Inserting " << capacity << " integers" << endl;
   //for (int i = 0; i<capacity; ++i) {
   //   intList.insert(i, i);
   //}
   //// one more insertion
   //cout << "Attempting to insert one more integer: ";
   //if (intList.insert(-1, 0)) {
   //   cout << "insertion succeeded!" << endl;
   //}
   //else {
   //   cout << "insertion failed!" << endl;
   //}

   //cin.ignore();
}
