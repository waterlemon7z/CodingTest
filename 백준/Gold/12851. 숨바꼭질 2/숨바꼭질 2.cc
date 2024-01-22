#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
typedef pair<int, int> pii;
//int MM;
vector<vector<int>> dfsarr;
int n, m, min_ = INF, rst = 0;
bool check[100001] = {false,};

void dfs(int N, int M)
{
	int cur, sec;
	queue<pii> qq;
	qq.push({N, 0});
	check[N] = true;
	while(!qq.empty())
	{
		cur = qq.front().first;
		sec = qq.front().second;
		qq.pop();
		check[cur] = true;
		if(cur == M)
		{
			if(sec < min_)
			{
				min_ = sec;
				rst = 1;
			}
			else if(sec == min_)
			{
				rst++;
			}
		}
		if(cur - 1 >= 0 && !check[cur - 1])
			qq.push({cur - 1, sec + 1});
		if(cur + 1 <= 100000 && !check[cur + 1])
			qq.push({cur + 1, sec + 1});
		if(cur * 2 <= 100000 && !check[cur * 2])
			qq.push({cur * 2, sec + 1});
	}
}

int main()
{
	cin >> n >> m;
	dfs(n, m);
	cout << min_ <<'\n' << rst;
}