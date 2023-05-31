#include <stdio.h>

int main(void) {
	// rewrite this while loop as a for loop
	int j = 10;
	while (j >= 0) {
		printf("j is %d\n", j);
		j--;
	}
	printf("\n");

	// SOLUTION
	for (int i = 10; i >= 0; i--) {
		printf("i is %d\n", i);
	}
	printf("\n");
}
