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
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0}, arr[501][501] = {0,}, check[501][501] = {0,};
int bfs(int x, int y)
{
	int rst = 0;
	queue<pii> qq;
	qq.push({x, y});
	check[x][y] = 1;
	rst++;
	while(!qq.empty())
	{
		pii cur = qq.front();
		qq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if(nx >= 0 && nx < N && ny >= 0 && ny < M && check[nx][ny] == 0 && arr[nx][ny] == 1)
			{
				qq.push({nx,ny});
				check[nx][ny] = 1;
				rst++;
			}
		}
	}
	return rst;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int rst = 0, biggest = 0;
	queue<pii> qq;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j]== 1)
			{
				qq.push({i,j});
			}
		}
	}
	while(!qq.empty())
	{
		pii cur = qq.front();
		qq.pop();
		if(check[cur.first][cur.second] == 1)
			continue;
		biggest = max(bfs(cur.first, cur.second), biggest);
		rst++;
	}
	cout << rst << endl << biggest;
}