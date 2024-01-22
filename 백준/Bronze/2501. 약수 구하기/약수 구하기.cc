#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	int N, K, cur = 0;
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
	{
		if(N % i == 0)
		{
			cur++;
			if(cur == K)
			{
				cout <<  i;
				return 0;
			}
		}
	}
	cout << 0;
}