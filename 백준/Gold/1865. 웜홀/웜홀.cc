#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<pair<int, int>, int> pii;
vector<pii> arr;
vector<int> dist;

int T, N, M, W;

void bell(int start)
{
	int from, to, val;
	bool flag = 0;
	dist[start] = 0;
	for(int i = 0; i <= N - 1; i++)
	{
		for(auto iter : arr)
		{
			from = iter.first.first;
			to = iter.first.second;
			val = iter.second;
//			if(dist[from] == INF)
//				continue;
			if(dist[to] > dist[from] + val)
			{
				if(i == N - 1)
					flag = true;
				dist[to] = dist[from] + val;
			}
		}
	}

	cout << (flag ? "YES" : "NO") << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int start, end, val;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> N >> M >> W;
		dist = vector<int> (N + 1, INF);
		arr.clear();
		for(int u = 0; u < M; u++)
		{
			cin >> start >> end >> val;
			arr.push_back({{start, end}, val});
			arr.push_back({{end, start}, val});
		}
		for(int u = 0; u < W; u++)
		{
			cin >> start >> end >> val;
			arr.push_back({{start, end}, (-1) * val});
		}
		bell(1);
	}
}

