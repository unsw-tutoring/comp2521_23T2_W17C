#include "BSTree.h"

typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;

static int max(int num1, int num2);
static int abs(int num);

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
	if (t == NULL) return 0;
	return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
}

// return the number of odd nodes in the tree
int BSTreeCountOdds(BSTree t) {
	if (t == NULL) return 0;

	if (t->value % 2 == 0)
		return BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
	else
		return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
}

// The height is defined as the length of the longest path from the root to a
// leaf. The path length is a count of the number of links (edges) on the path.
// if the Tree is empty, return -1
int BSTreeHeight(BSTree t) {
	if (t == NULL) return -1;

	int lHeight = BSTreeHeight(t->left);
	int rHeight = BSTreeHeight(t->right);
	return max(lHeight, rHeight) + 1;
}

// Returns the number of internal nodes in the tree. An internal node is a node
// with at least one non-empty subtree.
int BSTreeCountInternal(BSTree t) {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 0;
	return 1 + BSTreeCountInternal(t->left) + BSTreeCountInternal(t->right);
}

// Returns the level of the node with the value equal to key.
// The level of the root node is zero
// returns -1 if the value is not in the tree
int BSTreeNodeLevel(BSTree t, Value v) {
	if (t == NULL) return -1;
	if (v == t->value) return 0;

	int subTreeLevel = -1;
	if (v < t->value) {
		subTreeLevel = BSTreeNodeLevel(t->left, v);
	} else {
		subTreeLevel = BSTreeNodeLevel(t->right, v);
	}

	if (subTreeLevel == -1) return -1;
	return subTreeLevel + 1;
}

// alternative -- I like this way better
int BSTreeNodeLevelAlt(BSTree t, Value v) {
	return doBSTreeNodeLevelAlt(t, v, 0);
}
int doBSTreeNodeLevelAlt(BSTree t, Value v, int level) {
	if (t == NULL) return -1;

	if (v == t->value) return level;

	if (v < t->value) {
		return doBSTreeNodeLevelAlt(t->left, v, level + 1);
	} else {
		return doBSTreeNodeLevelAlt(t->right, v, level + 1);
	}
}

// return the number of nodes with a value greater than val
// avoid visiting nodes that you don't need to visit
int BSTreeCountGreater(BSTree t, Value v) {
	if (t == NULL) return 0;

	if (t->value > v) {
		return 1 + BSTreeCountGreater(t->left, v) +
		       BSTreeCountGreater(t->right, v);
	}

	return BSTreeCountGreater(t->right, v);
}

// return the height of the tree if the tree is height balanced
// otherwise return NOT_HEIGHT_BALANCED
// height of an empty tree is -1
int BSTreeIsHeightBalanced(BSTree t) {
	if (t == NULL) return -1;

	int lHeight = BSTreeIsHeightBalanced(t->left);
	int rHeight = BSTreeIsHeightBalanced(t->right);

	if (lHeight == NOT_HEIGHT_BALANCED || rHeight == NOT_HEIGHT_BALANCED)
		return NOT_HEIGHT_BALANCED;

	if (abs(lHeight - rHeight) > 1) return NOT_HEIGHT_BALANCED;

	return max(lHeight, rHeight) + 1;
}

static int abs(int num) {
	return (num < 0) ? -num : num;
}

static int max(int num1, int num2) {
	return (num1 > num2) ? num1 : num2;
}
