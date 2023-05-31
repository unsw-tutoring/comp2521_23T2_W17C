#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

int main(void) {
	// struct node n;
	// n.value = 42;
	// n.next = NULL;

	struct node *n = malloc(sizeof(struct node));
	(*n).value = 42;
	(*n).next = NULL;

	n->value = 42;
	n->next = NULL;
}

int main(void) {
	int a[5];
	for (int i = 0; i < 5; i++) {
		a[i] = 42;
	}

	int *a = malloc(5 * sizeof(int));

	a[0] = 1;
	a[1] = 1;

	free(a);

	int *b = calloc(5, sizeof(int));

	int c[5] = {0, 1, 2, 3, 4};

	int nums;
	scanf("%d", &nums);
	int w[nums];  // ! BAD

	int *w = malloc(nums * sizeof(int));
	if (w == NULL) {
		exit(EXIT_FAILURE);
	}
}

int main(void) {
	struct list *l = ListNew();
	l = ListInsert(l, 5);
	l = ListInsert(l, 5);
	l = ListInsert(l, 5);
	l = ListInsert(l, 5);
	l = ListInsert(l, 5);

	struct list *l = ListNew();
	ListInsert(l, 5);
	ListInsert(l, 5);
	ListInsert(l, 5);
	ListInsert(l, 5);
	ListInsert(l, 5);
}

// Representation 2
struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
	struct node *tail;
	int size;
};

int listLength(struct list *list);

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
};

void listDelete(struct list *l, int value) {
	// make variable current point to head of linked list
	struct node *current = l->head;

	// if the linked list is empty
	if (current == NULL) {
		return;
	}

	// if head of list is the one we want to delete
	if (current->value == value) {
		struct node *tmp = current->next;
		free(current);
		l->head = tmp;
		return;
	}

	while (current->next != NULL) {
		// if next node is node we want to delete
		if (current->next->value == value) {
			// save the address of the next next node
			struct node *tmp = current->next->next;
			// delete the next node
			free(current->next);
			current->next = tmp;
			return;
		}

		current = current->next;
	}
}
