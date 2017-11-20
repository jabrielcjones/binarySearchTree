//  file name -- binary-tree.h
//  This file contains the header file for the class BinaryTree.

#ifndef class_BinaryTree_
#define class_BinaryTree_

template <class ItemType>
class BinaryNode
{
   public:
      ItemType info;
      BinaryNode *left;
      BinaryNode *right;
};  // end of class BinaryNode


template <class ItemType>
class BinaryTree
{
   protected:
      BinaryNode <ItemType> *root;
      void preorderVisit(BinaryNode <ItemType> *start,
                         void (*process_node)(ItemType &item));
      void postorderVisit(BinaryNode <ItemType> *start,
                          void (*process_node)(ItemType &item));
      void inorderVisit(BinaryNode <ItemType> *start,
                        void (*process_node)(ItemType &item));

   public:
      BinaryTree();
      BinaryTree(int maximum_nodes);
      BinaryTree(BinaryTree <ItemType> &source);
      ~BinaryTree();
      void operator=(const BinaryTree <ItemType> &source);
      int isEmpty();
      int noRoomLeft();
      virtual void add(const ItemType &item) = 0;
      void preorderTraversal(void (*process_node)(ItemType &item));
      void postorderTraversal(void (*process_node)(ItemType &item));
      void inorderTraversal(void (*process_node)(ItemType &item));
};  // end of class BinaryTree

#include "binary-tree.cpp"
#endif
