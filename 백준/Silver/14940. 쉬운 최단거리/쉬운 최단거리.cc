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

int board[1001][1001] = {0,};

int rst[1001][1001] = {0,}, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void bfs(queue<pii> qq)
{
	queue<pii> temp;
	while (!qq.empty())
	{
		int x = qq.front().first;
		int y = qq.front().second;
		int cur = rst[x][y];
		qq.pop();
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M)
			{
				if (rst[x + dx[i]][y + dy[i]] > cur + 1)
				{
					rst[x + dx[i]][y + dy[i]] = cur + 1;
					temp.push({x + dx[i], y + dy[i]});
				}
			}
		}
	}
	if (!temp.empty())
		bfs(temp);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	queue<pii> qq;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				rst[i][j] = 0;
				qq.push({i, j});
			}
			else if (board[i][j] == 0)
				rst[i][j] = 0;
			else
				rst[i][j] = INF;
		}
	}
	bfs(qq);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << (rst[i][j] == INF ? -1 : rst[i][j]) << " ";
		}
		cout << endl;
	}

}