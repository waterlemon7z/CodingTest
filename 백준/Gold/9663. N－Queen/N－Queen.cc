#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
int N, rst = 0;
vector<int> arr;

bool check(int pos)
{
	for(int i = 0; i < N ; i++)
	{
		if(i == pos || arr[i] == -1)
			continue;
//		if(arr[i] == arr[pos])
//			return false;
		if(abs(pos - i) == abs(arr[pos] - arr[i]))
			return false;
	}
	return true;
}

void backT(int cur)
{
	if(cur == N)
	{
		rst++;
		return;
	}
	for(int i = 0; i < N; i++)
	{
		if(arr[i] == -1)
		{
			arr[i] = cur;
			if(check(i))
				backT(cur + 1);
			arr[i] = -1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	arr = vector<int> (N, -1);
	backT(0);
	cout << rst;
}

