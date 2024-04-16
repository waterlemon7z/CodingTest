#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	string str;
	int rst = 0;
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if(str[i] == '=')
		{
			if(str[i-1] == 'c' || str[i-1] == 's')
			{
				i--;
			}
			else if(str[i-1] == 'z')
			{
				if(i-2 >= 0 && str[i-2] == 'd')
				{
					i--;
				}
				i--;
			}
		}
		else if(str[i] == '-')
		{
			if(str[i-1] == 'c' || str[i-1] == 'd')
			{
				i--;
			}
		}
		else if(str[i] == 'j')
		{
			if(str[i-1] == 'l' || str[i-1] == 'n')
			{
				i--;
			}
		}
			rst++;
	}
	cout << rst;
}
