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

int N, M, total = 0, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

vector<vector<int>> input;

queue<pii> qq;

bool bfs()
{
	vector<vector<int>> temp = input;
	queue<pii> tempqq;
	bool check[301][301] = {0,};
	int x, y, cnt;
	while (!qq.empty())
	{
		x = qq.front().first;
		y = qq.front().second;
		qq.pop();
		cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M)
			{
				if (input[x + dx[i]][y + dy[i]] == 0)
				{
					cnt++;
				}
			}
		}
		if (input[x][y] - cnt <= 0)
		{
			temp[x][y] = 0;
			total--;
		}
		else
		{
			temp[x][y] -= cnt;
			tempqq.push({x, y});
		}
	}
	input = temp;
	qq = tempqq;
	cnt = 1;
	queue<pii> search;
	search.push(qq.front());
	check[qq.front().first][qq.front().second] = 1;
	while (!search.empty())
	{
		x = search.front().first;
		y = search.front().second;
		search.pop();
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M)
			{
				if (input[x + dx[i]][y + dy[i]] != 0 && check[x + dx[i]][y + dy[i]] == 0)
				{
					check[x + dx[i]][y + dy[i]] = 1;
					search.push({x + dx[i], y + dy[i]});
					cnt++;
				}
			}
		}
	}
	if (cnt != total)
	{
		return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	input = vector<vector<int>>(N, vector<int>(M, 0));
	int rst = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> input[i][j];
			if (input[i][j] != 0)
			{
				qq.push({i, j});
				total++;
			}
		}
	}
	while (total != 0)
	{
		rst++;
		if (!bfs())
			break;
	}
	cout << ((total == 0) ? 0 : rst);
}