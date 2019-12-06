#include<iostream>
#include<vector>
#include<set>
using namespace std;

void Reachability(int N, vector<vector<int>>& bridges);
bool updateReach(int from, int relay, vector<set<int>>& can_reach, vector<set<int>>& reachable_from);

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
	Reachability(N, bridges);
}

void Reachability(int N, vector<vector<int>>& bridges)
{
	vector<set<int>> can_reach(N); // for each island, which islands can be reached from here? (store the answer here)
	vector<set<int>> reachable_from(N); // for each island, which islands can reach here? (to tell which ones should be updated)
	set<int> changed; // add island to changed when its reach set (can_reach) is updated and modified with another island's reach set

	for (int i = 0; i < bridges.size(); ++i) {
		int src = bridges[i][0], dst = bridges[i][1];
		can_reach[src].insert(dst);
		reachable_from[dst].insert(src);
		changed.insert(src);
		// add these 3 lines to make it an undirected graph
		can_reach[dst].insert(src);
		reachable_from[src].insert(dst);
		changed.insert(dst);
	}
	int iter = -1;
	while (!changed.empty()) {
		set<int>::iterator relay = changed.begin();
		// update set of reachable islands for all those which depend on relay
		for (set<int>::iterator from = reachable_from[*relay].begin(); from != reachable_from[*relay].end(); ++from) {
			bool change = updateReach(*from, *relay, can_reach, reachable_from);
			if (change) changed.insert(*from);
		}
		changed.erase(relay);
	}

	// uncomment to see the reach set of each island
	//for (int i = 0; i < N; ++i) {
	//	cout << i + 1 << ':';
	//	for (set<int>::iterator it = can_reach[i].begin(); it != can_reach[i].end(); ++it) {
	//		cout << *it + 1 << ' ';
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < N; ++i) {
		cout << can_reach[i].size() << ' ';
	}
}

bool updateReach(int from, int relay, vector<set<int>>& can_reach, vector<set<int>>& reachable_from)
{
	bool change = false;
	for (set<int>::iterator dest = can_reach[relay].begin(); dest != can_reach[relay].end(); ++dest) {
		if (*dest != from && can_reach[from].find(*dest) == can_reach[from].end()) { // island not already in set, new reachable island found
			change = true;
			can_reach[from].insert(*dest);
			reachable_from[*dest].insert(from);
		}
	}
	return change;
}