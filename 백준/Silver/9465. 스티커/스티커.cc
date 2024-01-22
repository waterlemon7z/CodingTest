#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 987654321
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
int N;
vector<vector<int>> arr;
vector<vector<int>> memo;

void dp()
{
	memo = vector<vector<int>> (2, vector<int>(N + 1,0));
	memo[0][0] = 0;
	memo[1][0] = 0;
	memo[0][1] = arr[0][1];
	memo[1][1] = arr[1][1];
	for(int i = 2; i <= N; i++)
	{
		memo[0][i] = max(memo[1][i-1], memo[1][i-2]) + arr[0][i];
		memo[1][i] = max(memo[0][i-1], memo[0][i-2]) + arr[1][i];
	}
	cout << max(memo[0][N], memo[1][N]) << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> N;
		arr = vector<vector<int>> (2, vector<int>(N  +1, 0));
		for(int ll = 0; ll < 2; ll++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> arr[ll][j];
			}
		}
		dp();
	}
}
