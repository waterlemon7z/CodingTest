#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef long long ll;
int arr[201], dp[201];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K, rst = -1;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}
	for(int i = 0; i < K; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[j] < arr[i])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	for (int i = 0; i < K; i++)
	{
		rst = max(rst, dp[i]);
	}
	cout << K - rst;
}