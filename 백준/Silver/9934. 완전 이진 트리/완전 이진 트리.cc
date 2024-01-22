#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, long long> pii;
typedef unsigned long long ull;
vector<int> tree;
vector<vector<int>> ans;
int N;

void treeans(int fst, int lst, int level)
{
	if(fst == lst)
	{
		ans[level].push_back(tree[fst]);
		return;
	}
	int root = (fst + lst) / 2;
	ans[level].push_back(tree[root]);
	treeans(fst, root - 1, level + 1);
	treeans(root + 1, lst, level + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int temp;
	cin >> N;
	ans = vector<vector<int>> (N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < pow(2,i); j++)
		{
			cin >> temp ;
			tree.push_back(temp);
		}

	treeans(0, tree.size() - 1, 0);
	for(auto iter : ans)
	{
		for(auto node : iter)
		{
			cout << node << ' ';
		}
		cout << endl;
	}
}