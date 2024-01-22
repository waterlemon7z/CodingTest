#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;


int main()
{
	FASTIO
	int N ,x,y;
	vector<pair<int, int>> arr;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		arr.push_back({y,x});
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].second << ' ' << arr[i].first << endl;
	}
}
