/* bst.h ------------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class bst
-------------------------------------------------------------------*/

#ifndef BST_H_
#define BST_H_

#include <iostream>

using namespace std;

//template <typename T> class BinarySearchTree;
//template <typename T> ostream& operator<<(ostream&, const BinarySearchTree<T>&);

//-- Function/Class Declarations ------------------------------------
template <class T>
class BinarySearchTree {

private:
   class Node {
   public:
      T data;
      Node * left;
      Node * right;
      Node * parent;

      Node() :left(NULL), right(NULL), parent(NULL) {};
      Node(const T& item) {
         data = item;
         left = NULL;
         right = NULL;
         parent = NULL;
      };
   };

public:
   // Construction --------------------------------------------------
   BinarySearchTree();
   /*----------------------------------------------------------------
   Purpose: Construct a BinarySearchTree object.
   Precondition: None.
   Postcondition: Creates empty BinarySearchTree object; _root is 0.
   Time Complexity: O(1)
   ----------------------------------------------------------------*/
   BinarySearchTree(BinarySearchTree&);
   /*----------------------------------------------------------------
   Purpose: Construct a copy of a BinarySearchTree object.
   Precondition: A copy of original is needed; originalTree is a 
   const reference parameter.
   Postcondition: A copy of originalTree has been constructed.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   // Destruction ---------------------------------------------------
   ~BinarySearchTree();
   /*----------------------------------------------------------------
   Purpose: Destroys a BinarySearchTree object.
   Precondition: The life of List object is over.
   Postcondition: The memory dynamically allocated in linked lists by
   the constructor has been returned to the heap.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   bool isEmpty() const;
   /*----------------------------------------------------------------
   Purpose: Check if BinarySearchTree object is empty.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/
   bool search(const T&) const;
   /*----------------------------------------------------------------
   Purpose: Search BinarySearchTree object for specified item.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   T getSuccessor(const T&) const;
   /*----------------------------------------------------------------
   Purpose: Get successor of an value in BinarySearchTree object.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/
   T getPredecessor(const T&) const;
   /*----------------------------------------------------------------
   Purpose: Get predecessor of an value in BinarySearchTree object.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/
   T getMinimum() const;
   /*----------------------------------------------------------------
   Purpose: Get minimum value in BinarySearchTree object.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/
   T getMaximum() const;
   /*----------------------------------------------------------------
   Purpose: Get maximum value in BinarySearchTree object.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/
   int getHeight() const;
   /*----------------------------------------------------------------
   Purpose: Get height of BinarySearchTree object.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/
   int getSize() const;
   /*----------------------------------------------------------------
   Purpose: Get size of BinarySearchTree object.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   void inorder(ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Output BinarySearchTree object in inorder format.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/
   void postorder(ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Output BinarySearchTree object in postorder format.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/
   void preorder(ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Output BinarySearchTree object in preorder format.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   bool insert(const T&);
   /*----------------------------------------------------------------
   Purpose: Insert a value into BinarySearchTree object.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/
   bool remove(const T&);
   /*----------------------------------------------------------------
   Purpose: Remove value from BinarySearchTree object.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   void displayGraphic(ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Display BinarySearchTree object.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   BinarySearchTree& operator=(const BinarySearchTree& rhs);
   /*----------------------------------------------------------------
   Purpose: Overload = operator.
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

private:
   Node * _root;	// pointer to the root of a tree

   // Private Functions
   bool copyTree(Node *, Node * &);
   /*----------------------------------------------------------------
   Purpose: Copy a tree.
   Precondition: originalTree is the tree to be copied.
   Postcondition: copy points to a copy of original.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/
   bool deleteTree(Node *);
   /*----------------------------------------------------------------
   Purpose: Delete a tree
   Precondition: The life of the tree is over.
   Postcondition: The memory dynamically allocated by each node of 
   the tree is returned to the heap.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

};

//-- Function/Class Implementations ---------------------------------

// Construction Start -----------------------------------------------
template <class T>
BinarySearchTree<T>::BinarySearchTree() {
   // Initialize an empty tree
   _root = 0;
}
template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree& originalTree) {
   // Initialize an empty tree
   _root = 0;

   // Copy the original tree
   copyTree(originalTree._root, _root);
}
// Construction End -------------------------------------------------


// Destruction Start ------------------------------------------------
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {

}
// Destruction End --------------------------------------------------


// Verification Functions Start -------------------------------------
template <class T>
bool BinarySearchTree<T>::isEmpty() const {

}
template <class T>
bool BinarySearchTree<T>::search(const T&) const {

}
// Verification Functions End ---------------------------------------


// Getter Functions Start -------------------------------------------
template <class T>
T BinarySearchTree<T>::getSuccessor(const T&) const {

}
template <class T>
T BinarySearchTree<T>::getPredecessor(const T&) const {

}
template <class T>
T BinarySearchTree<T>::getMinimum() const {

}
template <class T>
T BinarySearchTree<T>::getMaximum() const {

}
template <class T>
int BinarySearchTree<T>::getHeight() const {

}
template <class T>
int BinarySearchTree<T>::getSize() const {

}
// Getter Functions End ---------------------------------------------


// Tree Traversal Start ---------------------------------------------
template <class T>
void BinarySearchTree<T>::inorder(ostream&) const {

}
template <class T>
void BinarySearchTree<T>::postorder(ostream&) const {

}
template <class T>
void BinarySearchTree<T>::preorder(ostream&) const {

}
// Tree Traversal End -----------------------------------------------


// Update Functions Start -------------------------------------------
template <class T>
bool BinarySearchTree<T>::insert(const T&) {

}
template <class T>
bool BinarySearchTree<T>::remove(const T&) {

}
//-- Update Functions End -------------------------------------------


//-- Display Function Start -----------------------------------------
template <class T>
void BinarySearchTree<T>::displayGraphic(ostream&) const {

}
//-- Display Function End -------------------------------------------


//-- Operator Overloading Start -------------------------------------
template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& rhs) {

}
//-- Operator Overloading End ---------------------------------------


//-- Helper Functions Start -----------------------------------------
template <class T>
bool BinarySearchTree<T>::copyTree(Node * originalTreeRoot, Node * &copiedTreeRoot) {
   // if original tree is empty, delete anything held in the copied 
   if (originalTreeRoot == 0) {
      deleteTree(copiedTreeRoot);
   }

   // if copied tree is not originally empty, then delete tree
   deleteTree(copiedTreeRoot);

   // copy the data from the root node
   copiedTreeRoot = new Node;
   copiedTreeRoot->data = originalTreeRoot->data;
   copiedTreeRoot->left = 0;
   copiedTreeRoot->right = 0;
   copiedTreeRoot->parent = 0;

   // create a pointer to the current location of each tree
   Node * originalPtr = originalTreeRoot;
   Node * copiedPtr = copiedTreeRoot;

   //// copy the data in the remaining nodes
   //for (int count = 1; originalPtr->left != 0 && originalPtr->right != 0; count++) {
   //   copiedPtr->left = new Node;
   //   originalPtr = 
   //}

   // recursively copy the left, right, and parent values from original
   copiedTreeRoot = new Node;
   copiedTreeRoot->data = originalTreeRoot->data;
   copiedTreeRoot->parent = originalTreeRoot->parent;
   copyTree(copiedTreeRoot->left, originalTreeRoot->left);
   copyTree(copiedTreeRoot->right, originalTreeRoot->right);
}
template <class T>
bool BinarySearchTree<T>::deleteTree(Node * rootPtr) {

}
//-- Helper Functions End -------------------------------------------

#endif /*BST_H_*/

/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/
