#include<iostream>
#include<vector>
#define max(a,b) (a>b)?a:b
using namespace std;
using ull = unsigned long long;

ull maxScore(vector<int>& s, vector<int>& t, int items, int time);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int m, n;
	cin >> n >> m;
	vector<int> s(n + 1), t(n + 1);	// s=scores, t=times
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> t[i];
	}
	cout << maxScore(s, t, n, m);
}

// OJ verdict RE (try iterative method with reduced table)
//ull maxScore(vector<int>& s, vector<int>& t, vector<vector<ull>>& dp, int item, int time)
//{
//	if (item <= 0 || time <= 0) return 0;
//	if (dp[item][time] > 0) return dp[item][time];
//	if (time < t[item]) dp[item][time] = maxScore(s, t, dp, item - 1, time);
//	else dp[item][time] = max(maxScore(s, t, dp, item - 1, time), maxScore(s, t, dp, item - 1, time - t[item]) + s[item]);
//	return dp[item][time];
//}

ull maxScore(vector<int>& s, vector<int>& t, int items, int time)
{
	vector<vector<ull>> dp(2, vector<ull>(time + 1, 0)); // only two rows necessary at a time (dp[2][time+1])
	for (int i = 1; i <= items; ++i) { // items
		for (int j = 0; j <= time; ++j) { // remaining time
			if (j < t[i]) {
				dp[i % 2][j] = dp[(i + 1) % 2][j]; // should be (i-1)%2 to reference the previous row, but use (i+1)%2 to prevent negatives
			} else {
				dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[(i + 1) % 2][j - t[i]] + s[i]);
			}
		}
	}
	return dp[items % 2][time];
}
