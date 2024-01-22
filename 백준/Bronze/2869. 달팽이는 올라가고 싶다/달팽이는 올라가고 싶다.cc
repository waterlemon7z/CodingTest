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
	int a, b, v;
	cin >> a >> b >> v;
	if(v < a)
	{
		cout << 1;
		return 0;
	}
	if((v-a) % (a-b) == 0)
	{
		cout  << (v - a) /(a - b) + 1;
	}
	else
	{
		cout  << (v - a) /(a - b) + 2;
	}
}