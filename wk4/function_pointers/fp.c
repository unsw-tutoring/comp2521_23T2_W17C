#include <stdio.h>

int square(int num1) {
	return num1 * num1;
}

int main(void) {
	// declare a function pointer called fp
	int (*fp)(int);
	// fp points to the function 'square'
	fp = square;

	printf("the square function is located at %p\n", fp);

	printf("the square of 2 is %d\n", fp(2));
}
