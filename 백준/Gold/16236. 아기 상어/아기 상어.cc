#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cmath>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int arr[20][20] = {0,};
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
int rst, row, col, dolSize = 2, full = 0;
int N;

pii bfs(int x, int y)
{
	queue<pii> q, temp, clear;
	set<pii> locSet;
	int check[20][20] = {0,};
	int cnt = 0;
	check[x][y] = 1;
	q.push(make_pair(x,y));
	while(locSet.empty())
	{
		while (!q.empty())
		{
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				if (curX + dx[i] >= 0 && curX + dx[i] < N && curY + dy[i] >= 0 && curY + dy[i] < N && arr[curX + dx[i]][curY + dy[i]] <= dolSize && check[curX + dx[i]][curY + dy[i]] == 0)
				{
					check[curX + dx[i]][curY + dy[i]] = 1;
					temp.push(make_pair(curX + dx[i], curY + dy[i]));
					if (arr[curX + dx[i]][curY + dy[i]] < dolSize && arr[curX + dx[i]][curY + dy[i]] != 0)
					{
						locSet.insert(make_pair(curX + dx[i],curY + dy[i]));
					}
				}
			}
		}
		if(temp.empty())
		{
			return {-1,-1};
		}
		cnt++;
		q = temp;
		temp = clear;
	}
	rst+= cnt;
	return *locSet.begin();
//	cout << locSet.begin()->first << " " << locSet.begin()->second;
}


void solve()
{
	arr[row][col] = 0;
	pii tempRst;
	while(1)
	{
		if ((tempRst = bfs(row, col)) == make_pair(-1, -1))
		{
			return;
		}
		row = tempRst.first;
		col = tempRst.second;
		full++;
		if(full == dolSize)
		{
			full = 0;
			dolSize++;
		}
		arr[row][col] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 9)
			{
				row = i;
				col = j;
			}
		}
	}

	solve();
	cout << rst;
}