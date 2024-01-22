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

void solve(string s, string t)
{
	bool revs = 0;
	while(s.size() < t.size())
	{
		if(!revs)
		{
			if(t.back() == 'A')
			{
				t.pop_back();
			}
			else
			{
				t.pop_back();
				revs = true;
			}
		}
		else
		{
			if(t.front() == 'A')
			{
				t.erase(t.begin());
			}
			else
			{
				t.erase(t.begin());
				revs = false;
			}
		}
	}
	if(revs)
		reverse(t.begin(), t.end());
	if(s == t)
	{
		cout << 1;
	}
	else
		cout << 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string S, T;
	cin >> S >> T;

	solve(S,T);
}
