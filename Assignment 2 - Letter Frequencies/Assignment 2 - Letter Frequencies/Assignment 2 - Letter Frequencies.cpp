#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int a, int b)
{
	return (a < b);
}

int main()
{
	string capstr;
	cin >> capstr;
	vector<int> freq('Z' + 1, 0);
	int len = capstr.length(); //supposedly O(1), but just to be safe
	for (int i = 0; i < capstr.length(); ++i) {
		++freq[capstr[i]];
	}

	vector<int> cpy(freq);
	sort(cpy.begin(), cpy.end(), compare);
	int lastnum = 0;
	for (int i = cpy.size() - 1; i >= 0; --i) {
		if (cpy[i] == 0) break;
		if (cpy[i] == lastnum) continue;
		lastnum = cpy[i];
		for (int c = 'A'; c <= 'Z'; ++c) {
			if (freq[c] == cpy[i]) {
				cout << c << ' ' << freq[c] << '\n';
			}
		}
	}
}