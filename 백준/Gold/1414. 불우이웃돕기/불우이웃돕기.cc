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

set<pair<int,pii>> adjacent;
int root[50] = {0,};
int N, total = 0;
int check[50] = {0,};
int find_(int x)
{
	if(root[x] == x)
	 return x;
	return root[x] = find_(root[x]);
}

void union_(int x, int y)
{
	x = find_(x);
	y = find_(y);

	if(x == y)
		return;
	root[y] = x;
}

int char2int(char c)
{
	if('a' <= c && c <= 'z')
		return c - 'a' + 1;
	if('A' <= c && c <= 'Z')
		return c - 'A' + 27;

	return -1;
}

void solve()
{
	int i;
	while (!adjacent.empty())
	{
		int val = adjacent.begin()->first;
		int x = adjacent.begin()->second.first;
		int y = adjacent.begin()->second.second;
		adjacent.erase(adjacent.begin());
		if (find_(x) == find_(y))
			continue;
		union_(x, y);
		total -= val;
	}
	int tempRoot = find_(0);
	for (i = 1; i < N; i++)
	{
		if(tempRoot != find_(i))

			break;
	}
	if(i != N)
	{
		cout << -1;
		exit(0);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		root[i] = i;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if((temp = char2int(str[j])) == -1)
				continue;
			total += temp;
			if(i != j)
				adjacent.insert({temp,{i,j}});
		}
	}
	solve();
	cout << total;
}