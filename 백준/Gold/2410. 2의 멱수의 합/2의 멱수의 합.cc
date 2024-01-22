#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N, K, i;
	cin >> K;
	vector<int> coin;
	vector<int> arr(K + 1);
	arr[0] = 1;
	for(i = 1; i <= K; i *= 2)
	{
		coin.push_back(i);
	}
	for(auto iter = coin.begin(); iter != coin.end(); iter++)
	{
		for(int j = *iter; j <= K; j++)
		{
			arr[j] = (arr[j] + arr[j-*iter])%1000000000;
		}
	}
	cout << arr[K];
}
