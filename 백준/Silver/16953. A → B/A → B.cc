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
//typedef pair<int, int> pii;
//int MM;
int start, dest, min_ = INF;

void dfs(long long cur, int rst)
{
	if(cur > dest)
		return;
	if(cur == dest)
	{
		min_ = min(min_, rst);
		return;
	}
	dfs(cur * 2, rst + 1);
	dfs(cur * 10 + 1, rst + 1);
}

int main()
{
	int n, m;
	cin >> start >> dest;
	dfs(start, 1);
	cout << ((min_ == INF) ? -1 : min_);
}