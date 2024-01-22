#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int N;

ull dp(int n){return (n == 1 || n == 2 ? 1 : dp(n - 1) + dp(n - 2)); }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cout << dp(N) << ' ' << N - 2;
}