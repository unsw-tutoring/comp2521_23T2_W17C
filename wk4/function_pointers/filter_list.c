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

// Implement the following function that takes a linked list and a function
// pointer and removes all nodes that return 0 when passed through the filter
// function.

// try doing it recursively maybe?
void listFilter(List l, FilterFunc fp) {
	// TODO
}

int main(void) {
	return 0;
}

// examples

// calling listFilter(l, isEven) would delete all odd nodes from the linked list
int isEven(int n) {
	return n % 2 == 0;
}
