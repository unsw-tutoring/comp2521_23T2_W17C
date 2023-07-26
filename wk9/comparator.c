#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ZID_LEN 8

typedef struct student {
	char zid[ZID_LEN + 1];
	int mark;
	/* ... other fields ...*/
};
typedef struct student *Student;

typedef int (*Comparator)(Student, Student);

/**
 * @brief Compare two students by their mark in descending order, then by zid in ascending order.
 * 
 * @return 
 *      int < 0 if student a has higher mark than student b, 
 *              or same mark but lower zid than student b
 *      int = 0 if student a has same mark and zid as student b
 *      int > 0 if student a has lower mark than student b, 
 *              or same mark but higher zid than student b
 */
int studentCmp(Student a, Student b) {
	if (a->mark - b->mark != 0) {
		return b->mark - a->mark;
	}
	return strcmp(a->zid, b->zid);
}

// comparator is a function pointer to a function that takes two students and compares them
void sort(struct student *students, int length, Comparator comparator) {
	bool swapped = true;
	while (swapped) {
		swapped = false;

		for (int i = 0; i < length - 1; i++) {
			// here we call the comparator function
			if (comparator(&students[i], &students[i + 1]) > 0) {
				struct student temp = students[i];
				students[i] = students[i + 1];
				students[i + 1] = temp;
				swapped = true;
			}
		}
	}
}

int main(void) {
	sort({}, 0, studentCmp);
}
