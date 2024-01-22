#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<long, long> pii;

typedef long long ull;

int main()
{
	FASTIO
	int arr[101] = {0,}, N, M, u, v;
	for (int i = 1; i <= 100; i++)
	{
		arr[i] = i;
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		int temp = arr[u];
		arr[u] = arr[v];
		arr[v] = temp;
	}
	for (int i = 1; i <= N; i++)
	{
		cout << arr[i] << ' ';
	}
}
