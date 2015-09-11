/* circularLinkedList.h ---------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class circularLinkedList
-------------------------------------------------------------------*/

#ifndef CIRCULARLINKEDLIST_H_
#define CIRCULARLINKEDLIST_H_

//#include <iostream>
//#include <vector>
//#include <cassert>
//using namespace std;

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
   Purpose: Implement the default constructor to create an empty linked
   list.
   Precondition: None.
   Postcondition: Creates an empty List object; _first is 0.
   Big Oh:
   ----------------------------------------------------------------*/
   List(const List&);
   /*----------------------------------------------------------------
   Purpose: Implement the copy constructor.
   Precondition:
   Postcondition:
   Big Oh:
   ------------------------------------------------------------------*/

   ~List();
   /*----------------------------------------------------------------
   Purpose: Implement the destructor.
   Precondition:
   Postcondition:
   Big Oh:
   ----------------------------------------------------------------*/

   int getSize() const;
   /*----------------------------------------------------------------
   Purpose: Implement getSize() function.
   Precondition:
   Postcondition:
   Big Oh:
   ----------------------------------------------------------------*/
   int getCapacity() const;
   /*----------------------------------------------------------------
   Purpose: Implement getCapacity() function.
   Precondition:
   Postcondition:
   Big Oh:
   ----------------------------------------------------------------*/

   bool isEmpty() const;
   /*----------------------------------------------------------------
   Purpose: Implement the isEmpty() function.
   Precondition:
   Postcondition:
   Big Oh:
   ----------------------------------------------------------------*/
   bool insert(const T&, const int&);
   /*----------------------------------------------------------------
   Purpose: Implement the insert() function.
   Precondition:
   Postcondition:
   Big Oh:
   ----------------------------------------------------------------*/
   bool remove(const int&);
   /*----------------------------------------------------------------
   Purpose: Implement the remove() function.
   Precondition:
   Postcondition:
   Big Oh:
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
   Big Oh:
   ----------------------------------------------------------------*/

   const List& operator=(const List&);
   /*----------------------------------------------------------------
   Purpose: Implement the assignment operator (=).
   Precondition:
   Postcondition:
   Big Oh:
   ----------------------------------------------------------------*/

   void display(ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Implement the display() function.
   Precondition:
   Postcondition:
   Big Oh:
   ----------------------------------------------------------------*/
   friend ostream& operator<< <>(ostream&, const List<T>&);
   /*----------------------------------------------------------------
   Purpose: Implement the left shift operator (<<).
   Precondition:
   Postcondition:
   Big Oh:
   ----------------------------------------------------------------*/

private:
   Node* _first;  // pointer to the first element of the linked list
   //Node* _last;   // pointer to the last element of the linked list
   int _size;
   int _capacity;
};

int randomNumberGenerator();
/*----------------------------------------------------------------
Purpose: Implement the left shift operator (<<).
Precondition:
Postcondition:
Big Oh:
----------------------------------------------------------------*/


//-- Function/Class Implementations ---------------------------------

template <class T>
List<T>::List() {
   _first = 0;
   _size = 0;
   _capacity = 0;
}

template <class T>
List<T>::List(const List& originalList) {
   //_first = _first;
   _first = originalList._first;

   Node* origPtr = originalList._first;
   Node* copyPtr = _first;

   while (origPtr != 0) {
      copyPtr->next = origPtr->next;
   }

   _size = originalList._size;
   _capacity = originalList._capacity;
}

template <class T>
List<T>::~List() {
   if (!isEmpty()) {
      Node* currentPtr = _first;
      Node* tempPtr;
      while (currentPtr != 0) {
         tempPtr = currentPtr;
         current = currentPtr->next;
         delete tempPtr;
      }
   }
}


template <class T>
int List<T>::getSize() const {
   Node* ptr = _first;  // potential error???
   int counter = 0;
   while (ptr != 0) {
      ++count;
      ptr = ptr->next;
   }
   _size = count;
   return _size;
}

template <class T>
int List<T>::getCapacity() const {
   return _capacity;
}


template <class T>
bool List<T>::isEmpty() const {
   return ((_size == 0) ? true : false);
}

template <class T>
bool List<T>::insert(const T& value, const int& location) {
   Node* newPtr = value;

   if (isEmpty()) {
      return false;
   }
   else {
      newPtr->next = _first;
      _first = newPtr;
   }
}

template <class T>
bool List<T>::remove(const int&) {

}


template <class T>
T List<T>::runJosephusAlgorithm() {

}


template <class T>
const List& List<T>::operator=(const List&) {

}


template <class T>
void List<T>::display(ostream&) const {

}

template <class T>
//friend ostream& List<T>::operator<< (ostream&, const List<T>&)
// potential error in declaration in previous way
friend ostream& operator<< (ostream&, const List&) {

}

int randomNumberGenerator() {

}

#endif

/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Big Oh:
-------------------------------------------------------------------*/
