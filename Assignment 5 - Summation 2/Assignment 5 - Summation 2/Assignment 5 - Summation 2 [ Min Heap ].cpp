#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MinHeapify(vector<int>& heap, int node);
void BuildMinHeap(vector<int>& arr);
int ExtractMin(vector<int>& heap);
void InsertNode(vector<int>& heap, int key);
inline int leftChild(int index);
inline int rightChild(int index);
inline int parent(int index);

int main() 
{
	int N;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	BuildMinHeap(arr);
	vector<int>& heap = arr; // the array is now a min heap, so we shall refer to it as such
	int total_cost = 0;
	while (heap.size() > 1) {
		int min1 = ExtractMin(heap); // extract smallest
		int min2 = ExtractMin(heap); // extract second smallest
		InsertNode(heap, min1 + min2); // and put their sum back in
		total_cost += min1 + min2;
		if (total_cost >= 524287) { 
			total_cost %= 524287; // 3AC 7WA without this part
		}
	}
	cout << total_cost;
}

void MinHeapify(vector<int>& heap, int node) // adjust subheap rooted at 'node' to satisfy heap structure (only 'node' is misplaced within the subheap)
{
	int l = leftChild(node), r = rightChild(node), n = heap.size(), minNode = node;
	if (l < n && heap[l] < heap[node]) {
		minNode = l;
	}
	if (r < n && heap[r] < heap[minNode]) {
		minNode = r;
	}
	if (minNode != node) {
		swap(heap[node], heap[minNode]);
		MinHeapify(heap, minNode);
	}
}

void BuildMinHeap(vector<int>& arr)
{
	// start heapifying from the last node's parent (skip leaf nodes, which trivially satisfy heap structure)
	for (int node = parent(arr.size() - 1); node >= 0; --node) {
		MinHeapify(arr, node);
	}
}

int ExtractMin(vector<int>& heap)
{
	int minVal = heap.front();
	swap(heap.front(), heap.back());
	heap.resize(heap.size() - 1);
	MinHeapify(heap, 0);
	return minVal;
}

void InsertNode(vector<int>& heap, int key)
{
	heap.push_back(key);
	int node = heap.size() - 1;
	while (node >= 1) {
		if (heap[node] < heap[parent(node)]) {
			swap(heap[node], heap[parent(node)]);
			node = parent(node);
		} else break;
	}
}

int leftChild(int index)
{
	return 2 * index + 1;
}

int rightChild(int index)
{
	return 2 * index + 2;
}

int parent(int index)
{
	return (index - 1) / 2;
}