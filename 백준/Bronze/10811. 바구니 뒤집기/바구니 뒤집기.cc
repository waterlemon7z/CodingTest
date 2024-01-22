#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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
	vector<int> arr;
	int N, M, x, y;
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		arr.push_back(i);
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		reverse(arr.begin() + x - 1, arr.begin() + y);
	}
	for (auto iter: arr)
		cout << iter << ' ';
}