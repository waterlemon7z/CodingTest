#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//typedef long long ll;
vector<vector<int>> liquid;
int N, M, rst = 0, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char arr[20][20];
vector<bool> check(26, false);
void bfs(int xx, int yy, int cur)
{
	if(cur > rst)
		rst = cur;
	for(int i = 0; i < 4; i++)
	{
		if(xx + dx[i] >= 0 && xx + dx[i] < N && yy + dy[i] >= 0 && yy + dy[i] < M)
		{
			if(check[arr[xx + dx[i]][yy + dy[i]] - 'A'])
				continue;
			check[arr[xx + dx[i]][yy + dy[i]] - 'A'] = true;
			bfs(xx + dx[i], yy + dy[i], cur + 1);
			check[arr[xx + dx[i]][yy + dy[i]] - 'A'] = false;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char temp;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			temp = cin.get();
			if(temp == '\n')
				temp = cin.get();
			arr[i][j] = temp;
		}
	}
	check[arr[0][0] - 'A'] = true;
	bfs(0, 0, 1);
	cout << rst;
}