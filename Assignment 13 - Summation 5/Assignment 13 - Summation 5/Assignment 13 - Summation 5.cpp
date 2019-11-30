#include<iostream>
#include<vector>
using namespace std;

vector<int> maxSubArraySum(vector<int> a);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	vector<int> max_interval = maxSubArraySum(arr);
	cout << max_interval[0] << ' ' << max_interval[1];
}

vector<int> maxSubArraySum(vector<int> a)
{
	long long max_so_far = 0, max_ending_here = 0;
	int start_idx = 0, max_start_idx = 0, max_end_idx = 0;
	int all_neg = 1, least_neg_idx = 0;
	for (int i = 0; i < a.size(); i++) {
		max_ending_here = max_ending_here + a[i];
		if (max_ending_here < 0) {    // the previous segment adds up to negative, so don't include it and start anew
			max_ending_here = 0;
			start_idx = i + 1;
		} else if (max_ending_here > max_so_far) {    // new highscore, record it!
			max_so_far = max_ending_here;
			max_start_idx = start_idx;
			max_end_idx = i + 1;
		}    // else no breakthroughs yet
		if (a[i] > 0) all_neg = 0;
		else if (a[i] < 0) least_neg_idx = (a[least_neg_idx] < 0 && a[i] > a[least_neg_idx]) ? i : least_neg_idx;
	}
	if (all_neg) return vector<int> {least_neg_idx, least_neg_idx + 1};
	else return vector<int> {max_start_idx, max_end_idx};
}