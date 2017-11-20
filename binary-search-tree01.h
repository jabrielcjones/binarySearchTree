//  file name -- binary-search-tree01.h
//  This file contains the declaration of BinarySearchTree class.

#ifndef class_BinarySearchTree_
#define class_BinarySearchTree_

#include "binary-tree.h"

template <class ItemType>
class BinarySearchTree : public BinaryTree <ItemType>
{
   private:
      void addNode(BinaryNode <ItemType> *&start,
                   const ItemType &item);
      void searchNode(BinaryNode <ItemType> *start,
                      ItemType &item,
                      int &found);
		void removeNode(BinaryNode <ItemType> *&start,
                      const ItemType &item);

   protected:
      int (*precedes) (const ItemType &one, const ItemType &two);
      int (*equals) (const ItemType &one, const ItemType &two);

   public:
      BinarySearchTree(int (*precedes)(const ItemType &one,
                         const ItemType &two),
                         int (*equals)(const ItemType &one,
                         const ItemType &two));
      BinarySearchTree(BinarySearchTree <ItemType> &source);
      ~BinarySearchTree();
      void operator=(const BinarySearchTree <ItemType> &source);
      virtual void add(const ItemType &item);
      void search(ItemType &item, int &found);
      void remove(const ItemType &item);
};  // end of class BinarySearchTree

#include "binary-search-tree01.cpp"
#endif
