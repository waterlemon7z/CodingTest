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
typedef pair<pair<int,int>, int> pii;
vector<vector<int>> arr;
//bool check[100001] = {false,};
int n, m, min_ = INF, rst = 0;
void dfs(int N)
{
	int curx, cury, status;
	queue<pii> qq;

	qq.push({{2, 1}, 0});

	while(!qq.empty())
	{
		curx = qq.front().first.first;
		cury = qq.front().first.second;
		status = qq.front().second;
		qq.pop();
		if(curx == n && cury == n)
		{
			rst++;
			continue;
		}
		switch (status)
		{
			case 0:
				if(curx + 1 <= n && arr[cury][curx + 1] == 0)
					qq.push({{curx + 1, cury}, 0});
				if(curx + 1 <= n && cury + 1 <= n && arr[cury][curx + 1] == 0 && arr[cury + 1][curx + 1] == 0 && arr[cury + 1][curx] == 0)
					qq.push({{curx + 1, cury + 1}, 1});
				break;
			case 1:
				if(curx + 1 <= n && arr[cury][curx + 1] == 0)
					qq.push({{curx + 1, cury}, 0});
				if(curx + 1 <= n && cury + 1 <= n && arr[cury][curx + 1] == 0 && arr[cury + 1][curx + 1] == 0 && arr[cury + 1][curx] == 0)
					qq.push({{curx + 1, cury + 1}, 1});
				if(cury + 1 <= n && arr[cury + 1][curx] == 0)
					qq.push({{curx, cury + 1}, 2});
				break;
			case 2:
				if(curx + 1 <= n && cury + 1 <= n && arr[cury][curx + 1] == 0 && arr[cury + 1][curx + 1] == 0 && arr[cury + 1][curx] == 0)
					qq.push({{curx + 1, cury + 1}, 1});
				if(cury + 1 <= n && arr[cury + 1][curx] == 0)
					qq.push({{curx, cury + 1}, 2});
				break;
		}
	}
}

int main()
{
	cin >> n ;
	arr = vector<vector<int>> (n + 1, vector<int>(n + 1, 0));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cin >> arr[i + 1][j + 1];
	}
	dfs(n);
	cout << rst;
}