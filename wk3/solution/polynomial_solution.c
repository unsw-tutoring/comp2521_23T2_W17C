#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// evaluates a polynomial with coefficients for a given x value

// solution: O(n)
int polynomial(int *coefficients, int length, int x) {
	int totalSum = 0;
	int xPower = 1;

	for (int i = 0; i < length; i++) {
		totalSum += coefficients[i] * xPower;
		xPower *= x;
	}

	return totalSum;
}

int main(void) {
	return 0;
}
