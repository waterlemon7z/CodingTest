#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
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

int root[1001] = {0,};

ll maxrst = 0;

vector<pair<int, ll>> adjacent[1000];

int check[1001];

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
	if(a < b)
		root[b] = a;
	else
		root[a] = b;
}

void dfs(int cur, ll cnt)
{
	maxrst = max(maxrst, cnt);

	for (auto iter: adjacent[cur])
	{
		if (check[iter.first] != 1)
		{
			check[iter.first] = 1;
			dfs(iter.first, cnt + iter.second);
			check[iter.first] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, M, x, y, val, road = 0, rst = 0;
	vector<pair<ll, pii>> s;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		root[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> val;
		s.push_back({val, {x, y}});
	}
	sort(s.begin(), s.end());
	for (auto &iter: s)
	{
		val = iter.first;
		x = iter.second.first;
		y = iter.second.second;

		if (find_(x) == find_(y))
			continue;
		union_(x, y);
		road++;
		rst += val;
		adjacent[x].push_back({y, val});
		adjacent[y].push_back({x, val});
//		maxx = max (val, maxx);
		if (road == N - 1)
		{
			cout << rst << endl;
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		check[i] = 1;
		dfs(i, 0);
		memset(check, 0, sizeof(check));
	}
	cout << maxrst;
}
