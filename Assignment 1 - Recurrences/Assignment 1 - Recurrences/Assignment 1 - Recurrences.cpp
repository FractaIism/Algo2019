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
		vector<int> S(k, 0), sel;
		for (int i = 0; i < k; ++i) {
			cin >> S[i];
		}
		GenerateSelection(S, sel);
		cout << '\n';
	} 
	return 0;
}

void GenerateSelection(const vector<int>& S, vector<int> sel)
{
	int k = S.size();
	if (sel.size() == 6) {
		PrintSelection(S, sel);
		return;
	} else if (sel.empty()) { //initial
		sel.push_back(0);
		for (int i = 0; i <= k - 6; ++i) {
			sel[0] = i;
			GenerateSelection(S, sel);
		}
		return;
	}

	for (sel.push_back(sel.back()+1); sel.back() + (6 - sel.size()) <= k - 1; ++sel.back()) {
		GenerateSelection(S, sel);
	}
	return;
}

void PrintSelection(const vector<int>& S, const vector<int>& sel)
{
	for (int i = 0; i < sel.size(); ++i) {
		cout << S[sel[i]] << ' ';
	}
	cout<<'\n';
	return;
}