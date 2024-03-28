#include <bits/stdc++.h>

#define FSIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
	FSIO
	int N, K, board[15][15] = {0,};
	for (int i = 0; i < 15; i++)
	{
		board[0][i] = i;
	}
	for(int i = 1; i < 15; i++)
		for(int j = 1; j < 15; j++)
		{
			board[i][j] = board[i-1][j] + board[i][j-1];
		}
	int T;
	cin >> T;
	while(T--)
	{
		cin >> K >> N;
		cout << board[K][N] << endl;
	}
}