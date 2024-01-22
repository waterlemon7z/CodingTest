#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> arr;
	int N, temp;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	cin >> N;
	sort(arr.begin(), arr.end());
	for(int i = 0; i < N; i ++)
	{
		cin >> temp;
		cout <<( binary_search(arr.begin(), arr.end(), temp) ? 1 : 0) << endl;
	}
}