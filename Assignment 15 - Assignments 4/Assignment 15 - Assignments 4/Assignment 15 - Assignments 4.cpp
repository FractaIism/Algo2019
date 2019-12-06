#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using ull = unsigned long long;

struct assignment {
	int score, due_time;
};

ull MaxScore(vector<assignment> &asg);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	cin >> n;
	vector<assignment> asg(n);
	for (int i = 0; i < n; ++i) {
		cin >> asg[i].score >> asg[i].due_time;
	}
	cout << MaxScore(asg);
}

// sort by due time in ascending order, then traverse the list
// if there is enough time to accomodate another assignment, add it
// if there is not enough time for another assignment but the current assignment gives better score than a previously chosen one, replace it
ull MaxScore(vector<assignment> &asg)
{
	sort(asg.begin(), asg.end(), [](auto a, auto b) { return a.due_time < b.due_time; }); // sort by due time
	priority_queue<int, vector<int>, greater<int>> scores; // scores of the picked assignments (min heap)
	for (int i = 0; i < asg.size(); ++i) {
		if (scores.size() < asg[i].due_time) {
			scores.push(asg[i].score);
		} else if (asg[i].score > scores.top()) {
			scores.pop();
			scores.push(asg[i].score);
		}
	}
	ull sum = 0;
	while (!scores.empty()) {
		sum += scores.top();
		scores.pop();
	}
	return sum;
}