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
	// if empty tree
	if (t == NULL) return 0;
	// recursive case
	int numNodeInRightSubtree = BSTreeNumNodes(t->right);
	int numNodeInLeftSubtree = BSTreeNumNodes(t->left);

	return numNodeInRightSubtree + numNodeInLeftSubtree + 1;
}

// return the number of odd nodes in the tree
int BSTreeCountOdds(BSTree t) {
	//
	if (t == NULL) return 0;

	// recursive case
	int numOddNodeInRightSubtree = BSTreeCountOdds(t->right);
	int numOddNodeInLeftSubtree = BSTreeCountOdds(t->left);

	if (t->value % 2 != 0) {
		return 1 + numOddNodeInRightSubtree + numOddNodeInLeftSubtree;
	}

	return numOddNodeInLeftSubtree + numOddNodeInRightSubtree;
}

// The height is defined as the length of the longest path from the root to a
// leaf. The path length is a count of the number of links (edges) on the path.
// if the Tree is empty, return -1
int BSTreeHeight(BSTree t) {
	// TODO
	if (t == NULL) return -1;

	int rHeight = BSTreeHeight(t->right);
	int lHeight = BSTreeHeight(t->left);

	return max(rHeight, lHeight) + 1;
}

int max(int num1, int num2) {
	return (num1 > num2) ? num1 : num2;
}

// Returns the number of internal nodes in the tree. An internal node is a node
// with at least one non-empty subtree (i.e., not a leaf).
int BSTreeCountInternal(BSTree t) {
	// TODO
	if (t == NULL) return 0;
	// if (t->left == NULL && t->right == NULL) return 0;

	// recursive case
	int numOddNodeInRightSubtree = BSTreeCountInternal(t->right);
	int numOddNodeInLeftSubtree = BSTreeCountInternal(t->left);

	if (t->left != NULL || t->right != NULL) {
		return 1 + numOddNodeInRightSubtree + numOddNodeInLeftSubtree;
	}

	return numOddNodeInLeftSubtree + numOddNodeInRightSubtree;
}

// Returns the level of the node with the value equal to key.
// The level of the root node is zero
// if v is not in the tree, return -1
int BSTreeNodeLevel(BSTree t, Value v) {
	// TODO
	if (t == NULL) return -1;

	if (t->value > v) {
		int level = BSTreeNodeLevel(t->left, v);
		if (level == -1) {
			return -1;
		}
		return 1 + level;
	} else if (t->value < v) {
		int level = BSTreeNodeLevel(t->right, v);
		if (level == -1) {
			return -1;
		}
		return 1 + level;
	} else {
		return 0;
	}
}

// return the number of nodes with a value greater than val
// ! avoid visiting nodes that you don't need to visit
int BSTreeCountGreater(BSTree t, Value val) {
	if (t == NULL) return 0;

	int numNodesGreaterThanValRight = BSTreeCountGreater(t->right, val);

	int numNodesGreaterThanValLeft = 0;
	if (t->value <= val) {
		numNodesGreaterThanValLeft = BSTreeCountGreater(t->left, val);
	}

	if (t->value > val) {
		return 1 + numNodesGreaterThanValLeft + numNodesGreaterThanValRight;
	} else {
		return numNodesGreaterThanValLeft + numNodesGreaterThanValRight;
	}
}

// return the height of the tree if the tree is height balanced
// otherwise return NOT_HEIGHT_BALANCED
// height of an empty tree is -1
int BSTreeIsHeightBalanced(BSTree t) {
	if (t == NULL) return -1;

	// the height of the left subtree OR -99 if the left subtree is not height balanced
	int lheight = BSTreeIsHeightBalanced(t->left);
	// the height of the right subtree OR -99 if the right subtree is not height balanced
	int rheight = BSTreeIsHeightBalanced(t->right);

	if (lheight == NOT_HEIGHT_BALANCED || rheight == NOT_HEIGHT_BALANCED) {
		return NOT_HEIGHT_BALANCED;
	}

	int diff = lheight - rheight;
	if (diff > 1 || diff < -1) return NOT_HEIGHT_BALANCED;

	return max(lheight, rheight) + 1;
}
