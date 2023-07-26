#include <stdlib.h>

typedef struct student {
	char zid[8];    // 7-digit number
	char name[50];  // names are stored *within* the struct
	int prog;       // 4-digit number
	int favnum;     // favourite number
} Student;

// return -ve if a < b, +ve if a > b, 0 if a == b
int stuCmp(const void *a, const void *b);

int main(int argc, char *argv[]) {
	Student students[999];

	// read stdin line-by-line into students[]
	int num_students = 0;
	while (scanf("%s %s %d %d", &students[num_students]) == 4) {
		num_students++;
	}

	// sort the students[] array
	qsort(students, num_students, sizeof(struct student), stuCmp);

	// print the contents of the students[] array
	// use this format string "%s %-20s %4d %d\n"
	for (int i = 0; i < num_students; i++) {
		printf("%s %-20s %4d %d\n", students[i].zid, students[i].name,
		       students[i].prog, students[i].favnum);
	}
}
