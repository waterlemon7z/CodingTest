#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;

int main()
{
	FASTIO
	int N, M,u,v,w,curdist;
	int start;
	priority_queue<pii> qq;
	vector<vector<pii>> arr(20001);
	int dist[20001];
	cin >> N >> M;
	cin >> start;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		arr[u].push_back({v,w});
	}
	for(int i = 0; i <= N; i++)
	{
		dist[i] = INF;
	}
	dist[start] = 0;
	qq.push({0,start});
	while(!qq.empty())
	{
		curdist = -1*qq.top().first;
		u = qq.top().second;
		qq.pop();
		if(dist[u] < curdist)
		{
			continue;
		}
		for(pii iter : arr[u])
		{
			v = iter.first;
			w = iter.second;
			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				qq.push({-1*dist[v], v});
			}
		}
	}
	for(int i = 1 ; i <= N; i++)
	{
		if(dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}
}