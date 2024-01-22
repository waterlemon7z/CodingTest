#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, long long> pii;
typedef unsigned long long ull;
vector<vector<int>> arr;
vector<int> color;
int N, M, rst = 0;

void bfs()
{
	int cur, c_color;
	queue<pii> qq;
	for(int i = 0; i < N; i++)
	{
		if(color[i] == 0)
			continue;
		qq.push({i + 1, color[i]});
		color[i] = 0;
		while(!qq.empty())
		{
			cur = qq.front().first;
			c_color = qq.front().second;
			qq.pop();
			for(auto iter : arr[cur])
			{
				if(color[iter - 1] == c_color)
				{
					qq.push({iter, c_color});
					color[iter - 1] = 0;
				}
			}
		}
		rst ++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int temp, to, from;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		color.push_back(temp);
	}
	arr = vector<vector<int>>( N + 1);
	for(int i = 0; i < N - 1; i++)
	{
		cin >> to >> from;
		arr[to].push_back(from);
		arr[from].push_back(to);
	}
	bfs();
	cout << rst;
}