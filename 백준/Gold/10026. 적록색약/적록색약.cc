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

int N;
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
vector<vector<int>> input;
vector<vector<int>> dinput;

int str2int(char i)
{
	if(i == 'R')
		return 1;
	if(i == 'G')
		return 2;
	if(i == 'B')
		return 3;
	return -1;
}
int str2intd(char i)
{
	if(i == 'R')
		return 1;
	if(i == 'G')
		return 1;
	if(i == 'B')
		return 3;
	return -1;
}

void dfs(int x, int y, int cur)
{
	input[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		if(x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < N)
		{
			if(input[x + dx[i]][y + dy[i]] == cur)
				dfs(x + dx[i], y + dy[i], cur);
		}
	}
}

void solve()
{
	int rst = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(input[i][j] != 0)
			{
				dfs(i, j, input[i][j]);
				rst++;
			}
		}
	}
	cout << rst << endl;
	input = dinput;
	rst = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(input[i][j] != 0)
			{
				dfs(i, j, input[i][j]);
				rst++;
			}
		}
	}
	cout << rst;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> N;
	input = vector<vector<int>> ( N, vector<int>(N, 0));
	dinput = vector<vector<int>> ( N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			input[i][j] = str2int(str[j]);
			dinput[i][j] = str2intd(str[j]);
		}
	}
	solve();
}