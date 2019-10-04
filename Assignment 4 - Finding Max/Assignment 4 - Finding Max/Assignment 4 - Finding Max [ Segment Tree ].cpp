#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> buildSegmentTree(vector<int> arr);
int buildSegmentTreeUtil(vector<int>& arr, vector<int>& st, int ss, int se, int si);
void setValue(vector<int>& st, int n, int index, int newValue); // ugly af but need the n ( = arr.size() )
void setValueUtil(vector<int>& st, int index, int newValue, int ss, int se, int si);
int getMax(vector<int>& st, int n, int qs, int qe);
int getMaxUtil(vector<int>& st, int ss, int se, int qs, int qe, int si);
inline int parent(int);
inline int leftChild(int);
inline int rightChild(int);
inline int max(int, int);

int main()
{
	int n, m, i, j, k;
	cin >> n >> m;
	vector<int> arr(n, 0); // arr no longer used after constructing the segment tree
	for (int l = 0; l < n; ++l) {
		cin >> arr[l];
	}

	vector<int> st = buildSegmentTree(arr); // using vector instead of new int[] to catch index out of bounds error
	for (int l = 0; l < m; ++l) {
		cin >> i >> j >> k;
		if (i == 1) {
			setValue(st, arr.size(), j, k); // set arr[j] = k
		} else { // i == 2
			cout << getMax(st, n, j, k) << '\n'; // get max value in arr[j..k]
		}
	}
}

vector<int> buildSegmentTree(vector<int> arr) // arrays passed by reference by default (since they are just pointers!)
{
	// find an appropriate size for the segment tree array
	int size = 1;
	while (size < arr.size()) {
		size = (size << 1);
	}
	size = (size << 1) - 1;
	vector<int> st(size, 0);
	buildSegmentTreeUtil(arr, st, 0, arr.size() - 1, 0); // build segment tree recursively from root node
	return st;
}

// st = segment tree array
// ss = segment start (first index of arr)
// se = segment end (last index of arr)
// si = segment node index
int buildSegmentTreeUtil(vector<int>& arr, vector<int>& st, int ss, int se, int si)
{
	if (ss == se) {
		st[si] = arr[ss];
		return st[si];
	}
	int mid = (ss + se) / 2; // index addition won't overflow, no need for tricks
	st[si] = max(
				buildSegmentTreeUtil(arr, st, ss, mid, leftChild(si)),
				buildSegmentTreeUtil(arr, st, mid + 1, se, rightChild(si))
				);
	return st[si];
}

void setValue(vector<int>& st, int n, int index, int newValue)
{
	setValueUtil(st, index, newValue, 0, n - 1, 0);
}

void setValueUtil(vector<int>& st, int index, int newValue, int ss, int se, int si)
{
	if (ss == se) { // ss = se = index
		st[si] = newValue;
		return;
	}
	int mid = (ss + se) / 2;
	if (index <= mid) {
		setValueUtil(st, index, newValue, ss, mid, leftChild(si));
	} else {
		setValueUtil(st, index, newValue, mid + 1, se, rightChild(si));
	}
	st[si] = max(st[leftChild(si)], st[rightChild(si)]);
}

// qs = query start index
// qe = query end index
int getMax(vector<int>& st, int n, int qs, int qe)
{
	return getMaxUtil(st, 0, n - 1, qs, qe, 0);
}

int getMaxUtil(vector<int>& st, int ss, int se, int qs, int qe, int si)
{
	// segment completely outside of query range
	if (ss > qe || se < qs) {
		return INT_MIN;
	}
	// segment contained within query range
	if (ss >= qs && se <= qe) {
		return st[si];
	}
	// part of segment within query range
	int mid = (ss + se) / 2;
	return max(
				getMaxUtil(st, ss, mid, qs, qe, leftChild(si)), 
				getMaxUtil(st, mid + 1, se, qs, qe, rightChild(si))
			);
}

int parent(int index)
{
	return index / 2; // floor'd due to int data type
}

int leftChild(int index)
{
	return 2 * index + 1;
}

int rightChild(int index)
{
	return 2 * index + 2;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}