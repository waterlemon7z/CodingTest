#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, long long> pii;
typedef unsigned long long ull;
vector<int> arr, rst;
int r,l;

void treeans(int A, int B)
{
	if(A == 1)
	{
		r += B - 1;
		return;
	}
	else if(B == 1)
	{
		l += A - 1;
		return;
	}
	if(A < B)
	{
		r += B / A;
		treeans(A, B % A);
	}
	else if(A > B)
	{
		l += A / B;
		treeans(A % B, B);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	r = 0, l = 0;
	int a, b;

	cin >> a >> b;
	treeans(a, b);
	cout << l << ' ' << r;
}