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

vector<vector<int>> arr;

int N, rst = 0;

int check[101] = {0,};

void dfs(int x)
{
	check[x] = 1;
	rst++;
	for(auto iter : arr[x])
	{
		if(check[iter] != 1)
			dfs(iter);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, x, y;
	cin >> N;
	arr = vector<vector<int>>(N + 1);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	dfs(1);
	cout << rst - 1;
}