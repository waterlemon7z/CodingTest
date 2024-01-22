#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
clock_t start;
typedef pair<int, int> pii;
int N;
vector<vector<pii>> arr(801);
vector<int> dist;
priority_queue<pii, vector<pii>, greater<pii>> qq;

int dij(int start, int end)
{
	int cur, min_, next, sum_;
	dist = vector<int>(N + 1, INF);
	qq.push({0, start});
	dist[start] = 0;
	while (!qq.empty())
	{
		cur = qq.top().second;
		min_ = qq.top().first;
		qq.pop();
		for (auto iter: arr[cur])
		{
			next = iter.first;
			sum_ = min_ + iter.second;
			if (sum_ < dist[next])
			{
				dist[next] = sum_;
				qq.push({sum_, next});
			}
		}
	}
	return dist[end];
}
int main()
{
	int E, s, e, V, vv,vvv, rst = 0, ari;
	cin >> N >> E;
	for(int i = 0; i < E; i++)
	{
		cin >> s >> e >> V;
		arr[s].push_back({e, V});
		arr[e].push_back({s, V});
	}
	cin >> vv >> vvv;
	rst = min(dij(1, vv) + dij(vv,vvv) + dij(vvv, N), dij(1, vvv)+dij(vvv,vv) + dij(vv, N));
	cout << (rst >= INF || rst < 0 ? -1 : rst) << '\n';
}