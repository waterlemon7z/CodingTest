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
int memo[1001]= {0,};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memo[0] = 1;
	memo[1] = 1;

	for(int i = 2; i < 1001; i++)
	{
		memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
	}

	int N, key;
	cin >> key;
	cout << memo[key] << endl;
}
