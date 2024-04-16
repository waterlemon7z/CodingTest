#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	string str;
	cin >> str;
	int rst = 0;
	for(auto iter : str)
	{
		int temp = iter - 'A';
		if(temp >= 'S' - 'A')
			temp--;
		if(temp == 'Z' - 'A' - 1) temp--;
		rst += temp / 3 + 3;
	}
	cout << rst;
}
