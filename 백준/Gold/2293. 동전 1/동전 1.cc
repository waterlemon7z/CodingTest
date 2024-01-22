#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> coin(N);
	vector<int> arr(K + 1);
	arr[0] = 1;
	for(int i = 0; i < N; i++)
	{
		cin >> coin[i];
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = coin[i]; j <= K; j++)
		{
			arr[j] += arr[j-coin[i]];
		}
	}
	cout << arr[K];
}
