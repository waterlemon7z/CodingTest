#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 1987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;

ull seg[4000004] = {0,};

int input[1000001] = {0,};

ull insert(int s, int e, int index)
{
	if (s == e)
	{
		return seg[index] = input[s] % DIV;
	}
	int mid = (s + e) / 2;

	return seg[index] = (insert(s, mid, index * 2) * insert(mid + 1, e, index * 2 + 1))% DIV;
}

ull find(int s, int e, int l, int r, int index)
{
	if (l > e || s > r)
		return 1;
	if (r >= e && l <= s)
		return seg[index];
	int mid = (s + e) / 2;
	return (find(s, mid, l, r, index * 2) * find(mid + 1, e, l, r, index * 2 + 1)) % DIV;
}

ull update(int s, int e, int tar, int key, int index)
{
	if(tar < s || tar > e)
		return seg[index];
	if( s  == e)
	{
		return seg[index] = key;
	}
	int mid = (s + e) / 2;
	return seg[index] = (update(s, mid, tar, key, index * 2) * update(mid + 1, e, tar, key, index * 2 + 1))%DIV;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, L, s, e, mod;
	cin >> N >> M >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}
	insert(0, N - 1, 1);
	M += L;
	while(M--)
	{
		cin >> mod >> s >> e;
		s--;
		if(mod == 1)
		{
			update(0, N - 1, s, e, 1);
		}
		else
		{
			e--;
			cout << find(0, N - 1,s, e, 1) << endl;
		}
	}
}
