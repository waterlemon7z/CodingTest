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
vector<int> crain, contain;

int solve()
{
	int rst = 0, cur = 0;
	reverse(contain.begin(), contain.end());
	reverse(crain.begin(), crain.end());
	while(!contain.empty())
	{
		for(int i = 0; i < crain.size(); i++)
		{
			for(auto iter = contain.begin(); iter != contain.end(); iter++)
			{
				if (crain[i] >= *iter)
				{
					contain.erase(iter);
					if (contain.empty())
					{
						break;
					}
					break;
				}
			}
		}
		if(contain[0] > crain[0])
		{
			return -1;
		}
		rst++;
	}
	return rst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	crain.resize(N);
	for(int i = 0; i < N; i++)
	{
		cin >> crain[i];
	}

	cin >> N;
	contain.resize(N);
	for(int i = 0; i < N; i++)
	{
		cin >> contain[i];
	}
	sort(crain.begin(), crain.end());
	sort(contain.begin(), contain.end());
	cout << solve();
}