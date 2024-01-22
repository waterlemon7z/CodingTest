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
typedef pair<int, int> pii;
vector<vector<pii>> arr;
vector<int> saved;
int N, inext;

bool cmp(pii a, pii b) {return a.first > b.first;}

int bfs(int start)
{
	int cur, val, max_ = 0;
	queue<pii> q;
	vector<int> check(N + 1, 0);
	vector<pii> dist;
	q.push({start, 0});
	check[start] = 1;
	dist.push_back({0, start});
	while(!q.empty())
	{
		cur = q.front().first;
		val = q.front().second;
		q.pop();
		check[cur] = 1;
		for(auto iter : arr[cur])
		{

			if(check[iter.first] == 1)
			{
				continue;
			}
			check[iter.first] = 1;
			dist.push_back({val + iter.second, iter.first});
			q.push({iter.first, val + iter.second});
		}
	}
	sort(dist.begin(), dist.end(), cmp);
	inext = dist[0].second;
	return dist[0].first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int start, end, val, rst = 0;
	cin >> N;
	arr = vector<vector<pii>> (N + 1);
	for(int i = 0; i < N - 1; i++)
	{
		cin >> start >> end >> val;
		arr[start].push_back({end, val});
		arr[end].push_back({start, val});
	}
	rst = bfs(1);
	rst = max(rst , bfs(inext));
	cout << rst;
}

