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

int root[1001] = {0,};

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
	int N, M, x, y, val, road = 0, rst = 0;
	bool isMale[1001] = {0,};
	char mode;
	set<pair<int, pii>> s;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		root[i] = i;
		cin >> mode;
		isMale[i] = mode == 'M';
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> val;
		s.insert({val,{x,y}});
	}
	for(auto &iter:s)
	{
		val = iter.first;
		x = iter.second.first;
		y = iter.second.second;

		if(isMale[x] == isMale[y])
			continue;
		if(find_(x) == find_(y))
			continue;
		union_(x, y);
		road++;
		rst+= val;
		if(road == N - 1)
		{
			cout <<rst;
			break;
		}
	}
	if(road < N - 1)
		cout << -1;
}
