#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;

int main()
{
	FASTIO
	int N, M, row[51] = {0,}, col[51] = {0,}, rst = 0;
	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			if (str[j] == 'X')
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	int i = 0, j = 0;
	while (i < N && j < M)
	{
		if(!row[i] && !col[j])
		{
			row[i] = 1;
			col[j] = 1;
			rst++;
		}
		if(!row[i])
		{
			j++;
			continue;
		}
		if(!col[j])
		{
			i++;
			continue;
		}
		i++;j++;
	}
	for (i = 0; i < N; i++)
	{
		if (!row[i])
		{
			rst++;
		}
	}
	for (j = 0; j < M; j++)
	{
		if (!col[j])
		{
			rst++;
		}
	}
	cout << rst;
}