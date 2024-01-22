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

const int MAX = 9;

int board[MAX][MAX] = {0,};
vector<pii> blank;

void print()
{
	for(auto & i : board)
	{
		for(auto & j : i)
		{
			cout << j;
		}
		cout << endl;
	}
}

bool is_avail(int x, int y, int key)
{
	for(int i = 0; i < 9; i++)
	{
		if(i != x && board[i][y] == key)
			return false;
		if(i != y && board[x][i] == key)
			return false;
		int cx = x / 3 * 3 + i / 3;
		int cy = y / 3 * 3 + i % 3;
		if(cx != x && cy != y && board[cx][cy] == key)
			return false;
	}
	return true;
}

void backT(int cur)
{
	if(cur == blank.size())
	{
		print();
		exit(0);
	}
	int x = blank[cur].first;
	int y = blank[cur].second;
	for(int i = 1; i <= 9; i++)
	{
		if(is_avail(x,y,i))
		{
			board[x][y] = i;
			backT(cur + 1);
			board[x][y] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int temp;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX;j++)
		{
			board[i][j] = cin.get() - '0';
			if(board[i][j] == 0)
				blank.push_back({i,j});
		}
		cin.get();
	}
	backT(0);

}