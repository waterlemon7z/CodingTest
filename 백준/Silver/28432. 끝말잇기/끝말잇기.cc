#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<long, long> pii;

typedef long long ull;

int main()
{
	FASTIO
	set<string> s;
	int N;
	char first = ' ', end = ' ';
	cin >> N;
	string prev = "", cur, temp;
	for (int i = 0; i < N; i++)
	{
		cin >> cur;
		if (cur == "?")
		{
			if (prev == "")
				first = ' ';
			else
				first = prev[prev.size() - 1];
		} else if (prev == "?")
		{
			end = cur[0];
			prev = "";
		}
		s.insert(cur);
		prev = cur;
	}
	cin >> N;
	if(N == 1)
	{
		cin >> temp;
		cout << temp;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (s.find(temp) != s.end())
			continue;
		if (temp[0] == first && temp[temp.size() - 1] == end)
		{
			cout << temp;
			return 0;
		} else if (temp[0] == first && end == ' ')
		{
			cout << temp;
			return 0;
		} else if (' ' == first && temp[temp.size() - 1] == end)
		{
			cout << temp;
			return 0;
		}
	}
}