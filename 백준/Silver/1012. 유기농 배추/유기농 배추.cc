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

int T, N, M, K;
int arr[51][51], check[51][51], dx[] = {1,0,-1,0} ,dy[] = {0,1,0,-1};

void bfs(int x, int y)
{
	queue<pii> qq;
	qq.push({x, y});
	check[x][y] = 1;
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
			}
		}
	}
}

void init()
{
	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			arr[i][j] = check[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	int x,y, rst = 0;
	while(T--)
	{
		queue<pii> qq;
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			arr[x][y] = 1;
			qq.push({x,y});
		}
		while(!qq.empty())
		{
			pii cur = qq.front();
			qq.pop();
			if(check[cur.first][cur.second] == 1)
				continue;
			bfs(cur.first, cur.second);
			rst++;
		}
		cout << rst << endl;
		init();
		rst = 0;
	}
}