#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};
typedef struct node *List;

// sort a linked list using selection sort
// you should NOT malloc new nodes, instead just rearrange the given nodes
List selectionSort(List ls) {
	List res = NULL;
	for (List l = ls; l != NULL; l = l->next) {
		// find the smallest node in the linked list
		List minNode = findMinNode(l);

		// removing it from ls
		l = removeNode(ls, minNode);

		// insert into the back of res
		if (res == NULL) res = minNode;
		res->next = minNode;
		res = minNode;
	}
	return res;
}

List findMinNode(List ls) {
	if (ls == NULL) return NULL;

	List min = ls;
	for (List l = ls; l != NULL; l = l->next) {
		if (l->value < min->value) {
			min = l;
		}
	}

	return min;
}

List removeNode(List ls, List nodeToRemove) {
	if (ls == nodeToRemove) return ls->next;

	for (List l = ls; l != NULL; l = l->next) {
		if (l->next == nodeToRemove) {
			l->next = l->next->next;
		}
	}
}
