#include <iostream>
#include <algorithm> // for heap utilities
#include <vector>
using namespace std;
// see https://stackoverflow.com/questions/23529815/how-to-use-stdmake-heap for why heap operations in the algorithm STL behave so strangely
int main()
{
	int N;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	make_heap(arr.begin(), arr.end(), greater<int>{}); // make arr into a min heap (std::greater is a comparator function returning true if lhs > rhs)
	vector<int>& heap = arr;
	int total_cost = 0;
	while (heap.size() > 1) {
		// extract smallest
		pop_heap(heap.begin(), heap.end(), greater<int>{});
		int min1 = heap.back();
		heap.pop_back();
		// extract second smallest
		pop_heap(heap.begin(), heap.end(), greater<int>{});
		int min2 = heap.back();
		heap.pop_back();
		// insert their sum
		heap.push_back(min1 + min2);
		push_heap(heap.begin(), heap.end(), greater<int>{});

		total_cost += min1 + min2;
		if (total_cost >= 524287) {
			total_cost %= 524287;
		}
	}
	cout << total_cost;
}