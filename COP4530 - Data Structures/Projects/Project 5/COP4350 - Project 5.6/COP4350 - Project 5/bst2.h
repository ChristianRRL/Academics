/* bst.h ------------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class bst
Note: this binary search requires that all items be unique
-------------------------------------------------------------------*/

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <iomanip>

const int INDENT_VALUE = 8;

//== Function/Class Declarations ====================================
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
   Purpose: Construct a Binary Search Tree Object.
   Precondition: None.
   Postcondition: An empty BST has been constructed.
   Time Complexity: O(1).
   ----------------------------------------------------------------*/
   BinarySearchTree(BinarySearchTree&);
   /*----------------------------------------------------------------
   Purpose: Copy constructor for a Binary Search Tree Object.
   Precondition: Original is a BST.
   Postcondition: An empty BST has been constructed.
   Time Complexity: O(1).
   ----------------------------------------------------------------*/

   // Destruction ---------------------------------------------------
   ~BinarySearchTree();
   /*----------------------------------------------------------------
   Purpose: Destructor for a Binary Search Tree.
   Precondition: The life of the BST is over.
   Postcondition: Memory used by BST is freed.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   bool isEmpty() const;
   /*----------------------------------------------------------------
   Purpose: Check if Binary Search Tree is empty and false otherwise.
   Precondition: None.
   Postcondition: Return true if the Binary Search Tree is empty and
      false otherwise.
   Time Complexity: O(1).
   ----------------------------------------------------------------*/
   bool search(const T&) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for an item.
   Precondition: None.
   Postcondition: Returns true if item found and false otherwise.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/

   T getSuccessor(const T&) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for the inorder successor
      of item. If the item is not present in the tree, then return a
      garbage value.
   Precondition: None.
   Postcondition: Returns the inorder successor of the node
      containing item.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   T getPredecessor(const T&) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search tree for the inorder predecessor
      of item. If the item is not present in the tree, then return a
      garbage value.
   Precondition: None.
   Postcondition: Returns the inorder predecessor of item.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   T getMaximum() const;
   /*----------------------------------------------------------------
   Purpose: Determine the maximum item in the Binary Search Tree
   Precondition: None.
   Postcondition: Return the maximum value held in the binary search.
      If the tree is empty then a garbage value is returned.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   T getMinimum() const;
   /*----------------------------------------------------------------
   Purpose: Determine the minimum item in the Binary Search Tree
   Precondition: None.
   Postcondition: Return the minimum value held in the binary search.
      If the tree is empty then a garbage value is returned.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   int getHeight() const;
   /*----------------------------------------------------------------
   Purpose: Determine the number of levels in a binary search tree. 
      For example, a binary tree with a single node has height 1 and  
      a binary tree with a root and a single child has height 2
   Precondition: None.
   Postcondition: Return the number of levels in this BST.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   int getSize() const;
   /*----------------------------------------------------------------
   Purpose: Determine the number of vertices in Binary Search Tree.
   Precondition: None.
   Postcondition: Return the number of vertices in this BST.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   void inorder(std::ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Inorder traversal of Binary Search Tree.
   Precondition: ostream out is open.
   Postcondition: BST has been inorder traversed and values in nodes
      have been output to out.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   void preorder(std::ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Preorder traversal of Binary Search Tree
   Precondition: ostream out is open.
   Postcondition: BST has been preorder traversed and values in
      nodes have been output to out.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   void postorder(std::ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Postorder traversal of Binary Search Tree.
   Precondition: ostream out is open.
   Postcondition: BST has been postorder traversed and values in
      nodes have been output to out.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   bool insert(const T&);
   /*----------------------------------------------------------------
   Purpose: Insert a value into the Binary Search Tree.
   Precondition: item is not present in the BST.
   Postcondition: BST has been modified with the item inserted at the
      proper position to maintain the BST property. Returns true if
      item is inserted into the tree and false otherwise.
   Time Complexity: O(h).
   ----------------------------------------------------------------*/
   bool remove(const T&);
   /*----------------------------------------------------------------
   Purpose: Remove item from the Binary Search Tree.
   Postcondition: BST has been modified with  the item removed, if
      present. BST property is maintained. Returns true if insertion
      is successful and false otherwise.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/

   void displayGraphic(std::ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Graphic output of binary search tree.
   Precondition: ostream out is open.
   Postcondition: Graphical representation of BST has been output to 
      out.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   BinarySearchTree& operator=(const BinarySearchTree& rhs);
   /*----------------------------------------------------------------
   Purpose: Assign a copy of a Binary Search Tree object to the
      current object.
   Precondition: None.
   Postcondition: A copy of rhs has been assigned to this object. A
      const reference to this binary search tree is returned.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

private:
   Node * _root;	// pointer to the root of a tree

   // Private Functions
   void searchHelper(const T&, Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for an item.
   Precondition: subtreePtr points to a subtree of this BST.
   Postcondition: Set itemLocation to point to the item if it is found
      and to NULL otherwise.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   void searchParent(const T&, Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for the parent of an item.
   Precondition: subtreePtr points to a subtree of this BST.
   Postcondition: Sets itemLocation to point to the direct parent of
      the node that contains item OR sets itemLocation to point to
      the node that will be the parent of a node that contains item
      if item is inserted into the tree.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   void getMaximumHelper(Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Determine the maximum item for the subtree rooted at
      subtreeRoot.
   Precondition:subtreeRoot is a node in the binary seach tree.
      maxLocation points to null.
   Postcondition: maxLocation points to the maximum item in the
      subtree rooted at subtreeRoot (points to NULL for an empty
      subtree)
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   void getMinimumHelper(Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Determine the minimum item for the subtree rooted at
      subtreeRoot.
   Precondition: subtreeRoot is a node in the binary seach tree.
      minLocation points to null.
   Postcondition: minLocation points to the minimum item in the
      subtree rooted at subtreeRoot (points to NULL for an empty
      subtree).
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/

   void inorderHelper(std::ostream&, Node *) const;
   /*----------------------------------------------------------------
   Purpose: Inorder traversal helper function
   Precondition: ostream out is open. subtreePtr points to a subtree 
      of this BST.
   Postcondition: subtree with root pointed to by subtreePtr has been
      output to output.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   void preorderHelper(std::ostream&, Node *) const;
   /*----------------------------------------------------------------
   Purpose: Preorder traversal helper function.
   Precondition: ostream out is open. subtreePtr points to a subtree
      of this BST.
   Postcondition: subtree with root pointed to by subtreePtr has been
      output to output
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   void postorderHelper(std::ostream&, Node *) const;
   /*----------------------------------------------------------------
   Purpose: Postorder traversal helper function.
   Precondition: ostream out is open. subtreePtr points to a subtree
      of this BST.
   Postcondition: subtree with root pointed to by subtreePtr has been
      output to output.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   void displayGraphicHelper(std::ostream&, const int&, Node *) const;
   /*----------------------------------------------------------------
   Purpose: Graphic output of Binary Search Tree helper function.
   Precondition: ostream out is open. subtreePtr points to a subtree
      of this BST.
   Postcondition: Graphical representation of subtree with root
      pointed to by subtreePtr has been output to out, indented indent
      spaces.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/


   void getSuccessorHelper(Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for the inorder successor
      of the node, item.
   Precondition: item points to a node in the BST. succLocation
      points to NULL.
   Postcondition: succLocation points to the inorder successor of
      item in the BST.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   void getPredecessorHelper(Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for the inorder predecessor
      of the node, item.
   Precondition: item points to a node in the BST. predLocation
      points to NULL.
   Postcondition: predLocation points to the inorder predecessor of
      item in the BST.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/

   bool copyBinarySearchTree(Node *, Node * &);
   /*----------------------------------------------------------------
   Purpose: Copy the Binary Search Tree rooted at original.
   Precondition: original is a BST.
   Postcondition: copy holds a copy of the BST.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   bool deleteBinarySearchTree(Node *);
   /*----------------------------------------------------------------
   Purpose: Delete the Binary Search Tree rooted at bstRoot.
   Precondition: he life of the BST rooted at bstRoot is over.
   Postcondition: Memory used by the BST rooted at bstRoot is freed.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

};

//== Function/Class Implementations =================================

// Construction Start ===============================================
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
   copyBinarySearchTree(originalTree._root, _root);
}
// Construction End =================================================

// Destruction Start ================================================
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
   //deleteBinarySearchTree(_root);
}
// Destruction End ==================================================

// Verification Functions Start =====================================
template <class T>
bool BinarySearchTree<T>::isEmpty() const {
   return _root == NULL;
}
template <class T>
bool BinarySearchTree<T>::search(const T&) const {

}
// Verification Functions End =======================================

// Getter Functions Start ===========================================
template <class T>
T BinarySearchTree<T>::getSuccessor(const T&) const {

}
template <class T>
T BinarySearchTree<T>::getPredecessor(const T&) const {

}
template <class T>
T BinarySearchTree<T>::getMinimum() const {
   // iterate through the left side of the tree
}
template <class T>
T BinarySearchTree<T>::getMaximum() const {
   // iterate through the right side of the tree
}
template <class T>
int BinarySearchTree<T>::getHeight() const {

}
template <class T>
int BinarySearchTree<T>::getSize() const {

}
// Getter Functions End =============================================

// Tree Traversal Start =============================================
template <class T>
void BinarySearchTree<T>::inorder(std::ostream&) const {

}
template <class T>
void BinarySearchTree<T>::postorder(std::ostream&) const {

}
template <class T>
void BinarySearchTree<T>::preorder(std::ostream&) const {

}
// Tree Traversal End ===============================================

// Update Functions Start ===========================================
template <class T>
bool BinarySearchTree<T>::insert(const T& item) {
   // create a new node with the specified data
   Node * newNode = new Node(item);

   // if tree is empty, insert item at root
   if (isEmpty()) {
      _root = newNode;
      return true;
   }

   // iterate through the tree
   Node * rootPtr = _root;
   Node * prevPtr = rootPtr;
   while (rootPtr != 0) {
      prevPtr = rootPtr;
      Node * tempNode = new Node(rootPtr->data);

      if (item == rootPtr->data) {
         rootPtr->data = item;
         //rootPtr->parent = 
         cout << "item: " << rootPtr->data << ", parent: " << 0 << endl;

         return true;
      }
      else if (item < rootPtr->data) {
         rootPtr = rootPtr->left;
         //rootPtr->parent = tempNode;
         cout << "rootPtr->parent = tempNode: " << rootPtr->parent->data << endl;
         cin.ignore();
      }
      else if (item > rootPtr->data) {
         rootPtr = rootPtr->right;
         rootPtr->parent = tempNode;
      }
   }

   // insert the new item
   rootPtr = newNode;
   rootPtr->parent = prevPtr;

   cout << "item: " << rootPtr->data << ", parent: " << rootPtr->parent->data << endl;

   return true;
}
template <class T>
bool BinarySearchTree<T>::remove(const T& item) {
   // verify if we can delete item
   if (isEmpty() || !search(item)) {
      return false;
   }


}
// Update Functions End =============================================

// Display Function Start ===========================================
template <class T>
void BinarySearchTree<T>::displayGraphic(std::ostream&) const {

}
// Display Function End =============================================

// Operator Overloading Start =======================================
template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& rhs) {

}
// Operator Overloading End =========================================

// Helper Functions Start ===========================================
template <class T>
bool BinarySearchTree<T>::copyBinarySearchTree(Node * originalTreeRoot, Node * &copiedTreeRoot) {
   // if original tree is empty, delete anything held in the copied 
   if (originalTreeRoot == 0) {
      deleteBinarySearchTree(copiedTreeRoot);
   }

   // if copied tree is not originally empty, then delete tree
   deleteBinarySearchTree(copiedTreeRoot);

   //// copy the data from the root node
   //copiedTreeRoot = new Node;
   //copiedTreeRoot->data = originalTreeRoot->data;
   //copiedTreeRoot->left = 0;
   //copiedTreeRoot->right = 0;
   //copiedTreeRoot->parent = 0;

   //// create a pointer to the current location of each tree
   //Node * originalPtr = originalTreeRoot;
   //Node * copiedPtr = copiedTreeRoot;

   //// copy the data in the remaining nodes
   //for (int count = 1; originalPtr->left != 0 && originalPtr->right != 0; count++) {
   //   copiedPtr->left = new Node;
   //   originalPtr = 
   //}

   // copy data from the root node
   copiedTreeRoot = new Node;
   copiedTreeRoot->data = originalTreeRoot->data;
   copiedTreeRoot->parent = originalTreeRoot->parent;

   // recursively copy the left and right values from original
   copyBinarySearchTree(copiedTreeRoot->left, originalTreeRoot->left);
   copyBinarySearchTree(copiedTreeRoot->right, originalTreeRoot->right);
}
template <class T>
bool BinarySearchTree<T>::deleteBinarySearchTree(Node * rootPtr) {
   if (rootPtr == 0) {
      return true;
   }
   else {
      // recursively call remove function until tree is empty
      Node * ptr = rootPtr;
      remove(ptr);
   }


   //Node * ptr = rootPtr;

   //while (ptr != 0) {
   //   Node * tempPtr = ptr;
   //   ptr = ptr->next;
   //   delete tempPtr;
   //}

   //rootPtr = 0;

   //return true;
}
// Helper Functions End =============================================

#endif /*BST_H_*/

/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Time Complexity:
-------------------------------------------------------------------*/
