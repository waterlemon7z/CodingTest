#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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

int arr[10001] = {0,};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr[temp]++;
	}
	for(int i = 0; i < 10001; i++)
	{
		if(arr[i] == 0)
		{
			continue;
		}
		for(int j = 0; j < arr[i]; j++)
		{
			printf("%d\n", i);
		}
	}
}