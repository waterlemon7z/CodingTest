#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
typedef pair<int, int> pii;
vector<vector<pii>> arr;
int N;
int bfs(int ari, int dest)
{
	bool check[1001] = {0,};
	int cur;
	queue<int> qq;
	vector<int> dist(N + 1, 0);
	qq.push(ari);
	check[ari] = 1;
	while(!qq.empty())
	{
		cur = qq.front();
		qq.pop();
		for(int i = 0; i < arr[cur].size(); i++)
		{
			if(!check[arr[cur][i].first])
			{
				qq.push(arr[cur][i].first);
				check[arr[cur][i].first] = 1;
				dist[arr[cur][i].first] += arr[cur][i].second + dist[cur];
			}
		}
	}
	return dist[dest];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M, from, to, val;
	cin >> N >> M;
	arr = vector<vector<pii>>(N + 1);
	for(int i = 0; i < N - 1; i++)
	{
		cin >> from >> to >>val;
		arr[from].push_back({to, val});
		arr[to].push_back({from, val});
	}
	for(int i = 0; i < M; i++)
	{
		cin >> from >> to;
		cout << bfs(from, to) << '\n';
	}
}