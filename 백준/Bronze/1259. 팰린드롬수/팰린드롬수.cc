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
	int i;
	string str;
	cin >> str;
	while (str != "0")
	{
		for (i = 0; i < str.length() / 2; i++)
		{
			if(str[i] != str[str.length() - i - 1])
			{
				break;
			}
		}
		if(i == str.length()/2)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		cin >> str;
	}
}