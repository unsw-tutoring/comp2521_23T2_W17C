#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
};

typedef struct list *List;

// create a new empty linked list
List listCreate() {
	List l = malloc(sizeof(struct list));
	l->head = NULL;
	return l;
}

// add to front of linked list
void listAdd(List l, int value) {
	struct node *newNode = malloc(sizeof(struct node));
	newNode->value = value;
	newNode->next = l->head;
	l->head = newNode;
}

int listSize(List l) {
	// TODO: return the size of the linked list
	return 0;
}

int main(void) {
	List l = listCreate();

	// see how I no longer need to reassign every time I perform a
	// function on the list
	listAdd(l, 1);
	listAdd(l, 2);
	listAdd(l, 3);
	listAdd(l, 4);

	printf("Size of list: %d\n", listSize(l));

	return 0;
}
