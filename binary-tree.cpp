//  file name -- binary-tree.cpp
//  This file contains the implementation of the class BinaryTree.

//  ========================= header files ===========================
#include <stddef.h>                     // for NULL


template <class ItemType>
BinaryTree <ItemType>::BinaryTree()
//  purpose -- default constructor to set root to NULL
//  preconditions -- none
//  postconditions -- the root node is set to NULL
{
   root = NULL;
}  // end of BinaryTree:BinaryTree()


template <class ItemType>
BinaryTree <ItemType>::BinaryTree(int maximum_nodes)
//  purpose -- default constructor to set root to NULL
//  preconditions -- none
//  postconditions -- the root node is set to NULL
{
}  // end of BinaryTree:BinaryTree(int)


template <class ItemType>
BinaryTree <ItemType>::
   BinaryTree(BinaryTree <ItemType> &source)
//  purpose -- default constructor to set root to NULL
//  preconditions -- none
//  postconditions -- the root node is set to NULL
{
}  // end of BinaryTree:BinaryTree(BinaryTree <ItemType>&)


template <class ItemType>
BinaryTree <ItemType>::~BinaryTree()
//  purpose -- default constructor to set root to NULL
//  preconditions -- none
//  postconditions -- the root node is set to NULL
{
}  // end of binary::~binary()


template <class ItemType>
void BinaryTree <ItemType>::
   operator=(const BinaryTree <ItemType> &source)
//  purpose -- default constructor to set root to NULL
//  preconditions -- none
//  postconditions -- the root node is set to NULL
{
}  // end of binary::operator=


template <class ItemType>
int BinaryTree <ItemType>::isEmpty()
//  purpose -- check to see if the tree is empty
//  preconditions -- none
//  postconditions -- return TRUE if the binary tree is empty;
//                   otherwise, return FALSE
{
   return (root == NULL);
}  // end of binary::isEmpty


template <class ItemType>
int BinaryTree <ItemType>::noRoomLeft()
//  purpose -- check to see if the binary tree will allow no further
//             additions
//  preconditions -- none
//  postconditions -- returns TRUE if the binary tree will allow no
//                   further additions; otherwise, return FALSE
{
   return (0);
}  // end of binary::noRoomLeft


template <class ItemType>
void BinaryTree <ItemType>::add(const ItemType &item)
//  purpose -- default constructor to set root to NULL
//  preconditions -- none
//  postconditions -- the root node is set to NULL
{
}  // end of binary::add


template <class ItemType>
void BinaryTree <ItemType>::
   preorderTraversal(void (*processNode)(ItemType &item))
//  purpose -- visit and process nodes in a preorder traversal
//  preconditions -- processNode points to a function which will process
//                   a node in the tree.
//  postconditions -- all nodes in the binary tree are visited in a preorder
//                   traversal (root, left subtree, right subtree) and each
//                   node is processed as it is visited.
{
   preorderVisit(root, processNode);
}  // end of binary::preorderTraversal 


template <class ItemType>
void BinaryTree <ItemType>::
   postorderTraversal(void (*processNode)(ItemType &item))
//  purpose -- visit and process nodes in a postorder traversal
//  preconditions -- processNode points to a function which will process
//                   a node in the tree.
//  postconditions -- all nodes in the binary tree are visited in a
//                   postorder traversal (left subtree, right subtree,
//                   root) and each node is processed as it is visited.
{
   postorderVisit(root, processNode);
}  // end of binary::postorderTraversal


template <class ItemType>
void BinaryTree <ItemType>::
   inorderTraversal(void (*processNode)(ItemType &item))
//  purpose -- visit and process nodes in an inorder traversal
//  preconditions -- processNode points to a function which will process
//                   a node in the tree.
//  postconditions -- all nodes in the binary tree are visited in an
//                   inorder traversal (left subtree, root, right subtree)
//                   and each node is processed as it is visited.
{
   inorderVisit(root, processNode);
}  // end of binary::inorderTraversal


template <class ItemType>
void BinaryTree <ItemType>::
   preorderVisit(BinaryNode <ItemType> *start,
                 void (*processNode)(ItemType &item))
//  purpose -- visit and process nodes in a preorder traversal
//  preconditions -- start points to the root of binary tree; processNode
//                   points to a function which will process a node in the
//                   tree.
//  postconditions -- all nodes in the binary tree are visited in a preorder
//                   traversal (root, left subtree, right subtree) and each
//                   node is processed as it is visited.
{
   if (start != NULL)
   {
      processNode(start -> info);
      preorderVisit(start -> left, processNode);
      preorderVisit(start -> right, processNode);
   }  // if
}  // end of binary::preorderVisit


template <class ItemType>
void BinaryTree <ItemType>::
   postorderVisit(BinaryNode <ItemType> *start,
                  void (*processNode)(ItemType &item))
//  purpose -- visit and process nodes in a postorder traversal
//  preconditions -- start points to the root of binary tree; processNode
//                   points to a function which will process a node in the
//                   tree.
//  postconditions -- all nodes in the binary tree are visited in a
//                   postorder traversal (left subtree, right subtree,
//                   root) and each node is processed as it is visited.
{
   if (start != NULL)
   {
      postorderVisit(start -> left, processNode);
      postorderVisit(start -> right, processNode);
      processNode(start -> info);
   }  // if
}  // end of binary::postorderVisit


template <class ItemType>
void BinaryTree <ItemType>::
   inorderVisit(BinaryNode <ItemType> *start,
                void (*processNode)(ItemType &item))
//  purpose -- visit and process nodes in an inorder traversal
//  preconditions -- start points to the root of binary tree and
//                   processNode points to a function which will
//                   process a node in the tree.
//  postconditions -- all nodes in the binary tree are visited in an
//                   inorder traversal (left subtree, root, right subtree)
//                   and each node is processed as it is visited.
{
   if (start != NULL)
   {
      inorderVisit(start -> left, processNode);
      processNode(start -> info);
      inorderVisit(start -> right, processNode);
   }  // if
}  // end of binary::inorderVisit
