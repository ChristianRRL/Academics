/* permutations.h ---------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class permutations
-------------------------------------------------------------------*/

#ifndef PERMUTATIONS_H_ // What is "#pragma once" used for?
#define PERMUTATIONS_H_

#include <iostream>
#include <cassert>

using namespace std;

const int DEFAULT_SIZE = 1024;

template <typename T> class List;
template <typename T> ostream& operator<<(ostream&, const List<T>&);


template <class T>
class List {

public:
   List();
   List(const List&);

   ~List();

   int getSize() const;
   int getCapacity()const;

   bool isEmpty() const;
   bool insert(const T&, const int&);
   bool remove(const int&);

   const List& operator=(const List& rhs);

   void display(ostream&) const;
   friend ostream& operator<< <>(ostream&, const List<T>&);

private:
   T* _items;
   //int _capacity;
   int _size;
};


template <class T>
List<T>::List() {
   _size = 5;
   //_capacity = DEFAULT_SIZE;
   _items = new(nothrow)T[_size];
   //_size = 0;

   assert(_items != 0);
}

template <class T>
List<T>::List(const List& originalList) {
   _capacity = originalList._capacity;
   _size = originalList._size;

   _items = new(nothrow)T[_capacity];

   assert(_items != 0);

   for (int i = 0; i < _size; ++i) {
      _items[i] = originalList._items[i];
   }
}

template <class T>
List<T>::~List() {
   delete[] _items;
}

template <class T>
int List<T>::getCapacity() const {
   return _capacity;
}

template <class T>
bool List<T>::isEmpty() const {
   return _size == 0;
}


template <class T>
bool List<T>::insert(const T& item, const int& position) {
   if (_size == _capacity) {
      return false;
   }

   if (position<0 || position>_size) {
      return false;
   }

   // shift elements to the right to make space for the new element
   for (int i = _size; i>position; --i) {
      _items[i] = _items[i - 1];
   }

   // put the new element in the correct position
   _items[position] = item;

   // increment the size of the current list
   ++_size;

   return true;
}

template <class T>
bool List<T>::remove(const int& position) {
   // verify we can delete an element
   if (_size == 0) {
      return false;
   }

   // verify this is a valid item to delete
   if (position<0 || position >= _size) {
      return false;
   }

   // shift the array left
   for (int i = position; i<_size; ++i) {
      _items[i] = _items[i + 1];
   }

   --_size;

   return true;
}

template <class T>
const List<T>& List<T>::operator=(const List& rhs) {
   // verify this is not a self-assignment
   if (this == &rhs) {
      return *this;
   }

   // allocate a new array, if necessary
   if (_capacity != rhs._capacity) {
      delete[] _items;

      _capacity = rhs._capacity;

      _items = new(nothrow)T[_capacity];

      assert(_items != 0);
   }

   // copy rhs's elements into the new array
   _size = rhs._size;
   for (int i = 0; i<_size; ++i) {
      _items[i] = rhs._items[i];
   }

   return *this;
}



//template < class T >
int* items;
int size;

template < class T >
void generateArray() {
   size = 4;
   items = new(nothrow) int[5];
   items = { 0, 1, 2, 3, 4 };
}

template <typename T>
ostream& operator<<(ostream& out) {
   outputArray(out);

   return out;
}
//void display(ostream& out) {
//   for (int i = 0; i<size; ++i) {
//      out << items[i];
//      if (i + 1<size) {
//         out << " ";
//      }
//   }
//}


template < class T >
void outputArray(T* items, const int& size, ostream& out) {
   for (int i = 0; i < size; ++i) {
      out << items[i] << " ";
   }
   out << "\n";

   //cout << out;
}


long factorial(const int& n) {
   assert(n >= 0);
   if (n == 0) {
      return 1;
   }
   else {
      return n*factorial(n - 1);
   }
}


template < class T >
void outputPermutations(T* items, const int& size, ostream& out);

//template < class T >
//T* items;

//template <class T>
//class List {
//
//public:
//   List();
//   //List(const List& originalList);
//
//   ~List();
//
//   //int getSize() const;
//   //int getCapaticy() const;
//
//   //void generateArray(int& size);
//
//   //const List& operator=(const List& rhs);
//   //bool isEmpty() const;
//   //bool insert(const T&, const int&);
//   //bool remove(const int&);
//   //void display(ostream& out) const;
//   friend ostream& operator<< <>(ostream&, const List<T>&);
//
//private:
//   int _size;
//   int _capacity;
//   T *_items;
//
//}; // end of class declaration
//
//template < class T >
//List<T>::List()
//{
//   _capacity = DEFAULT_SIZE;
//   _items = new T[_capacity];
//   _size = 0;
//
//   assert(_items != 0);
//
//}










#endif

//-- Function Description Template
/*----------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
----------------------------------------------------------------*/