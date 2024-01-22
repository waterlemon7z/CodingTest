#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

vector<int> root;

int find(int x)
{
	if (root[x] == x)
	{
		return x;
	}
	else
	{
		return root[x] = find(root[x]);
	}
}

void union_(int x, int y)
{
	x = root[x];
	y = root[y];
	if (x == y)
		return;
	root[y] = x;
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);
	vector<pair<int, pii>> input;
	vector<int> check;
	int V, E, x, y, edge, rst = 0, cnt = 0;
	cin >> V >> E;
	check = vector<int>(V,0);
	root.push_back(0);
	for (int i = 0; i < V; i++)
	{
		root.push_back(i + 1);
	}
	for (int i = 0; i < E; i++)
	{
		cin >> x >> y >> edge;
		input.push_back(make_pair(edge, make_pair(x, y)));
	}
	sort(input.begin(), input.end());
	for(auto iter : input)
	{
		if(cnt == V-2) break;
		edge = iter.first;
		x = iter.second.first;
		y = iter.second.second;
		if(find(x) == find(y))
		{
			continue;
		}
		rst += edge;
		union_(x, y);
		cnt++;
	}
	cout << rst;
}