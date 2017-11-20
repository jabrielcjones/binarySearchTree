//  file name -- binary-search-tree01.cpp
//  This file contains the implementation of the class
//  binary_search_tree.

//  ========================= header files ==========================
#include <stddef.h>                 // for NULL


template <class ItemType>
BinarySearchTree <ItemType>::
   BinarySearchTree(int (*precedes)(const ItemType &one,
                                     const ItemType &two),
                    int (*equals)(const ItemType &one,
                                  const ItemType &two))
   : BinaryTree <ItemType> ()
//  purpose -- set up a comparison function to order the nodes in a
//             binary search tree and initialize the binary search
//             tree.
//  preconditions -- precedes points to a function which will be
//             used to order the nodes in a binary tree.
//  postconditions -- instantiate a binary tree object which refers
//             to an empty binary search tree and set up a function
//             to order the nodes in a binary search tree.
{
   this -> precedes = precedes;
   this -> equals = equals;
}  // end of BinarySearchTree:BinarySearchTree()


template <class ItemType>
BinarySearchTree <ItemType>::
   BinarySearchTree(BinarySearchTree <ItemType> &source)
//  purpose -- copy the nodes in the binary search tree represented
//             by source to the current binary serach tree
//  preconditions -- current binary search tree is not initialized
//             and source represents a well-defined binary
//             search tree.
//  postconditions -- the nodes in the binary search tree represented
//             by source are duplicated and stored in the current
//             binary search tree.
{
}  // end of BinarySearchTree(BinarySearchTree <ItemType>&)


template <class ItemType>
BinarySearchTree <ItemType>::~BinarySearchTree()
//  purpose -- remove all the nodes from the current binary search
//             tree
//  preconditions -- none
//  postconditions -- all the nodes in the current binary search
//             tree are removed
{
}  // end of BinarySearchTree::~BinarySearchTree()


template <class ItemType>
void BinarySearchTree <ItemType>::
   operator=(const BinarySearchTree <ItemType> &source)
//  purpose -- copy the nodes in the binary search tree represented
//             by source to the current binary serach tree
//  preconditions -- source represents a binary search tree which
//             contains the same binary_node data type as the nodes
//             in the current binary search tree.
//  postconditions -- the nodes in the binary search tree represented
//             by source are duplicated and stored in the current
//             binary search tree.
{
}  // end of BinarySearchTree::operator=


template <class ItemType>
void BinarySearchTree <ItemType>::add(const ItemType &item)
//  purpose -- add an item to one of the nodes in the current binary
//             search tree.
//  preconditions -- item does not exist in the current binary
//             serach tree.
//  postconditions -- item is added to one of the nodes in the
//             current binary search tree.
{
   addNode(this->root, item);
}  // BinarySearchTree::add


template <class ItemType>
void BinarySearchTree <ItemType>::
   addNode(BinaryNode <ItemType> *&start,
           const ItemType &item)
{
   if (start == NULL) // a new leaf node is created for insertion
   {
      start = new BinaryNode <ItemType>;
      start -> info = item;
      start -> left = NULL;
      start -> right = NULL;
   }
   else  // continue to find the place to insert a new node
   {
      if (precedes(item, start -> info))
         addNode(start -> left, item);
      else
         addNode(start -> right, item);
   }  // else
}  // end of BinarySearchTree::addNode


template <class ItemType>
void BinarySearchTree <ItemType>::
   search (ItemType &item, int &found)
{
   searchNode(this->root, item, found);
}  // end of BinarySearchTree::search


template <class ItemType>
void BinarySearchTree <ItemType>::
   searchNode(BinaryNode <ItemType> *start,
              ItemType &item,
              int &found)
{
   if (start == NULL)
   {
      found = 0;
   }  // not found
   else if (equals(item, start -> info))
   {
      item = start -> info;
      found = 1;
   }
   else
   {
      if (precedes(item, start -> info))
         searchNode(start -> left, item, found);
      else
         searchNode(start -> right, item, found);
   }
}  // end of BinarySearchTree::searchNode


template <class ItemType>
void BinarySearchTree <ItemType>::remove(const ItemType &item)
//  purpose -- remove a node in the current binary
//             search tree.
//  preconditions -- item does exist in the current binary
//             serach tree.
//  postconditions -- node is removed from one of the nodes in the
//             current binary search tree.
{
   removeNode(this->root, item);
}  // BinarySearchTree::remove


template <class ItemType>
void BinarySearchTree <ItemType>::
   removeNode(BinaryNode <ItemType> *&start,
              const ItemType &item)
{
   if (start -> info == item)
   {
		BinaryNode<ItemType> 	*temp;
		
		if (start -> left == NULL && start -> right == NULL)	// leaf node
		{
			temp = start;
			start = NULL;
			delete temp;
		}
      else if (start -> left != NULL && start -> right == NULL)	// one child node (left)
		{
			temp = start;
			start = start -> left;
			delete temp;
		}
		else if (start -> left == NULL && start -> right != NULL)	// one child node (right)
		{
			temp = start;
			start = start -> right;
			delete temp;
		}
		else	// two child nodes
		{
			BinaryNode<ItemType>		*parent;
			parent = start -> right;
			temp = parent -> left;
	
			if (temp == NULL)
			{
				start -> info = parent -> info;
				start -> right = parent -> right;
				delete parent;
			}
			else
			{				
				while (temp -> left != NULL)
				{
					parent = temp;
					temp = temp -> left;
				}			
			
				start -> info = temp -> info;
				parent -> left = temp -> right;
				delete temp;
			}
		}
   }
   else  // continue to find the place to insert a new node
   {
      if (precedes(item, start -> info))
         removeNode(start -> left, item);
      else
         removeNode(start -> right, item);
   }  // else
}  // end of BinarySearchTree::removeNode
