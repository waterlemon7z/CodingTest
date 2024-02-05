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
int main()
{
	FASTIO
	string str;
	int N = 0;
	while(getline(cin, str))
	{
		N++;
	}
	cout<< N;
}
