#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

void doListTransform(List l, int position);
List doListDeleteSecond(List l, int position);

// create a new empty list
List ListNew() {
	return NULL;
}

// add item to end of list
List ListAdd(List l, int val) {
	// malloc a new node
	List newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = val;

	// if empty list
	if (l == NULL) {
		return newNode;
	}

	// add to end of list
	List curr = l;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newNode;
	return l;
}

// delete the first item with value 'val' from list -- recursively
List ListDelete(List l, int val) {
	if (l == NULL) return l;
	if (l->data == val) {
		List tmp = l->next;
		free(l);
		return tmp;
	}

	l->next = ListDelete(l->next, val);
	return l;
}

// delete all odd numbers from list -- recursively
List ListDeleteOdds(List l) {
	if (l == NULL) return l;

	l->next = ListDeleteOdds(l->next);

	// if current node's value is odd, delete and return the node after this
	if (l->data % 2 != 0) {
		List tmp = l->next;
		free(l);
		return tmp;
	}
	// else, return this node
	return l;
}

// delete every second node (second, fourth, sixth, etc. node)
List ListDeleteSecond(List l) {
	return doListDeleteSecond(l, 1);
}
List doListDeleteSecond(List l, int position) {
	if (l == NULL) return NULL;

	l->next = doListDeleteSecond(l->next, position + 1);

	if (position % 2 == 0) {
		List tmp = l->next;
		free(l);
		return tmp;
	}

	return l;
}

// prints out the linked list
void ListPrint(List l) {
	if (l == NULL) {
		return;
	}
	printf("%d, ", l->data);
	ListPrint(l->next);
}

// prints out the linked list in reverse
void ListPrintReverse(List l) {
	if (l == NULL) {
		return;
	}
	ListPrintReverse(l->next);
	printf("%d, ", l->data);
}

// returns length of linked list
int ListLength(List l) {
	if (l == NULL) return 0;

	return 1 + ListLength(l->next);
}

// returns number of even nodes in linked list
int ListCountEvens(List l) {
	if (l == NULL) return 0;

	if (l->data % 2 == 0) return 1 + ListCountEvens(l->next);

	return ListCountEvens(l->next);
}

// check if list is sorted in non-descending order
bool ListIsSorted(List l) {
	if (l == NULL) return true;
	if (l->next == NULL) return true;

	return ListIsSorted(l->next) && (l->data <= l->next->data);
}

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransform(List l) {
	doListTransform(l, 1);
}
void doListTransform(List l, int position) {
	if (l == NULL) return;

	l->data *= position;
	doListTransform(l->next, position + 1);
}

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransformAlternate(List l) {
	if (l == NULL) return;
	// kinda cheesy way
	// pass in the address of a variable to the helper recursive function
	// pos becomes kinda like a 'global variable' throughout the recursive calls
	int pos = 1;
	doListTransformAlternate(l, &pos);
	return;
}
void doListTransformAlternate(List l, int *pos) {
	if (l == NULL) return;
	l->data = l->data * (*pos);
	*pos = *pos + 1;
	doListTransformAlternate(l->next, pos);
}
