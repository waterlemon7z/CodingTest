#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<long, long> pii;

typedef long long ull;
int K, N, M, v, u;

bool BFS(vector<vector<int>> &g, int check[], int start)
{
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto iter: g[cur])
		{
			if (check[iter] == 0)
			{
				check[iter] = check[cur] * -1;
				q.push(iter);
			} else if (check[iter] + check[cur] != 0)
			{
				return false;
			}

		}
	}
	return true;
}


void solve()
{
	cin >> N >> M;
	vector<vector<int>> g(N + 1);
	int check[20001] = {0,};
	for (int i = 0; i < M; i++)
	{
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	queue<int> q;
	for(int i = 1; i <= N ; i++)
	{
		if(check[i] == 0)
		{
			if(!BFS(g,check, i))
			{
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int main()
{
	FASTIO
	cin >> K;
	while (K--)
	{
		solve();
	}
}