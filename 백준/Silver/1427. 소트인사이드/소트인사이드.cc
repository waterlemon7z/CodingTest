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

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vector<int> arr;
	while ((n = cin.get()) != '\n')
	{
		n -='0';
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end(), comp);
	for(auto iter : arr)
		cout << iter;
}