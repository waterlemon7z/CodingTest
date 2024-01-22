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

	int N, rst = -2147483648;
	int input[100001] = {0,};
	int dp[100001] = {0,};
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> input[i];

	}
	dp[1] = input[1];
	for (int i = 2; i <= N; i++)
	{
		dp[i] = max(dp[i - 1] + input[i], input[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		if (rst < dp[i])
		{
			rst = dp[i];
		}
	}
	printf("%d", rst);

}
