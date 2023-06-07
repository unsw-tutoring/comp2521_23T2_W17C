#include <assert.h>
#include <stdio.h>

#include "List.h"

void spacing() {
	printf("\n");
}

int main(void) {
	List l = ListNew();

	l = ListAdd(l, 1);
	l = ListAdd(l, 2);
	l = ListAdd(l, 3);
	l = ListAdd(l, 4);
	l = ListAdd(l, 5);
	l = ListAdd(l, 6);
	l = ListAdd(l, 7);
	l = ListAdd(l, 8);
	l = ListAdd(l, 10);
	l = ListAdd(l, 11);
	l = ListAdd(l, 12);
	l = ListAdd(l, 13);
	l = ListAdd(l, 14);
	l = ListAdd(l, 15);
	l = ListAdd(l, 16);
	l = ListAdd(l, 9);

	// print list
	printf("\nInitial List:\n\t");
	ListPrint(l);
	spacing();

	// print list in reverse
	printf("\nReverse List:\n\t");
	ListPrintReverse(l);
	spacing();

	// delete value in middle of the list
	l = ListDelete(l, 5);
	printf("\nAfter delete 5:\n\t");
	ListPrint(l);
	spacing();

	// delete value not in the list
	l = ListDelete(l, 100);
	printf("\nAfter delete 100:\n\t");
	ListPrint(l);
	spacing();

	// delete first value in list
	l = ListDelete(l, 1);
	printf("\nAfter delete 1:\n\t");
	ListPrint(l);
	spacing();

	// delete last value in list
	l = ListDelete(l, 9);
	printf("\nAfter delete 9:\n\t");
	ListPrint(l);
	spacing();

	// delete odd values in list
	l = ListDeleteOdds(l);
	printf("\nAfter delete odds:\n\t");
	ListPrint(l);
	spacing();

	// calculate list length
	printf("\nList Length is: ");
	printf("%d", ListLength(l));
	spacing();

	// list transform
	ListTransform(l);
	printf("\nAfter list transform:\n\t");
	ListPrint(l);
	spacing();

	// list delete every second
	l = ListDeleteSecond(l);
	printf("\nAfter deleting every second node:\n\t");
	ListPrint(l);
	spacing();

	// check if list is sorted
	printf("\n");
	printf(ListIsSorted(l) ? "List is sorted" : "List is not sorted");
	spacing();

	return 0;
}
