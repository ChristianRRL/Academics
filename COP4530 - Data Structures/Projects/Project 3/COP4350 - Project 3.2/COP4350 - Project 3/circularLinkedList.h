/* circularLinkedList.h ---------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class circularLinkedList
-------------------------------------------------------------------*/

#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

#include <iostream>
//#include <vector>
//#include <cassert>
using namespace std;

template <typename T> class List;
template <typename T> ostream& operator<<(ostream&, const List<T>&);

const int NULL_VALUE = -1;

//-- Function/Class Declarations ------------------------------------

template <class T>
class List {
private:
   class Node {
   public:
      T data;
      Node* next;
   };

public:
   List();
   /*----------------------------------------------------------------
   Purpose: Construct a List object.
   Precondition: None.
   Postcondition: Creates an empty List object; _first is 0.
   Time Complexity: O(1)
   ----------------------------------------------------------------*/
   List(const List&);
   /*----------------------------------------------------------------
   Purpose: Construct a copy of a List object.
   Precondition: A copy of original is needed; original is a const
   reference parameter.
   Postcondition: A copy of original has been constructed.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   ~List();
   /*----------------------------------------------------------------
   Purpose: Destroys a List object.
   Precondition: The life of a List object is over.
   Postcondition: The memory dynamically allocated in linked lists by
   the constructor has been returned to the heap.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   int getSize() const;
   /*----------------------------------------------------------------
   Purpose: Get the size of a List object.
   Precondition: None.
   Postcondition: The number of elements held in the list is returned.
   Time Complexity: O(1)
   ----------------------------------------------------------------*/
   int getCapacity() const;
   /*----------------------------------------------------------------
   Purpose: Get the capacity of a List object. (Only provided for
   compatibility with other list).
   Precondition: None.
   Postcondition: -1 is returned since a pointer based linked list
   has no predefined capacity.
   Time Complexity: O(1)
   ----------------------------------------------------------------*/

   bool isEmpty() const;
   /*----------------------------------------------------------------
   Purpose: Check if list is empty.
   Precondition: None.
   Postcondition: Returns true if list is empty and false otherwise.
   Time Complexity: O(1)
   ----------------------------------------------------------------*/

   bool insert(const T&, const int&);
   /*----------------------------------------------------------------
   Purpose: Insert an item into the list at a given position.
   Precondition: item is the value to be inserted; ...
   Postcondition: item is inserted into the list at the specified
   position.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/
   bool remove(const int&);
   /*----------------------------------------------------------------
   Purpose: Remove an item from the list at a given position.
   Precondition: The list is not empty and 0 <= position < size.
   Postcondition: Element at the given position has been removed.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   T runJosephusAlgorithm();
   /*----------------------------------------------------------------
   Purpose: Implement the function to determine the node selected by
   the Josephus Algorithm. The function cannot modify the contents of
   the list object calling the function. For each iteration of the
   algorithm: randomly select a start node, from the remaining nodes,
   such that each of the nodes of the remaining linked list are
   equally likely to be selected; randomly select a count between 0
   and two times the size of the original list that you will walk to
   determine which node will be removed.
   Precondition:
   Postcondition:
   Time Complexity: ???
   ----------------------------------------------------------------*/

