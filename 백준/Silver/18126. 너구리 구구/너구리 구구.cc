#include<bits/stdc++.h>

using namespace std;
using ll = long long;
vector<pair<int, ll>> v[5010];
ll dfs(int x, int p);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int a, b, c;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cout<<dfs(1,-1);
	return 0;
}
ll dfs(int x,int p)
{
	ll ret = 0;
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i].first == p)continue;
		ret = max(ret, dfs(v[x][i].first,x) + v[x][i].second);
	}
	return ret;
}