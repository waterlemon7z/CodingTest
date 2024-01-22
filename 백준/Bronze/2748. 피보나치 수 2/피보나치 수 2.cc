#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long f0, f1, ans= 1, N;
	f0 = 0;
	f1 = 1;
	cin >> N;
	for(int i = 0; i < N - 1; i++)
	{
		ans = f0 + f1;
		f0 = f1;
		f1 = ans;
	}
	cout  << ans;
}