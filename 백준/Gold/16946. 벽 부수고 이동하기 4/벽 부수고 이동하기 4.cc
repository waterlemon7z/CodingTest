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

int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
int matrix[1000][1000];
int rstMat[1000][1000] = {0,};
int memo[1000000] = {0,};
int zeroCnt = 2;
int N, M;
void bfs(int row, int col)
{
	if(matrix[row][col] >= 1)
		return;
	matrix[row][col] = zeroCnt;
	memo[zeroCnt]++;
	for(int i =0; i < 4; i++)
	{
		if(row + dx[i] < N && row + dx[i] >= 0 && col + dy[i] < M && col + dy[i] >= 0)
			bfs(row + dx[i], col + dy[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<pii> qFor0, qFor1;
	set<int> visit;

	int row, col, rst = 0, cur;
	string input;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> input;
		for(int j = 0; j < M ;j++)
		{
			matrix[i][j] = input[j] - '0';
			if(matrix[i][j] == 0)
			{
				qFor0.push(make_pair(i,j));
			}
			else
				qFor1.push(make_pair(i,j));
		}
	}
	while(!qFor0.empty())
	{
		bfs(qFor0.front().first, qFor0.front().second);
		qFor0.pop();
		zeroCnt++;
	}
	while(!qFor1.empty())
	{
		row = qFor1.front().first;
		col = qFor1.front().second;
		qFor1.pop();
		visit.clear();
		for(int i =0; i < 4; i++)
		{
			if(row + dx[i] < N && row + dx[i] >= 0 && col + dy[i] < M && col + dy[i] >= 0)
				if((cur = matrix[row + dx[i]][col + dy[i]]) >= 2)
				{
					if(visit.find(cur) == visit.end())
					{
						rst += memo[cur];
						visit.insert(cur);
					}
				}
		}
		rst ++;
		rstMat[row][col] = rst;
		rst = 0;
	}
	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << rstMat[i][j]%10;
		}
		cout << endl;
	}
}