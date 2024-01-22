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

int N, M;

int arr[501][501] = {0,}, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, rst = -1, check[501][501] = {0,}, maxVal = -1;

void backT(int x, int y, int cur, int cnt)
{
	if((4-cnt) * maxVal + cur <= rst)
		return;
	if (cnt == 4)
	{
		rst = max(rst, cur);
		return;
	}
	if (cnt == 3 && y >= 2 && check[x][y - 1] == 1 && check[x][y - 2] == 1)
	{
		if (x >= 1 && x <= N - 1)
		{
			backT(x - 1, y - 1, cur + arr[x - 1][y - 1], cnt + 1);
			backT(x + 1, y - 1, cur + arr[x + 1][y - 1], cnt + 1);
		}
		else if (x == 0)
			backT(x + 1, y - 1, cur + arr[x + 1][y - 1], cnt + 1);
		else
			backT(x - 1, y - 1, cur + arr[x - 1][y - 1], cnt + 1);
	}
	if (cnt == 3 && x >= 2 && check[x - 1][y] == 1 && check[x - 2][y] == 1)
	{
		if (y >= 1 && y <= M - 1)
		{
			backT(x - 1, y + 1, cur + arr[x - 1][y + 1], cnt + 1);
			backT(x - 1, y - 1, cur + arr[x - 1][y - 1], cnt + 1);
		}
		else if(y == 0)
			backT(x - 1, y + 1, cur + arr[x - 1][y + 1], cnt + 1);
		else
			backT(x - 1, y - 1, cur + arr[x - 1][y - 1], cnt + 1);
	}
	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M && check[x + dx[i]][y + dy[i]] == 0)
		{
			check[x + dx[i]][y + dy[i]] = 1;
			backT(x + dx[i], y + dy[i], cur + arr[x + dx[i]][y + dy[i]], cnt + 1);
			check[x + dx[i]][y + dy[i]] = 0;
		}
	}

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
			cin >> arr[i][j];
			maxVal = max(arr[i][j], maxVal);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			check[i][j] = 1;
			backT(i, j, arr[i][j], 1);
			check[i][j] = 0;
		}
	}
	cout << rst;
}