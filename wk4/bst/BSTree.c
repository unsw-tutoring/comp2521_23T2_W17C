#include "BSTree.h"

typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;

// create a new BSTree with a single node with Value
BSTree BSTreeNew(Value v) {
	BSTNode *newNode = malloc(sizeof(BSTNode));
	newNode->left = newNode->right = NULL;
	newNode->value = v;
	return newNode;
}

// insert a value into the BSTree
BSTree BSTreeInsert(BSTree t, Value v) {
	if (t == NULL) return BSTreeNew(v);

	if (v < t->value) {
		t->left = BSTreeInsert(t->left, v);
	} else if (v > t->value) {
		t->right = BSTreeInsert(t->right, v);
	}
	return t;
}

// return the number of nodes in the tree
int BSTreeNumNodes(BSTree t) {
	// TODO
	return 0;
}

// return the number of odd nodes in the tree
int BSTreeCountOdds(BSTree t) {
	// TODO
	return 0;
}

// The height is defined as the length of the longest path from the root to a
// leaf. The path length is a count of the number of links (edges) on the path.
// if the Tree is empty, return -1
int BSTreeHeight(BSTree t) {
	// TODO
	return 0;
}

// Returns the number of internal nodes in the tree. An internal node is a node
// with at least one non-empty subtree (i.e., not a leaf).
int BSTreeCountInternal(BSTree t) {
	// TODO
	return 0;
}

// Returns the level of the node with the value equal to key.
// The level of the root node is zero
int BSTreeNodeLevel(BSTree t, Value v) {
	// TODO
	return 0;
}

// return the number of nodes with a value greater than val
// avoid visiting nodes that you don't need to visit
int BSTreeCountGreater(BSTree t, Value v) {
	// TODO
	return 0;
}

// return the height of the tree if the tree is height balanced
// otherwise return NOT_HEIGHT_BALANCED
// height of an empty tree is -1
int BSTreeIsHeightBalanced(BSTree t) {
	// TODO
	return NOT_HEIGHT_BALANCED;
}
