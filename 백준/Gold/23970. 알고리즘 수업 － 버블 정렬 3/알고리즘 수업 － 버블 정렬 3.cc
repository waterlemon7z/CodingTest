#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, cnt = 0, temp;
	cin >> N;
	vector<int> arr(N);
	vector<int> key(N);
	vector<bool> check(N);

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for(int i = 0; i < N; i++)
	{
		cin >> key[i];
		if(arr[i] == key[i])
		{
			check[i] = 1;
			cnt++;
		}
	}

	if(cnt == N)
	{
		cout << 1;
		return 0;
	}
	for(int i = N - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				if(arr[j] == key[j])
				{
					if(!check[j])
					{
						check[j] = true;
						cnt++;
					}
				}
				else
				{
					if(check[j])
					{
						check[j] = false;
						cnt--;
					}
				}

				if(arr[j + 1] == key[j + 1])
				{
					if(!check[j + 1])
					{
						check[j + 1] = true;
						cnt++;
					}
				}
				else
				{
					if(check[j + 1])
					{
						check[j + 1] = false;
						cnt--;
					}
				}
			}
			if(cnt == N)
			{
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}