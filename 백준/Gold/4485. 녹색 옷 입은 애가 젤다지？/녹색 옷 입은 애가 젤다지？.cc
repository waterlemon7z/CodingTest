#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F printf("%f\n", (double)(clock() - start) / CLOCKS_PER_SEC);

using namespace std;
typedef pair<int, int> pii;
clock_t start;
vector<vector<int>> arr(256,vector<int>(256, INF));
int N, iii = 1;
int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, 1, 0, -1};
void dijstra()
{
	int cc, cr;

	vector<vector<int>> dist(N, vector<int>(N,INF));
	dist[0][0] = arr[0][0];
	queue<pii> qq;
	qq.push({0,0});
	while(!qq.empty())
	{
		cr = qq.front().first;
		cc = qq.front().second;
		qq.pop();
		for(int i = 0; i < 4; i++)
		{

			if(dc[i] + cc < 0 || dc[i] + cc >= N || dr[i] + cr < 0 || dr[i] + cr >= N )
				continue;
			if(dist[dr[i] + cr][dc[i] + cc] > arr[dr[i] + cr][dc[i] + cc] + dist[cr][cc])
			{
				dist[dr[i] + cr][dc[i] + cc] = arr[dr[i] + cr][dc[i] + cc] + dist[cr][cc];
				qq.push({dr[i] + cr, dc[i] + cc});
			}
		}
	}
	cout << "Problem "<< iii++ << ": " <<dist[N-1][N-1] << endl;
}
int main()
{
	cin >> N;
	while(N != 0)
	{
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}

		TIMER_S
		dijstra();
//		TIMER_F
		cin >> N;
	}
}

