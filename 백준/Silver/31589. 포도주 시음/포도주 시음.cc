#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;


int main()
{
	FASTIO

	ull rst = 0;
	int N, K, fst,lst;
	int arr[300001] = {0,};
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr+N + 1);
	fst = 0;
	lst = N ;

	for(int i = 0; i < K; i++)
	{
		if(i % 2== 0)
		{
			rst += arr[lst] - arr[fst];
			lst--;
		}
		else
			fst++;
	}
	cout << rst;
}

