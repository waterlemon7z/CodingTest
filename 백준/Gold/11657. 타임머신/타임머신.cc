#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define INF LLONG_MAX
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef long long ull;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, from, to, val;
	bool cycle = false;
	cin >> N >> M;
	vector<vector<pii>> arr(N + 1);
	vector<ull> dist(N + 1, INF);

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> val;
		arr[from].push_back({to, val});
	}
	dist[1] = 0;
	for(int l = 1; l <= N; l++)
	{
		for (int i = 1; i <= N; i++)
		{
			for(auto edge:arr[i])
			{
				if (dist[i] == INF)
					continue;
				if (dist[edge.first] > dist[i] + edge.second)
				{
					dist[edge.first] = dist[i] + edge.second;
					if(l == N)
						cycle = true;
				}
			}
		}
	}
	if(cycle)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 2; i <= N; i++)
	{
		cout << (dist[i] == INF ? -1 : dist[i]) << endl;
	}
}