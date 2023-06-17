#ifndef BSTREE_H
#define BSTREE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_HEIGHT_BALANCED -99

typedef struct BSTNode *BSTree;
typedef int Value;

// create a new BSTree with a single node with Value
BSTree BSTreeNew(Value);

// insert a value into the BSTree
BSTree BSTreeInsert(BSTree, Value);

// return the number of nodes in the tree
int BSTreeNumNodes(BSTree);

// return the number of odd nodes in the tree
int BSTreeCountOdds(BSTree);

// The height is defined as the length of the longest path from the root to a
// leaf. The path length is a count of the number of links (edges) on the path.
// if the Tree is empty, return -1
int BSTreeHeight(BSTree);

// Returns the number of internal nodes in the tree. An internal node is a node
// with at least one non-empty subtree.
int BSTreeCountInternal(BSTree);

// Returns the level of the node with the value equal to key.
// The level of the root node is zero
int BSTreeNodeLevel(BSTree, Value);

// return the number of nodes with a value greater than val
// avoid visiting nodes that you don't need to visit
int BSTreeCountGreater(BSTree, Value);

// return the height of the tree if the tree is height balanced
// otherwise return NOT_HEIGHT_BALANCED
int BSTreeIsHeightBalanced(BSTree);

#endif
