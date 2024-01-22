#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
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

typedef unsigned long long ull;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, rst = 0;
	int dp[1000001] = {0,};
	dp[0] = 1;
	dp[1] = 1;
	cin >> N;

	for(int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}
	cout << dp[N];
}
