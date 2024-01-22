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
	string str;
	int N, M;
	cin >> str >> N >> M;
	while(str != "#" && N != 0 && M != 0)
	{
		cout << str << " " << (N > 17 || M >= 80 ?"Senior" : "Junior") << endl;
		cin >> str >> N >> M;
	}

}