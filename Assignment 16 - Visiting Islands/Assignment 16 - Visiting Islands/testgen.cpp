#include<fstream>
#include<cstdlib>
#include<time.h>
#define vertices 10000
#define edges 10000
using namespace std;

int main()
{
	ofstream file("testcase.txt");
	srand(time(NULL));
	int N, M;
	N = rand() % vertices + 1;
	while(N<vertices/2)
		N = rand() % vertices + 1;
	M = rand() % edges;
	while(M<N/2||M>N*2||M>N*(N-1)/2)
		M = rand() % edges;
	file << N << ' ' << M << '\n';
	for (int i = 0; i < M; ++i) {
		int v1, v2;
		v1 = rand() % N + 1;
		v2 = rand() % N + 1;
		while(v2==v1)
			v2 = rand() % N + 1;
		file << v1 << ' ' << v2 << '\n';
	}
	file.close();
}
