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
int root[200001] = {0,};

int find_(int a)
{
	if(root[a] == a)
		return a;
	return root[a] = find_(root[a]);
}

void union_(int a, int b)
{
	a = find_(a);
	b = find_(b);
	if(a == b)
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
	int N, M,x, y, val, cnt, nodes;
	ll rst = 0;
	vector<int> arr;
	set<pair<int,pii>> s;
	cin >> N >> M;
	while(!(N == M && N == 0))
	{
		cnt = 0;
		rst = 0;
		nodes = 0;
		s.clear();
		for (int i = 0; i < N; i++)
		{
			root[i] = i;
		}
		for (int i = 0; i < M; i++)
		{
			cin >> x >> y >> val;
			cnt += val;
			s.insert({val, {x, y}});
		}

		for (auto &iter: s)
		{
			val = iter.first;
			x = iter.second.first;
			y = iter.second.second;
			if (find_(x) == find_(y))
				continue;
			union_(x, y);
			rst += val;
			nodes++;
			if(nodes == N - 1)
				break;
		}
		arr.push_back(cnt - rst);
		cin >> N >> M;
	}
	for (const auto &item: arr)
	{
		cout << item << endl;
	}
}
