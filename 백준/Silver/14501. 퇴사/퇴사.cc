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

	int N, memo[16] = {0,}, day, val, rst = -1, big;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> day >> val;
		if(i + day <= N)
		{
			for(int j = i + day ; j <= N; j++)
			{
				memo[j] = max(memo[i] + val, memo[j]);
			}
//			rst = max(memo[i + day], rst);
		}
	}
	cout << memo[N];
}
