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

int N, M, R;

vector<vector<int>> input;

vector<int> nodes;

int dijk(int start)
{
	vector<int> dist( N + 1, INF);
	priority_queue<pii> qq;
	dist[start] = 0;
	int rst = 0;
	qq.push({0, start});
	while(!qq.empty())
	{
		int cost = -qq.top().first;
		int cur = qq.top().second;
		qq.pop();
		for (int i = 1; i < input[cur].size(); i++)
		{
			if(input[cur][i] != INF)
			{
				int nextNode = i;
				int nextCost = input[cur][i] + cost;
				if(nextCost < dist[nextNode])
				{
					dist[nextNode] = nextCost;
					qq.push({-nextCost, nextNode});
				}
			}
		}
	}
	for (int i = 0; i <= N; i++)
	{
		if(dist[i] != INF)
			if(dist[i] <= M)
				rst += nodes[i];
	}
	return rst;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y, edge, rst = -1;
	cin >> N >> M >> R;
	input = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));
	nodes = vector<int>(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> nodes[i + 1];
	}
	for (int i = 0; i < R; i++)
	{
		cin >> x >> y >> edge;
		input[x][y] = edge;
		input[y][x] = edge;
	}
	for (int i = 1; i <= N; i++)
	{
		rst = max(rst, dijk(i));
	}
	cout << rst;
}