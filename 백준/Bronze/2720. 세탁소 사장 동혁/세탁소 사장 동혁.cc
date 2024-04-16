#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	int N ,cur;
	cin >> N ;
	while(N--)
	{
		cin >> cur;

		cout << cur / 25<< ' ';
		cur %= 25;
		cout << cur / 10<< ' ';
		cur %= 10;
		cout << cur / 5 << ' ';
		cur %= 5;
		cout << cur << endl;
	}
}
