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

void comp(int &a, int &b)
{
	if(a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<string> str;
	int x,y,z;
	cin >> x >> y >> z;
	comp(x, y);
	comp(y, z);
	comp(x, y);
//	comp(y, z);

	if(x == y && y == z)
	{
		cout << 10000 + z * 1000;
	}
	else if(x == y || y == z)
	{
		cout << 1000 + y * 100;
	}
	else
		cout << z * 100;

}