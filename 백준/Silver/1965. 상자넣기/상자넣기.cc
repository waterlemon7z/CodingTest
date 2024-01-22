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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, rst = -1;
	int dp[1001] = {0,}, input[1001];
	cin >> N;
	for(int i = 0; i < 1001; i++)
	{
		dp[i] = 1;
	}
	for(int i = 0; i < N; i++)
	{
		cin >> input[i];
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(input[j] < input[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		rst = max(dp[i], rst);
	}
	cout << rst;
}
