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

char arr[1001][1001] = {0,};

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

queue<pair<pii, int>> castles[10], cls;

pii players[10] = {{0, 0},};

int N, M, P, total = 0, timeP[10] = {0,};

bool check[1001][1001] = {0,};

void solve()
{
	int turn = 0, cnt = 0;
	while (cnt != P)
	{
		while (!castles[turn % P + 1].empty())
		{
			if (castles[turn % P + 1].front().second == players[turn % P + 1].first)
			{
				players[turn % P + 1].first += timeP[turn % P + 1];
				break;
			}
			int x = castles[turn % P + 1].front().first.first;
			int y = castles[turn % P + 1].front().first.second;
			int val = castles[turn % P + 1].front().second;
			castles[turn % P + 1].pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && check[nx][ny] == 0 && arr[nx][ny] == '.')
				{
					check[nx][ny] = 1;
					arr[nx][ny] = '0' + turn % P + 1;
					castles[turn % P + 1].push({{nx, ny}, val + 1});
					players[turn % P + 1].second++;
					total++;
				}
			}
		}
		turn++;

		if(castles[turn % P + 1].empty())
		{
			if(players[turn % P + 1].first != 0)
			{
				players[turn % P + 1].first = 0;
				cnt++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++)
	{
		cin >> players[i].first;
		timeP[i] = players[i].first;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] >= '1' && arr[i][j] <= '9')
			{
				castles[arr[i][j] - '0'].push({{i, j}, 0});
				players[arr[i][j] - '0'].second++;
				total++;
			}
			else if (arr[i][j] == '#')
				total++;
		}
	}

	solve();
	for (int i = 1; i <= P; i++)
	{
		cout << players[i].second << ' ';
	}
}
