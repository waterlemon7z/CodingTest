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
int N, M;
int root[1000001] = {0,};
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int oper, x, y;
	for (int i = 0; i < N + 1; i++)
	{
		root[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> oper >> x >> y;
		if(oper == 0)
		{
			union_(x, y);
		}
		else
			if(find_(x) == find_(y))
			{
				cout << "YES" << endl;
			}
			else
				cout << "NO" << endl;
	}
}