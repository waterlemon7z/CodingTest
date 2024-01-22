#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
int n, k;
vector<int> memo;
vector<int> coins;

void dp()
{
	memo[0] = 1;
	for(auto value : coins)
	{
		memo[value] = min(memo[value], 1);
		for(int i = value + 1; i <= k; i++)
		{
			memo[i] = min(memo[i], memo[i-value] + 1);
		}
	}
	cout << (memo[k] == INF ? -1 : memo[k]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int temp;
	cin >> n >>k;
	memo = vector<int> (k + 1, INF);
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		coins.push_back(temp);
	}
	sort(coins.begin(), coins.end());
	dp();
}
