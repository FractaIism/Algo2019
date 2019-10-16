#include<iostream>
#include<stack>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int M, a, b, c, d;
	cin >> M;
	for (int n = 0; n < M; ++n) {
		cin >> a >> b >> c >> d;
		bool valid = true;
		stack<char> moves;
		while (!(c == a && d == b)) {
			if (c > d) { // right child of its parent
				c -= d;
				moves.push('R');
			} else { // left child of its parent
				d -= c;
				moves.push('L');
			}
			if (c < a || d < b) {
				valid = false;
				break;
			}
		}

		if (!valid) {
			cout << -1 << '\n';
			continue;
		}

		int index = 1;
		while (!moves.empty()) {
			switch (moves.top()) {
			case 'L':
				index = 2 * index;
				break;
			case 'R':
				index = 2 * index + 1;
				break;
			}
			moves.pop();
			if (index >= 524287) index %= 524287;
		}
		cout << index << '\n';
	}
}