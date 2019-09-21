#include<iostream>
using namespace std;

void PrintSelection(int[], int[]);
void GenerateSelection(int[], int);

int main()
{
	int k;
	while (cin >> k) {
		if (k == 0) return 0;
		int *S = new int[k];
		for (int i = 0; i < k; ++i) {
			cin >> S[i];
		}
		GenerateSelection(S, k);
		cout << '\n';
		delete[] S;
	}
}

void GenerateSelection(int S[], int k)
{
	int a[6 + 1]; //index to select from S
	for (a[1] = 0; a[1] + (6 - 1) <= k - 1; ++a[1]) {
		for (a[2] = a[1] + 1; a[2] + (6 - 2) <= k - 1; ++a[2]) {
			for (a[3] = a[2] + 1; a[3] + (6 - 3) <= k - 1; ++a[3]) {
				for (a[4] = a[3] + 1; a[4] + (6 - 4) <= k - 1; ++a[4]) {
					for (a[5] = a[4] + 1; a[5] + (6 - 5) <= k - 1; ++a[5]) {
						for (a[6] = a[5] + 1; a[6] + (6 - 6) <= k - 1; ++a[6]) {
							PrintSelection(S, a);
						}
					}
				}
			}
		}
	}
}

void PrintSelection(int S[], int a[])
{
	for (int i = 1; i <= 6; ++i) {
		cout << S[a[i]] << ' ';
	}
	cout << '\n';
	return;
}