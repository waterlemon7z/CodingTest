#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,cur, dp[1000001];
	cin >> N;
	dp[1] = 0;
	for(int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if(i % 2 == 0)
		{
			dp[i] = min(dp[i/2] + 1, dp[i]);
		}
		if(i % 3 == 0)
		{
			dp[i] = min(dp[i/3] + 1, dp[i]);
		}
	}
	cout << dp[N];
}
