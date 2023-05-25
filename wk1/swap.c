#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b);

int main(void) {
	int a = 5;
	int b = 7;
	swap(a, b);
	printf("a = %d, b = %d\n", a, b);
}

// why does this function fail to swap a & b in the main function
void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}
