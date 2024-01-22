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
	int N, M,x, y, val, cnt = 0, visit[1001] = {0,}, rst = 0;
	set<pair<int,pii>> s;
	cin >> N >> M;

	for(int i = 1; i <= N; i++)
	{
		root[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> val;
		s.insert({val, {x,y}});
	}

	for(auto &iter :s)
	{
		val = iter.first;
		x = iter.second.first;
		y= iter.second.second;
//		if(visit[x] == 1 && visit[y] == 1)
//			continue;
		if(find_(x) == find_(y))
			continue;
		union_(x, y);
//		if(visit[x] == 0)
//			cnt++;
//		if(visit[y] == 0)
//			cnt++;
//		visit[x] = visit[y] = 1;
		rst += val;
	}
	cout << rst;
}
