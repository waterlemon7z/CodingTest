#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
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

void solve(int N)
{
	int cnt = 0;
	int cur = 666;
	int temp;
	while(1)
	{
		temp = cur;
		while(temp % 100 != temp)
		{
			if(temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			temp /= 10;
		}
		if(N == cnt)
		{
			cout << cur;
			return;
		}
		cur++;

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<string> str;
	int N;
	cin >> N;
	solve(N);
}