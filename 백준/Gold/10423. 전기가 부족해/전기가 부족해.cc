#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;

int check[1001] = {0,};
typedef struct graph_{
	int val,to, from;
}GRA;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, to, from, val, rst = 0;
	cin >> N >> M >> K;
	vector<vector<pii>> adja(N + 1);
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> qq;
	int elec[1001];
	for (int i = 0; i < K; i++)
	{
		cin >> elec[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> to >> from >> val;
		adja[to].push_back({from, val});
		adja[from].push_back({to, val});
	}

	for (int i = 0; i < K; i++)
	{
		for(auto iter : adja[elec[i]])
		{
			qq.push({iter.second, {i, iter.first}});
		}
		check[elec[i]] = 1;
	}
	while(!qq.empty())
	{
		int cur = qq.top().first;
		int curFrom = qq.top().second.first;
		int curTo = qq.top().second.second;
		qq.pop();

		if(check[curTo] == 0)
		{
			rst += cur;
			check[curTo] = 1;
			for(auto iter : adja[curTo])
			{
				if(check[iter.first] == 1 )
					continue;
				qq.push({iter.second,{curTo, iter.first}});
			}
		}
	}
	cout << rst;
}
