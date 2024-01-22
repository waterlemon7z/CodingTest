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

pii seg[400004] = {{0, 0},};

int input[100001] = {0,};

pii insert(int s, int e, int index)
{
	if (s == e)
	{
		seg[index].first = input[s];
		seg[index].second = input[s];
		return seg[index];
	}
	int mid = (s + e) / 2;
	insert(s, mid, index * 2);
	insert(mid + 1, e, index * 2 + 1);
	seg[index].first = min(seg[index * 2].first, seg[index * 2 + 1].first);
	seg[index].second = max(seg[index * 2].second, seg[index * 2 + 1].second);

	return seg[index];
}

pii find(int s, int e, int l, int r, int index)
{
	if(l > e || s > r)
		return {INF, -1};
	if (r >= e &&  l <= s)
		return seg[index];
	int mid = (s + e) / 2;
	pii le = find(s, mid, l, r,index * 2);
	pii ri = find(mid + 1, e,l, r, index * 2 + 1);
	return {min(ri.first, le.first), max(ri.second, le.second)};
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, s, e;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}
	insert(0, N - 1, 1);
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		pii temp = find(0, N - 1, s-1, e-1, 1);
		cout << temp.first << ' ' << temp.second << endl;
	}
}
