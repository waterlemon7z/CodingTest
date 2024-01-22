#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//int MM;
vector<int> arr;
vector<int> input;
void dp(int N)
{
	int rst = 0;
	for(int i = 0; i < N; i++)
	{
		arr[i] = 1;
		for(int j = i; j >= 0; j--)
		{
			if(input[j] < input[i])
			{
				arr[i] = max(arr[i], arr[j] + 1);
			}
		}
		rst = max(arr[i], rst);
	}
	cout << rst;
}

int main()
{
	int n, m, temp;
	cin >> n;
	arr = vector<int>(n);
	for(int  i = 0; i < n ; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}
	dp(n);

}