#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	int N;
	int dist[31] = {0,};
	cin >> N;
	dist[0] = 1;
	dist[2] = 3;
	for (int i = 4; i <= N; i++)
	{
		if(i % 2 == 1) continue;
		dist[i] = dist[i-2] * 4 - dist[i-4];
	}
	cout << dist[N];
}
