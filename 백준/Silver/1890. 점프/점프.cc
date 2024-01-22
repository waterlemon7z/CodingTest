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

int arr[101][101] = {0,}, N;
ull memo[111][111] = {0,};

ull solve()
{
	memo[0][0] = 1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(i == N - 1 && j == N - 1)
				continue;
			memo[i + arr[i][j]][j] += (memo[i][j]);
			memo[i][j + arr[i][j]] += (memo[i][j]);
		}
	}
	return memo[N - 1][N - 1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << solve();

}
