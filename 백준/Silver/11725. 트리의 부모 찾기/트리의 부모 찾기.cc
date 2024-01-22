#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//typedef unsigned long long ull;
int N;
vector<vector<int>> arr;
vector<bool> check;
vector<int> ans;

void bfs()
{
	int cur;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		for(auto iter : arr[cur])
		{
			if(!check[iter])
			{
				ans[iter] = cur;
				check[iter] = 1;
				q.push(iter);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int fst, lst;
	arr = vector<vector<int>> (N + 1);
	ans = vector<int> (N + 1, 0);
	check = vector<bool> (N + 1, 0);
	check[1] = 1;
	for(int i = 0; i < N - 1; i++)
	{
		cin >> fst >> lst;
		arr[fst].push_back(lst);
		arr[lst].push_back(fst);
	}
	bfs();
	for(int  i =2; i <= N; i++)
	{
		cout << ans[i] << endl;
	}
}
