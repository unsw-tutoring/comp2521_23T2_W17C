#include <stdio.h>

int main() {
	int a = 5;
	int b = 123;

	int *pa = &a;
	int *pb = &b;

	printf("a is %d and is located at address %p\n", a, &a);
	printf("b is %d and is located at address %p\n", b, &b);

	*pa = 6;
	*pb = 234;

	printf("\nChanging...\n\n");

	printf("a is %d and is located at address %p\n", a, &a);
	printf("b is %d and is located at address %p\n", b, &b);

	int c = *pa;

	printf("\nChanging...\n\n");

	printf("c is %d and is located at address %p\n", c, &c);

	*pa = *pb;
	*pb = c;

	printf("\nChanging...\n\n");

	printf("a is %d and is located at address %p\n", a, &a);
	printf("b is %d and is located at address %p\n", b, &b);
	printf("c is %d and is located at address %p\n", c, &c);

	pa = pb;
	*pa = 345;

	printf("\nChanging...\n\n");

	printf("a is %d and is located at address %p\n", a, &a);
	printf("b is %d and is located at address %p\n", b, &b);
	printf("c is %d and is located at address %p\n", c, &c);
}
