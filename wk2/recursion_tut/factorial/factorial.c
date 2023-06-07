#include <stdio.h>

// recursive version
int factorial(int n) {
	// because 0! == 1
	// this is the base case
	if (n == 0)
		return 1;

	// this is the recursive case
	return n * factorial(n - 1);
}

int main(void) {
	for (int i = 0; i < 10; i++) {
		printf("%d! = %d\n", i, factorial(i));
	}
}
