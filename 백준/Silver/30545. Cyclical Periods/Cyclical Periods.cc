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
	int cycle[26] = {0,}, N, cur, minV= 2147483647, rst;
	string str;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> cur >> str;
		for(auto iter : str)
		{
			if(cycle[iter-'a'] == 0)
			{
				cycle[iter-'a'] = cur;
			}
			else if(cycle[iter-'a'] > 0)
			{
				cycle[iter-'a'] = cycle[iter-'a'] - cur;
				if(cycle[iter-'a'] < minV)
				{
					minV =cycle[iter-'a'];
					rst = iter-'a';
				}
			}
		}
	}
	printf("%c", rst + 'a');
}
