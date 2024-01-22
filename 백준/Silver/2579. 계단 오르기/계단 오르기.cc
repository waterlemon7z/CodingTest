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

	int arr[301], N;
	int dp[301] = {0,};
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[2] + dp[1];
	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(arr[i] + arr[i -1] + dp[i - 3], arr[i] + dp[i - 2]);
	}
	cout << max(dp[N], dp[N - 2]);
}
