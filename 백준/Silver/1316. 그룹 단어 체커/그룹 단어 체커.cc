#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	string str;
	int N, rst = 0;
	cin >> N;
	while(N --)
	{
		int idx[27] = {0,};int i;
		cin >> str;
		for (i = 1; i <= str.size(); i++)
		{
			if(idx[str[i-1]-'a' + 1] == i-1 || idx[str[i-1]-'a' + 1] == 0)
			{
				idx[str[i-1]-'a' + 1] = i;
			}
			else
			{
				break;
			}
		}
		if(i == str.size()+1)
			rst++;
	}
	cout << rst;
}
