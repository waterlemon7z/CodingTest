#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
char arr[1001][1001] = {0,};
bool check[1001][1001] = {0,};
int R, C, rst = 0;

queue<pii> jihoon, fire,Njihoon, Nfire, cls;

bool solve()
{
	while(!Njihoon.empty())
	{
		jihoon = Njihoon;
		fire = Nfire;
		Njihoon = Nfire = cls;
		rst++;
		while (!jihoon.empty())
		{
			int x = jihoon.front().first;
			int y = jihoon.front().second;
			jihoon.pop();
			if (arr[x][y] == 'F')
			{
				continue;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= R || ny < 0 || ny >= C)
					return 1;
				if (arr[nx][ny] == '.' && check[nx][ny] == 0)
				{
					Njihoon.push({nx, ny});
					check[nx][ny] = 1;
				}
			}
		}
		while (!fire.empty())
		{
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= R || ny < 0 || ny >= C)
					continue;
				if (arr[nx][ny] == '.')
				{
					Nfire.push({nx, ny});
					arr[nx][ny] = 'F';
				}
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'J')
			{
				Njihoon.push({i, j});
			}
			else if (arr[i][j] == 'F')
			{
				Nfire.push({i, j});
			}
		}
	}

	if(solve())
	{
		cout << rst;
	}
	else cout << "IMPOSSIBLE";
}
