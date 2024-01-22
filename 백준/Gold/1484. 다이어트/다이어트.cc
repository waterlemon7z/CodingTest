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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x = 2, y = 1 ,G, cnt;
	vector<int> rst;
	cin >> G;
	while(1)
	{
		cnt = (x + y) * (x - y);
		if(cnt == G)
		{
			rst.push_back(x);
			y++;
		}
		else if(cnt > G)
		{
			if(cnt > G && y == x-1)
				break;
			y++;
		}
		else
		{
			if(cnt > G && y == x-1)
				break;
			x++;
		}
	}
	if(rst.empty())
		cout << -1;
	else
	{
		for (auto iter: rst)
		{
			cout << iter << endl;
		}
	}
}