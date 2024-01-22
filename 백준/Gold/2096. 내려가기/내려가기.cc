#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
clock_t start;
typedef pair<int, int> pii;
int N;
//vector<vector<int>> arr;
void DP()
{
	int arr[3];
	int min_[2][3] = {0,};
	int max_[2][3] = {0,};
	for(int j = 0; j < 3; j++)
	{
		cin >> arr[j];
	}
	min_[0][0] = arr[0];
	min_[0][1] = arr[1];
	min_[0][2] = arr[2];
	max_[0][0] = arr[0];
	max_[0][1] = arr[1];
	max_[0][2] = arr[2];
	for(int i = 1; i < N; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cin >> arr[j];
		}
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
			{
				min_[1][j] = min_[0][j] + arr[0];
				min_[1][j] = min(min_[1][j], min_[0][j + 1] + arr[0]);
				max_[1][j] = max_[0][j] + arr[0];
				max_[1][j] = max(max_[1][j], max_[0][j + 1] + arr[0]);
			}
			else if (j == 1)
			{
				min_[1][j] = min_[0][j - 1] + arr[1];
				min_[1][j] = min(min_[1][j], min_[0][j] + arr[1]);
				min_[1][j] = min(min_[1][j], min_[0][j + 1] + arr[1]);
				max_[1][j] = max_[0][j - 1] + arr[1];
				max_[1][j] = max(max_[1][j], max_[0][j] + arr[1]);
				max_[1][j] = max(max_[1][j], max_[0][j + 1] + arr[1]);
			}
			else if (j == 2)
			{
				min_[1][j] = min_[0][j] + arr[2];
				min_[1][j] = min(min_[1][j], min_[0][j - 1] + arr[2]);
				max_[1][j] = max_[0][j] + arr[2];
				max_[1][j] = max(max_[1][j], max_[0][j - 1] + arr[2]);
			}
		}
		for(int j = 0; j < 3; j++)
		{
			min_[0][j] = min_[1][j];
			max_[0][j] = max_[1][j];
		}
	}
	if(N == 1)
	{
		sort(min_[0], min_[0] + 3);
		sort(max_[0], max_[0] + 3);
		cout << max_[0][2] << ' ' << min_[0][0] << '\n';
	}
	else
	{
		sort(min_[1], min_[1] + 3);
		sort(max_[1], max_[1] + 3);
		cout << max_[1][2] << ' ' << min_[1][0] << '\n';
	}
}

int main()
{
	cin >> N;
	DP();
}