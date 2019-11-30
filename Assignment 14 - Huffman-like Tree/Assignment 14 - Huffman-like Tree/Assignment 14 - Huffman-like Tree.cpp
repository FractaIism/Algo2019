#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ull = unsigned long long;

ull minWeightedLength(vector<int>& w);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> weights(n);
	for (int i = 0; i < n; ++i) {
		cin >> weights[i];
	}
	cout << minWeightedLength(weights);
}

ull minWeightedLength(vector<int>& w)
{
	priority_queue<ull, vector<ull>, greater<ull>> zaQ(w.begin(), w.end());
	while (zaQ.size() > 1) {
		ull min1, min2, sum;
		min1 = zaQ.top(); zaQ.pop();
		min2 = zaQ.top(); zaQ.pop();
		sum = min1 + min2;
		zaQ.push(sum << 1);
	}
	return zaQ.top();
}
