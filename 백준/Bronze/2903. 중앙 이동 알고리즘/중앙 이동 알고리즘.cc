#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	int N ,cur = 2;
	cin >> N ;
	for (int i = 0; i < N; i++)
	{
		cur += (cur-1);
	}
	cout << (long)cur*cur;
}
