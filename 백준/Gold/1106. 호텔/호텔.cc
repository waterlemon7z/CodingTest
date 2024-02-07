#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
int cost[1001] = {0,};
pii info[20];
int C, N;

int solve(int cus)
{
	int rst = 1000000;
	if(cus <= 0)
		return 0;
	else if(cost[cus]>0)
		return cost[cus];
	for(int i = 0;i < N; i++)
		rst = min(rst, solve(cus - info[i].second) + info[i].first);
	
	return cost[cus] = rst;
}

int main()
{
	FASTIO
	cin >> C >> N;
	for (int i = 0; i < N; i++)
		cin >> info[i].first >> info[i].second;
	cout << solve(C);
}
