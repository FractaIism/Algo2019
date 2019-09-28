#include <iostream>
using namespace std;
// Option 1,2 are different ways of counting the number of inversions, pick one at your leisure
long long MergeSort(int[], int, int);
long long Merge(int[], int, int, int); // count inversions while merging

int main()
{
	int n, *a;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long inversions = MergeSort(a, 0, n - 1);
	cout << inversions;
	delete[] a;
}

long long MergeSort(int a[], int p, int r)
{
	if (p >= r) return 0;

	int q = (p + r) / 2;
	long long inv = 0;
	inv += MergeSort(a, p, q);
	inv += MergeSort(a, q + 1, r);
	inv += Merge(a, p, q, r);
	return inv % 524287;
}

long long Merge(int a[], int p, int q, int r)
{
	int i = p, j = q + 1, k = 0; // index of left subarray a[p..q], right subarray a[q+1..r], sorted array b[0..r-p] respectively
	int *b = new int[r - p + 1]; // store sorted subarray
	long long inv = 0; // count inversions (must use long long int or it will overflow)
	while (i <= q && j <= r) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
			// Option 1
			// inv += (j - 1) - (q + 1) + 1;
		} else { // a[i] > a[j]
			b[k++] = a[j++];
			// Option 2
			inv += q - i + 1;
		}
	}
	// cleanup remaining elements
	while (i <= q) {
		b[k++] = a[i++];
		// Option 1
	    // inv += r - (q + 1) + 1;
	}
	while (j <= r) {
		b[k++] = a[j++];
	}
	// put sorted subarray back into a[]
	for (int l = 0; l < k; ++l) {
		a[p + l] = b[l];
	}
	delete[] b;
	return inv;
}