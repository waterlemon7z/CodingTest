#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
int N;

int dijstra(vector<vector<int>> arr, int start, int fine)
{
	int cur, min_;
	vector<int> check(N + 1, 0);
	vector<int> dij(N + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> qq;
	qq.push({0, start});
	while(!qq.empty())
	{
		cur = qq.top().second;
		min_ = qq.top().first;
		qq.pop();
		for(int i = 1; i <= N; i++)
		{
			if(arr[cur][i] == -1)
				continue;
			if(arr[cur][i] + min_ < dij[i])
			{
				dij[i] = arr[cur][i] + min_;
//				if(check[i] == 0)
				{
					qq.push({arr[cur][i] + min_, i});
//					check[i] = 1;
				}

			}
		}
	}

	return dij[fine];
}
int main()
{
	int M, x, y, st, dt, temp;
	cin >> N >> M;
	vector<vector<int>> arr(N + 1, vector<int>(N + 1, -1));
	for(int i = 1; i <= M; i++)
	{
		cin >> x >> y;
		if(arr[x][y] != -1)
		{
			cin >> temp;
			arr[x][y] = min(temp, arr[x][y]);
		}
		else
			cin >> arr[x][y];
	}
	cin >> st >> dt;
	cout << dijstra(arr, st, dt);
}
