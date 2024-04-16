#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	char arr[5][16] = {0,};
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(arr[j][i] != '\n' && arr[j][i] != 0)
			{
				cout << arr[j][i];
			}
		}
	}
}