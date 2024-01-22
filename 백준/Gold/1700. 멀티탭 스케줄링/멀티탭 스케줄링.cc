#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 1987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool pluged;
	int N, K, arr[101], plug[101] = {0,}, cur, rst = 0;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < K; i++)
	{
		cur = arr[i];
		pluged = false;
		for (int j = 0; j < N; j++)
		{
			if (plug[j] == cur)
			{
				pluged = true;
			}
		}
		if (pluged)
			continue;

		for (int j = 0; j < N; j++)
		{
			if (plug[j] == 0)
			{
				plug[j] = cur;
				pluged = true;
				break;
			}
		}
		if (pluged)
			continue;

		int index, changeIdx = -1;
		for (int j = 0; j < N; j++)
		{
			int lindex = 0;
			for (int l = i + 1; l < K; l++)
			{
				if (arr[l] == plug[j])
				{
					break;
				}
				lindex++;
			}
			if (lindex > changeIdx)
			{
				index = j;
				changeIdx = lindex;
			}
		}
		rst++;
		plug[index] = cur;
	}
	cout << rst;
}
