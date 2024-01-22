#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;

ull tree[4000004] = {0,};

ull sum(int curL, int curR, int index, int fst, int lst)
{
	if(fst <= curL && curR <= lst)
		return tree[index];
	if(curR < fst || curL > lst)
		return 0;
	int mid = (curR + curL)/2;
	return sum(curL, mid, index * 2, fst, lst) + sum(mid+1, curR, index * 2 + 1, fst, lst);

}

ull update(int curL, int curR, int index, int loc, int key)
{
	if(curL == curR && curL == loc)
		return tree[index] = key;
	if(curR < loc || curL > loc)
		return tree[index];
	int mid = (curL + curR) / 2;
	return tree[index] = update(curL, mid, index * 2, loc, key) + update(mid + 1, curR, index * 2 + 1, loc, key);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, mode, x, y;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> mode >> x >> y;
		if(mode == 0)
		{
			if(x< y)
				cout << sum(1, N, 1, x, y) << endl;
			else
				cout << sum(1, N, 1, y, x) << endl;
		}
		else
			update(1, N, 1, x, y);
	}
}
