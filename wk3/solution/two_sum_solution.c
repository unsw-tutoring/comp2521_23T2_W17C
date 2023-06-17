#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// returns a boolean declaring whether there are two numbers in
// the array that sum to the target. length contains the number
// of values in the nums array

// solution: O(n^2)
bool two_sum(int *nums, int length, int target) {
	// outer loop runs ~n times
	for (int i = 0; i < length; i++) {
		// inner loop runs (length - i - 1) times
		for (int j = i; j < length; j++) {
			if (nums[i] + nums[j] == target) {
				return true;
			}
		}
	}

	return false;
}

int main(void) {
	return 0;
}
