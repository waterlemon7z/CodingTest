#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int N ,M, baseval = 0, dx[4] = {0,1,0,-1}, dy[4]={1,0,-1,0};
int rst = 0;
vector<vector<int>> basearr(8, vector<int> (8,0));
queue<pii> basequeue;

bool checkbound(int x, int y)
{
	if(x >= 0 && x < M && y >= 0 && y < N)
		return true;
	return false;
}

void bfs()
{
	int xx, yy, nx, ny, currst = baseval;
	queue<pii>qq;
	vector<vector<int>> arr;
	arr = basearr;
	qq = basequeue;
	while(!qq.empty())
	{
		yy = qq.front().first;
		xx = qq.front().second;
		qq.pop();
		for(int  i = 0 ; i < 4; i++)
		{
			nx = xx + dx[i];
			ny = yy + dy[i];
			if(checkbound(nx, ny))
			{
				if(arr[ny][nx] == 0)
				{
					arr[ny][nx] = 2;
					qq.push({ny, nx});
					currst--;
				}
			}
		}
		if(currst < rst)
			return;
	}
	if(currst > rst)
		rst = currst;
}

void backT(int row, int col, int cur)
{
	if(cur == 3)
	{
		bfs();
		return;
	}
	int j = col;
	for(int i = row; i < N; i++)
	{
		for(; j < M; j++)
		{
			if(basearr[i][j] == 0)
			{
				basearr[i][j] = 1;
				backT(i, j + 1, cur + 1);
				basearr[i][j] = 0;
			}
		}
		j = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> basearr[i][j];
			if(basearr[i][j] == 0)
			{
				baseval ++;
			}
			else if (basearr[i][j] == 2)
			{
				basequeue.push({i,j});
			}
		}
	}
	backT(0, 0, 0);
	cout << rst - 3;
}