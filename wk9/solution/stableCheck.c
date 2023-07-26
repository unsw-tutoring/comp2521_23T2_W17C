#include <stdbool.h>

typedef struct {
	int a;
	int b;
} Item;

bool isStableSort(Item original[], Item sorted[], int size) {
	int i, j, k, key;

	for (i = 0; i < size; i++) {
		// current item we are examining
		key = sorted[i].a;

		j = 0;
		k = 0;

		while (j < size && k < size) {
			// find the next item in the sorted[] array that has the same .a value
			for (; j < size; j++)
				if (sorted[j].a == key) break;

			// find the next item in the original[] array that has the same .a value
			for (; k < size; k++)
				if (original[k].a == key) break;

			if (j < size && k < size) {
				// if j and b are not the same Item (i.e., their b value different),
				// then the sort was not stable, since their must be out of order
				if (sorted[j].b != original[k].b) return false;

				j++;
				k++;
			}
		}
	}
	return true;
}
