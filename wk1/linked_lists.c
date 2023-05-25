#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
};

struct list *listCreate(void);
void listAdd(struct list *l, int value);
void listShow(struct list *l);

void listDelete(struct list *l, int value) {
	// TODO: delete value from a linked list l
}

int main(void) {
	struct list *l = listCreate();
	listAdd(l, 1);
	listAdd(l, 2);
	listAdd(l, 3);
	listAdd(l, 4);
	listAdd(l, 5);

	listShow(l);

	listDelete(l, 3);
	listShow(l);

	listDelete(l, 1);
	listShow(l);

	listDelete(l, 5);
	listShow(l);

	return 0;
}

struct list *listCreate(void) {
	struct list *l = malloc(sizeof(struct list));
	l->head = NULL;
	return l;
}

void listAdd(struct list *l, int value) {
	struct node *n = malloc(sizeof(struct node));
	n->value = value;
	n->next = l->head;
	l->head = n;
}

void listShow(struct list *l) {
	printf("List:\n");
	for (struct node *n = l->head; n != NULL; n = n->next) {
		printf("\t%d\n", n->value);
	}
	printf("\n");
}
