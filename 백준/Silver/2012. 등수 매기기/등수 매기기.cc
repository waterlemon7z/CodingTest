#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;

using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> arr;
	int N;
	ll rst = 0;
	cin >> N;
	arr.resize(N);
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i < N; i++)
	{
		rst += abs(arr[i] - i - 1);
	}
	cout << rst;
}