#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
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

vector<int> arr;
int N, M,rst = -1;

void solve(int x, int sum, int cnt)
{
	if(sum > M)
		return;
	if(cnt == 3)
	{
		rst = max(rst, sum);
		return;
	}
	for(int i = x + 1; i < N; i++)
	{
		solve(i, sum + arr[i], cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		arr.push_back(n);
	}
	for(int i = 0; i< N; i++)
	{
		solve(i, arr[i], 1);
	}

	cout << rst;
}