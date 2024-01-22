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
vector<vector<int>> arr;
int N ,M, rst = 0, zeroval = 0, total = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pii> qq, tempqq, cls;

void bfs()
{
	int row, col;
	bool check[1001][1001] = {0,};
if(qq.empty())
{
	cout << -1;
	return;
}
	while(1)
	{
		row = qq.front().first;
		col = qq.front().second;
		qq.pop();
		for(int i = 0; i < 4; i++)
		{
			if(row + dx[i] < 0 || row + dx[i] >= M || col + dy[i] < 0 ||col + dy[i] >= N)
				continue;
			if(check[row + dx[i]][col + dy[i]] == 1 || arr[row + dx[i]][col + dy[i]] == -1)
				continue;
			if(arr[row + dx[i]][col + dy[i]] == 0)
			{
				arr[row + dx[i]][col + dy[i]] = 1;
				check[row + dx[i]][col + dy[i]] = 1;
				total++;
				tempqq.push({row + dx[i], col + dy[i]});
			}
		}
		if(qq.empty())
		{
			if(tempqq.empty())
				break;
			rst++;
			qq = tempqq;
			tempqq = cls;
		}
	}
	if(total == zeroval)
		cout << rst;
	else
		cout << -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	arr = vector<vector<int>> (M, vector<int>(N, 0));
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 1)
			{
				qq.push({i, j});
			}
			else if (arr[i][j] == 0)
				zeroval++;
		}
	}
	bfs();
}