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

	int N, arr[1001] = {0,}, dp[1001] = {0,};

	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[j] < arr[i])
			{
				dp[i] = max(dp[j] + arr[i], dp[i]);
			}
		}
	}
	sort(dp + 1, dp + N + 1);
	cout << dp[N];
}