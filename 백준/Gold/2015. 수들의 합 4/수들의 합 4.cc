#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
	FASTIO
	map<int,int> m;
	m[0] = 1;
	int N, K, arr[200001] = {0,};
	long long rst = 0;
	cin >> N  >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		arr[i] = arr[i] + arr[i-1];
		if(m[arr[i] - K] > 0)
		{
			rst += m[arr[i] - K];
		}
		m[arr[i]]++;
	}
	cout << rst;
}