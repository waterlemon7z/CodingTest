#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
clock_t start;
typedef pair<int, int> pii;
int N, K;
vector<vector<int>> arr;
vector<pii> input;

int dp()
{
	int curK, Val;
	arr = vector<vector<int>>(N + 1,vector<int>(K + 1, 0));
	for(int i = 1; i <= N; i++)
	{
		curK = input[i-1].first;
		Val = input[i-1].second;
		for(int j = 1; j <= K; j++)
		{
			if(j < curK)
				arr[i][j] = arr[i-1][j];
			else
				arr[i][j] = max(arr[i-1][j], arr[i-1][j - curK] + Val);
		}
	}
	return arr[N][K];
}
int main()
{
	int n, m;
	cin >> N >> K;
	for(int i =0 ;i < N; i++)
	{
		cin >> n >> m;
		input.push_back({n, m});
	}
	cout << dp();
}