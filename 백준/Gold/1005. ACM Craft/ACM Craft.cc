#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

typedef long long ull;

int arr[1001], degree[1001] = {0,}, N;
vector<vector<int>> adja(1001,vector<int>());


int solve(int key)
{
	int rst = 0, cur, maxTime;
	queue<int> q, nq;
	vector<int> dp(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		if(degree[i] == 0)
			q.push(i);
	}
	while(!q.empty())
	{
		while(!q.empty())
		{
			cur = q.front();
			q.pop();
			if(cur == key)
				return dp[cur] + arr[cur];
			for(auto next : adja[cur])
			{
				if(--degree[next] == 0)
				{
					nq.push(next);
				}
				dp[next] = max(dp[next], dp[cur] + arr[cur]);
			}
		}
		q = nq;
		nq = queue<int>();
	}
}

int main(){
	FASTIO
	int T, K,x ,y, key;
	cin >> T;
	while(T--)
	{
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			degree[i] = 0;
			cin >> arr[i];
		}
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			adja[x].push_back(y);
			degree[y]++;
		}
		cin >> key;
		cout << solve(key) << endl;
		adja = vector<vector<int>>(1001,vector<int>());
	}
}