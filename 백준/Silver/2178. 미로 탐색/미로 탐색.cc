#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
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
int input[101][101] = {0,};
int dest[101][101] = {0,};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, newX, newY, cur;
	cin >> N >> M;
	queue<pii> qq;
	cin.get();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			input[i][j] = cin.get() - '0';
			dest[i][j] = INF;
		}
		cin.get();
	}
	dest[0][0] = 1;
	qq.push({0,0});
	while(!qq.empty())
	{
		int x = qq.front().first;
		int y = qq.front().second;
		cur = dest[x][y];
		qq.pop();
		for(int i = 0; i < 4; i++)
		{
			newX = x + dx[i];
			newY = y + dy[i];
			if(newX >=0 && newX < N && newY >= 0 && newY < M && input[newX][newY] == 1)
			{
				if(dest[newX][newY] > cur + 1)
				{
					dest[newX][newY] = cur + 1;
					qq.push({newX, newY});
				}
			}
		}
	}
	cout << dest[N - 1][M - 1];
}