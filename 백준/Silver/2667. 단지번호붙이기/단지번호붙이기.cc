#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;
int arr[26][26] = {0,}, N, check[26][26] = {0,}, dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

class customQeueu : queue<pii>
{
	pii pop_back()
	{
		pii cur = this->front();
		this->pop();
		return cur;
	}
};

int bfs(int x, int y)
{
	int rst = 0;
	queue<pii> q;
	q.push({x,y});
	check[x][y] = 1;
	while(!q.empty())
	{
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + cur.first;
			int ny = dy[i] + cur.second;
			if(nx >= 0 && nx < N && ny >= 0 && ny < N && check[nx][ny] == 0 && arr[nx][ny] == 1)
			{
				q.push({nx, ny});
				check[nx][ny] = 1;
				rst++;
			}
		}
	}
	return ++rst;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<pii> qq;
	vector<int> rst;
	cin >> N;
	cin.get();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = cin.get() - '0';
			if(arr[i][j] == 1)
			{
				qq.push({i,j});
			}
		}
		cin.get();
	}
	while(!qq.empty())
	{
		pii cur = qq.front();
		qq.pop();
		if(check[cur.first][cur.second] == 0)
		{
			rst.push_back(bfs(cur.first, cur.second));
		}
	}
	sort(rst.begin(), rst.end());
	cout << rst.size() << endl;
	for(auto iter : rst)
	{
		cout << iter << endl;
	}
}