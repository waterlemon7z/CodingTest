#include <bits/stdc++.h>
using namespace std;
int rst = -1;

typedef pair<int, int> pii;
vector<pii> adjacent[10001];
int check[10001] = {0,};
int bfs(int cur, int val)
{
	int fst = 0, scd = 0;
	int rtn = 0;
	for (auto iter : adjacent[cur])
	{
		if(check[iter.first] != 1)
		{
			check[iter.first] = 1;
			int bfsrst = bfs(iter.first, iter.second);
			if (fst < bfsrst)
			{
				scd = fst;
				fst = bfsrst;
			}
			else if (scd < bfsrst)
				scd = bfsrst;
		}
	}
	rst = max(fst+scd, rst);
	return val + fst;
}

int main()
{
	int x, y, val, i = 0;
	while(scanf("%d %d %d", &x, &y, &val) != EOF )
	{
		adjacent[x].push_back({y, val});
		adjacent[y].push_back({x, val});
	}
	check[1] = 1;
	rst = max(rst, bfs(1,0));
	cout << rst;
}
