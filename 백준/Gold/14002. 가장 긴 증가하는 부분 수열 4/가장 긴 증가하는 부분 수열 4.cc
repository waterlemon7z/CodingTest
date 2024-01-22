#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
stack<int> s;
	int N,arr[1001], dp[1001], maxLen = -1;
cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		int len = 0;
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[j] < arr[i])
			{
				len = max(dp[j], len);
			}
		}
		len += 1;
		maxLen = max(maxLen, len);
		dp[i] = len;
	}
	cout << maxLen << endl;
	for(int i = N - 1;i >= 0; i--)
	{
		if(dp[i] == maxLen)
		{
			s.push(arr[i]);
			maxLen--;
		}
	}
	while(!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
}
