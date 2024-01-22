#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef long long ull;

int N, M, K;

ull input[1000001] = {0,};

ull tree[4000004] = {0,};

ull mk_tree(int start, int end, int node)
{
	if (start == end)
		return tree[node] = input[start];
	int mid = (start + end) / 2;
	return tree[node] = mk_tree(start, mid, node * 2) + mk_tree(mid + 1, end, node * 2 + 1);
}

ull sum(int start, int end, int node, int l, ull r)
{
	if (start > r || end < l)
		return 0;
	if (start >= l && end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, l, r) + sum(mid + 1, end, node * 2 + 1, l, r);
}

void update(int start, int end, int node, int l, ull key)
{
	if (start > l || end < l)
		return;
	tree[node] += key;
	if(start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, l, key);
	update(mid + 1, end, node * 2 + 1, l, key);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int oper, from;
	ull to;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> input[i];
	}
	mk_tree(1, N, 1);
	for (int i = 0; i < K + M; i++)
	{
		cin >> oper >> from >> to;
		if (oper == 1) //update
		{
			update(1, N, 1, from, to - input[from]);
			input[from] = to;
		}
		else //sum
		{
			cout << sum(1, N, 1, from, to) << endl;
		}
	}
}