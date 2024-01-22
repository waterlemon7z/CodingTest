#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>> arr, int cut, int root)
{
	int ret = 1;
	int child = 0;
	for(auto iter : arr[root])
	{
		if(iter == cut)
			continue;
		child += dfs(arr, cut, iter);
	}
	if(child)
	{
		return child;
	}
	else
		return ret;

}

int main()
{
	int N, temp, del, root;
	cin >> N;
	vector<vector<int>> arr(N);
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		if(temp == -1)
		{
			root = i;
			continue;
		}
		arr[temp].push_back(i);
	}
	cin >> del;
	if(root == del)
		cout << 0;
	else
		cout << dfs(arr, del, root);
	return 0;
}
