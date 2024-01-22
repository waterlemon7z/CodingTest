#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, cur = 1, i;
	cin >> N >> M;
	cout << 0 << ' ' << 1 << endl;
	for(i = 2; i < N - M + 1; i++)
	{
		cout << cur << ' ' << i << endl;
		cur++;
	}
	for( ; i < N; i++)
	{
		cout << cur << ' ' << i << endl;
	}
}