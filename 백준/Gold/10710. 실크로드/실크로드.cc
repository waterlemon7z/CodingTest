#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	int N, M, arr[1001], time[1001] = {0,}, dist[1001] = {0,},j;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i + 1];
		dist[i+1] = 1000000001;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> time[i + 1];
	}
	dist[1] = arr[1] * time[1];
	for (int i = 2; i <= M; i++)
	{
		j = min(i, N);
		for (; j >= 1; j--)
		{
			if (dist[j - 1] + time[i] * arr[j] < dist[j])
				dist[j] = dist[j - 1] + time[i] * arr[j];
		}
	}
	cout << dist[N];
}
