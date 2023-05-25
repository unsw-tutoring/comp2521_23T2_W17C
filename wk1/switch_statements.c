#include <stdio.h>

int main(void) {
	char ch = 'a';

	// S1
	printf("S1\n");

	switch (ch) {
		case 'a': printf("eh? "); break;
		case 'e': printf("eee "); break;
		case 'i': printf("eye "); break;
		case 'o': printf("ohh "); break;
		case 'u': printf("you "); break;
	}
	printf("\n\n");

	// S2
	printf("S2\n");

	switch (ch) {
		case 'a': printf("eh? ");
		case 'e': printf("eee ");
		case 'i': printf("eye ");
		case 'o': printf("ohh ");
		case 'u': printf("you ");
	}
	printf("\n");
}
