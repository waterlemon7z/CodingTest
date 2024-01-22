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
//typedef pair<int, int> pii;

vector<int> inorder;
vector<int> inorder_index;
vector<int> postorder;
int N, init_root, d = 1;

void tree(int fst, int lst, int pfst, int plst)
{
	if(fst > lst || pfst > plst)
		return;
	int root_index = inorder_index[postorder[plst]], left, right;

	left = root_index - fst;
	right = lst - root_index;
	cout << inorder[root_index] << ' ';

	tree(fst, root_index - 1, pfst, pfst + left - 1);
	tree(root_index + 1, lst, pfst + left, plst - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int temp;

	cin>> N;
	inorder_index = vector<int> (N + 1);
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		inorder.push_back(temp);
		inorder_index[temp] = i;
	}
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		postorder.push_back(temp);
	}
	init_root = postorder.back();
	tree(0, N - 1, 0, N - 1);
}
