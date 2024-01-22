#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
int N, rst = 0;
vector<vector<int>> dist;

void flo()
{
	for(int k = 0; k < N; k++)
	{
		for(int from = 0; from < N; from++)
		{
			for(int to = 0; to < N; to++)
			{
				if(dist[from][to] > dist[from][k] + dist[k][to])
					dist[from][to] = dist[from][k] + dist[k][to];
			}
		}
	}
	for(auto iter : dist)
	{
		for(auto val : iter)
		{
			if(val == INF)
				cout << 0 << ' ';
			else cout << val << ' ';
		}
		cout << endl;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, from, to ,val;
	cin >> N >> k;
	dist = vector<vector<int>> (N, vector<int>(N, INF));
	for(int i  = 0; i < N; i++)
	{
		dist[i][i] = 0;
	}
	for(int i = 0; i < k; i++)
	{
		cin >> from >> to >> val;

		if(dist[from - 1][to - 1] > val)
			dist[from - 1][to - 1] = val;
	}
	flo();
}

