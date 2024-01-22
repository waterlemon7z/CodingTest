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
	int h,m,s,add;
	cin >> h >> m >> s >> add;
	cout <<( h + (m + (s + add)/60)/60)%24 << ' ' << (m + (s + add)/60)%60 << ' ' << (s + add)%60;
}
