#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	int temp;
	int max = -1, x,y;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> temp;
			if(max < temp)
			{
				max = temp;
				x = i + 1; y = j + 1;
			}
		}
	}
	cout << max << endl << x << ' ' << y;
}
