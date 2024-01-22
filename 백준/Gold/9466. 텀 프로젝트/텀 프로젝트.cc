#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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

int input[100001] = {0,};

bool check[100001] = {0,};

bool cycle[100001] = {0,};

int T, N, rst;

void solve(int node)
{
	check[node] = 1;
	int adja = input[node];

	if (!check[adja])
		solve(adja);
	else if (!cycle[adja])
	{
		for (int i = adja; i != node; i = input[i])
		{
			rst++;
		}
		rst++;
	}
	cycle[node] = 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		rst = 0;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> input[i];
		}
		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
				solve(i);
		}
		memset(check, 0, 100001);
		memset(cycle, 0, 100001);

		cout << N - rst << endl;
	}

}