#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
pii arr[2000001] = {{0,0},};

int main()
{
	FASTIO
	int N, rst = -1, cur = 0;
	cin >> N;
	for (int i = 0; i < 2*N; i++)
	{
		cin >> arr[i].first;
		 arr[i].second = i % 2 == 0 ? 1 : -1;
	}
	sort(arr, arr + 2*N);
	for (int i = 0; i < 2 * N; i++)
	{
		cur += arr[i].second;
		rst = max(rst, cur);
	}
	cout <<rst;
}
