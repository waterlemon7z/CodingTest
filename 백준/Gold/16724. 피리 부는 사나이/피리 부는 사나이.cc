#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
int N, M;
char input[1000][1000] = {0,};
pii root[1000][1000];
bool check[1000][1000] = {0,};

pii find_(pii x)
{
	if(root[x.first][x.second] == x)
	{
		return x;
	}
	return root[x.first][x.second] = find_(root[x.first][x.second]);
}

void union_(pii x, pii y)
{
	x = find_(x);
	y = find_(y);
	if(x == y)
		return;
	root[x.first][x.second] = y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	int rst = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			input[i][j] = str[j];
			root[i][j] = {i,j};
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(input[i][j] == 'D' && i + 1 < N)
				union_({i,j}, {i + 1, j});
			else if(input[i][j] == 'U' && i - 1 >= 0)
				union_({i, j}, {i - 1, j});
			else if(input[i][j] == 'R' && j + 1 < M)
				union_({i, j}, {i, j + 1});
			else if(input[i][j] == 'L' && j - 1 >= 0)
				union_({i, j}, {i, j - 1});
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			pii temp = find_({i,j});
			if(check[temp.first][temp.second] == 0)
			{
				check[temp.first][temp.second] = 1;
				rst ++;
			}
		}
	}
	cout<<rst;
}