#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;

int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	if(N == M)
	{
		cout << 0;
		return 0;
	}
	queue<pii> qq;
	int check[100001] = {0,}, rst = INF;
	qq.push({N, 1});
	check[N] = 1;
	while (!qq.empty())
	{
		pii cur = qq.front();
		qq.pop();

		if (cur.first * 2 <= 100000 && check[cur.first * 2] == 0)
		{
			qq.push({cur.first * 2, cur.second + 1});
			check[cur.first * 2] = 1;
		}
		if (cur.first + 1 <= 100000 && check[cur.first + 1] == 0)
		{
			qq.push({cur.first + 1, cur.second + 1});
			check[cur.first + 1] = 1;
		}
		if (cur.first - 1 >= 0 && check[cur.first - 1] == 0)
		{
			qq.push({cur.first - 1, cur.second + 1});
			check[cur.first - 1] = 1;
		}

		if (cur.first * 2 == M || cur.first - 1 == M || cur.first + 1 == M)
		{
			rst = min (rst, cur.second);
		}
	}
	cout << rst;
}