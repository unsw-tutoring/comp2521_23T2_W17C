#include <stdio.h>

#include "List.h"

int main(void) {
	List l = ListNew();
	ListAdd(l, 2);

	// ! what is wrong with this line of code???
	int size = l->size;
}
