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
int memo[41][2] = {0,};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memo[0][0] = 1;
	memo[0][1] = 0;
	memo[1][0] = 0;
	memo[1][1] = 1;

	for(int i = 2; i < 41; i++)
	{
		memo[i][0] = memo[i - 1][0] + memo[i - 2][0];
		memo[i][1] = memo[i - 1][1] + memo[i - 2][1];
	}
	int N, key;
	cin >> N;
	while(N--)
	{
		cin >> key;
		cout << memo[key][0] << ' ' << memo[key][1]<< endl;
	}
}
