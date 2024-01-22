#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
typedef pair<long long , long long> pii;
//int MM;
vector<long long> dist;
vector<vector<pii>> dfs;

void dji(int start, int dest)
{
	int t;
	long long cur, min_, next, sum_;
	vector<int> visit(dfs.size()), arrv;
	priority_queue<pii, vector<pii>, greater<pii>> qq;
	qq.push({0,start});
	dist[start] = 0;
	while(!qq.empty())
	{
		min_ = qq.top().first;
		cur = qq.top().second;
		qq.pop();
		if(min_ > dist[dest])
		{
			continue;
		}
		for(int i = 0; i < dfs[cur].size(); i++)
		{
			next = dfs[cur][i].first;
			sum_ = dfs[cur][i].second + min_;
			if(dist[next] > sum_)
			{
				dist[next] = sum_;
				qq.push({sum_, next});
				visit[next] = cur;
			}
		}
	}
	cout << dist[dest] << '\n';
	t = dest;
	while(1)
	{
		if(t == start)
		{
			arrv.push_back(t);
			break;
		}
		arrv.push_back(t);
		t = visit[t];
	}
	cout << arrv.size() << '\n';
	reverse(arrv.begin(), arrv.end());
	for(auto iter : arrv)
		cout << iter << ' ';
}

int main()
{
	int n, m, ss, dd, val;
	cin >> n >> m;
	dfs = vector<vector<pii>> (n + 1);
	dist = vector<long long> (n + 1, INF);
	for (int i = 0; i < m; i++)
	{
		cin >> ss >> dd >> val;
		dfs[ss].push_back({dd, val});
	}
	cin >> ss >> dd;
	dji(ss, dd);
}