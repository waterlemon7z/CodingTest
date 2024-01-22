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
//typedef pair<int, int> pii;
//int MM;
int dist[2][3];
vector<vector<int>> input;

void dp(int N)
{
	dist[0][0] = input[0][0];
	dist[0][1] = input[0][1];
	dist[0][2] = input[0][2];
	for(int i = 1; i < N; i++)
	{
		dist[1][0] = min(input[i][0] + dist[0][1], input[i][0] + dist[0][2]);
		dist[1][1] = min(input[i][1] + dist[0][0], input[i][1] + dist[0][2]);
		dist[1][2] = min(input[i][2] + dist[0][0], input[i][2] + dist[0][1]);

		dist[0][0] = dist[1][0];
		dist[0][1] = dist[1][1];
		dist[0][2] = dist[1][2];
	}
	cout << min(min(dist[0][0], dist[0][1]), dist[0][2]);
}

int main()
{
	int n, m;
	vector<int> temp(3);
	cin >> n;
	for(int  i = 0; i < n ; i++)
	{
		cin >> temp[0] >> temp[1] >> temp[2];
		input.push_back(temp);
	}
	dp(n);

}