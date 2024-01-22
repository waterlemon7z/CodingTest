#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
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
int N, M;
int adjacent[501][501] = {0,};
vector<int> bfs(int start)
{
	vector<int> dij(N + 1, INF);
	queue<pii> qq;
	qq.push({start, 0});
	while(!qq.empty())
	{
		int cur = qq.front().first;
		int cnt = qq.front().second;
		qq.pop();
		if(dij[cur] > cnt)
		{
			dij[cur] = cnt;
			for (int i = 1; i <= N; i++)
			{
				if(adjacent[cur][i] == 1)
					qq.push({i, cnt + 1});
			}
		}
	}
	return dij;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y, q, oper;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		adjacent[x][y] = 1;
		adjacent[y][x] = 1;
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> oper >> x >> y;
		if(oper == 1)
		{
			adjacent[x][y] = 1;
			adjacent[y][x] = 1;
		}
		else
		{
			adjacent[x][y] = 0;
			adjacent[y][x] = 0;
		}
		vector<int> rst = bfs(1);
		for(int l = 1; l <= N; l++)
		{
			cout << ((rst[l] == INF) ? -1 : rst[l]) << " ";
		}
		cout << endl;
	}
}