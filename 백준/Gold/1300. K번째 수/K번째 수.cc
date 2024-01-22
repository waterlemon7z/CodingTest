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
int N;
long long K;
long long count(long long x )
{
	long long cnt = 0;
	for(int i =1; i <= N; i++)
	{
		cnt += min((long long)x/i, (long long)N);
	}
	return cnt;
}

void BS(long long f, long long l)
{
	if(f > l)
	{
		cout << f;
		exit(0);
	}
	int mid = (f + l)/2;
	if(count(mid) >= K)
		BS(f, mid - 1);
	else
		BS(mid + 1, l);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long f, l, mid;

    cin >> N >> K;
	K = min(1000000000LL,min((long long)N * N, K));
	f = 1;
	l = N * N;
	while(f <= l)
	{
		mid = (f + l)/2;
		if(count(mid) >= K)
			l = mid - 1;
		else
			f = mid + 1;
	}
	cout << f;
}