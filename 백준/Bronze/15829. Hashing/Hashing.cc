#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
typedef unsigned long long ull;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ull M = 1234567891;
	ull l, r = 1, cur;
	ull rst = 0;
	cin >> l;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		cur = str[i] - 'a' + 1;
		rst = (rst + cur * r) %M;
		r = (r * 31)%M;
	}
	cout << rst;
}