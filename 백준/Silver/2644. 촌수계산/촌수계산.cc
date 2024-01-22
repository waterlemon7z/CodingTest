#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;

int N, M, from, to;
vector<vector<int>> adjacent;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<pii> qq;
	int x, y;
	cin >> N;
	adjacent = vector<vector<int>> (N + 1);
	vector<int> check (N + 1);
	cin >> from >> to;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		adjacent[x].push_back(y);
		adjacent[y].push_back(x);
	}
	qq.push({from, 0});
	check[from] = 1;
	while(!qq.empty())
	{
		pii cur = qq.front();
		qq.pop();
		for(auto i : adjacent[cur.first])
		{
			if(i == to)
			{
				cout << cur.second + 1;
				return 0;
			}
			if(check[i] == 1)
				continue;
			qq.push({i, cur.second + 1});
			check[i] = 1;
		}
	}
	cout << -1;
}