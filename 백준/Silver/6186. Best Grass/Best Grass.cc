#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, int> pii;
int R, C, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char arr[101][101] = {0,};
//bool check[101][101] = {0,};
queue<pii> glass;

void bfs()
{
	int xx, yy, nx, ny, rst = 0;
	queue<pii> qq;
//	qq.push(glass.front());
//	glass.pop();
	while(1)
	{
		while(!glass.empty() && arr[glass.front().first][glass.front().second] == '.')
		{
			glass.pop();
		}
		if(glass.empty())
			break;
		qq.push({glass.front().first, glass.front().second});
		glass.pop();
		while(!qq.empty())
		{
			xx = qq.front().second;
			yy = qq.front().first;
			arr[yy][xx] = '.';
			qq.pop();
			for(int i = 0 ;i  < 4; i++)
			{
				nx = xx + dx[i];
				ny = yy + dy[i];
				if(nx >= 0 && nx < C && ny >= 0 && ny < R)
				{
					if( arr[ny][nx] == '.')
					{
						continue;
					}
					arr[ny][nx] = '.';
					qq.push({ny, nx});
				}
			}
		}
		rst++;
	}
	cout << rst;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			cin  >> arr[i][j];
			if(arr[i][j] == '#')
				glass.push({i,j});
		}
	}
	bfs();
}