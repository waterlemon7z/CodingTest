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
	int x, y, z, temp;
	cin >> x >> y >> z;
	while (!(x == 0 && y == 0 && z == 0))
	{
		if (z > y && z > x)
		{
			temp = z;
			z = x;
			x = temp;
		}
		else if (y > x && y > z)
		{
			temp = y;
			y = x;
			x = temp;
		}
		if (x * x == y * y + z * z)
			cout << "right\n";
		else
			cout << "wrong\n";
		cin >> x >> y >> z;
	}
}