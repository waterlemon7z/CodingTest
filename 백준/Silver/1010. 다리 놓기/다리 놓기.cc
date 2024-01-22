#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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

int T, memo[31][31] = {0,};

int dp(int n, int m)
{
	if(memo[n][m] != 0)
	{
		return memo[n][m];
	}
	else
		return memo[n][m] = dp(n-1,m-1) + dp(n-1,m);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> T;
	for(int i = 0; i < 31; i++)
	{
		memo[i][0] = 1;
		memo[i][i] = 1;
	}
	while (T--)
	{
		cin >> n >> m;
		cout << dp(m, n) << endl;
	}

}