///* permutations.cpp -------------------------------------------------
//author: Christian A. Rodriguez
//Implementation file of the class library for the class permutations
//-------------------------------------------------------------------*/
//
//#include <iostream>
//#include <cassert>
////#include "permutations.h"
//
//using namespace std;
//
//
//template < class T >
//void outputArray(T* items, const int& size, ostream& out)
//{
//}
//
//long factorial(const int& n) {
//   assert(n >= 0);
//   if (n == 0) {
//      return 1;
//   }
//   else {
//      return n*factorial(n - 1);
//   }
//}
//
//template < class T >
//void outputPermutations(T* items, const int& size, 
//   ostream& out)
//{
//}
//
////template < class T > 
////void List<T>::generateArray(int& size)
////{
////   //_items = new(nothrow) T[size];
////
////   for (int i = 0; i < size; ++i) {
////      _items[i] = i;
////      cout << _items[i] << " ";
////   }
////   cout << endl;
////
////}
//
//template <class T>
//List<T>::List()
//{
//   _capacity = DEFAULT_SIZE;
//   _items = new T[_capacity];
//   _size = 0;
//
//   assert(_items != 0);
//}
//
//template <class T>
//List<T>::~List()
//{
//   delete[] _items;
//}
//
////template < class T >
////int List<T>::getSize() const
////{
////   return _size;
////}
//
////template <class T>
////List<T>::List(const List& originalList)
////{
////}
////
////template <class T>
////bool List<T>::isEmpty() const
////{
////}
////
////template < class T >
////bool List<T>::insert(const T&, const int&)
////{
////}
//
////template <class T>
////bool List<T>::remove(const int&)
////{
////}
////
////template <class T>
////void List<T>::display(ostream& out) const
////{
////}