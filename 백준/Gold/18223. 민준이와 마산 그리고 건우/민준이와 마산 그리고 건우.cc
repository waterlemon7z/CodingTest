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

void init(int V, int dist[])
{
	for (int i = 0; i <= V; i++)
	{
		dist[i] = INF;
	}
}

void dijkstra(priority_queue<pii> &pq, vector<pii> input[], int dist[])
{
	int u, v, w;
	while (!pq.empty())
	{
		u = pq.top().second;
//		curW = pq.top().second;
		pq.pop();
		for (pii iter: input[u])
		{
			v = iter.first;
			w = iter.second;
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({-dist[v], v});
			}
		}
	}
}

int main()
{
	FASTIO
	int V, E, P, u, v, w, minDist = INF, middle;
	priority_queue<pii> pq;
	int dist[5001] = {0,};
	vector<pii> input[5001];
	cin >> V >> E >> P;
	init(V, dist);
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		input[u].push_back({v, w});
		input[v].push_back({u, w});
	}
	dist[1] = 0;
	pq.push({0, 1});
	dijkstra(pq,input,dist);
	minDist = min(minDist, dist[V]);
	middle = dist[P];
	init(V, dist);
	dist[P] = 0;
	pq.push({0, P});
	dijkstra(pq,input,dist);
	middle += dist[V];
	if(middle <= minDist)
	{
		cout << "SAVE HIM";
	}
	else
		cout << "GOOD BYE";
}