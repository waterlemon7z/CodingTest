#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
queue<pair<int, int>> qq;

int bfs(vector<vector<int>> arr)
{
	vector<vector<int>> dist(M, vector<int>(N, INF));
	dist[0][0] = 0;

	int  cr, cc, nr, nc;
	qq.push({0,0});
	while(!qq.empty())
	{
		cr = qq.front().first;
		cc = qq.front().second;
		qq.pop();
		for(int i = 0; i < 4; i++)
		{
			nr = cr + dy[i];
			nc = cc + dx[i];
			if(nr < 0 || nr >= M || nc < 0 || nc >= N)
				continue;
			if(arr[nr][nc] == 1)
			{
				if(dist[cr][cc] + 1 < dist[nr][nc])
				{
					dist[nr][nc] = dist[cr][cc] + 1;
					qq.push({nr,nc});
				}
			}
			else if(arr[nr][nc] == 0)
			{
				if(dist[cr][cc] < dist[nr][nc])
				{
					dist[nr][nc] = dist[cr][cc];
					qq.push({nr,nc});
				}
			}
		}
	}
	return dist[M-1][N-1];
}

int main()
{
	char ch;
	cin >> N >> M;
	vector<vector<int>> arr(M, vector<int>(N, 0));
	for(int i = 0 ; i < M; i++)
	{
		for(int j = 0 ; j < N; j++)
		{
			ch = cin.get();
			if(ch == '\n')
				ch = cin.get();
			arr[i][j] = ch - '0';
		}
	}
	cout << bfs(arr);
}
