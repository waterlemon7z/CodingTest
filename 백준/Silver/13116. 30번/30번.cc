#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N, A, B, lar, sma, aver;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if(A == 1 || B == 1)
		{
			cout << 10 << endl;
			continue;
		}

		lar = max(A, B);
		sma = min(A, B);
		aver = pow(2, int(log2(sma)) + 1);
		while (lar >= aver)
		{
			lar /= 2;
		}
		while (lar != 0)
		{
			if (lar == sma)
			{
				cout << lar * 10 << endl;
				break;
			}
			else
			{
				lar /= 2;
				sma /= 2;
			}
		}
	}
}