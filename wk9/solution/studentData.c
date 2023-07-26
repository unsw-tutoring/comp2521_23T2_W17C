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
	int i = 0;
	while (scanf("%s %s %d %d", &students[i].zid, students[i].name,
	             &students[i].prog, &students[i].favnum) == 4) {
		i++;
	}

	// sort the students[] array
	int nstudents = i;
	qsort(students, nstudents, sizeof(Student), stuCmp);

	// print the contents of the students[] array
	for (i = 0; i < nstudents; i++) {
		printf("%7d %-20s %4d %d\n", students[i].zid, students[i].name,
		       students[i].prog, students[i].favnum);
	}
}
