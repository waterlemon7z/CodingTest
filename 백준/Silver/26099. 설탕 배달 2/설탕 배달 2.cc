#include <iostream>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef  long long ull;

int main()
{
	FASTIO
	ull N;
	cin >> N;
	for(ull i = N / 5; i >= 0; i--)
	{
		if((N - i * 5) % 3 == 0)
		{
			cout << i + (N - i * 5) / 3;
			return 0;
		}
	}
	cout << -1;
}

