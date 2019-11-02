#include<iostream>
#define max(a, b) ((a > b) ? a : b)
using namespace std;
using ull = unsigned long long;
ull MaxSum(int a[], int n);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ull maxsum = max(MaxSum(a, n - 1), MaxSum(a + 1, n - 1));
	cout << maxsum;
	delete[] a;
}

ull MaxSum(int a[], int n)
{
	ull incl = a[0], excl = 0, tmpincl;
	for (int i = 1; i < n; ++i) {
		tmpincl = incl;
		incl = excl + a[i];
		excl = max(tmpincl, excl);
	}
	return (incl > excl) ? incl : excl;
}