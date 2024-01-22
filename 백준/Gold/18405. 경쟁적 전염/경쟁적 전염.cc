#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, S, x, y;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<vector<int>> arr;
typedef pair<int, int> pii;
priority_queue<pair<int, pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> qq;
priority_queue<pair<int, pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> newqq;
priority_queue<pair<int, pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> cls;
void bfs()
{

	int cnt = 0, xx, yy, nx, ny, cur;
//	if(S == 0)
//	{
//		cout << arr[x-1][y-1];
//		return;
//	}
	while(cnt != S)
	{
		while(!qq.empty())
		{
			cur = qq.top().first;
			xx= qq.top().second.first;
			yy= qq.top().second.second;
			qq.pop();
			for(int i = 0 ; i < 4; i++)
			{
				nx = xx + dx[i];
				ny = yy + dy[i];
				if(nx >= 0 && ny >= 0 && nx < N && ny < N)
				{
					if(arr[ny][nx] == 0)
					{
						arr[ny][nx] = cur;
						newqq.push({cur,{nx, ny}});
					}
				}
			}
		}
		if(arr[x-1][y-1] != 0)
		{

			cout << arr[x-1][y-1];
			return;
		}
		qq = newqq;
		newqq = cls;
		cnt++;
	}

	cout << arr[x-1][y-1];
}
int main()
{
	cin >> N >> M;
	arr = vector<vector<int>> (N, vector<int>(N));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] != 0)
			{
				qq.push({arr[i][j],{j,i}});
			}
		}
	}
	cin >> S >> x >> y;
	bfs();
}
