#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef long long ll;

int root[10001] = {0,};

int find_(int a)
{
	if (root[a] == a)
		return a;
	return root[a] = find_(root[a]);
}

void union_(int a, int b)
{
	a = find_(a);
	b = find_(b);
	if (a == b)
	{
		return;
	}
	root[a] = b;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K,x ,y ,val,cnt = 0, rst = 0;
//	priority_queue<pair<int, pii>, vector<pair<int,pii>>, greater<pair<int, pii>>> q;
set<pair<int,pii>> q;
vector<pii> adjacent[10001];
	cin >> N >> M >> K;
	for(int i  = 1; i <= N; i++)
	{
		root[i] =i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> val;
		adjacent[x].push_back({y, val});
		adjacent[y].push_back({x, val});
	}
	for(auto iter : adjacent[1])
	{
		q.insert({iter.second,{1, iter.first}});
	}
	while(cnt != N - 1)
	{
		val = q.begin()->first;
		x = q.begin()->second.first;
		y = q.begin()->second.second;
		q.erase(q.begin());

		if(find_(x) == find_(y))
			continue;
		union_(x,y);
		rst += val + K * cnt++;
		for(auto iter : adjacent[y])
		{
			q.insert({iter.second,{y, iter.first}});
		}
	}
	cout << rst;
}
