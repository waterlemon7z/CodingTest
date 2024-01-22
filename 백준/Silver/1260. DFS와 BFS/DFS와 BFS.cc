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

int adjacent[1001][1001] = {0,};

bool dfsCheck[1001] = {0,};
int N, M, S, x, y;

void dfs(int cur)
{
	cout << cur << ' ';
	dfsCheck[cur] = 1;
	for (int iter = 1; iter <= N; iter++)
	{
		if (!dfsCheck[iter] && adjacent[cur][iter])
			dfs(iter);
	}
}

void bfs(int cur)
{
	bool check[1001] = {0,};
	queue<int> q;
	q.push(cur);
	check[cur] = 1;
	while (!q.empty())
	{
		int cnt = q.front();
		cout << cnt << ' ';
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			int iter = adjacent[cnt][i];
			if (!check[i] && iter)
			{
				check[i] = 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> S;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		adjacent[x][y] = 1;
		adjacent[y][x] = 1;
	}
	dfs(S);
	cout << endl;
	bfs(S);
}