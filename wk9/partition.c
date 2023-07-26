int partition(int A[], int lo, int hi) {
	int pivot = A[lo];  // pivot
	int l = lo + 1;
	int r = hi;
	while (l < r) {
		while (l < r && A[l] <= pivot)
			l++;
		while (l < r && A[r] >= pivot)
			r--;
		if (l == r) break;
		swap(A, l, r);
	}
	int m = A[l] <= pivot ? l : l - 1;
	swap(A, lo, m);
	return m;
}
