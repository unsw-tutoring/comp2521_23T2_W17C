#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct student {
	int zId;
	int mark;
};

// returns:
//      a number < 0 if first student is meant to be before second student
//      a number = 0 if first student is equal to second student
//      a number > 0 if first student is meant to be after second student
typedef int (*Comparator)(struct student, struct student);

// sort by zid
int sortByZid(struct student a, struct student b) {
	return a.zId - b.zId;
}

// sort by mark, but if mark is the same, sort by zid
int sortByMark(struct student a, struct student b) {
	int markDiff = a.mark - b.mark;

	if (markDiff != 0) return markDiff;

	return a.zId - b.zId;
}

// comparator is a function pointer to a function that takes two students and compares them
void sort(struct student *students, int length, Comparator comparator) {
	bool swapped = true;
	while (swapped) {
		swapped = false;

		for (int i = 0; i < length - 1; i++) {
			// here we call the comparator function
			if (comparator(students[i], students[i + 1]) > 0) {
				struct student temp = students[i];
				students[i] = students[i + 1];
				students[i + 1] = temp;
				swapped = true;
			}
		}
	}
}

int main(void) {
	const int SIZE = 5;

	struct student s1 = {1234569, 50};
	struct student s2 = {1234567, 99};
	struct student s3 = {1234571, 65};
	struct student s4 = {1234570, 85};
	struct student s5 = {1234568, 75};

	struct student list1[] = {s1, s2, s3, s4, s5};
	struct student list2[] = {s1, s2, s3, s4, s5};

	sort(list1, SIZE, sortByMark);
	sort(list2, SIZE, sortByZid);

	printf("Sorted by mark:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("zId: %d, mark: %d\n", list1[i].zId, list1[i].mark);
	}
	printf("\n");

	printf("Sorted by zid:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("zId: %d, mark: %d\n", list2[i].zId, list2[i].mark);
	}
	printf("\n");
}
