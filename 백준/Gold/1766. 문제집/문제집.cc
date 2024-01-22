#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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
int inDegree[32001] = {0,};
int N, K, to, from;
vector<int> adja[32001];
int rst[32001];

void solve()
{
	int cur;
	priority_queue<int, vector<int>, greater<int>> qq;
	for(int i = 1; i <= N; i++)
	{
		if(inDegree[i] == 0)
		{
			qq.push(i);
		}
	}
	for(int i = 1; i <= N; i++)
	{
		if(qq.empty())
		{
			return;
		}
		cur = qq.top();
		qq.pop();
		rst[i] = cur;
		for(int j = 0; j < adja[cur].size(); j++)
		{
			if(--inDegree[adja[cur][j]] == 0)
				qq.push(adja[cur][j]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> from >> to;
		inDegree[to]++;
		adja[from].push_back(to);
	}
	solve();
	for (int i = 1; i <= N; i++)
	{
		cout << rst[i] << ' ';
	}
}