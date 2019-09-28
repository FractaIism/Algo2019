#include <iostream>
using namespace std;

int inversions(int[], int);

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << inversions(a, n);
	delete[] a;
}

int inversions(int a[], int n)
{
	int inv = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) ++inv;
		}
		inv %= 524287;
	}
	return inv;
}