#include <stdio.h>

// iterative solution for fibonnaci
int fibonnaci(int n) {
	int prevprev = 0;
	int prev = 1;
	int curr = 1;

	for (int i = 2; i < n; i++) {
		prevprev = prev;
		prev = curr;
		curr = prevprev + prev;
	}

	return curr;
}

// returns the nth Fibonnaci number
int fib(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

int main(void) {
	printf("fib(1)  = %d\n", fib(1));
	printf("fib(2)  = %d\n", fib(2));
	printf("fib(3)  = %d\n", fib(3));
	printf("fib(6)  = %d\n", fib(6));
	printf("fib(10) = %d\n", fib(10));
}