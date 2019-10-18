// see: https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pairSum {
	int first, second, sum; // index of first and second element, and the sum of these elements
	pairSum() {}
	pairSum(int n1, int n2, int s) : first(n1), second(n2), sum(s) {}
};

int ZeroSum(vector<int> &a);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << ZeroSum(a);
}

int ZeroSum(vector<int> &a)
{
	sort(a.begin(), a.end(), [](int n1, int n2) {return n1 < n2; });

	int n = a.size();
	vector<pairSum> pairS;
	pairS.resize(n*(n - 1));
	int k = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			pairS[k++] = pairSum(i, j, a[i] + a[j]);
		}
	}
	pairS.resize(k);

	sort(pairS.begin(), pairS.end(), [](pairSum ps1, pairSum ps2) {return ps1.sum < ps2.sum; });
	int i = 0, j = k - 1, valid = 0;
	while (i < j) {
		int quadSum = pairS[i].sum + pairS[j].sum;
		if (quadSum < 0) {
			++i;
		} else if (quadSum > 0) {
			--j;
		} else {
			// check that there are no common elements in the pair sum
			// assume all elements in the original a array are distinct
			if (pairS[i].first != pairS[j].first && pairS[i].second != pairS[j].second) {
				valid = 1;
				break;
			} else ++i;
		}
	}

	return valid;
}