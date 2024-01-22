#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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
	int N, cur = 1;
	cin >> N;
	while (N > 0)
	{
		N = N - cur;
		cur ++;
	}
	cur--;
	N *= -1;
	if(cur % 2 == 1)
	{
		cout << N  + 1 << '/' <<  cur - N;
	}
	else
	{
		cout << cur - N<< '/' <<  N  + 1;
	}

}