#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	vector<int> arr(26, 0);
	cin >> str;
	for(auto iter : str)
	{
		arr[iter - 'a']++;
	}
	for(auto iter : arr)
	{
		cout << iter << ' ';
	}
}