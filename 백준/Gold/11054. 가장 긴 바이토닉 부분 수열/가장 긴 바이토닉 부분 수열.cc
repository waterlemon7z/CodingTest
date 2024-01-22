#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//typedef long long ll;
vector<int> arr, up, down;

int N, rst = 0;

void dp()
{
	int cur;
	if(N == 1)
	{
		cout << 1;
		return;
	}
	for(int i = 0; i < N; i++)
	{
		cur = arr[i];
		for(int j = i-1; j >= 0; j--)
		{
			if(cur > arr[j])
			{
				up[i] = max(up[i], up[j] + 1);
			}
		}
	}
	for(int i = N - 1; i >= 0; i--)
	{
		cur = arr[i];
		for(int j = i + 1; j < N; j ++)
		{
			if(cur > arr[j])
			{
				down[i] = max(down[i], down[j] + 1);
			}
		}
	}

	for(int i = 0; i < N; i++)
	{
		if(up[i] + down[i] > rst)
		{
			if(i < N - 1 && arr[i] == arr[i + 1])
			{
				rst = max(up[i], down[i]);
				continue;
			}
			rst = up[i] + down[i] - 1;
		}

	}
	cout << rst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr.resize(N);
	up.resize(N, 1);
	down.resize(N, 1);
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dp();
}