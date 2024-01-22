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
int N;
int inDirect[1001] = {0,};
vector<vector<int>> adjacent;
void solve()
{
	vector<int> rst;
	queue<int> qq;
	for (int i = 1; i <= N; i++)
	{
		if(inDirect[i] == 0)
		{
			qq.push(i);
		}
	}

	for(int i = 0; i < N; i++)
	{
		if(qq.empty())
		{
			cout << 0;
			return;
		}
		int x = qq.front();
		qq.pop();
		rst.push_back(x);
		for(auto iter : adjacent[x])
		{
			if(--inDirect[iter] == 0)
			{
				qq.push(iter);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << rst[i] << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int from, M, to, T;
	cin >> N >> T;
	adjacent = vector<vector<int>> (N + 1);
	for (int i = 0; i < T; i++)
	{
		cin >> M;
		cin >> from;
		for (int j = 1; j < M; j++)
		{
			cin >> to;
			adjacent[from].push_back(to);
			inDirect[to]++;
			from = to;
		}
	}
	solve();
}