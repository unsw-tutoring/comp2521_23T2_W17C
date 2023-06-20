#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} *Node;

typedef struct list {
	Node head;
} *List;

typedef int (*FilterFunc)(int);

// try doing it recursively maybe?
void listFilter(List l, FilterFunc fp) {
	l->head = listFilterR(l->head, fp);
}

Node listFilterR(Node n, FilterFunc fp) {
	if (!n) return NULL;

	bool delete = !fp(n->value);

	Node rest = listFilterR(n->next, fp);

	if (delete) {
		free(n);
		return rest;
	} else {
		n->next = rest;
		return n;
	}
}

int main(void) {
	return 0;
}
