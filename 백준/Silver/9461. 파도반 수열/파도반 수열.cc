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

	int N, key;
	ull dp[101] = {0,};
	cin >> N;
	dp[0] = dp[1] = dp[2] =1;
	for(int i = 3; i < 101; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	for(int i = 0; i < N; i++)
	{
		cin >> key;
		cout << dp[key -1] << endl;
	}
}
