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
vector<int> arr, rst;
int N;

void treeans(int val)
{
	int cur,root;
	vector<bool> check(val, false);
	vector<vector<int>> ans(val);
	queue<int> qq;
	root = arr[0];

	for(int i = 0; i < N - 1; i++)
	{
		ans[arr[i]].push_back(arr[i+ 1]);
	}
	qq.push(root);
	while(!qq.empty())
	{
		cur = qq.front();
		qq.pop();
		for(auto iter : ans[cur])
		{
			if(!check[iter])
			{
				rst[iter] = cur;
				qq.push(iter);
				check[iter] = true;
			}
		}
	}

	rst[root] = -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int temp, max_ = 0;
	cin >> N;
	arr = vector<int> (N);
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		max_ = max(max_, arr[i]);
	}
	rst = vector<int> (max_ + 1);
	treeans(max_ + 1);

	cout << max_ + 1<< endl;
	for(auto iter : rst)
	{
		cout << iter << ' ';
	}
}