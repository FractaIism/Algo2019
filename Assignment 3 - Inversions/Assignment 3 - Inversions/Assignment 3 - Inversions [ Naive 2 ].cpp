#include <iostream>
#include <vector>
#include <utility> //pair
#include <algorithm> //sort
using namespace std;
//pair<index,value>
int inversions(vector<pair<int, int>>);
bool compare(pair<int, int>, pair<int, int>);

int main()
{
	int n, a_i;
	cin >> n;
	vector<pair<int, int>> a(n, pair<int,int>(0,0));
	for (int i = 0; i < n; ++i) {
		cin >> a_i;
		a[i] = pair<int, int>(i, a_i);
	}
	cout << inversions(a);
}

int inversions(vector<pair<int, int>> a_pair)
{
	int inv = 0;
	sort(a_pair.begin(), a_pair.end(), compare);
	for (int i = 0; i < a_pair.size(); ++i) {
		for (int j = i + 1; j < a_pair.size(); ++j) {
			if (a_pair[i].second == a_pair[j].second) {
				continue;
			}
			if (a_pair[i].first > a_pair[j].first) {
				++inv;
			}
		}
		inv %= 524287;
	}
	return inv;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}