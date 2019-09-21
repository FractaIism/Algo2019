#include<iostream>
#include<vector>
using namespace std;

void GenerateSelection(const vector<int>&, vector<int>);
void PrintSelection(const vector<int>&, const vector<int>&);

int main()
{
	int k;
	while (cin >> k) {
		if (k == 0) return 0;
		vector<int> S(k, 0), sel(1,1);
		for (int i = 0; i < k; ++i) {
			cin >> S[i];
		}
		GenerateSelection(S, sel);
	}
	return 0;
}

void GenerateSelection(const vector<int>& S, vector<int> sel)
{
	if (sel.size() == 6) {
		PrintSelection(S, sel);
		return;
	}
	sel.push_back(sel.back() + 1);
	for (int last = sel.back(); last < S.back(); ++last,++sel.back()) {
		GenerateSelection(S, sel);
	}
	return;
}

void PrintSelection(const vector<int>& S, const vector<int>& sel)
{
	for (int i = 0; i < sel.size(); ++i) {
		cout << S[i] << ' ';
	}
	cout<<'\n';
}