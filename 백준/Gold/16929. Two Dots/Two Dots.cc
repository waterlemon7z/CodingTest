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

int N, M, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, visit[51][51] = {0,}, tarx, tary;

char input[51][51];

void dfs(char cur, int x, int y) // recursion
{
	int newx, newy, k = visit[x][y];
	for (int i = 0; i < 4; i++)
	{
		newx = dx[i] + x;
		newy = dy[i] + y;
		if (newx >= 0 && newx < N && newy >= 0 && newy < M && input[newx][newy] == cur)
		{
			if (visit[newx][newy] == 0)
			{
				visit[newx][newy] = k + 1;
				dfs(cur, newx, newy);
				visit[newx][newy] = 0;
			}
			else if (newx == tarx && newy == tary && abs(visit[newx][newy] - k) >= 3)
			{
				cout << "Yes";
				exit(0);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<pair<pii, char>> waita;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> input[i][j];
			waita.push({{i, j}, input[i][j]});
		}
	}
	while(!waita.empty())
	{
		auto item = waita.front();
		waita.pop();
		visit[item.first.first][item.first.second] = 1;
		tarx = item.first.first;
		tary = item.first.second;
		dfs(item.second, item.first.first, item.first.second);
		visit[item.first.first][item.first.second] = 0;
	}
	cout << "No";
}