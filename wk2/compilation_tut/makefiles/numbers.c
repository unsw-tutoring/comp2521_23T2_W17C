#include <stdio.h>

#include "helperFunction.h"

#define MAX_TIMES 14

int main(void) {
	for (int i = 0; i < MAX_TIMES; i++) {
		printTwice(i);
	}
	printf("\n");

	return 0;
}
