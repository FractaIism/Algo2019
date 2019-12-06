#include<iostream>
#include<vector>
#include<set>
using namespace std;

void reach(int N, vector<vector<int>>& bridges);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> bridges(M, vector<int>(2));
	for (int i = 0; i < M; ++i) {
		cin >> bridges[i][0] >> bridges[i][1];
		--bridges[i][0]; --bridges[i][1]; // make island indexes zero-based
	}
	reach(N, bridges);
}

void reach(int N, vector<vector<int>>& bridges)
{
	vector<set<int>> islands(N);
	vector<int> inset(N); // which set is this island in?
	for (int i = 0; i < N; ++i) {
		islands[i].insert(i);
		inset[i] = i;
	}
	for (int i = 0; i < bridges.size(); ++i) {
		int src = bridges[i][0], dst = bridges[i][1];
		if (inset[src] == inset[dst]) continue;
		set<int>& src_set = islands[inset[src]];
		set<int>& dst_set = islands[inset[dst]];
		int sel = (src_set.size() > dst_set.size()) ? 0 : 1; // select the set with most islands to keep (to minimize the number of elements to move)
		if (sel == 0) { // keep src_set
			for (set<int>::iterator it = dst_set.begin(); it != dst_set.end(); ++it) {
				src_set.insert(*it);
				inset[*it] = inset[src];
			}
			dst_set.clear();
		} else { // keep dst_set
			for (set<int>::iterator it = src_set.begin(); it != src_set.end(); ++it) {
				dst_set.insert(*it);
				inset[*it] = inset[dst];
			}
			src_set.clear();
		}
	}
	//for (int i = 0; i < islands.size(); ++i) {
	//	cout << i << ": ";
	//	for (set<int>::iterator it = islands[i].begin(); it != islands[i].end(); ++it) {
	//		cout << *it << ' ';
	//	}
	//	cout << endl;
	//}
	for (int i = 0; i < islands.size(); ++i) {
		cout << islands[inset[i]].size() - 1 << ' ';
	}
}