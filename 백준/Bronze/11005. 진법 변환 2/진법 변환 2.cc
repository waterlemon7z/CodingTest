#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	int N , tar;
	cin >> N >> tar;
	string rst;
	while(N != 0)
	{
		int temp = N % tar;
		if(temp < 10)
			rst += (char)('0'+temp);
		else
		{
			rst += (char)('A' + temp - 10);
		}
		N /= tar;
	}
	std::reverse(rst.begin(), rst.end());
	cout << rst;
}
