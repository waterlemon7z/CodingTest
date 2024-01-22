#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cmath>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int cnt = i;
		int frag = 0;
		while(cnt != 0)
		{
			frag += cnt % 10;
			cnt /= 10;
		}
		if(frag + i == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
}