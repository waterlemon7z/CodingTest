#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;

using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
typedef unsigned long long ull;
int total, target;

void backT(int N, ull cur, int cnt)
{
	int floor;
	if(N == cnt)
	{
		if(target == ++total)
		{
			cout << cur;
			exit(0);
		}
	}
	else if(N > cnt)
	{
		floor = (cur == 0 ? 10: cur % 10);
		for (int i = 0; i < floor; i++)
		{
			if (cur == i)
				continue;
			backT(N, cur * 10 + i, cnt + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> target;
	if(target == 0)
	{
		cout << 0;
		return 0;
	}
	if(target > 1022)
		cout << -1;
	
	for(int i = 1; i <= 10; i++)
	{
		backT(i, 0, 0);
	}
}