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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int temp;
	vector<int> v;
	v.push_back(INF);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if(v.back() < temp)
			v.push_back(temp);
		else
		{
			int loc = lower_bound(v.begin(), v.end(), temp) - v.begin();
			v[loc] = temp;
		}
	}
	cout << v.size();
}