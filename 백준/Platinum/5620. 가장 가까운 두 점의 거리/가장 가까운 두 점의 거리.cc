#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define INF LLONG_MAX
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

typedef pair<int, int> pii;

typedef long long ull;

vector<pii> arr;
vector<pii> rarr;
vector<pii> temp(500001);

int sq(int n)
{
	return n * n;
}

int dist(pii a, pii b)
{
	return sq(a.first - b.first) + sq(a.second - b.second);
}

void merge(int f, int m , int l)
{
	int fst = f;
	int lst = m + 1;
	int cur = f;
	while(fst <= m && lst <= l)
	{
		if(rarr[fst].first < rarr[lst].first)
		{
			temp[cur++] = rarr[fst++];
		}
		else
			temp[cur++] = rarr[lst++];
	}
	for (; fst <= m; fst++)
	{
		temp[cur++] = rarr[fst];
	}
	for (; lst <= l; lst++)
	{
		temp[cur++] = rarr[lst];
	}
	for (int i = f; i <= l; i++)
	{
		rarr[i] = temp[i];
	}
}
int solve(int f, int l)
{
	vector<pii> strip;
	if (f == l)
		return 2147483647;
	else if (l - f == 1)
	{
		if (rarr[f].first > rarr[l].first)
			swap(rarr[f], rarr[l]);
		return dist(arr[f], arr[l]);
	}
	int mid = (f + l ) / 2;
//	sort(rarr.begin() + f, rarr.end() + l + 1);
	int d = min(solve(f, mid), solve(mid + 1, l));
	merge(f,mid,l);

	for (int i = f; i <= l; i++)
	{
		if (sq(arr[mid].first - rarr[i].second) < d)
		{
			strip.push_back(rarr[i]);
		}
	}
	int rst = d;
	for (int i = 0; i < strip.size(); i++)
	{
		for (int j = i + 1; j < strip.size(); j++)
		{
			if (sq(strip[i].first - strip[j].first) >= d)
				break;
			rst = min(rst, dist(strip[i], strip[j]));
		}
	}
	return rst;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	arr.resize(N);
	rarr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		rarr[i] = {arr[i].second, arr[i].first};
	}
	cout << solve(0, N - 1);
}