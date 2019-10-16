#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Point {
	// seq: sequence number, indicates the index of this point in the original input
	int x, y, rank = 0, seq = 0;
};

void MergeSort(vector<Point> &pts, int L, int R);
void Merge(vector<Point> &pts, int L, int M, int R);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	cin >> n;
	vector<Point> pts(n, Point{ 0,0 });
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		pts[i] = Point{ x,y,0,i };
	}
	// sort by x
	sort(pts.begin(), pts.end(), [](const Point &p1, const Point &p2) {return (p1.x != p2.x) ? (p1.x < p2.x) : (p1.y < p2.y); }); // < or <= both work?
	MergeSort(pts, 0, n - 1);
	sort(pts.begin(), pts.end(), [](const Point &p1, const Point &p2) {return p1.seq < p2.seq; }); // put them back in order
	for (auto pt : pts) {
		cout << pt.rank << ' ';
	}
}

void MergeSort(vector<Point> &pts, int L, int R) // sort by y
{
	if (L >= R) return;

	int M = (L + R) / 2;
	MergeSort(pts, L, M);
	MergeSort(pts, M + 1, R);
	Merge(pts, L, M, R);
}

void Merge(vector<Point> &pts, int L, int M, int R)
{
	int i = M, j = R, k = R - L; // go in reverse order to count rank in O(1) rather than O(n)
	vector<Point> tmp(R - L + 1, Point{ 0,0 });
	while (i >= L && j >= M + 1) {
		if (pts[j].y >= pts[i].y) { // pts[j] dominates pts[i]
			pts[j].rank += i - L + 1;
			tmp[k--] = pts[j--];
		} else { // no domination occurs
			tmp[k--] = pts[i--];
		}
	}
	// cleanup
	while (i >= L) tmp[k--] = pts[i--];
	while (j >= M + 1) tmp[k--] = pts[j--];
	for (k = 0; k <= R - L; ++k) {
		pts[L + k] = tmp[k];
	}
}