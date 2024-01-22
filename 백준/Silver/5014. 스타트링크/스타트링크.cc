#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;

using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
typedef long long ll;
vector<int> rst;
int F, S, G, U, D;

void dfs()
{
	int base = S, cur = -1;
	queue<int> qq;
	rst[base] = 0;
	qq.push(base);

	while(!qq.empty())
	{
		base = qq.front();
		qq.pop();
		if(base + U <= F)
		{
			if(rst[base + U] > rst[base] + 1)
			{
				rst[base + U] = rst[base] + 1;
				qq.push(base + U);
			}
		}
		if(base - D >= 1)
		{
			if(rst[base - D] > rst[base] + 1)
			{
				rst[base - D] = rst[base] + 1;
				qq.push(base - D);
			}
		}

	}
	if(rst[G] == INF)
		cout << "use the stairs";
	else
		cout << rst[G];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> F >> S >> G >> U >> D;
	rst.resize(F + 1, INF);
	dfs();
}