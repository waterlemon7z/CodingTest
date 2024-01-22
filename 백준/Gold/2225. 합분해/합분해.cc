#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
	int N, k;
	cin >> N >> k;
	vector<vector<ll>> dp(k + 1, vector<ll>(N + 1, 1));
	for(int i = 2; i <= k; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
		}
	}
	cout << dp[k][N];
}
