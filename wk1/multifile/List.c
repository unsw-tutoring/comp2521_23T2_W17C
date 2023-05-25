#include <stdio.h>
#include <stdlib.h>

#include "List.h"

struct node {
	Value val;
	struct node *next;
};

struct list {
	struct node *head;
	struct node *tail;
	int size;
};

List ListNew(void) {
	// code that returns a new list
}

static struct node *nodeNew(Value v) {
	// code that returns a new node
}

void ListAdd(List l, Value v) {
	// code that adds value
	// to the list
}
