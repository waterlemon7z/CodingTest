#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
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

int N, L;

int input[5000001] = {0,};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	deque<pii> dq;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (!dq.empty() && dq.front().second <= i - L)
		{
			dq.pop_front();
		}
		while (!dq.empty() && dq.back().first > input[i])
		{
			dq.pop_back();
		}
		dq.push_back({input[i], i});
		cout << dq.front().first << ' ';
	}

}