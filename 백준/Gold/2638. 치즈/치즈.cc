#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, int> pii;
int N, M, rst = 0;
int dx[4] = {1, 0 , -1, 0}, dy[4] = {0, 1, 0, -1};

vector<vector<int>> arr ,temparr;
queue<pii> qq;
queue<pii> tempqq, cls;

void aircheck()
{
	queue<pii> qqq;
	vector<vector<bool>> check(N, vector<bool>(M, 0));
	int xx, yy, nx, ny;
	qqq.push({0,0});
	while (!qqq.empty())
	{
		xx = qqq.front().first;
		yy = qqq.front().second;
		arr[xx][yy] = 0;
		qqq.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = dx[i] + xx;
			ny = dy[i] + yy;
			if(nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (arr[nx][ny] != 1)
			{
				if(check[nx][ny] == 0)
				{
					qqq.push({nx, ny});
					check[nx][ny] = 1;
				}
			}
		}
	}
}

void bfs()
{
	int xx, yy, nx, ny, cnt = 0;
	while(!tempqq.empty())
	{
		rst++;
		qq = tempqq;
		tempqq = cls;
		arr = temparr;
		aircheck();
		while (!qq.empty())
		{
			xx = qq.front().first;
			yy = qq.front().second;
			qq.pop();
			for (int i = 0; i < 4; i++)
			{
				nx = dx[i] + xx;
				ny = dy[i] + yy;
				if(nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;
				if (arr[nx][ny] == 0)
					cnt++;
			}
			if (cnt < 2)
				tempqq.push({xx, yy});
			else
				temparr[xx][yy] = 0;
			cnt = 0;
		}
	}
	cout << rst;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	arr = vector<vector<int>> (N, vector<int>(M, 0));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if( arr[i][j] == 0)
				arr[i][j] = -1;
			if( arr[i][j] == 1)
				tempqq.push({i, j});
		}
	}
	temparr = arr;
	bfs();
}

