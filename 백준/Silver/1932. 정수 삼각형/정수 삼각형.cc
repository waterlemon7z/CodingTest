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
	memo = vector<vector<int>> (N, vector<int>(N,0));
	memo[0][0] = arr[0][0];
	for(int i = 1; i < N; i++)
	{
		for(int j = 0 ; j <= i; j++)
		{
			if(j == 0)
			{
				memo[i][j] = memo[i-1][j] + arr[i][j];
			}
			else if(j == i)
			{
				memo[i][j] = memo[i-1][j-1] + arr[i][j];
			}
			else
			{
				memo[i][j] = max(memo[i-1][j-1] + arr[i][j], memo[i-1][j] + arr[i][j]);
			}
		}
	}
	sort(memo[N-1].begin(), memo[N-1].end());
	cout << memo[N-1][N-1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	arr = vector<vector<int>> (N, vector<int>(N,0));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0 ; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp();
}
