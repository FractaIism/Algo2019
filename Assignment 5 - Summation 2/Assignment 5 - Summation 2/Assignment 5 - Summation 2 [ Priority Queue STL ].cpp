#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, num;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> prioQ;
	// push numbers into priority queue to contruct min heap while taking input
	// or take input into vector and then pass vector iterators into priority queue constructor to have min heap created automatically
	// syntax: priority_queue<int, vector<int>, greater<int>> prioQ(vec.begin(), vec.end()); for the second approach
	for (int i = 0; i < N; ++i) {
		cin >> num;
		prioQ.push(num);
	}

	int total_cost = 0;
	while (prioQ.size() > 1) {
		// extract smallest
		int min1 = prioQ.top();
		prioQ.pop();
		// extract second smallest
		int min2 = prioQ.top();
		prioQ.pop();
		// insert their sum
		prioQ.push(min1 + min2);

		total_cost += min1 + min2;
		if (total_cost >= 524287) {
			total_cost %= 524287;
		}
	}
	cout << total_cost;
}