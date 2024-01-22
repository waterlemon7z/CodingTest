#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, long long> pii;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << "NFC West       W   L  T\n"
			"-----------------------\n"
			"Seattle        13  3  0\n"
			"San Francisco  12  4  0\n"
			"Arizona        10  6  0\n"
			"St. Louis      7   9  0\n"
			"\n"
			"NFC North      W   L  T\n"
			"-----------------------\n"
			"Green Bay      8   7  1\n"
			"Chicago        8   8  0\n"
			"Detroit        7   9  0\n"
			"Minnesota      5  10  1";
}