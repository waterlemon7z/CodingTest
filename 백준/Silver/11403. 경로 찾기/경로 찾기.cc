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

int board[101][101] = {0,};

int temp, N;

void dfs(int *rst, int cur)
{
	for (int i = 0; i < N; i++)
	{
		if (board[cur][i] == 1 && rst[i] != 1)
		{
			rst[i] = 1;
			dfs(rst, i);
		}
	}
}

void solve(int cur)
{
	int rst[101] = {0,};
	dfs(rst, cur);
	for (int i = 0; i < N; i++)
	{
		cout << rst[i] << ' ' ;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		solve(i);
		cout << endl;
	}

}