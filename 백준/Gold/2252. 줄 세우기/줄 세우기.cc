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
vector<int> input[32001];
vector<int> rst;
bool check[32001] = {0,};
int N, M;

int dfs(int x)
{
	for(int iter : input[x])
	{
		if(!check[iter])
		{
			check[iter] = true;
			rst.push_back(dfs(iter));
		}
	}
	return x;
}

void solve()
{
	for(int i = 1; i <= N; i++)
	{
		if(!check[i])
		{
			check[i] = true;
			rst.push_back(dfs(i));
		}
	}
	for(int i = rst.size() - 1; i >= 0; i--)
	{
		cout <<rst[i] << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		input[x].push_back(y);
	}
	 solve();
}