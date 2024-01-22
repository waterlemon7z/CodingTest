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
vector<int> visit;
int N, inext, max_;

bool cmp(pii a, pii b) {return a.first > b.first;}

void bfs(int cur, int val)
{
	int nextIndex, nextVal;
	if(visit[cur] == 1)
		return;
	if(max_ < val)
	{
		max_ = val;
		inext = cur;
	}
	visit[cur] = 1;
	for(auto iter : arr[cur])
	{
		nextIndex = iter.first;
		nextVal = iter.second;
		bfs(nextIndex, nextVal + val);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int start, end, val;
	cin >> N;
	arr = vector<vector<pii>> (N + 1);
	for(int i = 0; i < N; i++)
	{
		cin >> start;
		cin >> end;
		while(end != -1)
		{
			cin >> val;
			arr[start].push_back({end, val});
			cin >> end;
		}
	}
	visit = vector<int> (N + 1, 0);
	bfs(1, 0);
	visit = vector<int> (N + 1, 0);
	bfs(inext, 0);
	cout << max_;
}
