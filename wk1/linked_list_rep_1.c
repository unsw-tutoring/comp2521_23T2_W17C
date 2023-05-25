#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node *List;

// create a new linked list
List listCreate(int value) {
	List l = malloc(sizeof(struct node));
	l->value = value;
	l->next = NULL;
	return l;
}

// add to front of linked list
List listAdd(List l, int value) {
	List newNode = listCreate(value);
	newNode->next = l;
	return newNode;
}

// find size of linked list
int listSize(List l) {
	int size = 0;
	for (List curr = l; curr != NULL; curr = curr->next) {
		size++;
	}
	return size;
}

int main(void) {
	List l = listCreate(1);
	l = listAdd(l, 2);
	l = listAdd(l, 3);
	l = listAdd(l, 4);

	printf("Size of list: %d\n", listSize(l));

	return 0;
}
