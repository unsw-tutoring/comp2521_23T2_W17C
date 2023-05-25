#include <stdbool.h>
#include <stdio.h>

#define NUM_ELEMS 10

bool isSorted(int *a, int n);

int main(void) {
	int array1[NUM_ELEMS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int array2[NUM_ELEMS] = {0, 1, 9, 3, 4, 5, 6, 7, 8, 2};

	printf("array1 is sorted: %s\n",
	       isSorted(array1, NUM_ELEMS) ? "true" : "false");
	printf("array2 is sorted: %s\n",
	       isSorted(array2, NUM_ELEMS) ? "true" : "false");
}

// Input:
// - a is a valid pointer to the start of an array of ints
// - n is a positive int indicating how many elements in a[]
// Output:
// - returns true if a[i] <= a[i + 1] for all i in [0..n - 2]
bool isSorted(int *a, int n) {
	// TODO: implement this function
}
