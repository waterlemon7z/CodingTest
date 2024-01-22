#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, int> pii;
int N, M, rst = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	string str;
	int temp;
	vector<bool> arr (21, 0);
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		if(str != "all" && str != "empty")
		cin >> temp;
		if(str == "add")
		{
			arr[temp] = 1;
		}
		else if(str == "remove")
		{
			arr[temp] = 0;
		}
		else if(str == "check")
		{
			if(arr[temp])
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if(str == "toggle")
		{
			arr[temp] = !arr[temp];
		}
		else if(str == "all")
		{
			arr = vector<bool> (21, 1);
		}
		else if(str == "empty")
		{
			arr = vector<bool> (21, 0);
		}
	}
}