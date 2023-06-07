#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

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
// if 'val' is not in the list, do nothing
// returns the head of the new linked list
List ListDelete(List l, int val) {
	if (l == NULL) return NULL;
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
	if (l == NULL) return NULL;

	l->next = ListDeleteOdds(l->next);

	if (l->data % 2 == 1) {
		List tmp = l->next;
		free(l);
		return tmp;
	}

	return l;
}
List ListDeleteOdds(List l) {
	if (l == NULL) return NULL;

	if (l->data % 2 == 1) {
		List tmp = l->next;
		free(l);
		return ListDeleteOdds(l->next);
	}

	l->next = ListDeleteOdds(l->next);
	return l;
}

// delete every second node (second, fourth, sixth, etc. node)
List ListDeleteSecond(List l) {
	// TODO
	return NULL;
}

// prints out the linked list
void ListPrint(List l) {
	// base case
	if (l == NULL) return;

	// reursive
	printf("%d\n", l->data);
	ListPrint(l->next);
}

// prints out the linked list in reverse
void ListPrintReverse(List l) {
	// base case
	if (l == NULL) return;

	// reursive
	ListPrint(l->next);
	printf("%d\n", l->data);
}

// returns length of linked list
int ListLength(List l) {
	// if list is empty (base case)
	if (l == NULL) return 0;

	return 1 + ListLength(l->next);
}

// returns number of even nodes in linked list
int ListCountEvens(List l) {
	// base case: empty list
	if (l == NULL) return 0;

	if (l->data % 2 == 0) {
		return 1 + ListCountEvens(l->next);
	} else {
		return ListCountEvens(l->next);
	}
}

// check if list is sorted in non-descending order
bool ListIsSorted(List l) {
	// base case(s)
	if (l == NULL) return true;
	if (l->next == NULL) return true;

	// recursive case
	return (l->data <= l->next->data) && ListIsSorted(l->next);
}

// ! THE FOLLOWING TWO EXAMPLES SHOW TWO COMMON TRICKS / TECHNIQUES YOU CAN
// ! USE WHEN CODING RECURSIVELY. TAKE NOTE OF THESE.

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransform(List l) {
	doListTransform(l, 1);
}

void doListTransform(List l, int pos) {
	if (l == NULL) return;

	l->data = l->data * pos;
	doListTransform(l->next, pos + 1);
}

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransformAlternate(List l) {
	int pos = 0;

	doListTransform(l, &pos);
}

void doListTransform(List l, int *posPointer) {
	if (l == NULL) return;

	l->data = l->data * (*posPointer);
	(*posPointer)++;
	doListTransform(l->next, posPointer);
}
