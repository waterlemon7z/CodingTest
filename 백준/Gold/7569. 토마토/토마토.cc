#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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

typedef struct _loc
{
	short x, y, z;
} Loc;

int N, M, H, input[101][101][101], cnt = 0, day = 1, rst = 0;

int dx[] = {1, 0, -1, 0, 0, 0}, dy[] = {0, -1, 0, 1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};

void bfs(queue<Loc> cur)
{
	short x, y, z, xx, yy, zz;
	int curDay;
	while (!cur.empty())
	{
		x = cur.front().x;
		y = cur.front().y;
		z = cur.front().z;
		curDay = input[x][y][z];
		cur.pop();
		for (int i = 0; i < 6; i++)
		{
			xx = x + dx[i];
			yy = y + dy[i];
			zz = z + dz[i];
			if (xx >= 0 && xx < M && yy >= 0 && yy < N && zz >= 0 && zz < H)
			{
				if (input[xx][yy][zz] == 0)
				{
					input[xx][yy][zz] = curDay + 1;
					rst++;
					cur.push({xx, yy, zz});
				}
			}
		}
		if (rst == cnt)
		{
			cout << curDay ;
			return;
		}
	}
	cout << -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<Loc> cur;
	cin >> M >> N >> H;
	for (short k = 0; k < H; k++)
	{
		for (short j = 0; j < N; j++)
		{
			for (short i = 0; i < M; i++)
			{
				cin >> input[i][j][k];
				if (input[i][j][k] == 1)
				{
					cur.push({i, j, k});
				}
				else if (input[i][j][k] == 0)
					cnt++;
			}
		}
	}
	if (rst == cnt)
	{
		cout << 0;
		return 0;
	}
	bfs(cur);
}