#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	int x ,y ;
	cin >> x >> y;
	while(x != 0 && y != 0)
	{
		if (x < y)
		{
			if (y % x == 0)
				cout << "factor\n";
			else
				cout << "neither\n";
		} else
		{
			if (x % y == 0)
				cout << "multiple\n";
			else
				cout << "neither\n";
		}
		cin >> x >> y;
	}
}
