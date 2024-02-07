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
	char arr[10][10];
	int N, M, rst = -1,tmp, num;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int Na = -N; Na < N; Na++)
			{
				for (int Ma = -M; Ma < M; Ma++)
				{
					if(Na == 0 && Ma == 0) continue;
					int curx = i;
					int cury = j;
					string str = "";
					while(curx>=0 && cury>=0 && curx < N && cury < M)
					{
						str += arr[curx][cury];
						num = stoi(str);
						if(sqrt(num) == (int)sqrt(num))
						{
							rst = max(num,rst);
						}
						curx += Na;
						cury += Ma;
					}
				}
			}
		}
	}
	cout << rst;
}
