#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;

using namespace std;

//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;

bool check[500001] = {false,};
vector<vector<int>> tree;
ull rst = 0;

void dfs(int cur, int dep)
{
	check[cur] = true;
	bool isLeaf = true;
	for(int i = 0; i < tree[cur].size(); i++)
	{
		if(!check[tree[cur][i]])
		{
			isLeaf = false;
			dfs(tree[cur][i], dep + 1);
		}
	}
	if(isLeaf)
	{
		rst += dep;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, a, b;
	cin >> N;
	tree = vector<vector<int>>(N + 1);
	for (int i = 0; i < N - 1 ;i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,0);
	cout << (rst % 2 ? "Yes" : "No");
}