   const List& operator=(const List&);
   /*----------------------------------------------------------------
   Purpose: Assign a copy of a List object to the current object.
   Precondition: None.
   Postcondition: A copy of rhs has been assigned to this object. A
   const reference to this list is returned.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   void display(ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Output the list.
   Precondition: The ostream, out, is open.
   Postcondition: The list represented by this List object has been
   inserted into out.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/
   friend ostream& operator<< <>(ostream&, const List<T>&);
   /*----------------------------------------------------------------
   Purpose: Output operator for a List object.
   Precondition: The ostream, out, is open.
   Postcondition: The list represented by this List object has been
   inserted into out.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

private:
   Node* _first;  // pointer to the first element of the linked list
   //Node* _last;   // pointer to the last element of the linked list

   bool copyList(Node *, Node * &);
   /*----------------------------------------------------------------
   Purpose: Copy a linked list.
   Precondition: original is the list to be copied.
   Postcondition: copy points to a copy of original
   Time Complexity: O(n)
   ----------------------------------------------------------------*/
   bool deleteList(Node *);
   /*----------------------------------------------------------------
   Purpose: Delete a linked list.
   Precondition: The life of the linked list is over.
   Postcondition: The memory dynamically allocated by each node of the
   linked list is returned to the heap.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

};


//-- Function/Class Implementations ---------------------------------

template <class T>
List<T>::List() {
   _first = new Node;
   _first->next = _first;
}

template <class T>
List<T>::~List() {
   if (!isEmpty()) {
      Node* ptr = _first;

      do {
         Node* temp = ptr;
         ptr = ptr->next;
         delete temp;
      } while (ptr->next != _first);

      _first = 0;
   }
}

template <class T>
int List<T>::getSize() const {
   int size = 0;

   // Check if it an empty list (size 0)
   if (isEmpty()) {
      return size;
   }

   // Iterate through the linked list
   Node* predPtr = _first;
   while (predPtr != _first) {
      predPtr = predPtr->next;
      ++size;
   }

   return size;
}

template <class T>
int List<T>::getCapacity() const {
   return -1;
}

template <class T>
bool List<T>::isEmpty() const {
   return _first == 0;
}

template <class T>
bool List<T>::insert(const T& item, const int& position) {
   // Verify that position is not negative
   if (position < 0) {
      return false;
   }

   // Create a new node with the specified data
   Node* newNode = new Node;
   newNode->data = item;
   newNode->next = 0;

   // If this is the new head, then update _first
   if (position == 0) {
      if (_first == 0) {
         _first = newNode;
         _last = _first;
         _last->next = _first;
      }
      else {
         newNode->next = _first;
         _first = newNode;
         _last->next = _first;
      }
   }
   else {
      // Go to appropriate position in linked list to insert item
      Node* predPtr = _first;
      for (int i = 1; i < position; ++i) {
         predPtr = predPtr->next;

         // Verify position is not out of bounds (position > _size)
         if (predPtr == _first) {
            return false;
         }
      }

      // If insertion is at the end of the list
      if (predPtr == _last) {
         _last->next = newNode;
         _last = newNode;
         _last->next = _first;
      }
      // If insertion is between start and end of list
      else {
         newNode->next = predPtr->next;
         predPtr->next = newNode;
      }
   }

   return true;
}

template <class T>
bool List<T>::remove(const int& position) {
   // Verify we can delete an element
   if (isEmpty()) {
      return false;
   }

   // Verify that position is not negative
   if (position < 0) {
      return false;
   }

   // The first item is a special case
   if (position == 0) {
      Node* oldNode = _first;
      _first = _first->next;
      _last->next = _first;
      delete oldNode;
   }
   else {
      // Go to appropriate position in the linked list to delete item
      Node* oldNode = _first;
      Node* predPtr;
      for (int i = 0; i < position; ++i) {
         predPtr = oldNode;
         oldNode = oldNode->next;

         // Check for out of bounds (i.e. if the list loops around)
         // aka: if (position > _size)
         if (oldNode == _first) {
            return false;
         }
      }

      // The last item is a special case
      if (oldNode == _last) {
         _last = predPtr;
         predPtr->next = oldNode->next;
         delete oldNode;
      }
      else {
         // bypass the item to be deleted
         predPtr->next = oldNode->next;

         // free the memory for the item to be deleted
         delete oldNode;
      }
   }
}

template <class T>
void List<T>::display(ostream& out) const {
   if (!isEmpty()) {
      Node* ptr = _first;

      while (ptr->next != _first) {
         out << ptr->data << " ";
         ptr = ptr->next;
      }
   }
}

#endif   /*CIRCULAR_LINKED_LIST_H_*/

/*
do {
Node* temp = ptr;
ptr = ptr->next;
delete temp;
} while (ptr->next != _first);

*/