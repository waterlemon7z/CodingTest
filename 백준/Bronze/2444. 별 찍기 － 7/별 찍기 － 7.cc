#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	int N;
	cin >> N;
	string str;
	str.resize(2*N-1,' ');
	for (int i = 0; i < N; i++)
	{
		str[(2 * N - 1)/2 + i] = '*';
		str[(2 * N - 1)/2 - i] = '*';
		cout << str.substr(0,(2 * N - 1)/2 + i + 1) << '\n';
	}

	for (int i = N-1; i >=1; i--)
	{
		str[(2 * N - 1)/2 + i] = ' ';
		str[(2 * N - 1)/2 - i] = ' ';
		cout << str.substr(0,(2 * N - 1)/2 + i) << '\n';
	}
}
