#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stack>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//int MM;
vector<vector<long long>> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, x1, x2, y1, y2;
	cin >> N >> M;
	arr = vector<vector<long long>> (N + 1, vector<long long> (N + 1, 0));
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
		{
				cin >> arr[i][j];
				arr[i][j] += arr[i - 1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	for(int i = 0; i < M; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		cout << arr[y2][x2] - arr[y2][x1 - 1] - arr[y1 - 1][x2] + arr[y1 - 1][x1 - 1] << '\n';
	}
}