#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
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
char input[1501][1501] = {0,};
queue<pii> xque, xNque, birdque, birdNque;
pii swan;
int R, C, dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0}, check[1501][1501];
bool fine = false;

void bBFS()
{
	int nx, ny;
	while(!birdque.empty())
	{
		pii cur = birdque.front();
		birdque.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = cur.first + dx[i];
			ny = cur.second + dy[i];
			if(nx >= 0  && nx < R && ny >= 0 && ny < C && check[nx][ny] == 0)
			{
				if(input[nx][ny] == '.')
				{
					birdque.push({nx, ny});
				}
				else if(input[nx][ny] == 'X')
				{
					birdNque.push({nx, ny});
				}
				else if(input[nx][ny] == 'L')
				{
					fine = true;
					return;
				}
				check[nx][ny] = 1;
			}
		}
	}
}

void wBFS()
{
	int nx, ny, x, y;
	while(!xque.empty())
	{
		x = xque.front().first;
		y = xque.front().second;
		xque.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx >= 0 && nx < R && ny >= 0 && ny < C && input[nx][ny] == 'X')
			{
				input[nx][ny] = '.';
				xNque.push({nx,ny});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<pii> clear;
	int rst = 0;
	char temp;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> input[i][j];
			if(input[i][j] != 'X')
			{
				xque.push({i, j});
			}
			if(input[i][j] == 'L')
				swan = {i,j};
		}
	}
	birdque.push(swan);
	input[swan.first][swan.second] = '.';
	while(!fine)
	{
		rst++;
		wBFS();
		bBFS();
		xque = xNque;
		birdque = birdNque;
		xNque = clear;
		birdNque = clear;
	}
	cout << rst;
}
