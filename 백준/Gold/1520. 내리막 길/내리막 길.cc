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

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, N, M, rst = 0;

int input[501][501] = {0,};

int memo[501][501] = {0,};

int dfs(int x, int y)
{
	int xx, yy, cur = input[x][y], &weight = memo[x][y];
	if(x == N - 1 && y == M - 1)
	{
		return 1;
	}
	if(weight != -1)
	{
		return weight;
	}
	weight = 0;
	for (int i = 0; i < 4; i++)
	{
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx >= 0 && xx < N && yy >= 0 && y < M && cur > input[xx][yy])
		{
			weight += dfs(xx, yy);
		}
	}
	return weight;
}

int solve()
{
//	memo[0][0] = 1;
	dfs(0, 0);
	return memo[0][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			memo[i][j] = -1;
			cin >> input[i][j];
		}
	}
	cout << solve();

}