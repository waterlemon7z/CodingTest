#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, long long> pii;
typedef unsigned long long ull;
vector<pii> house, chick;
vector<vector<int>> ans;
vector<vector<int>> info;
int N, M, rst = 0, min_rst =INF;

void backT(int cur, int curM)
{
	int currst = 0 ;
	if(cur != 0)
	{
		for (int i = 0; i < house.size(); i++)
		{
			ans[cur][i] = min(ans[cur - 1][i], info[curM][i]);
			currst += ans[cur][i];
		}
	}
	if(currst != 0)
		min_rst = min(currst, min_rst);
	if(cur == M)
		return;
	for(int i = curM + 1; i < chick.size(); i++)
	{
		backT(cur + 1, i);
		ans[cur + 1] = vector<int>(2 * N, INF);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int temp, to, from;
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> temp;
			if(temp == 0)
				continue;
			else if(temp == 1)
			{
				house.push_back({j,i});
			}
			else
			{
				chick.push_back({j,i});
			}
		}
	}
	ans = vector<vector<int>> (M + 1, vector<int>(2 * N, INF));
	info = vector<vector<int>> (chick.size());
	for(int i = 0 ; i < chick.size(); i++)
	{
		for(int j = 0; j < house.size(); j++)
		{
			info[i].push_back(abs(house[j].first - chick[i].first) + abs(house[j].second - chick[i].second));
		}
	}
	backT(0,-1);
	cout << min_rst;
}