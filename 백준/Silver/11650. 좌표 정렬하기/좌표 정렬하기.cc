#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cmath>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	set<pii> ss;
	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		ss.insert({x, y});
	}
	for(auto iter : ss)
	{
		cout << iter.first << " " << iter.second << endl;
	}
}