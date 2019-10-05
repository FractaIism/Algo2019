// a file made for testing and correcting heap operations
#include<iostream>
#include<vector>
using namespace std;
void MinHeapify(vector<int>& heap, int node);
void BuildMinHeap(vector<int>& arr);
int ExtractMin(vector<int>& heap);
void InsertNode(vector<int>& heap, int key);
inline int leftChild(int index);
inline int rightChild(int index);
inline int parent(int index);

void print(vector<int> arr)
{
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main()
{
	vector<int> heap;
	heap.push_back(11);
	heap.push_back(5);
	heap.push_back(6);
	heap.push_back(3);
	heap.push_back(22);
	heap.push_back(37);
	heap.push_back(45);
	heap.push_back(0);
	heap.push_back(9);
	cout << "Start" << endl;
	print(heap);
	cout << "Build heap" << endl;
	BuildMinHeap(heap);
	print(heap);
	cout << "Insert 33" << endl;
	InsertNode(heap, 33);
	print(heap);
	cout << "Insert 1" << endl;
	InsertNode(heap, 1);
	print(heap);
	cout << "Extract min" << endl;
	cout << "min = " << ExtractMin(heap) << endl;
	print(heap);
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
