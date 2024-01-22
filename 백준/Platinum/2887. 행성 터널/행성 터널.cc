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

typedef struct _xyz
{
	int x;
	int y;
	int z;
} xyz;

vector<xyz> coordi;

set<pair<int, pii>> adjacent;

vector<pii> X;

vector<pii> Y;

vector<pii> Z;

int root[100001] = {0,};

int find_(int x)
{
	if (root[x] == x)
		return x;
	return root[x] = find_(root[x]);
}

void union_(int x, int y)
{
	x = find_(x);
	y = find_(y);
	if (x == y)
		return;
	root[y] = x;
}

void solve()
{
	int x, y, rst = 0;

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	for (int i = 0; i < N - 1; i++)
	{
		adjacent.insert({X[i + 1].first - X[i].first, {X[i + 1].second, X[i].second}});
		adjacent.insert({Y[i + 1].first - Y[i].first, {Y[i + 1].second, Y[i].second}});
		adjacent.insert({Z[i + 1].first - Z[i].first, {Z[i + 1].second, Z[i].second}});
	}
	for (auto iter: adjacent)
	{
		x = iter.second.first;
		y = iter.second.second;
		if (find_(x) != find_(y))
		{
			union_(x, y);
			rst += iter.first;
		}
	}
	cout << rst;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y, z;
	cin >> N;
	coordi = vector<xyz>(N + 1);
	for (int i = 1; i <= N; i++)
	{
		root[i] = i;
		cin >> x >> y >> z;
		X.push_back({x, i});
		Y.push_back({y, i});
		Z.push_back({z, i});
	}

	solve();
}